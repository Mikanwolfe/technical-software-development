#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double computeVoltageCharging(double VB, double C, double t, double R) {
	double result;
	result = VB * (1 - exp(-t / (R*C)));
	return result;
}

double computeCurrentCharging(double VB, double C, double t, double R) {
	double result;
	result = VB / R * exp(-t / (R * C));
	return result;
}

double computeVoltageDischarging(double VB, double C, double t, double R) {
	double result;
	result = VB * exp(-t / (R * C));
	return result;
}

double computeCurrentDischarging(double VB, double C, double t, double R) {
	double result;
	result = -VB / R * exp(-t / (R * C));
	return result;
}

void outputChargingDischarging(double VB, double C, double t, double R) {
	double IC, VC, uC;
	uC = C * pow(10, -6);	//capacitance conversation from uF to F

	VC = computeVoltageCharging(VB, uC, t, R);
	IC = computeCurrentCharging(VB, uC, t, R);
	cout << "Charging VC(t) = " << VC << " volts" << endl
		<< "Charging IC(t) = " << IC << " amps" << endl;

	VC = computeVoltageDischarging(VB, uC, t, R);
	IC = computeCurrentDischarging(VB, uC, t, R);
	cout << "Discharging VC(t) = " << VC << " volts" << endl
		<< "Discharging IC(t) = " << IC << " amps" << endl;
}

void printTimeSeriesVoltageCharging(double VB, double R, double C, int maxTime) {
	double uC = C * pow(10, -6);	//capacitance conversation from uF to F
	for (int i = 0; i <= maxTime; i++) {
		cout << "(" << i << ", " << computeVoltageCharging(VB, uC, i, R) << ")" << endl;
	}
}

void printTimeSeriesVoltageDischarging(double VB, double R, double C, int maxTime) {
	double uC = C * pow(10, -6);	//capacitance conversation from uF to F
	for (int i = 0; i <= maxTime; i++) {
		cout << "(" << i << ", " << computeVoltageDischarging(VB, uC, i, R) << ")" << endl;
	}
}

void printTimeSeriesVoltage(bool isCharging, double VB, double R, double C, int maxTime) {
	if (isCharging) {
		printTimeSeriesVoltageCharging(VB, R, C, maxTime);
	}
	else {
		printTimeSeriesVoltageDischarging(VB, R, C, maxTime);
	}
}


int main() {
	double VC, IC, R, C, VB, t, uC;
	int maxTime;

	R = 56000;				//Resistance in Ohms
	C = 470;				//Capacitance in MicroFarads (uF)
	VB = 9;					//Voltage across the battery in volts
	t = 26;					//Time constant in seconds
	maxTime = 30;

	cout << "Using the predetermined values, the calculated results are:" << endl << endl;
	outputChargingDischarging(VB, C, t, R);

	printTimeSeriesVoltage(false, VB, C, R, maxTime);
	printTimeSeriesVoltage(true, VB, C, R, maxTime);
	return 0;
}