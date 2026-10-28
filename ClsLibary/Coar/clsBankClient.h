#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "clsPerson.h";
#include "../LPy/clsString.h";
#include "../LPy/clsInputValidate.h";
#include "../LPy/clsDate.h";
#include "../LPy/clsUtil.h";
using namespace std;

class clsBankClient :public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewClient = 2};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool MarkedForDeleted = false;

	static clsBankClient _ConvertLientoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vString = clsString::SplitString(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, clsUtil::DecryptText(vString[0]), vString[1], vString[2], vString[3], vString[4], vString[5], stod(vString[6]));
	}
	struct stTransaforLog;

	static stTransaforLog _ConvertLientoTransforLog(string Line, string Seperator = "#//#")
	{
		vector<string>vString = clsString::SplitString(Line, Seperator);

		return stTransaforLog(vString[0], clsUtil::DecryptText(vString[1]), clsUtil::DecryptText(vString[2]), stod(vString[3]), stod(vString[4]), stod(vString[5]), vString[6]);
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadCleintsDataFromFile()
	{
		fstream MyFile;

		vector<clsBankClient>vClient;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile >> ws, Line))
			{
				clsBankClient Clinet = _ConvertLientoClientObject(Line);
				vClient.push_back(Clinet);
			}
			MyFile.close();

		}

		return vClient;
	}
	
	static string _ConvertClientObjectToLine(clsBankClient Clinet, string Seperator = "#//#")
	{
		string StrClinet = "";
		StrClinet = clsUtil::EncryptText(Clinet._AccountNumber)+ Seperator;
		StrClinet += Clinet.FirstName + Seperator;
		StrClinet += Clinet.ListName + Seperator;
		StrClinet += Clinet.email + Seperator;
		StrClinet += Clinet.Phone + Seperator;
		StrClinet += Clinet.PinCode + Seperator;
		StrClinet += to_string(Clinet.AccountBalance);

		return StrClinet;

	}
	
	 string _ConvertTransforLogToLine(float Amount,clsBankClient Desiont,string UsreName)
	{
		string TransforLine="";

		string Seperator = "#//#";

		TransforLine = clsDate::GetSystemDateTimeString()+ Seperator;
		TransforLine += clsUtil::EncryptText(_AccountNumber) + Seperator;
		TransforLine += clsUtil::EncryptText(Desiont.AccountNumbers()) + Seperator;
		TransforLine += to_string(Amount) + Seperator;
		TransforLine += to_string(AccountBalance) + Seperator;
		TransforLine += to_string(Desiont.AccountBalance) + Seperator;
		TransforLine += UsreName;

		return TransforLine;

	}

	static void _SaveClientDataToFile(vector<clsBankClient>vClients)
	{
		fstream MyFile;
		string Lien;

		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{
				if (C.MarkedForDeleted == false)
				{
					Lien = _ConvertClientObjectToLine(C);
					MyFile << Lien << endl;
				}
			
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsBankClient>vClient = _LoadCleintsDataFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumbers() == AccountNumbers())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(vClient);
	}

	void _AddClient()
	{

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream Myfile;

		Myfile.open("Clients.txt", ios::out | ios::app);

		if (Myfile.is_open())
		{
			Myfile << stDataLine << endl;
		}
		Myfile.close();
	}

public:

	static struct stTransaforLog
	{
		string DateTime;
		string AccounttSourceClient;
		string AccounttDestinationClien;
		float Amoun;
		float ScBalanc;
		float DcBalanc;
		string UserName;
	};

	clsBankClient(enMode Mode, string AccountNumber, string FirstName, string ListName, string email, string Phone,string PinCode, float AccountBalance) :
		clsPerson(FirstName, ListName, email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumbers()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLientoClientObject(Line);

				if (Client.AccountNumbers() == AccountNumber)
				{
					MyFile.clear();
					return Client;
				}
			}
		}
		return _GetEmptyClientObject();

	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLientoClientObject(Line);

				if (Client.AccountNumbers() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.clear();
					return Client;
				}
			}
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
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
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFillAccountNumberExist;
			}
			else
			{
				_AddClient();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		
		}
	}

	bool DeleteClient()
	{
		vector<clsBankClient>vClient = _LoadCleintsDataFromFile();

		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumbers() == _AccountNumber)
			{
				C.MarkedForDeleted = true;
				break;
			}
		}

		_SaveClientDataToFile(vClient);
		*this = _GetEmptyClientObject();
		return true;

	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewClient, AccountNumber,"", "", "", "", "", 0);
	}
	
	static vector<clsBankClient> GetClientList()
	{
		return _LoadCleintsDataFromFile();
	}

	static float GetTotalBalaces()
	{
		vector<clsBankClient>vClient = _LoadCleintsDataFromFile();

		double TotleBalaces = 0;
		for (clsBankClient Client : vClient)
		{
			TotleBalaces += Client.AccountBalance;
		}
		return TotleBalaces;
	}

	bool Deposit(double Balans)
	{
		if (Balans <= 0)
		{
			return false;
		}
		else
		{
			_AccountBalance += Balans;
			Save();
			return true;
		}
	}

	bool Withdeaw(double Balans)
	{

		if (Balans <= 0)
		{
			return false;
		}

		if (Balans > _AccountBalance)
		{
			return false;
		}
		
		_AccountBalance -= Balans;
		Save();
		return true;
	}

	bool Transfor(float Amount, clsBankClient& DestionationClient, string UserName)
	{

		if (Amount > AccountBalance || Amount <= 0)
		{
			return false;
		}

		if (!Withdeaw(Amount))
		{
			return false;
		}
		if (!DestionationClient.Deposit(Amount))
		{
			return false;
		}

		TransforLog(Amount, DestionationClient, UserName);
		return true;
	}

	 void TransforLog(float Amount,clsBankClient DestionationClient,string UserName)
	{
		 
		 fstream MyFile;
		 MyFile.open("TransforLog.txt", ios::out | ios::app);
		 string Line = "";
		 if (MyFile.is_open())
		 {
			  Line = _ConvertTransforLogToLine(Amount, DestionationClient, UserName);

			 MyFile << Line << endl;

			 MyFile.close();
		 }

	}

	 static vector<stTransaforLog> GetTransaforLogScreen()
	 {
		 vector<stTransaforLog>vSTransforLog;
		 fstream MyFile;
		 MyFile.open("TransforLog.txt", ios::in);
			 
		 if (MyFile.is_open())
		 {
			 string Line = "";
			 stTransaforLog Transaforlog;
			 while (getline(MyFile, Line))
			 {
				 Transaforlog =_ConvertLientoTransforLog(Line);
				 vSTransforLog.push_back(Transaforlog);
			 }
			 MyFile.close();
		 }
		 return vSTransforLog;
	 }

};
