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
	result = -VB /R * exp(-t / (R * C));
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

int main() {
	double VC, IC, R, C, VB, t, uC;

	R = 56000;				//Resistance in Ohms
	C = 470;				//Capacitance in MicroFarads (uF)
	VB = 9;					//Voltage across the battery in volts
	t = 26;					//Time constant in seconds

	cout << "Using the predetermined values, the calculated results are:" << endl << endl;
	outputChargingDischarging(VB, C, t, R);

	while (1) {

		cout << endl << "Please enter values for the following variables:" << endl
			<< "Resistance, R, in Ohms: " << endl;
		cin >> R;
		cout << "Capacitance, C, in microfarads (uF): " << endl;
		cin >> C;
		cout << "Voltage across battery, VB, in volts (v): " << endl;
		cin >> VB;
		cout << "Time to charge/discharge for, t, in seconds (t): " << endl;
		cin >> t;
		cout << endl;

		outputChargingDischarging(VB, C, t, R);
	}
	return 0;
}