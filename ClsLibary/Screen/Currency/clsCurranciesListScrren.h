#pragma once
#include<iostream>
#include "Global.h";
#include "LPy/clsString.h";
#include<string>
#include "clsScreen.h";
#include<vector>
#include "LPy/clsInputValidate.h";
#include "clsCurrency.h";
using namespace std;

class clsCurranciesListScrren:protected clsScreen
{
private:

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{

		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.GetCountry();
		cout << "| " << left << setw(8) << Currency.GatCurrencyCode();
		cout << "| " << left << setw(41) << Currency.GetCurrencyName();
		cout << "| " << left << setw(12) << Currency.GatRate();
	}


public:

	static void ShowCurrenciesListScrren()
	{
		
		vector<clsCurrency>vCurrency = clsCurrency::GatCurrenciesList();
		string Title = "Currencies List Screen";
		string SubTitle = "\t (" + to_string(vCurrency.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Cod";
		cout << "| " << left << setw(41) << "Name";
		cout << "| " << left << setw(12) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		if (vCurrency.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System! \n";

		}
		else
		{


			for (clsCurrency Currency : vCurrency)
			{
				_PrintCurrencyRecord(Currency);

				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
			cout << "________________________________\n" << endl;

		}



	}
};

