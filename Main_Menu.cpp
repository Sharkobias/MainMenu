#include <iostream>
#include <stdlib.h>
using namespace std;

int MenuStart()
{
	system("CLS");
	cout << " " << "______________________" << " " << endl;
	cout << "|" << "                      " << "|" << endl;
	cout << "|" << "      " << "MAIN" << "  " << "MENU" << "      " << "|" << endl;
	cout << "|" << "                      " << "|" << endl;
	cout << "|" << "   [1]CALCULATOR      " << "|" << endl;
	cout << "|" << "     [2]CINEMA        " << "|" << endl;
	cout << "|" << "      [3]MEAN         " << "|" << endl;
	cout << " " << "______________________" << " " << endl;
	cout << " " << endl;
	int choice;
	cin >> choice;
	return choice;
}
class Calculator
{
public:
	double a;
	double b;
	string typeoutput;
	double result;
	void GetCalculationType()
	{
		cout << "choose calculation type:" << endl;
		cout << "addition[+]" << " " << "difference[-]" << " " << "multiplication[*]" << "division[/]" << " " << "square[^2]" << endl;
		cin >> typeoutput;
	}
	void GetNums()
	{
		if (typeoutput == "+")
		{
			cout << "insert two numbers to add" << endl;
			cin >> a;
			cin >> b;
			result = a + b;
			cout << "The result of your addition equals:" << " " << result << endl;
		}
		else if (typeoutput == "-")
		{
			cout << "insert two numbers to Substract" << endl;
			cin >> a;
			cin >> b;
			result = a - b;
			cout<<"The result of your Substraction equals:" << " " << result << endl;
		}
		else if (typeoutput == "*")
		{
			cout << "insert two numbers to Multiply" << endl;
			cin >> a;
			cin >> b;
			result = a * b;
			cout<< "The result of your Multiplication equals : " << " " << result << endl;
		}
		else if (typeoutput == "/")
		{
			cout << "insert two numbers to divide" << endl;
			cin >> a;
			cin >> b;
			result = a / b;
			cout << "The result of your division equals : " << " " << result << endl;
		}
		else if (typeoutput == "2^") 
		{
			cout << "insert an number to square" << endl;
			cin >> a;
			result = a * a;
			cout << "The result of your exponentation equals : " << " " << result << endl;
		}
	}
};

int main()
{
	int choice;
	choice = MenuStart();
	if (choice == 1)
	{
		cout << "You entered Calculator" << endl;
		Calculator calculate;
		calculate.GetCalculationType();
		calculate.GetNums();
	}

	return 0;
}