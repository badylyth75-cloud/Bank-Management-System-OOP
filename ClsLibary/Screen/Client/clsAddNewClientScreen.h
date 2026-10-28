#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
using namespace std;

class clsAddNewClientScreen: protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client)
	{

		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();


		cout << "Enter ListName: ";
		Client.ListName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		Client.email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "Enter Pin Code: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "Enter AccuntBalance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();


	}

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


	static void ShowAddNewClientScreen()
	{

		
		if (!CheckAccessRights(clsUsers::enPermissions::PermissinonAddNew))
		{
			return;
		}
		_DrawScreenHeader("Adding Screen");
		string AccountNumber;

		cout << "\nEnter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		
		
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResults;

		SaveResults = NewClient.Save();

		switch (SaveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAcount Addling Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it`s Emotv";
			break;
		}
		case clsBankClient::enSaveResults::svFillAccountNumberExist:
		{
			cout << "\nFile Account Number Exist";
			break;

		}
		}


	}

};

