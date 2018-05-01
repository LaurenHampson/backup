#include "functor.h"
#include <iostream>
#include <string>

using namespace std;

template <class Comparator>
void DoStringCompare(const string& s1, const string& s2, Comparator comp)
{
	bool compa = comp(s1,s2);
  cout << compa << endl;  // calls comp.operator()(s1,s2);
}

int main()
 { 
 	string s1 = "Blue"; // 11 + 21 + 30 + 14
   	string s2 = "Red"; // 14 + 13 + 27
  	NumStrComp comp1;
 
 	cout << "Blue v Red  should be false" << endl;
 	DoStringCompare(s1,s2,comp1);
  

  	string s3 = "Red"; // 11 + 21 + 30 + 14
   	string s4 = "Red"; // 14 + 13 + 27
  	NumStrComp comp2;
 
 	cout << "Red v Red should be false" << endl;
 	DoStringCompare(s3,s4,comp2);


 	string s5 = "Red"; // 11 + 21 + 30 + 14
   	string s6 = "Blue"; // 14 + 13 + 27
  	NumStrComp comp3;
 
 	cout << "Red v Blue should be true" << endl;
 	DoStringCompare(s5,s6,comp3);
 	
 
  
 	 	cout << "a vs ca true " << endl;
 	 	DoStringCompare("a", "ca", comp3);


cout << "ca vs b false" << endl;
 	 	DoStringCompare("ca", "b", comp3);


 	 	cout << "b vs aa true" << endl;
 	 	DoStringCompare("b", "aa", comp3);

cout << "aa vs ab true" << endl;
 	 	DoStringCompare("aa", "ab", comp3);


cout << "ab vs c false" << endl;
 	 	DoStringCompare("ab", "c", comp3);

 	 	cout << "c vs d true" << endl;
 	 	DoStringCompare("c", "d", comp3);

 	 	cout << "d vs e true" << endl;
 	 	DoStringCompare("d", "e", comp3);

 	 	cout << "e vs x true" << endl;
 	 	DoStringCompare("e", "x", comp3);

 	 	cout << "x vs ac false" << endl;
 	 	DoStringCompare("x", "ac", comp3);

 	 	cout << "ac vs z true" << endl;
 	 	DoStringCompare("ac", "z", comp3);

		cout << "ca vs ac false" << endl;
 	 	DoStringCompare("ca", "ac", comp3); 	 	

    cout << "aB vs Ba false" << endl;
    DoStringCompare("aB", "Ba", comp3);


  return 1;
}