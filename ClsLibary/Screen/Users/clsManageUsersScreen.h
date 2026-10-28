#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
#include "clsAddNewUsersScreen.h";
#include "clsListUsersScreen.h";
#include "clsFindUsersScreen.h";
#include "clsUpdateUsersByNameScreen.h";
#include "clsDeleteUsersScreen.h";
using namespace std;
class clsManageUsersScreen:protected clsScreen
{
private:


	enum  enManageUsersManueOptiond
	{
		List = 1,
		AddNew = 2,
		Delete = 3,
		Update = 4,
		Find = 5,
		Manage = 6
	};

	static void _ResetScreen()
	{
		system("color 0F");
		system("cls");
	}


	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Main Menue..";
		system("pause");
		ShowManageUsersScreen();
	}


	static short _ReadManageUsers()
	{
		cout <<"\n"<< setw(30) << left << "" << "Choose what do you Want to do? [1 to 6]?";
		short Choice =clsInputValidate::ReadShortNumberBetween(1,6,"Choose what do you Want to do? [1 to 6]?");
	
		return Choice;
	}

	static void _ShowListUsersScreen()
	{
		
		_ResetScreen();
		_DrawScreenHeader("List Users");
		clsListUsersScreen::ShowListUsersScreen();
	}

	static void _ShowAddNewUsersScreen()
	{

		_ResetScreen();
		_DrawScreenHeader("Adding Users");
		clsAddNewUsersScreen::ShowAddNewUsersScreen();
	//	cout << "\nMange Users Client  Screen Will be here...\n";
	}

	static void _ShowDeleteUsersScreen()
	{

		_ResetScreen();
		_DrawScreenHeader("Delelte Users");
		clsDeleteUsersScreen::ShowDeleteUsersScreen();
	
	}

	static void _ShowUpdateUsersByNameScreen()
	{

		_ResetScreen();
		_DrawScreenHeader("Update Users");
		clsUpdateUsersByNameScreen::ShowUpdateUsersByNameScreen();
	}

	static void _ShowFindUsersScreen()
	{

		_ResetScreen();
		_DrawScreenHeader("Find Users");
		clsFindUsersScreen::ShowFindUsersScreen();
	}

	static void _ShowMainMenue()
	{
		
		cout << "\nMange Users Client  Screen Will be here...\n";
	}

	static void _PerfromUsersManageMenueOption(enManageUsersManueOptiond ManageUsers)
	{

		switch (ManageUsers)
		{
		case enManageUsersManueOptiond::List:
		{
			_ResetScreen();
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersManueOptiond::AddNew:
		{
			_ResetScreen();
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersManueOptiond::Delete:
		{
			_ResetScreen();
			_ShowDeleteUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersManueOptiond::Update:
		{
			_ResetScreen();
			_ShowUpdateUsersByNameScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersManueOptiond::Find:
		{
			_ResetScreen();
			_ShowFindUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersManueOptiond::Manage:
		{
			_ResetScreen();
			_ShowMainMenue();
			break;
		}


		}
	}

public:

	static void ShowManageUsersScreen()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::PermissinonManage))
		{
			return;
		}

		_ResetScreen();
		_DrawScreenHeader("Manage Users Screen");
		cout << setw(33) << left << "" << "============================================\n";
		cout << "\t\t\t\t\t\tManage Users Menue\n";
		cout << setw(33) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t[1] List User.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(33) << left << "" << "============================================";
		_PerfromUsersManageMenueOption((enManageUsersManueOptiond)_ReadManageUsers());

	}


};

