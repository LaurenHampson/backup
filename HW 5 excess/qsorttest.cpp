#include "qsort.h"
#include <vector>
#include <iostream>
#include <functional>
#include "functor.h"

using namespace std;


int main()
{

	vector<int> myArray1;
	vector<int> myArray2;



    int input[] = {11, 6, 3, 21, 9, 12, 24, 45};

    for (int i = 0; i < 8; i++)
    {
    	myArray1.push_back(input[i]);
    	myArray2.push_back(input[i]);
    }

    std::cout << "Before 1: ";
    for (int i=0; i < 8; i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;

    QuickSort(myArray1, std::less<int>());
   
    std::cout << "After quicksort ascending: ";
    for (int i=0; i < 8; i++)
        std::cout << myArray1[i] << " ";
    std::cout << std::endl;


    std::cout << "Before 2: ";
    for (int i=0; i < 8; i++)
        std::cout << input[i] << " ";
    std::cout << std::endl;

    QuickSort(myArray2, std::greater<int>());
    
    std::cout << "After quicksort descending: ";
    for (int i=0; i < 8; i++)
        std::cout << myArray2[i] << " ";
    std::cout << std::endl;



   vector<string> strArray;
   strArray.push_back("e");
   strArray.push_back("z");
   strArray.push_back("a");
   strArray.push_back("d");
   strArray.push_back("x");
   strArray.push_back("c");
   strArray.push_back("b");
   strArray.push_back("aa");
   strArray.push_back("ab");
   strArray.push_back("ac");
   strArray.push_back("ca");

   std::cout<< "NumStrComp Tester Before" << std::endl; 
   for (unsigned int i = 0; i < strArray.size();i++)
   {
   	std::cout<< strArray[i] << " ";
   }
  std::cout << std::endl;
   QuickSort(strArray, NumStrComp());

   std::cout<< "NumStrComp Tester After" << std::endl; 
   for (unsigned int i = 0; i < strArray.size();i++)
   {
   	std::cout<< strArray[i] << " ";
   }


   vector<int> a;
   a.push_back(124);
   a.push_back(50923);
   a.push_back(12);
   a.push_back(0);
   a.push_back(1);
   a.push_back(4);
   a.push_back(980);
   a.push_back(-3);

   
    std::cout << "Before 3: ";
    for (int i=0; i < 8; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    QuickSort(a, std::less<int>());
   
    std::cout << "After quicksort ascending: ";
    for (int i=0; i < 8; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;


 vector<int> b;
   b.push_back(124);
   b.push_back(50923);
   b.push_back(12);
   b.push_back(0);
   b.push_back(1);
   b.push_back(4);
   b.push_back(980);
   b.push_back(-3);
    std::cout << "Before 4: ";
    for (int i=0; i < 8; i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    QuickSort(b, std::greater<int>());
    
    std::cout << "After quicksort descending: ";
    for (int i=0; i < 8; i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;


    vector<string> str;
   str.push_back("ab");
    str.push_back("ba");
     str.push_back("ac");
      str.push_back("ca");
       str.push_back("da");
        str.push_back("ad");
          std::cout<< "NumStrComp Tester Before" << std::endl; 
   for (unsigned int i = 0; i < str.size();i++)
   {
    std::cout<< str[i] << " ";
   }
  std::cout << std::endl;
   QuickSort(str, NumStrComp());

   std::cout<< "NumStrComp Tester After" << std::endl; 
   for (unsigned int i = 0; i < str.size();i++)
   {
    std::cout<< str[i] << " ";
   }
  std::cout << std::endl;


  vector<string> s;
  s.push_back("ca");
  s.push_back("ac");

  cout <<" S before" << endl;

  for (int i = 0; i < 2; i++)
  {
    cout<< s[i] << " ";
  }
  cout << endl;
  cout << "S after" << endl;
  QuickSort(s, NumStrComp());
  for (int i = 0; i < 2; i++)
  {
    cout <<s[i] << " ";
  }
  cout<< endl;

    return 1;

}