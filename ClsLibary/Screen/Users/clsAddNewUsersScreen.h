#pragma once
#include<iostream>
#include "../../Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "../../Screen/clsScreen.h";
#include "../../LPy/clsInputValidate.h";
#include "../../Coar/clsUsers.h"
using namespace std;
class clsAddNewUsersScreen
{

private:

	static void _ReadUsersInfo(clsUsers& Client)
	{

		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "Enter ListName: ";
		Client.ListName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		Client.email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter Password: ";
		Client.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions";
		Client.Permissions = _ReadPermissionsToSet();

	}

	static void _PrintUsers(clsUsers Client)
	{

		cout << "\nClient Card ";
		cout << "\n==========================";
		cout << "\nFirst Name  :" << Client.FirstName;
		cout << "\nList Name   :" << Client.ListName;
		cout << "\nFull Name   :" << Client.FullName();
		cout << "\nEmail       :" << Client.email;
		cout << "\nPhone       :" << Client.Phone;
		cout << "\nUserName    :" << Client.UserName;
		cout << "\nPassword    :" << Client.Password;
		cout << "\nPermissions :" << Client.Permissions;
		cout << "\n==========================\n";

	}

	static int _ReadPermissionsToSet()
	{
		int PermissionSum = 0;
		char Answesr;

		cout << "\nDy you want to give full access y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum = -1;
			return PermissionSum;
		}

		cout << "\nShow Client y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum = clsUsers::enPermissions::PermissinonShowList;
		}

		cout << "\nAdd Nwe Client y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonAddNew;
		}

		cout << "\nDelete Client y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonDelete;
		}

		cout << "\nUpdate Client y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonUpdate;
		}
		cout << "\nFind Client y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonFind;
		}

		cout << "\nTransactions y/n ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonTransactions;
		}

		cout << "\nManage Users y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonManage;
		}
		cout << "\nLogin Register Users y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonRegister;
		}
		cout << "\nCurrancy  Users y/n? ";
		cin >> Answesr;
		if (Answesr == 'y' || Answesr == 'Y')
		{
			PermissionSum += clsUsers::enPermissions::PermissinonCurrency;
		}

		return PermissionSum;
	}


public:

	static void ShowAddNewUsersScreen()
	{



		string UsersName;

		cout << "\nEnter Users Name: ";
		UsersName = clsInputValidate::ReadString();

		while (clsUsers::IsUsersExist(UsersName))
		{
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			UsersName = clsInputValidate::ReadString();
		}

		clsUsers NewClient = clsUsers::GetAddNewUsersObject(UsersName);


		_ReadUsersInfo(NewClient);

		clsUsers::enSaveResults SaveResults;

		SaveResults = NewClient.Save();

		switch (SaveResults)
		{
		case clsUsers::enSaveResults::svSucceeded:
		{
			cout << "\nAcount Addling Successfully :-)\n";
			_PrintUsers(NewClient);
			break;
		}
		case clsUsers::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it`s Emotv";
			break;
		}
		case clsUsers::enSaveResults::svFillAccountNumberExist:
		{
			cout << "\nFile Account Number Exist";
			break;

		}
		}


	}
	
};

