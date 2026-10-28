#pragma once
#include<iostream>
#include "../../Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "../clsScreen.h";
#include "../../LPy/clsInputValidate.h";
#include "../../LPy/clsUtil.h";
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:

	static void _PrintClientRecord(clsBankClient Client)
	{

		cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumbers();
		cout << "| " << left << setw(20) << Client.FullName();
	    cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalancesScreen()
	{
		vector<clsBankClient>vClients = clsBankClient::GetClientList();
		string Title = "Total Balances Screen";
		string SubTitle = "\t (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		double Balanc = clsBankClient::GetTotalBalaces();
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System! \n";
		}
		else
		{


			for (clsBankClient Client : vClients)
			{
				_PrintClientRecord(Client);
				
				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
			cout << "________________________________\n" << endl;

			cout << setw(8) << left << "" << "\t\t\t\tTotle Balance= " << Balanc;
			cout << setw(8) << left << "" << "\n\t\t\t( " << clsUtil::NumberToText(Balanc)<<" )";

		}




	}
};

