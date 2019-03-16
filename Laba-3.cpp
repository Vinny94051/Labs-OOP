#include <iostream>
#include <math.h>

using namespace std;

class Array
{
private:
	int SearchMinPos();
	int SearchMaxPos();
	int SearchMinModulPos();
	int SearchMaxModulPos();
	void deleteOne(int number);
public:
	int array_size;
	int *array = new int[array_size];
	Array(int array_size);
	~Array();

	void Set();
	void Print();
	int Run1();
	int Run2();
	int Run3();
	int Run4();
	int Run5();
	int Run6();
	void Run7(int a, int b);
	void Run8(int a, int b);
};
void Array::deleteOne(int number) {
	for (int i = number; i < array_size; i++)
	{
		array[i] = array[i + 1];
	}
	--array_size;
}

void Array::Run8(int a, int b) {
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] > a && array[i] < b) {
			deleteOne(i);
			i = 0;
		}
	}
}
void Array::Run7(int a, int b) {
	if (a > b) swap(a, b);

	int *newArray = new int[array_size];
	int newArrayCounter = 0;
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] >= a && array[i] <= b) {
			newArray[newArrayCounter] = array[i];
			newArrayCounter++;
		}
	}

	for (int i = 0; i < array_size; i++)
	{
		if (array[i] <= a || array[i] >= b) {
			newArray[newArrayCounter] = array[i];
			newArrayCounter++;
		}
	}
	for (int i = 0; i < array_size; i++)
	{
		array[i] = newArray[i];
	}
}
int Array::Run6() {
	bool flag = false;
	int rezult = 0;
	bool first = true;

	for (int i = 0; i < array_size; i++)
	{
		if (array[i] > 0 && !flag)
		{
			if (first) {
				first = false;
			}
			else {
				flag = true;
			}
		}
		if (flag) rezult += array[i];
	}
	return rezult;
}

int Array::Run5() {
	int rezult = 0;
	for (int i = SearchMaxPos(); i < array_size; i++)
	{
		rezult += array[i];
	}
	return rezult;
}
int Array::Run4() {
	int rezult = 0;

	for (int i = SearchMinModulPos(); i < array_size; i++)
	{
		rezult += abs(array[i]);
	}
	return rezult;

}

int Array::Run3() {
	int rezult = 0;

	for (int i = SearchMinPos() + 1; i < array_size; i++)
	{
		rezult += array[i];
	}
	return rezult;
}

int Array::SearchMaxModulPos() {
	int maxPosition = 0, max = INT16_MIN;
	for (int i = 0; i < array_size; i++)
	{
		if (abs(array[i]) > max) {
			maxPosition = i;
			max = array[i];
		}
	}
	return maxPosition;
}

int Array::SearchMinModulPos() {
	int minPosition = 0, min = INT16_MAX;
	for (int i = 0; i < array_size; i++)
	{
		if (abs(array[i]) < min) {
			minPosition = i;
			min = array[i];
		}
	}
	return minPosition;
}
int Array::Run2() {
	int rezult = 1;
	if (SearchMinModulPos() > SearchMaxModulPos()) {
		for (int i = SearchMaxModulPos() + 1; i < SearchMinModulPos(); i++)
		{
			rezult *= array[i];
		}
	}
	else {
		for (int i = SearchMinModulPos() + 1; i < SearchMaxModulPos(); i++)
		{
			rezult *= array[i];
		}
	}
	return rezult;
}

int Array::Run1() {
	int rezult = 1;
	if (SearchMinPos() > SearchMaxPos()) {
		for (int i = SearchMaxPos() + 1; i < SearchMinPos(); i++)
		{
			rezult *= array[i];
		}
	}
	else {
		for (int i = SearchMinPos() + 1; i < SearchMaxPos(); i++)
		{
			rezult *= array[i];
		}
	}
	return rezult;
}

int Array::SearchMinPos() {
	int minPosition = 0, min = 10000;
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] < min) {
			minPosition = i;
			min = array[i];
		}
	}
	return minPosition;
}


int Array::SearchMaxPos() {
	int maxPosition = 0, max = 0;
	for (int i = 0; i < array_size; i++)
	{
		if (array[i] > max) {
			maxPosition = i;
			max = array[i];
		}
	}
	return maxPosition;
}

void Array::Set() {
	for (int i = 0; i < array_size; i++)
	{
		cout << "Enter the " << i << "st elemnt : " << endl;
		cin >> array[i];
	}

}

void Array::Print() {
	for (int i = 0; i < array_size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
Array::Array(int array_size)
{
	this->array_size = array_size;

}

Array ::~Array()
{
	cout << "deleting" << endl;
}

int main() {

	Array ar(6);
	ar.Set();
	ar.Print();
	cout << "Run 1 : " << ar.Run1() << endl;
	cout << "Run 2 : " << ar.Run2() << endl;
	cout << "Run 3 : " << ar.Run3() << endl;
	cout << "Run 4 : " << ar.Run4() << endl;
	cout << "Run 5 : " << ar.Run5() << endl;
	cout << "Run 6 : " << ar.Run6() << endl;

	int a, b;
	cout << "Enter your range : " << endl;
	cin >> a >> b;
	if (a > b) {
		swap(a, b);
	}
	ar.Run7(a, b);
	ar.Print();
	ar.Run8(a, b);
	ar.Print();
	system("pause");
	return 0;
}
