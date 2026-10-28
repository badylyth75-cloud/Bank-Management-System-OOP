#pragma once
#include<iostream>
#include "clsDate.h";
using namespace std;

class clsUtil
{
public:
	static int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static void Swop(int& A, int& B)
	{
		int Temp = A;
		A = B;
		B = Temp;
	}
	
	static void Swop(double&A, double& B)
	{
		double Temp = A;
		A = B;
		B = Temp;
	}

	static void Swop(string& A, string& B)
	{
		string Temp = A;
		A = B;
		B = Temp;
	}

	static void Swop(clsDate& A, clsDate& B)
	{
		clsDate Temp = A;
		A = B;
		B = Temp;
	}

	static enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpeciaCharacter = 3, Digit = 4,MixChars=5 };

	static char  GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SamallLetter:
		{
			return char((int)RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return RandomNumber(65, 90);
			break;
		}
		case enCharType::SpeciaCharacter:
		{
			return RandomNumber(33, 47);
			break;
		}
		case enCharType::Digit:
		{
			return (RandomNumber(48, 57));
			break;
		}
		case enCharType::MixChars:
		{
			return char((int)RandomNumber(48, 122));
			break;
		}

		}
	}

	static string  GenerateWord(enCharType CharType, short Length)
	{
		string Word = "";


		for (int j = 0;j < Length;j++)
		{
			Word += GetRandomCharacter(CharType);

		}

		return Word;
	}

	static string Generatakey(enCharType CharType)
	{
		string Key;

		Key = GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;

	}

	static void GenerateKeys(int Number, enCharType CharType)
	{
		for (int i = 1;i <= Number;i++)
		{
			cout << "key [" << i << "]" << " : " << Generatakey(CharType) << endl;
		}
	}

	static void  FillArrayWithRandomNumber(int arr[100], int arrLength,short From,short Top)
	{
		for (int i = 0;i < arrLength;i++)
		{
			arr[i] = RandomNumber(From, Top);

		}
	}

	static void  FillArrayWithRandomNumber(string arr[100], int arrLength,enCharType CharType,  short Top)
	{
		for (int i = 0;i < arrLength;i++)
		{
			arr[i] = GenerateWord(CharType, Top);

		}
	}

	static void  FillArrayWithRandomNumber(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0;i < arrLength;i++)
		{
			arr[i] = Generatakey(CharType);

		}
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int j = 0;j < arrLength;j++)
		{
			Swop(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int j = 0;j < arrLength;j++)
		{
			Swop(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string Tabs(int Tab)
	{
		string a = "";
		for (int i = 0; i < Tab; i++)
		{
			a += "\t";
		}
		return a;
	}

	static string EncryptText(string Text, short EncryPtionKey=3)
	{
		for (int i = 0;i < Text.length();i++)
		{
			Text[i] = char((int)+Text[i] + EncryPtionKey);
		}
		return Text;
	}

	static string DecryptText(string Text, short EncryPtionKey=3)
	{
		for (int i = 0;i < Text.length();i++)
		{
			Text[i] = char((int)+Text[i] - EncryPtionKey);
		}
		return Text;
	}



	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five",
						   "Six","Seven","Eigth","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
						   "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
			};
			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninty" };
			return NumberToText(Number / 10) + " " + arr[Number % 10];
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 9999)
		{
			return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 200);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number / 200);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + " Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 19999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + " Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000) + " Millions " + NumberToText(Number % 1000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + " Billions";
		}

	}



};

