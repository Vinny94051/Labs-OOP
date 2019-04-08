#include <iostream>
#include <ctime>

using namespace std;

class X {
protected:
	int x1;
	int x2;
public:

	X(int x1, int x2) {
		this->x1 = x1;
		this->x2 = x2;
	}
	X() {}
	~X(){}

	virtual int getX1() {
		return this->x1;
	}

	virtual int getX2() {
		return this->x2;
	}

	virtual void setX1(int x1) {
		this->x1 = x1;
	}

	virtual void setX2(int x2){
		this->x2 = x2;
	}

	virtual void print() {
		cout << "x1 = " << this->x1 << endl
			<< "x2 = " << this->x2 << endl;
	}
};

class Y : public X
{
	int y1;
public:
	Y(int y1) : X(x1,x2){
		this->y1 = y1;
	}
	Y() : X() {}
	
	~Y(){}
	virtual void print() {
	cout << "y1 = " << this->y1 << endl << "x1 = " << this->x1 << endl
		<< "x2 = " << this->x2 << endl;
	}

	void Run() {
		if (x1 != NULL && x2 != NULL)
			cout << "The sum is: " << y1 + x1 + x2 << endl <<
			"The multiply is: " << y1 * x1*x2 << endl <<
			"The squares sum is : " << y1 * y1 + x1 * x1 + x2 * x2 << endl <<
			"The 5th(x1+x2-y1) : " << x1 + x2 - y1 << endl <<
			"The 6th((x1+x2)/y1 : " << (x1 + x2) / y1 << endl <<
			"The 7th((x1+x2)*y1) : " << (x1 + x2)*y1 << endl <<
			"The 8th(x1*y1+x2) : " << x1 * y1 + x2 << endl;
	}
};

int main() {
	X x1(12, 3);
	x1.print();

	Y *y1 = new Y(1);
	y1->setX1(69);
	y1->setX2(96);
	y1->print();
	y1->Run();
	
	
	system("pause");
	return 0;
}
