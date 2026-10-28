#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
#include "Coar/clsUsers.h"
using namespace std;

class clsFindUsersScreen
{
private:

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


public:

	static void ShowFindUsersScreen()
	{

		string UsersName;

		cout << "\nEnter Users Name: ";
		UsersName = clsInputValidate::ReadString();

		while (!clsUsers::IsUsersExist(UsersName))
		{
			cout << "\nUsers Name Is Already Used, Choose another one: ";
			UsersName = clsInputValidate::ReadString();
		}

		clsUsers Users = clsUsers::Find(UsersName);

		if (!Users.IsEmpty())
		{
			cout << "\nUser  Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n ";
		}
		_PrintUsers(Users);
	}
};

