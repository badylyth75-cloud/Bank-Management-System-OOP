#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class clsString
{
private:
	string _Value;
public:

	clsString()
	{
		cout << _Value;
	}
	clsString(string Vaule)
	{
		_Value = Vaule;
	}

	void SetValue(string Vaule)
	{
		_Value = Vaule;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;
	
	static short Length(string S1)
	{
		return S1.length();
	}
	short Length()
	{
		return _Value.length();
	}

	static	short CountWords(string S1)
	{
		string delim = " ";

		short pos = 0;
		short Count = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Count++;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			Count++;
		}

		return Count;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	static	void PrintFirstLetterOfEachWord(string S1)
	{
		cout << "\nFirst Ietters of this string\n";
		bool FirstString = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (FirstString && S1[i] != ' ')
			{
				cout << S1[i] << endl;
			}
			FirstString = (S1[i] == ' ' ? true : false);
		}

	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static	void PrinttLetterOfEachWord(string S1)
	{
		cout << "\nFirst Ietters of this string\n";
		bool FirstString = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (FirstString && S1[i + 1] == ' ' || i == (S1.length() - 1))
			{
				cout << S1[i] << endl;
			}
			FirstString = (S1[i] != ' ' ? true : false);
		}

	}
	void PrinttLetterOfEachWord()
	{
		PrinttLetterOfEachWord(_Value);
	}

	static	char InvertLetterCase(char C1)
	{
		return isupper(C1) ? tolower(C1) : toupper(C1);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{

		bool FirstString = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (FirstString && S1[i] != ' ')
			{
				S1[i] = toupper(S1[i]);
			}
			FirstString = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value= UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{

		bool FirstString = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (FirstString && S1[i] != ' ')
			{
				S1[i] = tolower(S1[i]);
			}
			FirstString = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value= LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	void UpperAllString()
	{
		_Value=  UpperAllString(_Value);
	}

	static	string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static string InvertAllStringLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertAllStringLettersCase()
	{
		_Value = InvertAllStringLettersCase(_Value);
	}

	static	short CountSmallLetters(string S1)
	{
		short Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Count++;
		}
		return Count;
	}
	short CountSmallLetter()
	{
		return  CountSmallLetters(_Value);
	}

	static short CountCapitalLetters(string S1)
	{
		short Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Count++;

		}
		return Count;
	}
	short CountCapitalLetters()
	{
		return  CountCapitalLetters(_Value);
	}

	enum enWhatToCount { SmallLetters = 1, CapitalLtetters = 2, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCunt = enWhatToCount::All)
	{
		if (WhatToCunt == enWhatToCount::All)
		{
			return short(S1.length());
		}
		short Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCunt == enWhatToCount::SmallLetters && islower(S1[i]))
				Count++;

			if (WhatToCunt == enWhatToCount::CapitalLtetters && isupper(S1[i]))
				Count++;
		}
		return Count;
	}



	static short CountSpecifcLetter(string S1, char StCount, bool MatchCase = true)
	{
		short Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == StCount)
					Count++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(StCount))
					Count++;
			}

		}
		return Count;
	}
	short CountSpecifcLetter(char StCount, bool MatchCase = true)
	{
		return CountSpecifcLetter(_Value,  StCount,  MatchCase);
	}

	static short  OrCountLetter(string S1, char StCount)
	{
		short Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (tolower(S1[i]) == tolower(StCount))
				Count++;
		}
		return Count;
	}
	short  OrCountLetter(char StCount)
	{
		return   OrCountLetter(_Value, StCount);
	}

	static bool IsVowel(char Letter)
	{
		tolower(Letter);

		return (Letter == 'a') || (Letter == 'u') || (Letter == 'o') || (Letter == 'i') || (Letter == 'e');
	}


	static short CountVowels(string S1)
	{
		short Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Count++;
		}
		return Count;
	}
	short CountVowels()
	{
		return  CountVowels(_Value);
	}

	static void PrintVovwels(string S1)
	{
		cout << "\nVowels of string is: ";
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				cout << S1[i] << ' ';
		}

	}
	void PrintVovwels()
	{
		PrintVovwels(_Value);
	}

	static void PrintEachWordInString(string S1)
	{
		string delim = " ";
		cout << "\nYour String wrords are: \n\n";

		short pos = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
			cout << S1 << endl;

	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static vector<string> SplitString(string S1, string delim)
	{

		vector<string>vString;

		short pos = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + delim.length());

		}
		if (S1 != "")
		{
			vString.push_back(S1);
		}
		return vString;
	}
	 vector<string> SplitString(string delim)
	 {
		 return SplitString(_Value, delim);
	 }

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}

		}
		return "";
	}
	void TrimLeft()
	{
		_Value=  TrimLeft(_Value);
	}

	static string TrimRigth(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}

		}
		return "";

	}
	void TrimRigth()
	{
		_Value = TrimRigth(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRigth(S1)));
	}
	void Trim()
	 {
		_Value = Trim(_Value);
	 }

	static string JoinString(vector<string>& vString, string Delim)
	{
		string S1 = "";

		for (string& S : vString)
		{
			S1 += S + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string JoinString(string arrString[], short length, string Delim)
	{
		string S1 = "";

		for (short i = 0;i < length;i++)
		{
			S1 += arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string S1)
	{
		string S2 = "";
		vector<string>vString;
		vString = SplitString(S1, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + ' ';
		}

		S2 = S2.substr(0, S2.length() - 1);

		return S2;
	}
	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWordsInStringUsingBuiltInFunction(string S1, string StringToReplace, string sReplaceTo)
	{
		short pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
			pos = S1.find(StringToReplace);
		}
		return S1;
	}
	string ReplaceWordsInStringUsingBuiltInFunction(string StringToReplace, string sReplaceTo)
	{
		return  ReplaceWordsInStringUsingBuiltInFunction(_Value, StringToReplace, sReplaceTo);
	}

	static string ReplaceWordsInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MatchCaes = true)
	{
		vector<string >vString;
		vString = SplitString(S1, " ");
		for (string& s : vString)
		{
			if (MatchCaes)
			{
				if (s == StringToReplace)
				{
					s = sReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sReplaceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}
	string ReplaceWordsInStringUsingSplit(string StringToReplace, string sReplaceTo, bool MatchCaes = true)
	{
		return ReplaceWordsInStringUsingSplit(_Value, StringToReplace, sReplaceTo, MatchCaes);
	}

	static string RemovePunctuationsFromString(string S1)
	{
		string S2 = "";
		for (short i = 0;i < S1.length();i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}
	void RemovePunctuationsFromString()
	{
		_Value = RemovePunctuationsFromString(_Value);
	}

};

