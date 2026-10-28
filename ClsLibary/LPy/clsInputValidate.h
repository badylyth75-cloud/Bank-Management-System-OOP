#pragma once
#include<iostream>
#include<string>

using namespace std;

class clsInputValidate
{

public:

   static string ReadString()
	{ 

		string AccountNumber;
		getline(cin >>ws , AccountNumber);
		return AccountNumber;
	}

   static float ReadFloatNumber()
   {
	   float AccountNumber;
	    cin>> AccountNumber;
	   return AccountNumber;
   }

   static short ReadShortNumberBetween(short Choice, short Choice1, string Massega)
   {
	 
	   short Number;
	   cin >> Number;
	   
	   while (cin.fail() ||Number < Choice || Number>Choice1)
	   {
		   if (cin.fail())
		   {
			   cin.clear();
			   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			   cout << "Invalid Number, Enter again: " << endl;
			   cin >> Number;
		   }
		   else
		   {
			   cout << Massega << endl;
			   cin >> Number;
		   }
		  
	   }

	   return Number;
   }

    

};

