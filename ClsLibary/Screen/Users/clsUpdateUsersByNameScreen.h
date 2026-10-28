#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
#include "Coar/clsUsers.h"
using namespace std;

class clsUpdateUsersByNameScreen
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


		return PermissionSum;
	}



public:

	static void ShowUpdateUsersByNameScreen()
	{
		string UsersName;

		cout << "\nEnter Users Name: ";
		UsersName = clsInputValidate::ReadString();

		while (!clsUsers::IsUsersExist(UsersName))
		{
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			UsersName = clsInputValidate::ReadString();
		}

		clsUsers Client = clsUsers::Find(UsersName);
		_PrintUsers(Client);
		char Ansm = 'y';
		cout << "\nAre you sure you want to update this User y/n?";
		cin >> Ansm;
		if (Ansm == 'Y' || Ansm == 'y')
		{


			cout << "\n\nUpdate Usres Infe:";
			cout << "\n_______________________\n";

			_ReadUsersInfo(Client);

			clsUsers::enSaveResults SaveResult;

			SaveResult = Client.Save();
			switch (SaveResult)
			{
			case clsUsers::enSaveResults::svSucceeded:
			{
				cout << "\nAcounn Up fated Successfully :-)\n";
				_PrintUsers(Client);
				break;
			}
			case clsUsers::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it`s Emotv";
				break;
			}
			}
		}
		else
		{
			cout << "\nError account was not saved because it`s Emotv";
		}
	}
};

