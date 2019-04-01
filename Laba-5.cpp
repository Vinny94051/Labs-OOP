#include <iostream>
#include <string.h>
#include <string>
#include <String>
using namespace std;

class String {
private:
	string str;
	int str_size;
public:
	
	String(string str) {
		this->str = str;
	}

	~String(){}

	void Set();
	void print();

	String& operator=(String& o1);
};



int main() {
	string s;
	String str(s);
	str.Set();
	str.print();
	
	String str2(s);
	str2.Set();
	str2.print();


	str = str2;
	str.print();
	system("pause");
	exit(0);
	return 0;
}

void String::Set()
{
	cout << "Enter str." << endl;
	getline(cin, str);
	str_size = str.size();
}

void String::print()
{
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
}


//This method do all work, but on one launching you can show only one task
String & String::operator=(String & o1)
{
	if (this == &o1) return *this;

	cout << "Enter the number of operation(1-8)";
	int number;
	cin >> number;

	switch (number) {
	case 1: {
		str = o1.str.substr(1, o1.str.size() - 2);
		break;
	}
	case 2: {
		for (int i = 0; i < o1.str.size(); i++)
		{
			if ((o1.str[i] > 47 && o1.str[i] < 58) && (int)(o1.str[i]) % 2 == 0) {
				o1.str[i] = '_';
			}
		}
		string buf = "";
		for (int i = 0; i < o1.str.size(); i++)
		{
			if (o1.str[i] == '_') continue;
			buf += o1.str[i];
		}
		str = buf;
		break;
	}
	case 3: {
		for (int i = 0; i < o1.str.size(); i++)
		{
			if ((int)(o1.str[i]) > 47 && (int)(o1.str[i]) < 58) {
				o1.str[i] = '_';
			}
		}
		string buf = "";
		for (int i = 0; i < o1.str.size(); i++)
		{
			if (o1.str[i] == '_') continue;
			buf += o1.str[i];
		}
		str = buf;
		break;
	}//97-122
	case 4: {
		for (int i = 0; i < o1.str.size(); i++)
		{
			if ((int)(o1.str[i]) > 96 && (int)(o1.str[i]) < 123) {
				o1.str[i] = '_';
			}
		}
		string buf = "";
		for (int i = 0; i < o1.str.size(); i++)
		{
			if (o1.str[i] == '_') continue;
			buf += o1.str[i];
		}
		str = buf;
		break;
	}//65-90
	case 5: {
		for (int i = 0; i < o1.str.size(); i++)
		{
			if ((int)(o1.str[i]) > 64 && (int)(o1.str[i]) < 91) {
				o1.str[i] = '_';
			}
		}
		string buf = "";
		for (int i = 0; i < o1.str.size(); i++)
		{
			if (o1.str[i] == '_') continue;
			buf += o1.str[i];
		}
		str = buf;
		break;
	}
	case 6: {
		for (int i = 0; i < o1.str.size(); i++)
		{
			if (o1.str[i] == '(' || o1.str[i] == ')' || o1.str[i] == '{' || o1.str[i] == '}'
				|| o1.str[i] == '[' || o1.str[i] == ']') {
				o1.str[i] = '_';
			}
		}
		string buf = "";
		for (int i = 0; i < o1.str.size(); i++)
		{
			if (o1.str[i] == '_') continue;
			buf += o1.str[i];
		}
		str = buf;		
		break;
	}
	case 7: {
		str = o1.str.substr(0, o1.str.find(' '));
		break;
	}
	case 8: {
		int a = o1.str.find('{');
		int b = o1.str.find('}');
		str = o1.str.substr(a,b-1);
		break;
	}
	default: //simple appropriation (without any features)
		str = o1.str;
	}
	return *this;
}
