#include "include/DecimalMath.h"
#include "include/Decimal.h"


namespace System
{
	Decimal DecimalMath::PIx2 = Decimal::Parse("6.28318530717958647692528676655900576839433879875021");
	Decimal DecimalMath::PIdiv2 = Decimal::Parse("1.570796326794896619231321691639751442098584699687552910487");
	Decimal DecimalMath::PIdiv4 = Decimal::Parse("0.785398163397448309615660845819875721049292349843776455243");
	Decimal DecimalMath::Einv = Decimal::Parse("0.3678794411714423215955237701614608674458111310317678");
	Decimal DecimalMath::Log10Inv = Decimal::Parse("0.434294481903251827651128918916605082294397005803666566114");
	Decimal DecimalMath::Half = Decimal::Parse("0.5");

	Decimal DecimalMath::Pi = Decimal::Parse("3.14159265358979323846264338327950288419716939937510");
	Decimal DecimalMath::Epsilon = Decimal::Parse("0.0000000000000000001");
	Decimal DecimalMath::E = Decimal::Parse("2.7182818284590452353602874713526624977572470936999595749");
}
