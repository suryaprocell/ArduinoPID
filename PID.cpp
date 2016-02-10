#include <Arduino.h>
#include <PID.h>

PID::PID(double KP, double KI, double KD)
{
	_KP = KP;
	_KI = KI;
	_KD = KD;
	
}

void PID::LimitP(double MaxP, double MinP)
{
	_MaxP = MaxP;
	_MinP = MinP;
}

void PID::LimitI(double MaxI, double MinI)
{
	_MaxI = MaxI;
	_MinI = MinI;
}

double PID::Calculate(double SetPoint, double Input)
{
	Error = SetPoint - Input ;

	P = _KP * Error;
	if(P>_MaxP)
	{
		P = _MaxP;
	}
	else if(P<_MinP)
	{
		P = _MinP;
  	}

	I = I + (_KI * Error);
	if(I>_MaxI)
	{
		I = _MaxI;
	}
	else if(I<_MinI)
	{
		I = _MinI;
  	}

	D = _KD * (Error-LastError);

	LastError = Error;

	Output = P + I + D;

	return Output;
}
