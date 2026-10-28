#pragma once
#include<iostream>
#include<iomanip>
#include "../Global.h";
#include "../LPy/clsDate.h"
class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{

		cout << "\n\t\t\t\t _______________________________________________\n\n";
		cout << "\n\t\t\t\t\t\t " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t ________________________________________________\n";
		cout << "\n\t\t\t\t User: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t Date: " << clsDate::DateToString(clsDate()) << endl;
	}

	static bool CheckAccessRights(clsUsers::enPermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermission(Permissions))
		{
			cout << "\t\t\t\t______________________________________________________";
			cout << "\n\n\t\t\t\t\t Access Denied! Contact your Access Permission";
			cout << "\n\n\t\t\t\t____________________________________________________";
			return false;
		}
		else
			return true;
	}
};

