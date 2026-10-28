#pragma once
#include<iostream>
#include "LPy/clsInputValidate.h";
#include<iomanip>
#include "clsScreen.h";
#include "Screen/Client/clsClientListScreen.h";
#include "Screen/Users/clsManageUsersScreen.h";
#include "Screen/Client/clsDeleteClientScreen.h";
#include "Screen/Client/clsUpdateClientScreen.h";
#include "Screen/Client/clsFindClientScreen.h";
#include "Screen/Transactions/clsTransactionsManiScreen.h";
#include  "Screen/Client/clsAddNewClientScreen.h"
#include "Global.h";
#include "../Screen/Users/clsRegister.h";
#include "../Screen/Currency/clsCurrancyExhange.h";
//#include "clsLoginScreen.h";
class clsMainScreen :protected clsScreen
{
private:

	
	enum enMainMenueScreen { ShowClientList = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, Transactions = 6, ManageUsers = 7, LogoutRegister = 8, CurrancyExange = 9, eExte = 10 };

	static short _ReadMainMenueOption()
	{
		cout << "\n\t\t\t\tChoose what do you Want to do? [1 to 10]?";
		short Choose = clsInputValidate::ReadShortNumberBetween(1,10,"Enter Number Between");
		return Choose;
	}


	static void _ResetScreen()
	{
		system("color 0F");
		system("cls");
	}

	static void _GoBackToMainMenue()
	{
		cout << "\n\nPlless any key to go back to Main Menue..\n";
		system("pause");
		ShowMainMenue();

	}

	static void _ShowAllClientsScreen()
	{
		_ResetScreen();
		//cout << "\nClient List Screen Will be here...\n";
		clsClientListScreen::ShowClientsList();
		
	}

	static void _ShowAddNewClientsScreen()
	{
		
		_ResetScreen();
		clsAddNewClientScreen::ShowAddNewClientScreen();
		//cout << "\nAdd  Screen Will be here...\n";
		
	}

	static void _ShowDeletClientScreen()
	{

		_ResetScreen();
		//cout << "\nDelete Client Screen Will be here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();

	}

	static void _ShowUpdataClientScreen()
	{
		_ResetScreen();
		//cout << "\nUpdate Client  Screen Will be here...\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{

		
		//cout << "\nFind Client  Screen Will be here...\n";
		_ResetScreen();
		clsFindClientScreen::ShowFindClientScreen();
		
	}

	static void _ShowTransactionsManiScreen()
	{

		_ResetScreen();
	
		clsTransactionsManiScreen::ShowTransactionsManiScreen();
		
	}

	static void _ShowManageUsersManiScreen()
	{


		_ResetScreen();
		
		clsManageUsersScreen::ShowManageUsersScreen();
		//cout << "\nMange Users Client  Screen Will be here...\n";

	}
	static void _ShowLogoutRegister()
	{

		_ResetScreen();
		clsRegister::ShowListRegister();

	}
	static void _ShowCurrencyExchange()
	{
		_ResetScreen();
		clsCurrancyExhange::ShowCurrancyExhangeScreen();

	}
	
	static void _Logout()
	{
	
			_ResetScreen();

			CurrentUser = clsUsers::Find("", "");
			//T = true;
			//cout << "\nLogin Client  Screen Will be here...\n";


	}

    static void _PerfromMainMenueOption(enMainMenueScreen MainMenueScreen)
	{
		
		switch (MainMenueScreen)
		{
		case enMainMenueScreen::ShowClientList:
		{
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		
		}
		case enMainMenueScreen::AddNewClient:
		{
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueScreen::DeleteClient:
		{
			_ShowDeletClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueScreen::UpdateClient:
		{
			_ShowUpdataClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueScreen::FindClient:
		{
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueScreen::Transactions:
		{
			_ShowTransactionsManiScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueScreen::ManageUsers:
		{

			_ShowManageUsersManiScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueScreen::LogoutRegister:
		{
			_ShowLogoutRegister();
			_GoBackToMainMenue();
			break;

		}
		case enMainMenueScreen::CurrancyExange:
		{
			_ShowCurrencyExchange();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueScreen::eExte:
		{
			_Logout();
			break;
		
		}
		}
	}

public:

	static void ShowMainMenue()
	{
		

		_ResetScreen();
		_DrawScreenHeader("Main Screen");
		cout << setw(33) << left << "" << "============================================\n";
		cout << "\t\t\t\t\t\tMain Menue Screen\n";
		cout << setw(33)<< left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Logout Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(33) << left << "" << "=============================================";
		_PerfromMainMenueOption((enMainMenueScreen)_ReadMainMenueOption());
	}

};



