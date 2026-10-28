#pragma once
#include<iostream>
#include "LPy/clsDate.h";
#include "Global.h";
#include "LPy/clsString.h";
#include<string>
#include "clsScreen.h";
#include<fstream>
#include<vector>
class clsRegister :protected clsScreen
{
private:

    

	static void _PrintClientRecord(clsUsers::stLoginRegister Register)
	{

		cout << setw(8) << left << "" << "| " << left << setw(22) << Register.DateTime;
		cout << "| " << left << setw(15) << Register.UsreName;
		cout << "| " << left << setw(12) << Register.Password;
		cout << "| " << left << setw(12) << Register._Permissions;
	}


	

public:


	static void ShowListRegister()
	{
		if (!CheckAccessRights(clsUsers::enPermissions::PermissinonRegister))
		{
			return;
		}

		vector<clsUsers::stLoginRegister>vRegister = clsUsers::GetLoginRegister();
		string Title = "Login Register List Screen";
		string SubTitle = "\t (" + to_string(vRegister.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(22) << "Date Tiem";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
		cout << "________________________________\n" << endl;

		if (vRegister.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System! \n";
			
		}
		else
		{


			for (clsUsers::stLoginRegister Register : vRegister)
			{
				_PrintClientRecord(Register);

				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t________________________________________________________________________________";
			cout << "________________________________\n" << endl;

		}
		


	}




};


