#pragma once

#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
#include "clsCurrency.h";
using namespace std;

class clsUpdataRateCurrancyScrren:protected clsScreen
{
private:

	static void _PrintCurreny(clsCurrency Currency)
	{

		cout << "\nCurrency Card:";
		cout << "\n____________________________\n\n";
		cout << "Country	   : " << Currency.GetCountry();
		cout << "\nCode	   : " << Currency.GatCurrencyCode();
		cout << "\nName       : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) = : " << Currency.GatRate();
		cout << "\n____________________________\n";

	}
	static float _ReadRale()
	{
		float Rate = 0;
		cout << "\nEnter New Rate: ";
		Rate = clsInputValidate::ReadFloatNumber();
		return Rate;
	}

public:

	static void ShowUpdateRateCurrancyScrren()
	{
		_DrawScreenHeader("Update Currancy Screen");


		string Code;
		cout << "\nPleass Enter Code ? ";
		Code = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(Code))
		{
			cout << "\nAccunt number is not found, choose another one: ";
			Code = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		
		string Ansem = "n";
		cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
		cin >> Ansem;

		if (Ansem == "Y" || Ansem == "y")
		{
			
			cout << "\nUpate Currency Rate:";
			cout << "\n_____________________\n";

			Currency.UpdateRate(_ReadRale());
			cout << "\nCurrency Rate Update Successfully :-)\n";
			_PrintCurreny(Currency);

		}
		else
		{
			cout << "\nnot is Currency Code:-(\n";
		}


	}

};

