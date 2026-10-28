#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
using namespace std;

class clsDeleteClientScreen:protected clsScreen
{
private:


	static void _PrintClient(clsBankClient Client)
	{

		cout << "\nClient Card ";
		cout << "\n==========================";
		cout << "\nFirst Name  :" << Client.FirstName;
		cout << "\nList Name   :" << Client.ListName;
		cout << "\nFull Name   :" << Client.FullName();
		cout << "\nEmail       :" << Client.email;
		cout << "\nPhone       :" << Client.Phone;
		cout << "\nAcc. Number :" << Client.AccountNumbers();
		cout << "\nPassword    :" << Client.PinCode;
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n==========================\n";

	}
public:


	static void ShowDeleteClientScreen()
	{
		


		

		if (!CheckAccessRights(clsUsers::enPermissions::PermissinonDelete))
		{
			return;
		}
		_DrawScreenHeader("Delete Screen");
		string AccountNumber = "";

		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "\nAccunt number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		char Answer = 'Y';
		cout << "Are you sure you want to  delete this Client y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			if (Client.DeleteClient())
			{
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nError Client Was not Deleted\n";
			}

		}

	}

};

