#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";

using namespace std;

class clsClientListScreen: protected clsScreen
{
private:

	static void _PrintClientRecord(clsBankClient Client)
	{

		cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumbers();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(20) << Client.email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowClientsList()
	{
	

		if (!CheckAccessRights(clsUsers::enPermissions::PermissinonShowList))
		{
			return;
		}
		vector<clsBankClient>vClients = clsBankClient::GetClientList();
		string Title = "Client List Screen";
		string SubTitle= "\t (" +to_string( vClients.size())+ ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left <<"" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		cout << setw(8) << left <<"" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left <<"" << "\n\t________________________________________________________________________________";
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

		}

	}

};

