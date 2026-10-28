#pragma once
#include<iostream>
#include "../../Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "../clsScreen.h";
#include "../../LPy/clsInputValidate.h";
using namespace std;

class clsDepositScreen
{
private:


	static string _ReadAccountNumber()
	{
		cout << "\nEnter Accoun Number? ";
		string AccountNumber;
		getline(cin >> ws, AccountNumber);
		return AccountNumber;
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

	static void ShowDepositScreen()
	{

	
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with (" << AccountNumber << ") does Not extst." << endl;
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		double Balance = 0;
		cout << "\n\nPlease enter deposit amount? ";
		cin >> Balance;

		if (Balance<=0)
		{
			cout << "\nAmount must be greater than zero.\n";
		}
		else
		{
			char Answer = 'Y';
			cout << "\n\nArq you sure you want perfrom this trabsaction? y/n ? ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
				Client.Deposit(Balance);
				cout << "\nAmount Deposited Successfully.";
				cout << "\n\nDone Successfully New balance is: " << Client.AccountBalance;

			}

		}
		

	}

};

