#pragma once
#include<iostream>
#include "../../Coar/clsBankClient.h";
#include<string>
#include<iomanip>
#include "../../LPy/clsInputValidate.h";
#include "../../Global.h";
#include "../clsScreen.h";
using namespace std;

class clsTansaforLogScreen:protected clsScreen
{
private:

	static void _PrintClientRecord(clsBankClient::stTransaforLog TransaforLog)
	{

		cout << setw(8) << left << "" << "| " << left << setw(22) << TransaforLog.DateTime;
		cout << "| " << left << setw(15) << TransaforLog.AccounttSourceClient;
		cout << "| " << left << setw(12) << TransaforLog.AccounttDestinationClien;
		cout << "| " << left << setw(12) << TransaforLog.Amoun;
		cout << "| " << left << setw(12) << TransaforLog.ScBalanc;
		cout << "| " << left << setw(12) << TransaforLog.DcBalanc;
		cout << "| " << left << setw(12) << TransaforLog.UserName;
	}


public:

	static void ShowTransaforLogScreen()
	{
		vector<clsBankClient::stTransaforLog>vSTransforLog = clsBankClient::GetTransaforLogScreen();

		string Title = "Transfor Log  List Screen";
		string SubTitle = "\t (" + to_string(vSTransforLog.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(22) << "Date Tiem";
		cout << "| " << left << setw(15) << "s.Acc";
		cout << "| " << left << setw(12) << "d.Acc";
		cout << "| " << left << setw(12) << "Amoun";
		cout << "| " << left << setw(12) << "s.Balanc";
		cout << "| " << left << setw(12) << "d.Balanc";
		cout << "| " << left << setw(12) << "User Name";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		if (vSTransforLog.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System! \n";
		}
		else
		{


			for (clsBankClient::stTransaforLog TransforLog : vSTransforLog)
			{
				_PrintClientRecord(TransforLog);

				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
			cout << "________________________________\n" << endl;

		}



	}
};

