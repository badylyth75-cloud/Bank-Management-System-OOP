#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
#include "Coar/clsUsers.h"
using namespace std;

class clsDeleteUsersScreen
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

	static void ShowDeleteUsersScreen()
	{

			string UserName = "";


			cout << "\nPlease Enter User Name: ";
			UserName = clsInputValidate::ReadString();

			while (!(clsUsers::IsUsersExist(UserName)))
			{
				cout << "\nUser Nameis not found, choose another one: ";
				UserName = clsInputValidate::ReadString();
			}

			clsUsers Client = clsUsers::Find(UserName);

			_PrintUsers(Client);

			char Answer = 'Y';
			cout << "Are you sure you want to  delete this Users y/n? ";
			cin >> Answer;

			if (Answer == 'Y' || Answer == 'y')
			{

				if (Client.DeleteUsers())
				{
					cout << "\nUser Deleted Successfully :-)\n";
					_PrintUsers(Client);
				}
				else
				{
					cout << "\nError User Was not Deleted\n";
				}

			}

		


	}
};

