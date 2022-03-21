#pragma once
#include "Decimal.h"
#include "Exception.h"

// ReSharper disable once IdentifierTypo
namespace System
{
	/**
	 * \brief Analogy of Syatem.Math class for Decimal types 
	 */
	class DecimalMath
	{
		/**
		 * \brief represents 2*PI
		 */
		static Decimal PIx2;

		/**
		 * \brief represents PI/2
		 */
		static Decimal PIdiv2;

		/**
		 * \brief represents PI/4
		 */
		static Decimal PIdiv4;

		/**
		 * \brief represents 1.0/E
		 */
		static Decimal Einv;

		/**
		 * \brief log(10,E) factor
		 */
		static Decimal Log10Inv;

		/**
		 * \brief Represents 0.5M
		 */
		static Decimal Half;

		/**
		 * \brief Max iterations count in Taylor series
		 */
		static const int MaxIteration = 100;

		static bool IsInteger(Decimal value)
		{
			long longValue = Decimal::ToInt64(value);
			return Abs(value - longValue) <= Epsilon;
		}

		/**
		 * \brief Helper function for calculating sin(x) from cos(x)
		 * \param x 
		 * \param cos 
		 * \return 
		 */
		static Decimal CalculateSinFromCos(Decimal x, Decimal cos)
		{
			Decimal moduleOfSin = Sqrt(Decimal::One - (cos * cos));
			bool sineIsPositive = IsSignOfSinePositive(x);
			if (sineIsPositive) return moduleOfSin;
			return -moduleOfSin;
		}

		/**
		 * \brief Truncates to  [-2*PI;2*PI]
		 * \param x 
		 */
		static void TruncateToPeriodicInterval(Decimal& x)
		{
			while (x >= PIx2)
			{
				int divide = abs(Decimal::ToInt32(x / PIx2));
				x -= divide * PIx2;
			}

			while (x <= -PIx2)
			{
				int divide = abs(Decimal::ToInt32(x / PIx2));
				x += divide * PIx2;
			}
		}

		static bool IsSignOfSinePositive(Decimal x)
		{
			//truncating to  [-2*PI;2*PI]
			TruncateToPeriodicInterval(x);

			//now x in [-2*PI;2*PI]
			if (x >= -PIx2 && x <= -Pi) return true;
			if (x >= -Pi && x <= Decimal::Zero) return false;
			if (x >= Decimal::Zero && x <= Pi) return true;
			if (x >= Pi && x <= PIx2) return false;

			//will not be reached
			throw ArgumentException("x");
		}

	public:
		/**
		 * \brief represents PI
		 */
		static System::Decimal Pi;

		/**
		 * \brief represents PI
		 */
		static Decimal Epsilon;

		/**
		 * \brief represents E
		 */
		static Decimal E;

		/**
		 * \brief Analogy of Math.Exp method
		 * \param x 
		 * \return 
		 */
		static Decimal Exp(Decimal x)
		{
			int count = 0;

			if (x > Decimal::One)
			{
				count = Decimal::ToInt32(Decimal::Truncate(x));
				x -= Decimal::Truncate(x);
			}

			if (x < Decimal::Zero)
			{
				count = Decimal::ToInt32(Decimal::Truncate(x) - 1);
				x = Decimal::One + (x - Decimal::Truncate(x));
			}

			int iteration = 1;
			Decimal result = Decimal::One;
			Decimal factorial = Decimal::One;
			Decimal cachedResult;
			do
			{
				cachedResult = result;
				factorial *= x / iteration++;
				result += factorial;
			}
			while (cachedResult != result);

			if (count == 0)
				return result;
			return result * PowerN(E, count);
		}

		/**
		 * \brief Analogy of Math.Pow method
		 * \param value 
		 * \param pow 
		 * \return 
		 */
		static Decimal Power(Decimal value, Decimal pow)
		{
			if (pow == Decimal::Zero) return Decimal::One;
			if (pow == Decimal::One) return value;
			if (value == Decimal::One) return Decimal::One;

			if (value == Decimal::Zero)
			{
				if (pow > Decimal::Zero)
				{
					return Decimal::Zero;
				}

				throw Exception("Invalid Operation: zero base and negative power");
			}

			if (pow == -Decimal::One) return Decimal::One / value;

			bool isPowerInteger = IsInteger(pow);
			if (value < Decimal::Zero && !isPowerInteger)
			{
				throw Exception("Invalid Operation: negative base and non-integer power");
			}

			if (isPowerInteger && value > Decimal::Zero)
			{
				int powerInt = Decimal::ToInt32(pow);
				return PowerN(value, powerInt);
			}

			if (isPowerInteger && value < Decimal::Zero)
			{
				int powerInt = Decimal::ToInt32(pow);
				if (powerInt % 2 == 0)
				{
					return Exp(pow * Log(-value));
				}

				return -Exp(pow * Log(-value));
			}

			return Exp(pow * Log(value));
		}

		/**
		 * \brief  Power to the integer value
		 * \param value 
		 * \param power 
		 * \return 
		 */
		static Decimal PowerN(Decimal value, int power)
		{
			while (true)
			{
				if (power == Decimal::Zero) return Decimal::One;
				if (power < Decimal::Zero)
				{
					value = Decimal::One / value;
					power = -power;
					continue;
				}

				int q = power;
				Decimal prod = Decimal::One;
				Decimal current = value;
				while (q > 0)
				{
					if (q % 2 == 1)
					{
						// detects the 1s in the binary expression of power
						prod = current * prod; // picks up the relevant power
						q--;
					}

					current *= current; // value^i -> value^(2*i)
					q >>= 1;
				}

				return prod;
			}
		}

		/**
		 * \brief Analogy of Math.Log10
		 * \param x 
		 * \return 
		 */
		static Decimal Log10(Decimal x)
		{
			return Log(x) * Log10Inv;
		}

		/**
		 * \brief Analogy of Math.Log
		 * \param x 
		 * \return 
		 */
		static Decimal Log(Decimal x)
		{
			if (x <= Decimal::Zero)
			{
				throw ArgumentException("x must be greater than zero");
			}
			int count = 0;
			while (x >= Decimal::One)
			{
				x *= Einv;
				count++;
			}
			while (x <= Einv)
			{
				x *= E;
				count--;
			}
			x--;
			if (x == Decimal::Zero) return count;
			Decimal result = Decimal::Zero;
			int iteration = 0;
			Decimal y = Decimal::One;
			Decimal cacheResult = result - Decimal::One;
			while (cacheResult != result && iteration < MaxIteration)
			{
				iteration++;
				cacheResult = result;
				y *= -x;
				result += y / iteration;
			}
			return count - result;
		}

		/**
		 * \brief Analogy of Math.Cos
		 * \param x 
		 * \return 
		 */
		static Decimal Cos(Decimal x)
		{
			//truncating to  [-2*PI;2*PI]
			TruncateToPeriodicInterval(x);

			// now x in (-2pi,2pi)
			if (x >= Pi && x <= PIx2)
			{
				return -Cos(x - Pi);
			}
			if (x >= -PIx2 && x <= -Pi)
			{
				return -Cos(x + Pi);
			}

			x *= x;
			//y=1-x/2!+x^2/4!-x^3/6!...
			Decimal xx = -x * Half;
			Decimal y = Decimal::One + xx;
			Decimal cachedY = y - Decimal::One; //init cache  with different value
			for (int i = 1; cachedY != y && i < MaxIteration; i++)
			{
				cachedY = y;
				Decimal factor = i * ((i << 1) + 3) + 1; //2i^2+2i+i+1=2i^2+3i+1
				factor = -Half / factor;
				xx *= x * factor;
				y += xx;
			}
			return y;
		}

		/**
		 * \brief Analogy of Math.Tan
		 * \param x 
		 * \return 
		 */
		static Decimal Tan(Decimal x)
		{
			Decimal cos = Cos(x);
			if (cos == Decimal::Zero) throw ArgumentException("x");
			//calculate sin using cos
			Decimal sin = CalculateSinFromCos(x, cos);
			return sin / cos;
		}

		/**
		 * \brief Analogy of Math.Sin
		 * \param x 
		 * \return 
		 */
		static Decimal Sin(Decimal x)
		{
			Decimal cos = Cos(x);
			return CalculateSinFromCos(x, cos);
		}

		/**
		 * \brief Analogy of Math.Sqrt
		 * \param x 
		 * \param epsilon lasts iteration while error less than this epsilon
		 * \return 
		 */
		static Decimal Sqrt(Decimal x, Decimal epsilon = Decimal::Zero)
		{
			if (x < Decimal::Zero) throw System::OverflowException("Cannot calculate square root from a negative number");
			//initial approximation
			Decimal current = (Decimal)sqrt(Decimal::ToDouble(x)), previous;
			do
			{
				previous = current;
				if (previous == Decimal::Zero) return Decimal::Zero;
				current = (previous + x / previous) * Half;
			}
			while (Abs(previous - current) > epsilon);
			return current;
		}

		/**
		 * \brief  Analogy of Math.Sinh
		 * \param x 
		 * \return 
		 */
		static Decimal Sinh(Decimal x)
		{
			Decimal y = Exp(x);
			Decimal yy = Decimal::One / y;
			return (y - yy) * Half;
		}

		/**
		 * \brief Analogy of Math.Cosh
		 * \param x 
		 * \return 
		 */
		static Decimal Cosh(Decimal x)
		{
			Decimal y = Exp(x);
			Decimal yy = Decimal::One / y;
			return (y + yy) * Half;
		}

		/**
		 * \brief Analogy of Math.Sign
		 * \param x 
		 * \return 
		 */
		static int Sign(Decimal x)
		{
			return x < Decimal::Zero ? -1 : (x > Decimal::Zero ? 1 : 0);
		}

		/**
		 * \brief Analogy of Math.Tanh
		 * \param x 
		 * \return 
		 */
		static Decimal Tanh(Decimal x)
		{
			Decimal y = Exp(x);
			Decimal yy = Decimal::One / y;
			return (y - yy) / (y + yy);
		}

		/**
		 * \brief Analogy of Math.Abs
		 * \param x 
		 * \return 
		 */
		static Decimal Abs(Decimal x)
		{
			if (x <= Decimal::Zero)
			{
				return -x;
			}
			return x;
		}

		/**
		 * \brief Analogy of Math.Asin
		 * \param x 
		 * \return 
		 */
		static Decimal Asin(Decimal x)
		{
			if (x > Decimal::One || x < -Decimal::One)
			{
				throw ArgumentException("x must be in [-1,1]");
			}
			//known values
			if (x == Decimal::Zero) return Decimal::Zero;
			if (x == Decimal::One) return PIdiv2;
			//asin function is odd function
			if (x < Decimal::Zero) return -Asin(-x);

			//my optimize trick here

			// used a math formula to speed up :
			// asin(x)=0.5*(pi/2-asin(1-2*x*x)) 
			// if x>=0 is true

			Decimal newX = Decimal::One - 2 * x * x;

			//for calculating new value near to zero than current
			//because we gain more speed with values near to zero
			if (Abs(x) > Abs(newX))
			{
				Decimal t = Asin(newX);
				return Half * (PIdiv2 - t);
			}
			Decimal y = Decimal::Zero;
			Decimal result = x;
			Decimal cachedResult;
			int i = 1;
			y += result;
			Decimal xx = x * x;
			do
			{
				cachedResult = result;
				result *= xx * (Decimal::One - Half / (i));
				y += result / ((i << 1) + 1);
				i++;
			}
			while (cachedResult != result);
			return y;
		}

		/**
		 * \brief Analogy of Math.Atan
		 * \param x 
		 * \return 
		 */
		static Decimal Atan(Decimal x)
		{
			if (x == Decimal::Zero) return Decimal::Zero;
			if (x == Decimal::One) return PIdiv4;
			return Asin(x / Sqrt(Decimal::One + x * x));
		}

		/**
		 * \brief Analogy of Math.Acos
		 * \param x 
		 * \return 
		 */
		static Decimal Acos(Decimal x)
		{
			if (x == Decimal::Zero) return PIdiv2;
			if (x == Decimal::One) return Decimal::Zero;
			if (x < Decimal::Zero) return Pi - Acos(-x);
			return PIdiv2 - Asin(x);
		}

		/**
		 * \brief Analogy of Math.Atan2 for more see this
		 * \param y 
		 * \param x 
		 * \return  http://i.imgur.com/TRLjs8R.png
		 */
		static Decimal Atan2(Decimal y, Decimal x)
		{
			if (x > Decimal::Zero)
			{
				return Atan(y / x);
			}
			if (x < Decimal::Zero && y >= Decimal::Zero)
			{
				return Atan(y / x) + Pi;
			}
			if (x < Decimal::Zero && y < Decimal::Zero)
			{
				return Atan(y / x) - Pi;
			}
			if (x == Decimal::Zero && y > Decimal::Zero)
			{
				return PIdiv2;
			}
			if (x == Decimal::Zero && y < Decimal::Zero)
			{
				return -PIdiv2;
			}
			throw ArgumentException("invalid atan2 arguments");
		}
	};
}
