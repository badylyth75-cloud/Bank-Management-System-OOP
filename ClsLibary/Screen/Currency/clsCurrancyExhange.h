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
#include "clsFindCurrancyScrren.h";
#include "clsUpdataRateCurrancyScrren.h";
#include "clsCalculatorCurrencyScreen.h";
using namespace std;

class clsCurrancyExhange:protected clsScreen
{
private:

	static short _ReadMainMenueTr()
	{
		cout << "\t\t\t\tChoose what do you Want to do? [1 to 5]?";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter again: ");
		return Choice;
	}

	static void _ResetScreen()
	{
		system("color 0F");
		system("cls");
	}

	enum  enCurrancyExhange
	{
		ListCurrencies = 1,
		FindCurrency = 2,
		UpdateRate = 3,
		CurrencyCalculator = 4,
		MainMenue = 5
	};

	static void _GoBackToCurrancyExhangeMenue()
	{
		cout << "\n\nPlless any key to go back to Main Menue..";
		system("pause");
		ShowCurrancyExhangeScreen();
	}

	static void _ShowListCurrencies()
	{
		_ResetScreen();
		clsCurranciesListScrren::ShowCurrenciesListScrren();
	}
	static void _ShowFindCurrency()
	{
		_ResetScreen();
		clsFindCurrancyScrren::ShwoFindCurrancyScreen();
	}
	static void _ShowUpdateRate()
	{
		_ResetScreen();
		clsUpdataRateCurrancyScrren::ShowUpdateRateCurrancyScrren();
	}
	static void _ShowCurrencyCalculator()
	{
		_ResetScreen();
		clsCalculatorCurrencyScreen::ShowCalculatorCurrancyScreen();
	}

	static void _PerfromTransactionsMenueOption(enCurrancyExhange CurrancyExhange)
	{

		switch (CurrancyExhange)
		{
		case enCurrancyExhange::ListCurrencies:
		{
			_ShowListCurrencies();
			_GoBackToCurrancyExhangeMenue();
			break;
		}
		case enCurrancyExhange::FindCurrency:
		{
			_ShowFindCurrency();
			_GoBackToCurrancyExhangeMenue();
			break;
		}
		case enCurrancyExhange::UpdateRate:
		{
			_ShowUpdateRate();
			_GoBackToCurrancyExhangeMenue();
			break;
		}
		case enCurrancyExhange::CurrencyCalculator:
		{
			_ShowCurrencyCalculator();
			_GoBackToCurrancyExhangeMenue();
			break;
		}
		case enCurrancyExhange::MainMenue:
		{
			
			break;
		}
		}
	}


public:

	static void ShowCurrancyExhangeScreen()
	{

		_ResetScreen();
		_DrawScreenHeader("Currancy Exhange Screen");
		cout << setw(33) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\tCurrancy Exhange Menue Screen\n";
		cout << setw(33) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currecies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Updat Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(33) << left << "" << "==================================================\n";
		_PerfromTransactionsMenueOption((enCurrancyExhange)_ReadMainMenueTr());

	}

};