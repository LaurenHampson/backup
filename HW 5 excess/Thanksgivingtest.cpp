

/*

using namespace std;


int main()
{

	vector<int> myArray1;
	vector<int> myArray2;


	std::cout<< "Should Print Result" <<std:: endl;
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
    std::cout << std::endl;

	std::cout<< "Comparing should print result"<<std::endl;
    int input2[] = {500, 550, 580};
    int input3[] = {440, 470, 520};
    for (int i = 0; i < 3; i++)
    {
    	myArray3.push_back(input2[i]);
    	myArray4.push_back(input3[i]);
    }

    std::cout << std::endl;
    std::vector<std::pair<int, int> > resulter1 = assignPlates(myArray3, myArray4);

    for (unsigned int a = 0; a < resulter1.size(); a++)
    {
    	std::cout << resulter1[a].first << " " << resulter1[a].second << std::endl;
    }

    std::cout<< "Comparing should not print anything"<<std::endl;
    int input5[] = {1, 2, 3};
    int input6[] = {3, 2, 5};
    vector<int> myArray8;
	vector<int> myArray9;
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
    	myArray8.push_back(input5[i]);
    	myArray9.push_back(input6[i]);
    }

    std::cout << std::endl;
    std::vector<std::pair<int, int> > resulter5 = assignPlates(myArray8, myArray9);

    for (unsigned int a = 0; a < resulter5.size(); a++)
    {
    	std::cout << resulter5[a].first << " " << resulter5[a].second << std::endl;
    }

vector<int> myArray5;
	vector<int> myArray6;
    
    	myArray5.push_back(1);
    	myArray5.push_back(2);
    	myArray6.push_back(1);
    

    	std::cout<<"Error"<<std::endl;
    std::vector<std::pair<int, int> > resulter2 = assignPlates(myArray5, myArray6);

    for (unsigned int a = 0; a < resulter2.size(); a++)
    {
    	std::cout << resulter2[a].first << " " << resulter2[a].second << std::endl;
    }
        std::cout << std::endl;



    return 1;

}*/