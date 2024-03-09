#include <iostream>
#include <stdlib.h>
using namespace std;


string MenuStart()
{
	system("CLS");
	cout << " " << "______________________" << " " << endl;
	cout << "|" << "                      " << "|" << endl;
	cout << "|" << "      " << "MAIN" << "  " << "MENU" << "      " << "|" << endl;
	cout << "|" << "                      " << "|" << endl;
	cout << "|" << "     >CALCULATOR      " << "|" << endl;
	cout << "|" << "       >CINEMA        " << "|" << endl;
	cout << "|" << "        >MEAN         " << "|" << endl;
	cout << " " << "______________________" << " " << endl;
}
class Calculator
{
public:
	double a;
	double b;
	string typeoutput;
	string _type;
	void GetCalculationType()
	{
		cout << "choose calculation type:" << endl;
		cout << "addition[+]" << " " << "difference[-]" << " " << "multiplication[*]" << "division[/]" << " " << "square[^2]" << endl;
		cin >> typeoutput;
	}
	double GetNums()
	{
		if (typeoutput == "+")
		{
			cout << "insert two numbers to add" << endl;
			cin >> a;
			cin >> b;
		}
		else if (typeoutput == "-")
		{
			cout << "insert two numbers to Substract" << endl;
			cin >> a;
			cin >> b;
		}
		else if (typeoutput == "*")
		{
			cout << "insert two numbers to Multiply" << endl;
			cin >> a;
			cin >> b;
		}
		else if (typeoutput == "/")
		{
			cout << "insert two numbers to divide" << endl;
			cin >> a;
			cin >> b;
		}
		else if (typeoutput == "2^") 
		{
			cout << "insert an number to square" << endl;
			cin >> a;
		}
	}

};

int main()
{
	MenuStart();
	return 0;
}