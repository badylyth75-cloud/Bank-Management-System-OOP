#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "../clsScreen.h";
#include "LPy/clsInputValidate.h";
#include "../../Coar/clsCurrency.h";
class clsCalculatorCurrencyScreen:protected clsScreen
{
private:

	static void _PrintCurreny(clsCurrency Currency,string Massege)
	{

		cout << "\n" << Massege << endl;
		cout << "\n____________________________\n\n";
		cout << "Country	   : " << Currency.GetCountry();
		cout << "\nCode	   : " << Currency.GatCurrencyCode();
		cout << "\nName       : " << Currency.GetCurrencyName();
		cout << "\nRate(1$) = : " << Currency.GatRate();
		cout << "\n____________________________\n";

	}

	static void _PrintCalculationsResults(float Amount,clsCurrency CurrencyFr, clsCurrency CurrencyTo)
	{
		

			_PrintCurreny(CurrencyFr,"Convert From:");

			float AmountToUSD = CurrencyFr.ConverUSD(Amount);

			cout << "\n " << Amount << " " << CurrencyFr.GatCurrencyCode() << " = " << AmountToUSD << " USD";

			if (CurrencyTo.GatCurrencyCode() == "USD")
			{
				return;
			}
			cout << "\nConverting from USD to:\n";

			_PrintCurreny(CurrencyTo,"To:");

			float AmountInCurrency2 = CurrencyFr.ConverToOtheCurrency(Amount, CurrencyTo);
			cout << "\n " << Amount << " " << CurrencyFr.GatCurrencyCode() << " = " << AmountInCurrency2 << " " << CurrencyTo.GatCurrencyCode();


	}

	static float _ReadRale()
	{
		float Rate = 0;
		cout << "\nEnter Amount to Exchange: ";
		Rate = clsInputValidate::ReadFloatNumber();
		return Rate;
	}

	

	static clsCurrency GetCurrencyFind(string Massage)
	{
		cout << Massage << endl;
		string Currency = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(Currency))
		{
			cout << "\nCurrency Code is not found, choose another one: ";
			Currency = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCode(Currency);

		return Currency1;
	}

public:

	static void ShowCalculatorCurrancyScreen()
	{
		char Continue = 'y';
		while (Continue == 'y' || Continue == 'Y')
		{

			_DrawScreenHeader("Calculator Currancy Screen");

			clsCurrency CurrencyFr = GetCurrencyFind("\nPleass Enter Currency1 Code ? ");
			clsCurrency CurrencyTo = GetCurrencyFind("\nPleass Enter Currency2 Code ? ");
			float Amount = _ReadRale();

			
			_PrintCalculationsResults(Amount, CurrencyFr, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n? ";
			cin >> Continue;
		}
	
	}
};

