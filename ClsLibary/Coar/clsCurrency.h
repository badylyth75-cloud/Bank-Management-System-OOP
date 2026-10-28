#pragma once
#include "LPy/clsDate.h";
#include "Global.h";
#include "LPy/clsString.h";
#include<string>
#include "clsScreen.h";
#include<fstream>
#include<vector>
#include "LPy/clsInputValidate.h"/\;
using namespace std;
class clsCurrency
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLientoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string>vString = clsString::SplitString(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vString[0], vString[1], vString[2], stod(vString[3]));
	}

	static vector<clsCurrency> _LoadCurrencyDataFromFile()
	{
		fstream MyFile;

		vector<clsCurrency>vCurrency;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile >> ws, Line))
			{
				clsCurrency Currrency = _ConvertLientoCurrencyObject(Line);
				vCurrency.push_back(Currrency);
			}
			MyFile.close();

		}

		return vCurrency;
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
	static string _ConvertCurrenctyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string StrClinet = "";
		StrClinet += Currency._Country + Seperator;
		StrClinet += Currency.GatCurrencyCode() + Seperator;
		StrClinet += Currency._CurrencyName + Seperator;
		StrClinet += Currency.GatRate();
		return StrClinet;

	}

	static void _SaveClientDataToFile(vector<clsCurrency>vClients)
	{
		fstream MyFile;
		string Lien;

		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsCurrency C : vClients)
			{
				Lien = _ConvertCurrenctyObjectToLine(C);
				MyFile << Lien << endl;
			}

			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsCurrency>vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C.GetCurrencyName() ==GatCurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(vCurrency);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (enMode::EmptyMode == _Mode);
	}

	string GetCountry()
	{
		return _Country;
	}

	string GatCurrencyCode()
	{
		return _CurrencyCode;
	}

	string GetCurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}
	
	float GatRate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Lien = "";
			while (getline(MyFile, Lien))
			{
				clsCurrency Currency = _ConvertLientoCurrencyObject(Lien);

				if (Currency.GatCurrencyCode() ==CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{

		Country = clsString::UpperAllString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Lien = "";
			while (getline(MyFile, Lien))
			{
				clsCurrency Currency = _ConvertLientoCurrencyObject(Lien);

				if (clsString::UpperAllString(Currency.GetCountry()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencytCode)
	{
		clsCurrency C = clsCurrency::FindByCode(CurrencytCode);

		return (!C.IsEmpty());
	}

	static vector<clsCurrency> GatCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}
	
	float ConverUSD(float Amouns)
	{
		return (float)(Amouns / _Rate);
	}
	float ConverToOtheCurrency(float Amouns,clsCurrency Currency2)
	{
		float CurrencyUSD = ConverUSD(Amouns);

		if (Currency2.GatCurrencyCode() == "USD")
		{
			return CurrencyUSD;
		}

		return (float)(CurrencyUSD * Currency2.GatRate());
	}
	
};

