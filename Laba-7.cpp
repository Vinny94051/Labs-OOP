#include <iostream>
#include <math.h>

using namespace std;


template <class T>
class Runner {
protected:
	int size; //N
	T *array = new T[size];
public:
	Runner(T *array, int size) {
		this->array = array;
		this->size = size;
	}

	~Runner() {
		delete array;
	}

	void setArray() {
		for (int i = 0; i < size; i++)	
		{
			cin >> array[i];
		}
	}

	void print() {
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}

	void Run1() {
		T *result = new T[size];
		result[0] = array[0];
		cout << endl << result[0] << " ";
		for (int i = 1; i < size - 1; i++)
		{
			result[i] = result[i - 1] + array[i + 1];
			cout << result[i] << " ";
		}
		cout << result[size - 3] + result[size - 2] << endl;
	}

	void Run2() {
		T *result = new T[size];
		for (int i = 0; i < size; i++)
		{
			result[i] = array[i] * array[0];
			cout << result[i] << " ";
		}
		cout << endl;
	}

	void Run3() {
		T *result = new T[size];
		result[0] = fabs(array[0]);
		cout << result[0] << " ";
		for (int i = 1; i < size - 1; i++)
		{
			result[i] = fabs(result[i - 1] + array[i + 1]);
			cout << result[i] << " ";
		}
		cout << fabs(result[size - 3] + result[size - 2]) << endl;
	}

	void Run4() {
		T *result = new T[size];
		for (int i = 0; i < size; i++)
		{
			result[i] = array[i] * (i + 1);
			cout << result[i] << " ";
		}
		cout << endl;
	}

	void Run5() {
		T *result = new T[size];
		for (int i = 0; i < size; i++)
		{
			result[i] = array[i] * pow(-1, i + 1);
			cout << result[i] << " ";
		}
		cout << endl;
	}

	void Run6() {
		T *result = new T[size];
		for (int i = 0; i < size; i++)
		{
			result[i] = array[i] + i + 1;
			cout << result[i] << " ";
		}
		cout << endl;
	}

	void Run7() {
		Run4();
	}

	void Run8() {
		T *result = new T[size];
		result[0] = array[0] * array[0];
		cout << result[0] << " ";
		for (int i = 1; i < size - 1; i++)
		{
			result[i] = array[i] * array[i + 1];
			cout << result[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	int size = 5;
	int *a = new int[size];
	Runner<int> run(a, size);

	run.setArray();
	run.print();

	run.Run1();

	run.Run2();

	run.Run3();

	run.Run4();

	run.Run5();

	run.Run6();

	run.Run7();

	run.Run8();
	
	system("pause");
	return 0;
}
