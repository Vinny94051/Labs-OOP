#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

class Array {
private:
	double **matrix;
	//Help methods
	int elementSumInPositiveString(int stringNumber);
	double middleStringValue(int stringNumber);
public:
	int x;
	int y;
	
	Array(int x, int y) {
		this->x = x;
		this->y = y;
	}

	~Array() {
		delete matrix;
	}

	//Standart methods
	friend void arrayInicializacing(Array &array); //Friend function
	void print();
	void set(int i, int j, int new_value);
	void arrayNoConstantInicialize();

	//Different solutions
	void elementSumInPositiveStrings();
	int stringWithZeroNumber();
	int searchNegativeString();
	int searchNegativeColumn();
	int searchColumnWithMinimalyOnePositiveElement();
	int searchStringWithMinimalyOnePositiveElement();
	int compareToMiddleStringValue(double value);
	double sumElementsModuleHigherMainDiag();
};

int main() {
	srand(time(NULL));	//Not the constantly random
	Array array(5, 5);

	arrayInicializacing(array);
	array.print();
	
	array.elementSumInPositiveStrings();	//Task 1
	array.set(3, 3, 0);		//Set 0 instead of 3:3 element
	
	array.print();
	array.stringWithZeroNumber();	//Task 2

	for (int j = 0; j < array.y; j++)	//Set -5 instead of second string
	{
		array.set(2, j, -5);
	}

	array.print();
	
	array.searchNegativeString();	//Task 3
											
	for (int j = 0; j < array.x; j++) //Set -4 instead of second column
	{
		array.set(j, 2, -4);
	}

	array.print();
	
	array.searchNegativeColumn();	//Task 4
	array.searchColumnWithMinimalyOnePositiveElement();	//Task 5

	array.print();

	array.searchStringWithMinimalyOnePositiveElement();	//Task 6

	//==============================================================================================

	cout << "Now i create new matrix." << endl;
	double valueForComparing;								//This variable is for comparing with it
	cout << "Enter the value for comparing : " << endl;		//arithmetic average modules of array strings.
	cin >> valueForComparing;

	Array *ptrarray = new Array(3, 3);	//New not constant object for last tasks
	ptrarray->arrayNoConstantInicialize();
	ptrarray->print();
	ptrarray->compareToMiddleStringValue(valueForComparing);	//Task 7
	ptrarray->sumElementsModuleHigherMainDiag();	//Task 8

	system("pause");
	return 0;
}

int Array::elementSumInPositiveString(int stringNumber)
{
	int sum = 0;
	for (int j = 0; j < x; j++) {
		if (matrix[stringNumber][j] > 0) {
			sum += matrix[stringNumber][j];
		}
		else {
			return 0;
		}
	}

	return sum;

}

double Array::middleStringValue(int stringNumber)
{
	double middleValue = 0;
		for (int j = 0; j < x; j++)
		{
			middleValue += matrix[stringNumber][j];
		}
	return middleValue / x;
}

void arrayInicializacing(Array &array)
{
	array.matrix = new double*[array.x];
	for (int i = 0; i < array.y; i++)
	{
		for (int j = 0; j < array.x; j++)
		{
			array.matrix[i] = new double[array.y];
		}
	}

	for (int i = 0; i < array.y; i++)
	{
		for (int j = 0; j < array.x; j++) {
			array.matrix[i][j] = rand() % 101 - 30;
		}
	}
}

void Array::print()
{
	if (matrix) {
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Matrix isn't created." << endl;
	}

	cout << "\n\n";
}

void Array::set(int i, int j, int new_value)
{
	matrix[i][j] = new_value;
}

void Array::arrayNoConstantInicialize()
{
	matrix = new double*[x];
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			matrix[i] = new double[y];
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++) {
			matrix[i][j] = rand() % 101 - 30;
		}
	}
}

void Array::elementSumInPositiveStrings()
{

	for (int i = 0; i < x; i++)
	{
		int thisSum = elementSumInPositiveString(i);
		if (thisSum > 0) {
			cout << "String number " << (i+1) << " sum is : " << thisSum << endl;
		}
		else {
			cout << "String " << (i+1) << " isn't validated." << endl;
		}
	}
	cout << "\n";
}

int Array::stringWithZeroNumber()
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (matrix[i][j] == 0) {
				cout << "String number " << (i+1) << " have 0" << endl;
				return i;
			}
		}
	}
	cout << "We have no 0 in the array" << endl;
	cout << "\n";
}

int Array::searchNegativeString()
{
	bool isNegative;
	for (int i = 0; i < x; i++)
	{ 
		isNegative = true;
		for (int j = 0; j < y; j++)
		{
			if (matrix[i][j] > 0) isNegative = false;
		}
		if (isNegative) { 
			cout << "String number " << (i+1) << " consist of only negative numbers." << endl;
			cout << "\n";
			return i; 
		}
	}
	cout << "We have no it." << endl;
	return 0;
}

int Array::searchNegativeColumn()
{
	bool isNegative;
	for (int i = 0; i < y; i++)
	{
		isNegative = true;
		for (int j = 0; j < x; j++)
		{
			if (matrix[j][i] > 0) isNegative = false;
		}
		if (isNegative) {
			cout << "Column number " << (i+1) << " consist of only negative numbers.";
			cout << "\n";
			return i;
		}
	}
	cout << "We have no it." << endl;
	cout << "\n";
	return 0;
}

int Array::searchColumnWithMinimalyOnePositiveElement()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix[j][i] > 0) {
				cout << "\nThe column number " << (i+1) << " exactly has one positive element." << endl;
				cout << "\n";
				return i;
			}
		}
	}
	cout << "\nWe have no it." << endl;
	cout << "\n";
	return 0;
}

int Array::searchStringWithMinimalyOnePositiveElement()
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix[i][j] > 0) {
				cout << "\nThe string number " << (i + 1) << " exactly has one positive element." << endl;
				cout << "\n";
				return i;
			}
		}
	}
	cout << "\nWe have no it." << endl;
	cout << "\n";
	return 0;
}

int Array::compareToMiddleStringValue(double value)
{		
	int numberOfStrings = 0;
	for (int i = 0; i < y; i++)
	{	
		if (this->middleStringValue(i) > value) {
			numberOfStrings++;
		}
	}
	cout << "The number of matching condition strings are : " << numberOfStrings << endl;
	cout << "\n";
	return numberOfStrings;
}

double Array::sumElementsModuleHigherMainDiag()
{
	double sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = i+1; j < y; j++)
		{
			sum += fabs(matrix[i][j]);
		}
	}
	cout << "Sum of the elemetnts higher than main diagonal is : " << sum << endl;
	cout << "\n";
	return sum;
}
