
#include <vector>
#include <iostream>
#include <math.h>


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
  		if (myArray.size() == 2)
  		{
  			if (comp(myArray[0], myArray[1]))
  				{
  				T temp = myArray[0];
  				myArray[0]= myArray[1];
  				myArray[1] = temp;}
  				return;
  		}

  		if (start<end)

  		{
  		  			//std::cout<<"New Partition" << std::endl;
  		  			int p = partition(myArray, start, end, comp);
  		
  		  			qsort(myArray, start, p, comp);
  		
  		  			qsort(myArray, p+1, end, comp);
  		  		}

  		//return;

  }

 template <class T, class Comparator>
  int partition(std::vector<T> &myArray, int start, int end, Comparator comp)
  {
  		int mid = floor((end-start)/2) + start;
  	   
  		if ((comp(myArray[end-1], myArray[start])))//&& !comp(myArray[start], myArray[end-1]))|| (!comp(myArray[end-1], myArray[start])&& comp(myArray[start], myArray[end-1])))
  		{
  			//std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[start];
  				myArray[start]= myArray[end-1];
  				myArray[end-1] = temp;


  		}

  		if ((comp(myArray[mid], myArray[start])))//&& !comp(myArray[start], myArray[mid]))|| (!comp(myArray[mid], myArray[start])&& comp(myArray[start], myArray[mid])))
  		{
  			//std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[mid];
  				myArray[mid]= myArray[start];
  				myArray[start] = temp;
  		}

  		if ((comp(myArray[end-1], myArray[mid])))//&& !comp(myArray[mid], myArray[end-1]))|| (!comp(myArray[end-1], myArray[mid])&& comp(myArray[mid], myArray[end-1])))
  		{
  			//std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[end-1];
  				myArray[end-1]= myArray[mid];
  				myArray[mid] = temp;
  		}

  		//std::cout<<mid <<std::endl;
  		//return mid;


  		T pivot = myArray[mid];

  		int i = start; 
  		for (int j = start; j < end; j++)
  		{
  			if (comp(myArray[j], pivot))
  			{
  				//std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[i];
  				myArray[i]= myArray[j];
  				myArray[j] = temp;

  				i++;

  			}
  		}
				//std::cout<<"Swap Made" << std::endl;
  				T temp = myArray[i];
  				myArray[i]= myArray[mid];
  				myArray[mid] = temp;

  				//std::cout<< i << std::endl;
  				return i;
		   

  }
  		

