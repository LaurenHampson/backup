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
  		if (start < end)
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
  		T a = myArray.at(start);
  		T b = myArray.at((start+end)/2);
  		T c = myArray.at(end-1);

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

  		pivot = a;

  		while (1)
  		{
  			//count++;
  			while((comp(pivot,myArray[y]) && !comp(myArray[y], pivot) )|| (comp(myArray[y], pivot) && !comp(pivot,myArray[y])))
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
  				T temp = myArray.at(x);
  				myArray.at(x)= myArray.at(y);
  				myArray.at(y) = temp;
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

