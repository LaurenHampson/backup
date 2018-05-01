#include<vector>
#include<string>
#include<iostream>
#include <functional>
#include <utility>
#include<stdexcept>
#include "lengthmismatch.h"
#include "qsort.h"


using namespace std;

string sizeChecker (int a, int b)
{
	if (a != b )
	{
		throw LengthMismatch(a,b);
	}

	return "";
}



std::vector<std::pair<int, int> > assignPlates(std::vector<int> turkeys, std::vector<int> potatoes) 
	{
		try
		{
			std::cout<<sizeChecker(turkeys.size(), potatoes.size())<<std::endl;	
		}
		catch(LengthMismatch& o)
		{
			std::cout<< o.what() << std::endl;
			std::vector<std::pair<int, int> > results;

				return results;
			

		}

	
		qsort(turkeys, 0, turkeys.size(), std::greater<int>());
		qsort(potatoes, 0, potatoes.size(), std::less<int>());

		std::vector<std::pair<int, int> > result;
		vector<int> sums;

		for (unsigned int i = 0; i < turkeys.size(); i++)
		{
			result.push_back(std::make_pair(turkeys[i], potatoes[i]));
			sums.push_back(turkeys[i]+potatoes[i]);
		}

		for (unsigned int i = 0; i < (sums.size()-1); i++)
		{
			if (sums[i] != sums[i+1])
			{
				std::vector<std::pair<int, int> > results;

				return results;
			}
		}

		return result;

	}






using namespace std;


int main()
{

	vector<int> myArray1;
	vector<int> myArray2;



    int input[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
    	myArray1.push_back(input[i]);
    	myArray2.push_back(input[i]);
    }

    std::vector<std::pair<int, int> > resulter = assignPlates(myArray1, myArray2);

    for (unsigned int a = 0; a < resulter.size(); a++)
    {
    	std::cout << resulter[a].first << " " << resulter[a].second << std::endl;
    }


	vector<int> myArray3;
	vector<int> myArray4;
    int input2[] = {1, 2, 3, 4, 5};
    int input3[] = {56, 67, 122, 79, 0};
    for (int i = 0; i < 5; i++)
    {
    	myArray3.push_back(input2[i]);
    	myArray4.push_back(input3[i]);
    }

    std::vector<std::pair<int, int> > resulter1 = assignPlates(myArray3, myArray4);

    for (unsigned int a = 0; a < resulter1.size(); a++)
    {
    	std::cout << resulter1[a].first << " " << resulter1[a].second << std::endl;
    }

vector<int> myArray5;
	vector<int> myArray6;
    
    	myArray5.push_back(1);
    	myArray5.push_back(2);
    	myArray6.push_back(1);
    

    std::vector<std::pair<int, int> > resulter2 = assignPlates(myArray5, myArray6);

    for (unsigned int a = 0; a < resulter2.size(); a++)
    {
    	std::cout << resulter2[a].first << " " << resulter2[a].second << std::endl;
    }


    return 1;

}