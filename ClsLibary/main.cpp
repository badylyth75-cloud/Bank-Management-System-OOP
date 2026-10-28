#include<iostream>
#include "Coar/clsLoginScreen.h";

using namespace std;

template <typename T> T MyMax(T Number1, T Number2)
{
	return (T)(Number1 + Number2);
}

int main()
{
	
	while (true) 
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
		
	}
	
	



	

	// //Swap int 
	// int A = 10, B = 20;
	// cout << A << " " << B << endl;
	// clsUtil::Swop(A, B);
	// cout << A << " " << B << endl;
	// 
	// cout << endl;
	// //Swap double
	// double d1 = 10.5, d2 = 20.23;
	// cout << d1 << " " << d2 << endl;
	// clsUtil::Swop(d1, d2);
	// cout << d1 << " " << d2 << endl;

	// cout << endl;
	// //Swap string 
	// string s1 = "Ali", s2 = "Taha";
	// cout << s1 << " " << s2 << endl;
	// clsUtil::Swop(s1, s2);
	// cout << s1 << " " << s2<< endl;

	// cout << endl;
	// //Swap Dates
	// clsDate da1(1, 1, 2022), da2(10, 4, 2024);
	// cout << da1.DateToString() << " " << da2.DateToString() << endl;
	// clsUtil::Swop(da1, da2);
	// cout << da1.DateToString() << " " << da2.DateToString() << endl;

	// cout << endl;
	// //Shuffl Array

	// int Arr1[5] = { 1,2,3,4,5 };
	// clsUtil::ShuffleArray(Arr1, 5);
	// cout << "Array after shuffle :\n";
	// for (int i = 0;i < 5;i++)
	// {
	//	 cout << Arr1[i] << endl;
	// }

	// string Arr2[5] = { "Array", "after","Ali","Taha"," shuffle"};
	// clsUtil::ShuffleArray(Arr2, 5);
	// cout << "\nArray after shuffle :\n";
	// for (int i = 0;i < 5;i++)
	// {
	//	 cout << Arr2[i] << endl;
	// }


	// int Arr3[5];
	// clsUtil::FillArrayWithRandomNumber(Arr3, 5, 10, 20);
	// cout << "\nArray after fill :\n";
	// for (int i = 0;i < 5;i++)
	// {
	//	 cout << Arr3[i] << endl;
	// }

	// string Arr4[5];
	// clsUtil::FillArrayWithRandomNumber(Arr4, 5,clsUtil::MixChars, 8);
	// cout << "\nArray after fill :\n";
	// for (int i = 0;i < 5;i++)
	// {
	//	 cout << Arr4[i] << endl;
	// }

	// string Arr5[5];
	// clsUtil::FillArrayWithRandomNumber(Arr5, 5, clsUtil::MixChars);
	// cout << "\nArray after fill :\n";
	// for (int i = 0;i < 5;i++)
	// {
	//	 cout << Arr5[i] << endl;
	// }

	// cout << "\nText1 " << clsUtil::Tabs(5)<<"Text" << endl;

	// const short Encrypionk = 2;

	// string TextAsfterEncru, TextDecryp;
	// string Text = "Ali Taha";
	// TextAsfterEncru = clsUtil::EncryptText(Text, Encrypionk);
	// TextDecryp = clsUtil::DecryptText(TextAsfterEncru, Encrypionk);

	// cout << "\nText Before Encryption : ";
	// cout << Text << endl;
	// cout << "Text After Enct :  ";
	// cout << TextAsfterEncru << endl;
	// cout << "Text After Enct :  ";
	// cout << TextDecryp << endl;
	// 




	 
}