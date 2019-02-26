#include <iostream>

using namespace std;

class Tasks {
public:
	double a;
	double b;
	double c;

	int a_int;
	int b_int;
	int c_int;

	Tasks(int a_int,int b_int,int c_int,double a, double b, double c) {
		this->a_int = a_int;
		this->b_int = b_int;
		this->c_int = c_int;
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Tasks() {}
	void createObject();
	int differenceThird();
	int multiplyThird();
	int sumThird();
	double sumSwimPoint();
	double differenceSwimPoint();
	double multiplySwimPoint();
	int divisionThird();
	double divisionSwimPoint();
	void print();

	~Tasks()
	{
		cout << "Deleting..." << endl;
	}
};

void Tasks::createObject() {
	cout << "Enter three double numbers : " << endl;
	double a, b, c;
	cin >> a >> b >> c;
	this->a = a;
	this->b = b;
	this->c = c;

	cout << "Enter three integer numbers : " << endl;
	int a_int, b_int, c_int;
	cin >> a_int >> b_int >> c_int;
	this->a_int = a_int;
	this->b_int = b_int;
	this->c_int = c_int;
}

void Tasks::print() {
	cout << "a = " << this->a << "\tb = " << this->b << "\tc = " << this->c
		<< endl << "a_int = " << this->a_int << "\tb_int = " << this->b_int << "\tc_int = " << this->c_int << endl;
}

double Tasks::differenceSwimPoint() {
	return this->a - this->b - this->c;
}

double Tasks::multiplySwimPoint() {
	return this->a * this->b * this->c;
}

double Tasks::sumSwimPoint() {
	return this->a + this->b + this->c;
}

double Tasks::divisionSwimPoint() {
	if (this->b == 0) {
		cout << "We cannot divide on 0.";
			return 0.0;
	}
	else {
		return this->a / this->b;
	}
}

int Tasks::differenceThird() {
	return this->a_int - this->b_int - this->c_int;
}

int Tasks::multiplyThird() {
	return this->a_int * this->b_int * this->c_int;
}

int Tasks::sumThird() {
	return a_int + b_int + c_int;
}

int Tasks::divisionThird() {
	if (this->b_int == 0) {
		cout << "We cannot divide on 0.";
		return 0;
	}
	else {
		return this->a_int / this->b_int;
	}
}

int main() {
	Tasks nums(12,13,14,12.5,14.7,18.9);
	nums.print();
	cout << "\n\n";
	cout <<"differencePoint rezult = " <<  nums.differenceSwimPoint()<< endl;
	cout << "difference integer = " << nums.differenceThird() << endl;
	cout << "divisionPoint = "<< nums.divisionSwimPoint() << endl;
	cout << "division integer = " << nums.divisionThird() << endl;
	cout << "multiplyPoint = " << nums.multiplySwimPoint() << endl;
	cout << "multiply integer = " << nums.multiplyThird() << endl;
	
	Tasks *nums_cos = new Tasks(12, 13, 14, 12.5, 14.7, 18.9);
	
	cout << "Oblique using : " << endl;
	cout << "sumPoint = " << nums_cos->sumSwimPoint() << endl;
	cout << "sum integer = " << nums_cos->sumThird() << endl;

	system("pause");
	return 0;
}
