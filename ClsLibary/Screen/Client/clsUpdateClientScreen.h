#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
using namespace std;

class clsUpdateClientScreen :protected clsScreen
{
private:
	


	static void _ReadClientInfo(clsBankClient& Client)
	{

		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();


		cout << "\nEnter ListName: ";
		Client.ListName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Pin Code: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter AccuntBalance: ";
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

	static void ShowUpdateClientScreen()
	{
		_DrawScreenHeader("Updata Screen");

		if (!CheckAccessRights(clsUsers::enPermissions::PermissinonUpdate))
		{
			return;
		}


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

		cout << "\n\nUpdate Client Infe:";
		cout << "\n_______________________\n";

		_ReadClientInfo(Client);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAcount Upfated Successfully :-)\n";
			_PrintClient(Client);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it`s Emotv";
			break;
		}
		}
	}
};

