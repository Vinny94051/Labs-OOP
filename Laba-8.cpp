#include <iostream>
#include <math.h>

using namespace std;

double division(double up, double down);
void Run1(double b);
void Run2(double x);
void Run3(double m);
void Run4(double a);
void Run5(double a);
void Run6(double m, double n);
void Run7(double m);
void Run8(double x);

int main() {
	double a;
	cout << "Enter the value" << endl;
	cin >> a;
	Run1(a);
	Run2(a);
	Run3(a);
	Run4(a);
	Run5(a);
	Run6(a, a + rand()%6+5);
	Run7(a);
	Run8(a);
	
	system("pause");
	return 0;
}

double division(double up, double down)
{
	if (down == 0) throw down;
	return up / down;
}

void Run1(double b)
{
	double value = pow(b*b - 4, 1. / 2);
	try {
		double Z1 = division(pow(2 * b + value, 1. / 2), value + b + 2);
		double Z2 = division(1, pow(b + 2, 1. / 2));
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}

void Run2(double x)
{
	try {
		double Z1 = division(x*x + 2 * x - 3 + (x + 1)*pow(x*x - 9, 1. / 2), x*x - 2 * x - 3 + (x - 1)*pow(x*x - 9, 1. / 2));
		double Z2 = pow(division(x + 3, x - 3), 1. / 2);
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}

void Run3(double m) {
	try {
		double Z1 = -division(sqrt(pow(3 * m + 2, 2) - 24 * m), 3 * sqrt(m) - division(2, sqrt(m)));
		double Z2 = -sqrt(m);
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}

void Run4(double a) {
	try {
		double Z1 = division(sqrt(a) - sqrt(2), a + 2)*(division(a+2,sqrt(2*a))- division(a,sqrt(2*a))+2+division(2, a - sqrt(2*a)));
		double Z2 = division(4 - a * a, 2);
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}

//Ошибка в методичке 90%
void Run5(double a) {
	try {
		double Z1 = (5 - 2 * a*a)*(division(1+a+a*a,a*(2+a)) + 2 - division((1 - a + a*a), a*(2 - a)));
		double Z2 = 4 - a * a / 2;
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}

void Run6(double m, double n) {
	try {
		double Z1 = division((m - 1)*sqrt(m) - (n - 1)*sqrt(n), m*(m*n + n + m - 1));
		double Z2 = division(sqrt(m) - sqrt(n), m);
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}

void Run7(double m) {
	try {
		double Z1 = division(sqrt(2*m+2*sqrt(m*m-4)),m + sqrt(m*m - 4) + 2);
		double Z2 = division(1, sqrt(m + 2));
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}

void Run8(double x) {
	try {
		double Z1 = division((x+1)*sqrt(x*x-9) + x*(x+2)-3, (x - 1)*sqrt(x*x - 9) + x * (x - 2) - 3);
		double Z2 = sqrt(division((x+3),x-3));
		cout << Z1 << " ~ " << Z2 << endl;
	}
	catch (double ex) {
		cout << " The down of the fraction is = " << ex << endl;
	}
}
