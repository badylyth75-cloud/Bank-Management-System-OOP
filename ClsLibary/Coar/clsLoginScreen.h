#pragma once
#include<iostream>
#include "Global.h";
#include "../Screen/clsScreen.h";
#include "../Screen/clsMainScreen.h";
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		int Count = 0;
		string UserName, Password;

		do
		{

			if (LoginFaild)
			{
				Count++;
				cout << "\nInveli UserName/Password! " <<
				"\nYou have "<<(3 - Count)<<" Trials to login.\n\n";
			}
			
			if (Count == 3)
			{
				cout << "\nYour are Locked after 3 faild trails.\n";
				return false;
			}

			cout << "Enter User Name?";
			cin >> UserName;

			cout << "Enter Password?";
			cin >> Password;
			CurrentUser = clsUsers::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();
			
		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();

		return true;
		
	}
public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}

};

