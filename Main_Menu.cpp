#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <chrono>
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
	string problem;
	double result;
	void GetCalculation() 
	{
		cout << "write your mathematical problem with space delinated:" << endl;
		cin.ignore();
		getline(cin, problem);
		stringstream ss(problem);
		vector<string> split_problem;
		string part;

		while (getline(ss,part, ' '))
		{
			split_problem.push_back(part);
		}
		if (split_problem[1] == "+")
		{
			result = stod(split_problem[0]) + stod(split_problem[2]);
		}
		else if (split_problem[1] == "-")
		{
			result = stod(split_problem[0]) - stod(split_problem[2]);
		}
		else if (split_problem[1] == "*")
		{
			result = stod(split_problem[0]) * stod(split_problem[2]);
		}
		else if (split_problem[1] == "/" )
		{
			result = stod(split_problem[0]) / stod(split_problem[2]);
		}
		else 
		{
			cout << "unsupported type of equation" << endl;
		}
		cout << "equals:" << " " << result << endl;

	}
	/*void GetCalculationType()
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
	}*/
	void GetMean()
	{
		string input;
		cout << "enter your numbers space delinated" << endl;
		cin.ignore();
		getline(cin, input);
		string num;
		stringstream ss(input);
		vector<double> numbers;

		while (getline(ss, num, ' '))
		{
			numbers.push_back(stod(num));
		}
		double sum = 0;
		for (double i : numbers)
		{
			sum += i;
		}
		cout << "Your mean equals:" << " " << sum / numbers.size()<< endl;
	}
};
void PlayAnim()
{
	int i = 0;
	char spinnin[4] = {'|','/','--','\\'};
	while (true)
	{
		system("CLs");
		cout << spinnin[i] << endl;
		this_thread::sleep_for(chrono::milliseconds(300));
		i += 1;
		i = i % 4;
	}
}

int main()
{
	int choice;
	choice = MenuStart();
	Calculator calculate;
	if (choice == 1)
	{
		cout << "You entered Calculator" << endl;
		//calculate.GetCalculationType();
		//calculate.GetNums();
		calculate.GetCalculation();
	}
	else if (choice == 2) 
	{
		PlayAnim();
	}
	else if (choice == 3) 
	{
		cout << "You entered Mean Calculator" << endl;
		calculate.GetMean();
	}
	return 0;
}