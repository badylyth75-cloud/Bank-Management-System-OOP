#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "clsPerson.h";
#include "../Lpy/clsString.h";
#include "../LPy/clsInputValidate.h";
#include "../LPy/clsUtil.h";
using namespace std;

class clsUsers :public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewClient = 2 };


	string _UsreName;
	string _Password;
	int _Permissions;
	enMode _Mode;
	bool _MarkedForDeleted = false;

	struct stLoginRegister;

	

	static stLoginRegister _ConvertLohinRegisterLientoObject(string Line, string Seperator = "#//#")
	{
		vector<string>vString = clsString::SplitString(Line, Seperator);

		return stLoginRegister(vString[0], vString[1], clsUtil::DecryptText(vString[2],2), stod(vString[3]));
	}



	static clsUsers _ConvertLientoUsersObject(string Line, string Seperator = "#//#")
	{
		vector<string>vString = clsString::SplitString(Line, Seperator);

		return clsUsers(enMode::UpdateMode, vString[0], vString[1], vString[2], vString[3], vString[4], clsUtil::DecryptText(vString[5],2), stod(vString[6]));
	}

	static clsUsers _GetEmptyUsersObject()
	{
		return clsUsers(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUsers> _LoadUsersDataFromFile()
	{
		fstream MyFile;

		vector<clsUsers>vClient;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile >> ws, Line))
			{
				clsUsers Clinet = _ConvertLientoUsersObject(Line);
				vClient.push_back(Clinet);
			}
			MyFile.close();

		}

		return vClient;
	}

	static string _ConvertUsersObjectToLine(clsUsers Clinet, string Seperator = "#//#")
	{
		string StrClinet = "";

		StrClinet = Clinet.FirstName + Seperator;
		StrClinet += Clinet.ListName + Seperator;
		StrClinet += Clinet.email + Seperator;
		StrClinet += Clinet.Phone + Seperator;
		StrClinet += Clinet._UsreName + Seperator;
		StrClinet += clsUtil::EncryptText(Clinet._Password,2) + Seperator;
		StrClinet += to_string(Clinet._Permissions);

		return StrClinet;

	}

	static void _SaveUsersDataToFile(vector<clsUsers>vClients)
	{
		fstream MyFile;
		string Lien;

		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsUsers& C : vClients)
			{
				if (C._MarkedForDeleted == false)
				{
					Lien = _ConvertUsersObjectToLine(C);
					MyFile << Lien << endl;
				}

			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsUsers>vClient = _LoadUsersDataFromFile();

		for (clsUsers& C : vClient)
		{
			if (C._UsreName == UserName)
			{
				C = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vClient);
	}

	void _AddUsers()
	{

		_AddDataLineToFile(_ConvertUsersObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream Myfile;

		Myfile.open("Users.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << stDataLine << endl;
		}
		Myfile.close();
	}

	string _PrepareLogInRecord()
	{
		string dml = "#//#";
		string Register;
		Register = clsDate::GetSystemDateTimeString() + dml;
		Register += UserName + dml;
		Register += clsUtil::EncryptText(Password,2) + dml;
		Register += to_string(Permissions);

		return Register;
	}

public:


	static struct stLoginRegister
	{
		string DateTime;
		string UsreName;
		string Password;
		int _Permissions;
	};

	static enum enPermissions {
		PermissinonAlle = -1,
		PermissinonShowList = 1,
		PermissinonAddNew = 2,
		PermissinonDelete = 4,
		PermissinonUpdate = 8,
		PermissinonFind = 16,
		PermissinonTransactions = 32,
		PermissinonManage = 64,
		PermissinonRegister = 128,
		PermissinonCurrency = 256

		
	};

	clsUsers(enMode Mode, string FirstName, string ListName, string email, string Phone, string UserName, string Password, int Permissions) :
		clsPerson(FirstName, ListName, email, Phone)
	{
		_Mode = Mode;
		_UsreName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetUsreName()
	{
		return _UsreName;
	}

	void SetUsreName(string Name)
	{
		_UsreName = Name;
	}

	__declspec(property(get = GetUsreName, put = SetUsreName))string UserName;

	string GetPassword()
	{
		return _Password;
	}


	void SetPassword(string Password)
	{
		_Password = Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;


	int GetPermissions()
	{
		return _Permissions;
	}

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

	bool GetMarkedForDeleted()
	{
		return _MarkedForDeleted;
	}


	static clsUsers Find(string UserName)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUsers Client = _ConvertLientoUsersObject(Line);

				if (Client._UsreName == UserName)
				{
					MyFile.clear();
					return Client;
				}
			}
		}
		return _GetEmptyUsersObject();

	}

	static clsUsers Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUsers Client = _ConvertLientoUsersObject(Line);

				if (Client._UsreName == UserName && Client.Password == Password)
				{
					MyFile.clear();
					return Client;
				}
			}
		}
		return _GetEmptyUsersObject();
	}

	static bool IsUsersExist(string UserName)
	{
		clsUsers Client = Find(UserName);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFillAccountNumberExist = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enMode::AddNewClient:
		{
			if (clsUsers::IsUsersExist(_UsreName))
			{
				return enSaveResults::svFillAccountNumberExist;
			}
			else
			{
				_AddUsers();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}

		}
	}


	

	bool DeleteUsers()
	{
		vector<clsUsers>vClient = _LoadUsersDataFromFile();

		for (clsUsers& C : vClient)
		{
			if (C._UsreName == UserName)
			{
				C._MarkedForDeleted = true;
				break;
			}
		}

		_SaveUsersDataToFile(vClient);
		*this = _GetEmptyUsersObject();
		return true;

	}

	static clsUsers GetAddNewUsersObject(string UsersName)
	{
		return clsUsers(enMode::AddNewClient, "", "", "", "", UsersName, "", 0);
	}

	static vector<clsUsers> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (enPermissions::PermissinonAlle == Permission)
			return true;
		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogIn()
	{
		 string RegisterLogIn = _PrepareLogInRecord();

		 fstream MyFile;
		 MyFile.open("FileRegister.txt", ios::out | ios::app);
		 
		 if (MyFile.is_open())
		 {
			 MyFile << RegisterLogIn << endl;

			 MyFile.close();
		 }
	}

	static  vector<stLoginRegister> GetLoginRegister()
	{
		vector<stLoginRegister>VstRegister;

		fstream MyFile;
		MyFile.open("FileRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";
			stLoginRegister LoginRegister;
			while (getline(MyFile>>ws, Line))
			{
				LoginRegister = _ConvertLohinRegisterLientoObject(Line);
				VstRegister.push_back(LoginRegister);
			}
			MyFile.close();
		}

		return VstRegister;
	}

	
};

