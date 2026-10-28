#pragma once
#include<iostream>
using namespace std;

class clsCalculator
{
private:
	float _Result = 0;
	string _ListOperation = "Clear";
	float _LastNumber = 0;
	float _PreviousResult = 0;
	bool _IsZero(float Number)
	{
		return (Number == 0);
	}
public:


	clsCalculator()
	{

	}
	void Add(float Count)
	{
		_LastNumber = Count;
		_PreviousResult = _Result;
		_Result += Count;
		_ListOperation = " Adding ";
	}

	void Subtract(int Value)
	{
		_LastNumber = Value;
		_PreviousResult = _Result;
		_Result -= Value;
		_ListOperation = " Subtracting ";
	}
	void Divide(int Value)
	{

		_LastNumber = Value;

		if (_IsZero(Value))
			Value = 1;

		_PreviousResult = _Result;
		_Result /= Value;
		_ListOperation = " Dividing ";
	}
	void Multiply(int Value)
	{
		_LastNumber = Value;
		_PreviousResult = _Result;
		_Result *= Value;
		_ListOperation = " Mulrtiplying ";
	}
	void Clear()
	{
		_Result = 0;
		_LastNumber = 0;
		_ListOperation = " Clear ";
		_PreviousResult = _Result;
	}

	float GetFinalResults()
	{
		return _Result;
	}
	void CancelLastOperation()
	{
		_LastNumber = 0;
		_ListOperation = " Cancelling last Operation ";
		_Result = _PreviousResult;
	}
	void PrintResult()
	{
		cout << "Result After "
			<< _ListOperation << _LastNumber << " is: " << _Result << endl;
	}

};
 
