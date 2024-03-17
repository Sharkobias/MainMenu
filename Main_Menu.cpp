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
	cout << "|" << "     [4]RANDOM        " << "|" << endl;
	cout << " " << endl;
	cout << "|" << "  enter [0] to exit   " << "|" << endl;
	cout << "|" << "     or go back       " << "|" << endl;
	cout << " " << "______________________" << " " << endl;
	cout << " " << endl;
	int choice;
	cin >> choice;
	return choice;
}

class OpNode;

class ValueNode 
{
public:
	ValueNode() {}
	ValueNode(double value);
	ValueNode(OpNode* op);
private:
	double _value;
	OpNode* _op;
	bool _check;
public:
	double GetValue();
};

class OpNode 
{
public:
	OpNode() {}
	OpNode(ValueNode first, ValueNode second, string operation);
	ValueNode _first;
	ValueNode _second;
	string _operation;
	ValueNode Evaluate();
};
ValueNode OpNode::Evaluate()
{
	double result;
	if (_operation == "+")
	{
		result = _first.GetValue() + _second.GetValue();
	}
	else if (_operation == "-")
	{
		result = _first.GetValue() - _second.GetValue();
	}
	else if (_operation == "*")
	{
		result = _first.GetValue() * _second.GetValue();
	}
	else if (_operation == "/")
	{
		result = _first.GetValue() / _second.GetValue();
	}
	else
	{
		cout << "unsupported type of equation" << endl;
	}
	ValueNode ResultNode(result);

	return ResultNode;
}
OpNode::OpNode(ValueNode first, ValueNode second, string operation)
{
	_first = first;
	_second = second;
	_operation = operation;
}
ValueNode::ValueNode(double value) {
	_value = value;
	_check = false;
}

ValueNode::ValueNode(OpNode* op) {
	_op = op;
	_check = true;
}

double ValueNode::GetValue() {
	if (_check == false)
	{
		return _value;
	}
	else
	{
		ValueNode result = _op->Evaluate();
		return result.GetValue();
	}
}

class Calculator
{
public:
	bool GetCalculation()
	{
		string str;
		string problem;
		cout << "write your mathematical problem with space delinated:" << endl;
		getline(cin, problem);
		if (problem == "0")
		{
			return false;
		}
		stringstream ss(problem);
		vector<string> split_problem;
		string part;

		while (getline(ss, part, ' '))
		{
			split_problem.push_back(part);
		}

		ValueNode first(stod(split_problem[0]));
		ValueNode second(stod(split_problem[2]));
		OpNode exp(first, second, split_problem[1]);
		ValueNode result = exp.Evaluate();

		cout << "equals: " << result.GetValue() << endl;
		return true;

	}
	bool GetMean()
	{
		string input;
		cout << "enter your numbers space delinated" << endl;
		getline(cin, input);
		if (input == "0")
		{
			return false;
		}
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
		cout << "Your mean equals:" << " " << sum / numbers.size() << endl;
		return true;
	}
	bool GetRandom()
	{
		int max;
		int min;
		cout << "Input smaller number in range" << endl;
		cin >> min;
		cout << "Input bigger number in range" << endl;
		cin >> max;
		if (min, max == 0)
		{
			return false;
		}
		cout << rand() % min + max << endl;
		return true;
	}
};
void PlayAnim()
{
	int t = 10;
	int i = 0;
	char spinnin[4] = { '|','/','-','\\' };
	while (t > 0)
	{
		system("CLS");
		cout << spinnin[i] << endl;
		this_thread::sleep_for(chrono::milliseconds(300));
		i += 1;
		i = i % 4;
		t = t - 1;
	}
}

int main()
{
	while(true)
	{
		int choice;
		choice = MenuStart();
		Calculator calculate;
		if (choice == 1)
		{
			cout << "You entered Calculator" << endl;
			cin.ignore();
			while (calculate.GetCalculation()) {}
		}
		else if (choice == 2)
		{
			PlayAnim();
		}
		else if (choice == 3)
		{
			cout << "You entered Mean Calculator" << endl;
			cin.ignore();
			while (calculate.GetMean()) {}
		}
		else if (choice == 4)
		{
			cout << "You have entered random number generator" << endl;
			cin.ignore();
			while (calculate.GetRandom()) {}
		}
		else if (choice == 0)
		{
			cout << "you exited the program" << endl;
			abort();
		}
		else
		{
			system("CLS");
			cout << "No function found underneath that symbol, try again" << endl;
		}
	}
	return 0;
	
}
