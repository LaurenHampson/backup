#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

void divide(int mini, int maxi);

int main(int argc, char* argv[])
{
	srand (time(NULL));
	int a = rand();
	int b = rand();
	
	divide(a,b);

	
	
	return 0;
}

void divide(int mini, int maxi)
{
	if (mini > maxi)
	{
		int temp = mini;
		mini = maxi;
		maxi = temp;
	}
	int r = maxi % mini;
	int q = maxi / mini;
	std::cout << maxi << " / " << mini;
	std::cout << ": quotient = " << q << " remainder = " << r << std::endl;
}