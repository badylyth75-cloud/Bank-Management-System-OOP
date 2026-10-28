#pragma once
#include<iostream>
#include "Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "clsScreen.h";
#include "LPy/clsInputValidate.h";
#include "Coar/clsUsers.h";
using namespace std;
class clsListUsersScreen:protected clsScreen
{

private:

	static void _PrintUsersRecord(clsUsers Client)
	{

		cout << setw(8) << left << "" << "| " << left << setw(15) << Client.UserName;
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(20) << Client.email;
		cout << "| " << left << setw(12) << Client.Password;
		cout << "| " << left << setw(12) << Client.Permissions;
	}

public:

	static void ShowListUsersScreen()
	{

		vector<clsUsers>vClients = clsUsers::GetUsersList();
		string Title = "Users List Screen";
		string SubTitle = "\t (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "_____________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(11) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "_____________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Users Available In the System! \n";
		}
		else
		{


			for (clsUsers Client : vClients)
			{
				_PrintUsersRecord(Client);
				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
			cout << "_____________________________\n" << endl;

		}

	}

};

