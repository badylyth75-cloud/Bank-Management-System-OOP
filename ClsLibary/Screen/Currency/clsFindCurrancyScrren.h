#pragma once
#include<iostream>
#include "LPy/clsDate.h";
#include "Global.h";
#include "LPy/clsString.h";
#include<string>
#include "clsScreen.h";
#include<fstream>
#include<vector>
#include "LPy/clsInputValidate.h";
#include "clsCurranciesListScrren.h";
using namespace std;

class clsFindCurrancyScrren:protected clsScreen
{
private:
	static void _PrintCurreny(clsCurrency Currency)
	{

		cout << "\nCurrency Card:";
		cout << "\n____________________________\n\n";
		cout << "Country	  : " << Currency.GetCountry();
		cout << "\nCode	      : " << Currency.GatCurrencyCode();
		cout << "\nName       : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) = : " << Currency.GatRate();
		cout << "\n____________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "Currency Found :-)\n";
			_PrintCurreny(Currency);
		}
		else {
			cout << "\nCurrency Was not Found :-(\n";
		}
	}
public:

	static void ShwoFindCurrancyScreen()
	{

		string Find;

		_DrawScreenHeader("Find Currancy Screen");
		short Count;

		cout << "\nFind By: [1] Code or [2] Country ?";
		cin >> Count;
		if (Count == 1)
		{
			cout << "\nPlease Enter  Code: ";
			cin >> Find;
			clsCurrency Currency = clsCurrency::FindByCode(Find);
			_ShowResults(Currency);
		}
		else
		{
			cout << "\nPlease Enter  Country: ";
			cin >> Find;
			clsCurrency Currency = clsCurrency::FindByCountry(Find);
			_ShowResults(Currency);
		}
		


	}
};

