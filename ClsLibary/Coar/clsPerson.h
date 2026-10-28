#pragma once
#include<iostream>
using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _ListName;
	string _Phore;
	string _email;
 
public:

	clsPerson(string FirstName, string ListName, string email, string Phoer)
	{
		_FirstName = FirstName;
		_ListName = ListName;
		_email = email;
		_Phore = Phoer;
	}


	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	void SetListName(string ListName)
	{
		_ListName = ListName;
	}

	string GetListName()
	{
		return _ListName;
	}
	__declspec(property(get = GetListName, put = SetListName))string ListName;

	void SetEmail(string emali)
	{
		_email = emali;
	}

	string GetEmail()
	{
		return _email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string email;

	void SetPhone(string Phone)
	{
		_Phore = Phone;
	}

	string GetPhone()
	{
		return _Phore;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	void SendEmail(string M, string Masseg)
	{
		cout << "\n\nThe following massage sent succssfully to email: " << _email;
		cout << "\nSubject : " << M;
		cout << "\nBody: " << Masseg;
	}

	void SendSMS(string SMS)
	{
		cout << "\n\nThe following SMS sent succssfully to Phoer: " << _Phore;
		cout << "\n" << SMS;
	}

	string FullName()
	{
		return _FirstName + " " + _ListName;
	}



};


