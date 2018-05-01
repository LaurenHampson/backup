#include "../splayTree.h"
#include "../cacheLRU.h"
#include "gtest/gtest.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <cstring>
#include "../cacheLRU.h"
#include "../SplayTree.h"



using namespace std;
int main(int argc, char *argv[])
{
	std::ifstream input;
	if (argc<2) //default config file if no argument passed in
	{
		input.open("config.txt");
		
	}

	else//open the input argument
	{
		input.open(argv[1]);
	}
	
	int fileSize = 0;
	std::vector<std::string> words;
	std::string line;
	while (getline(input, line, " "))
	{
		fileSize++;
		words.push_back(line);
	}

	

	// std::map<std::string, std::string> crawlfiles;
	
	// configure(input, crawlfiles); // configure

	// std::map<std::string, std:: string>::iterator it = crawlfiles.find("INDEX_FILE");
	// string indexFile = "";
	// if (it != crawlfiles.end())
	// 	indexFile = (it->second);
	// std::ifstream index(indexFile);//read in index file

	// it = crawlfiles.find("OUTPUT_FILE");

	// string outputFile = "";
	// if (it!= crawlfiles.end())
	// 	outputFile = it->second;

	// std::ofstream output(outputFile); // read in output file

	// std::set<std::string> found;
	// std::vector<string> links;
	
	// std::string line;
	// while (getline(index, line))
	// {
	// 	links.push_back(line);
	// 	std::ifstream in(line);
	// 	DFS(in, found, links); // call crawler on each elemnt of the input 
	// 	in.close();
	// }
	
	// for (unsigned int i = 0; i < links.size(); i++)
	// {
	// 	output << links[i] << std::endl;
	// }


	
	index.close();
	output.close();


	return 0;

}