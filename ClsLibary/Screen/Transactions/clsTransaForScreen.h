#pragma once
#include<iostream>
#include "../../Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "../clsScreen.h";
#include "../../LPy/clsInputValidate.h";
#include "../../Global.h";
using namespace std;

class clsTransaForScreen:protected clsScreen
{
private:

	//Exceeds the available,Enter another Amother ? 
	static string _ReadAccountNumberFrom()
	{
		cout << "\nPlease Enter Account Number to Teansfor  From: ";
		string AccountNumber;
		getline(cin >> ws, AccountNumber);

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with (" << AccountNumber << ") does Not extst." << endl;
			cin >> AccountNumber;
		}
		return AccountNumber;
	}

	static string _ReadAccountNumberFrom1()
	{
		cout << "\nPlease Enter Account Number to Teansfor to From: ";
		string AccountNumber;
		getline(cin >> ws, AccountNumber);

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with (" << AccountNumber << ") does Not extst." << endl;
			cin >> AccountNumber;
		}
		return AccountNumber;
	}

	static double _ReadBalans(clsBankClient SourceClient)
	{
		cout << "\nExceeds the available,Enter another Amother ? ";
		double Balance;
		cin >> Balance;
	
		while (Balance <= 0)
		{
			cout << "\nAmount must be greater than zero.\n";
			cout << "Please enter another amount? ";
			cin >> Balance;
		}
		while (Balance > SourceClient.AccountBalance)
		{
			cout << "Amount Exceeds the balance, you can withdraw up to : " << SourceClient.AccountBalance << endl;
			cout << "Please enter another amount? ";
			cin >> Balance;
		}
		

		return Balance;


	}

	static void _PrintClient(clsBankClient Client)
	{

		cout << "\nClient Card: ";
		cout << "\n==========================";
		cout << "\nFull Name   :" << Client.FullName();
		cout << "\nAcc. Number :" << Client.AccountNumbers();
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n==========================\n";

	}


public:
	
	static void ShowTransaForScreen()
	{

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumberFrom());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumberFrom1());

		while(SourceClient.AccountNumbers() == DestinationClient.AccountNumbers())
		{
			cout << "\nError: You cannot transfer money to thr same account.\n";
			 DestinationClient = clsBankClient::Find(_ReadAccountNumberFrom1());

		}
		_PrintClient(DestinationClient);

		double Balance = _ReadBalans(SourceClient);
	
			char Answer = 'Y';
			cout << "\n\nArq you sure you want perfrom this trabsaction? y/n ? ";
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{
	
				if (SourceClient.Transfor(Balance, DestinationClient,CurrentUser.UserName))
				{
					cout << "\nTansfor done Successfully.";

				}
				else
				{
					cout << "\nTansfor Faild.";
				}
				
			}

			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);


			
	}
};

