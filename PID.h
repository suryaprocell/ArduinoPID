#ifndef PID_h
#define PID_h

#include <Arduino.h>

class PID
{
	public:
	PID(double KP, double KI, double KD);
	double Calculate(double SetPoint, double Input);
	void LimitP(double MaxP, double MinP);
	void LimitI(double MaxI, double MinI);

	private:
	double _KP;
	double _KI;
	double _KD;
	double P;
	double I;
	double D;
	double _MaxP;
	double _MinP;
	double _MaxI;
	double _MinI;
	double Error;
	double LastError;
	double Output;
};

#endif
