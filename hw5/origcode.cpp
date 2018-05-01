#include "functor.h"
#include <string>
#include <sstream>
#include <map>

using namespace std;


		bool NumStrComp::operator()(const string& lhs, const string& rhs)
		{
			
				lookUp.insert(std::make_pair('0',0 ));
				lookUp.insert(std::make_pair('1', 1 ));
				lookUp.insert(std::make_pair('2',2 ));
				lookUp.insert(std::make_pair('3',3 ));
				lookUp.insert(std::make_pair('4',4 ));
				lookUp.insert(std::make_pair('5',5 ));
				lookUp.insert(std::make_pair('6',6 ));
				lookUp.insert(std::make_pair('7',7 ));
				lookUp.insert(std::make_pair('8',8 ));
				lookUp.insert(std::make_pair('9',9 ));
				lookUp.insert(std::make_pair('a',10 ));
				lookUp.insert(std::make_pair('A',10 ));
				lookUp.insert(std::make_pair('b',11 ));
				lookUp.insert(std::make_pair('B',11 ));
				lookUp.insert(std::make_pair('c',12 ));
				lookUp.insert(std::make_pair('C',12 ));
				lookUp.insert(std::make_pair('d',13 ));
				lookUp.insert(std::make_pair('D',13 ));
				lookUp.insert(std::make_pair('e',14 ));
				lookUp.insert(std::make_pair('E',14 ));
				lookUp.insert(std::make_pair('f',15 ));
				lookUp.insert(std::make_pair('F',15 ));
				lookUp.insert(std::make_pair('g',16 ));
				lookUp.insert(std::make_pair('G',16 ));
				lookUp.insert(std::make_pair('h',17 ));
				lookUp.insert(std::make_pair('H',17 ));
				lookUp.insert(std::make_pair('i',18 ));
				lookUp.insert(std::make_pair('I',18 ));
				lookUp.insert(std::make_pair('j',19 ));
				lookUp.insert(std::make_pair('J',19 ));
				lookUp.insert(std::make_pair('k',20 ));
				lookUp.insert(std::make_pair('K',20 ));
				lookUp.insert(std::make_pair('l',21 ));
				lookUp.insert(std::make_pair('L',21 ));
				lookUp.insert(std::make_pair('m',22 ));
				lookUp.insert(std::make_pair('M',22 ));
				lookUp.insert(std::make_pair('n',23 ));
				lookUp.insert(std::make_pair('N',23 ));
				lookUp.insert(std::make_pair('o',24 ));
				lookUp.insert(std::make_pair('O',24 ));
				lookUp.insert(std::make_pair('p',25 ));
				lookUp.insert(std::make_pair('P',25 ));
				lookUp.insert(std::make_pair('q',26 ));
				lookUp.insert(std::make_pair('Q',26 ));
				lookUp.insert(std::make_pair('r',27 ));
				lookUp.insert(std::make_pair('R',27 ));
				lookUp.insert(std::make_pair('s',28 ));
				lookUp.insert(std::make_pair('S',28 ));
				lookUp.insert(std::make_pair('t',29 ));
				lookUp.insert(std::make_pair('T',29 ));
				lookUp.insert(std::make_pair('u',30 ));
				lookUp.insert(std::make_pair('U',30 ));
				lookUp.insert(std::make_pair('v',31 ));
				lookUp.insert(std::make_pair('V',31));
				lookUp.insert(std::make_pair('w',32 ));
				lookUp.insert(std::make_pair('W',32 ));
				lookUp.insert(std::make_pair('x',33 ));
				lookUp.insert(std::make_pair('X',33 ));
				lookUp.insert(std::make_pair('y',34 ));
				lookUp.insert(std::make_pair('Y',34 ));
				lookUp.insert(std::make_pair('z',35 ));
				lookUp.insert(std::make_pair('Z',35 ));
			int sum1 = 0;
			int sum2 = 0;

			stringstream leftss;
			leftss << lhs;
			char a;
			while (leftss>>a)
			{
				leftss>>a;
				std::map<char,int>::iterator it;

				it = lookup.find(a);

				if (it != lookup.end())
				{
					sum1 += it->second;
				}

			}

			leftss.clear();
			leftss.str("");

			stringstream rightss;
			rightss << rhs;
			char b;

			while (rightss>>b)
			{
				rightss>>b;
				std::map<char,int>::iterator it;

				it = lookup.find(b);

				if (it != lookup.end())
				{
					sum2 += it->second;
				}
			}

			rightss.clear();
			rightss.str("");

			if (sum1 > sum2)
			{
				string temp = lhs;

				lhs = rhs;

				rhs = temp;
			}
			

			else if (sum1 == sum2)
			{
				bool checker = false;
				
				
				leftss << lhs;
				rightss << rhs;

				char x;
				char y;

				int size1 = lhs.length();
				int size2 = rhs.lenghth();

				int len = 0;
				if(size1 >= size2)
				{
					int len = size2;
				}

				else
				{
					len = size1;
				}

				int i = 0;

				while (checker == false && i < len)
				{
					leftss>>x;
					rightss>y;

					if (x > y)
					{
						string temp = lhs;

						lhs = rhs;

						rhs = temp;

						checker = true;

						break;
					}

					i++;

				}

				if (checker == false && size1 > size2)
				{
					string temp = lhs;

					lhs = rhs;

					rhs = temp;
				}
			}


		}



#include <vector>
#include <iostream>


template <class T, class Comparator>
  void qsort(std::vector<T> &myArray, int start, int end, Comparator comp);

template <class T, class Comparator>
  int partition(std::vector<T> &myArray, int start, int end, Comparator comp);

template <class T, class Comparator>
  void QuickSort (std::vector<T> &myArray, Comparator comp)
  {
  		int size = myArray.size();
  		qsort(myArray, 0, size, comp);
  }






template <class T, class Comparator>
  void qsort(std::vector<T> &myArray, int start, int end, Comparator comp)
  {
  		if (end-start<2)
  		{
  			return;
  		}
  		else if (start < end)
  		{
  			std::cout<<"New Partition" << std::endl;
  			int p = partition(myArray, start, end, comp);

  			qsort(myArray, start, p, comp);

  			qsort(myArray, p+1, end, comp);
  		}

  		return;

  }

 template <class T, class Comparator>
  int partition(std::vector<T> &myArray, int start, int end, Comparator comp)
  {
  		T a = myArray[start];
  		T b = myArray[(start+end)/2];
  		T c = myArray[end-1];
  		T pivot;



  		int x = start;
  		int y = end - 1;

  		if ((comp(a,b) && comp(b,c)) || (comp(c,b) && comp(b,a)))//if (b>a && b<c || b>c && b<a)
  		{
  			pivot = b;
  		}

  		else if ((comp(a,c) && comp(c,b)) || (comp(b,c) && comp(c,a)))//else if (c>a && c < b || c>b && c<a)
  		{
  			pivot = c;
  		}

  		else {pivot = a;}

  		while (1)
  		{
  			//count++;
  			while((comp(pivot, myArray[y]) && !comp(myArray[y], pivot) )|| (comp(myArray[y], pivot) && !comp(pivot,myArray[y])))
  			//while (myArray[y] > a) /////*****************************
  			{
  				y--;
  			}
  			
  			//count++
  			while((comp(pivot,myArray[x]) && !comp(myArray[x], pivot) )|| (comp(myArray[x], pivot) && !comp(pivot,myArray[x])))
  			//while (myArray[x] < a) ////*******************************
  			{
  				x++;
  			}

  			if (x<y)//if (comp(x,y) && !comp(y,x) || comp(y,x) && !comp(x,y)) //if (x<y)
  			{
  				std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[x];
  				myArray[x]= myArray[y];
  				myArray[y] = temp;
  				//x++;
  				//y--;
  			
  			}
  			else
  			{
  				std::cout << y << std::endl;
  				return y;
  			}
  		}
  		
  }



/*

  	    T a = myArray[start];
  		T b = myArray[(start+end)/2];
  		T c = myArray[end-1];
  		T pivot;



  		int x = start;
  		int y = end - 1;

  		if ((comp(a,b) && comp(b,c)) || (comp(c,b) && comp(b,a)))//if (b>a && b<c || b>c && b<a)
  		{
  			pivot = b;
  		}

  		else if ((comp(a,c) && comp(c,b)) || (comp(b,c) && comp(c,a)))//else if (c>a && c < b || c>b && c<a)
  		{
  			pivot = c;
  		}

  		else {pivot = a;}

  		while (1)
  		{
  			//count++;
  			while((comp(pivot, myArray[y]) && !comp(myArray[y], pivot) )|| (comp(myArray[y], pivot) && !comp(pivot,myArray[y])))
  			//while (myArray[y] > a) /////*****************************
  			{
  				y--;
  			}
  			
  			//count++
  			while((comp(pivot,myArray[x]) && !comp(myArray[x], pivot) )|| (comp(myArray[x], pivot) && !comp(pivot,myArray[x])))
  			//while (myArray[x] < a) ////*******************************
  			{
  				x++;
  			}

  			if (x<y)//if (comp(x,y) && !comp(y,x) || comp(y,x) && !comp(x,y)) //if (x<y)
  			{
  				std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[x];
  				myArray[x]= myArray[y];
  				myArray[y] = temp;
  				//x++;
  				//y--;
  			
  			}
  			else
  			{
  				std::cout << y << std::endl;
  				return y;
  			}
  		}
  		*/




  
#include <vector>
#include <iostream>


template <class T, class Comparator>
  void qsort(std::vector<T> &myArray, int start, int end, Comparator comp);

template <class T, class Comparator>
  int partition(std::vector<T> &myArray, int start, int end, Comparator comp);

template <class T, class Comparator>
  void QuickSort (std::vector<T> &myArray, Comparator comp)
  {
  		int size = myArray.size();
  		qsort(myArray, 0, size, comp);
  }






template <class T, class Comparator>
  void qsort(std::vector<T> &myArray, int start, int end, Comparator comp)
  {
  		if (end-start<2)
  		{

  			return;
  		}
  		else if (start < end)
  		{
  			std::cout<<"New Partition" << std::endl;
  			int p = partition(myArray, start, end, comp);

  			qsort(myArray, start, p, comp);

  			qsort(myArray, p, end, comp);
  		}

  		return;

  }

 template <class T, class Comparator>
  int partition(std::vector<T> &myArray, int start, int end, Comparator comp)
  {
  		int mid = (start+end)/2;
  	   
  		if ((comp(myArray[end-1], myArray[start])))//&& !comp(myArray[start], myArray[end-1]))|| (!comp(myArray[end-1], myArray[start])&& comp(myArray[start], myArray[end-1])))
  		{
  			std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[start];
  				myArray[start]= myArray[end-1];
  				myArray[end-1] = temp;


  		}

  		if ((comp(myArray[mid], myArray[start])))//&& !comp(myArray[start], myArray[mid]))|| (!comp(myArray[mid], myArray[start])&& comp(myArray[start], myArray[mid])))
  		{
  			std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[mid];
  				myArray[mid]= myArray[start];
  				myArray[start] = temp;
  		}

  		if ((comp(myArray[end-1], myArray[mid])))//&& !comp(myArray[mid], myArray[end-1]))|| (!comp(myArray[end-1], myArray[mid])&& comp(myArray[mid], myArray[end-1])))
  		{
  			std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[end-1];
  				myArray[end-1]= myArray[mid];
  				myArray[mid] = temp;
  		}

  		std::cout<<mid <<std::endl;
  		return mid;


  }









