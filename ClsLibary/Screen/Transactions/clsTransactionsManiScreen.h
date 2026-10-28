#pragma once
#include<iostream>
#include "../../Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "../clsScreen.h";
#include "../../LPy/clsInputValidate.h";
#include "../../Screen/Transactions/clsDepositScreen.h";
#include "../../Screen/Transactions/clsWithdeawScreen.h";
#include "../../Screen/Transactions/clsTotalBalancesScreen.h";
#include "clsTransaForScreen.h";
#include "clsTransaforLogScreen.h";

class clsTransactionsManiScreen:protected clsScreen
{
private:

	static short _ReadMainMenueTr()
	{
		cout << "\t\t\t\tChoose what do you Want to do? [1 to 6]?";
		short Choice = clsInputValidate::ReadShortNumberBetween(1,6,"Enter again: ");
		return Choice;
	}

	static void _ResetScreen()
	{
		system("color 0F");
		system("cls");
	}

	enum  enTransactions
	{
		Deposit = 1,
		Withdeaw = 2,
		TotalBalances = 3,
		TransaFor = 4,
		TransaforLog=5,
		MainMenue = 6
	};

	static void _GoBackToTrabsactionsMenue()
	{
		cout << "\n\nPress any key to go back to Main Menue..";
		system("pause");
		ShowTransactionsManiScreen();
	}
	
	static void _ShowDepositScreen()
	{
		_ResetScreen();
		_DrawScreenHeader("Deposit Screen");
		clsDepositScreen::ShowDepositScreen();
		
	}

	static void _ShowWithdeawScreen()
	{
		_ResetScreen();
		_DrawScreenHeader("Withdeaw Screen");
		clsWithdeawScreen::ShowWithdeawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		_ResetScreen();
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}
	static void _ShowTransaForScreen()
	{
		_ResetScreen();
		_DrawScreenHeader("Transafor Screen");
		clsTransaForScreen::ShowTransaForScreen();
	}
	static void _ShowTransaforLogScreen()
	{
		_ResetScreen();
		clsTansaforLogScreen::ShowTransaforLogScreen();
	}


	static void _PerfromTransactionsMenueOption(enTransactions Transactions)
	{

		switch (Transactions)
		{
		case enTransactions::Deposit:
		{
			_ShowDepositScreen();
			_GoBackToTrabsactionsMenue();
			break;
		}
		case enTransactions::Withdeaw:
		{
			_ShowWithdeawScreen();
			_GoBackToTrabsactionsMenue();
			break;
		}
		case enTransactions::TotalBalances:
		{
			_ShowTotalBalancesScreen();
			_GoBackToTrabsactionsMenue();
			break;
		}
		case enTransactions::TransaFor:
		{
			_ShowTransaForScreen();
			_GoBackToTrabsactionsMenue();
			break;
		}
		case enTransactions::TransaforLog:
		{
			_ShowTransaforLogScreen();
			_GoBackToTrabsactionsMenue();
			break;
		}
		case enTransactions::MainMenue:
		{
			//_ShowMainMenue();
			break;
		}
		}
	}
	

public:

	static void ShowTransactionsManiScreen()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::PermissinonTransactions))
		{
			return;
		}

		_ResetScreen();
		_DrawScreenHeader("Transactions Screen");
		cout << setw(33) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t Transactions Menue Screen\n";
		cout << setw(33) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdeaw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transafor.\n";
		cout << setw(37) << left << "" << "\t[5] Transafor Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(33) << left << "" << "==================================================\n";
		_PerfromTransactionsMenueOption((enTransactions)_ReadMainMenueTr());

	}

};