#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <cstring>
#include "querysearch.h"
#include "webpage.h"
#include "parser.h"
#include "lowercase.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc<4)
	{
		//std::cout << "No Index File" << std::endl;

		return -1;
	}

	QuerySearch* searcher = new QuerySearch();
	Parser* parse = new Parser();

	std::ifstream input(argv[1]);
	
	searcher->pageParser(input, parse);
	
	std::ifstream inQuery(argv[2]);

	std::ofstream output(argv[3]);

	std::string line;

	while(getline(inQuery, line))
	{
		queue<string> split;
		stringstream ss;

		ss << line;

		//string newWords;

		string str;
		while(ss >> str);
		{
			split.push(str);
		}

		if (split.size() == 1)
		{
			searcher->search(lowerCase(split.front()), output);
			split.pop();
		}


		else
		{
			string opr = lowerCase(split.front());
			split.pop();
			searcher->query(opr, split, output);
			/*if (opr == "and")
			{
				searcher->andQ(split, output);
			}
			else if (opr == "or")
			{
				searcher->orQ(split, output);
			}
			
			else if (opr == "incoming")
			{
				searcher->inc(split.front(), output);
				split.pop();

			}
			else if (opr == "outgoing")
			{
				searcher->out(split.front(), output);
				split.pop();
				
			}
			else if (opr == "print")
			{
				output << "printing " << endl;
			}
			
		
			else
			{
				output << "Invalid Query" << std::endl;
			}

			while(split.size()>0)
			{
				split.pop();
			}*/
		}

		ss.str("");
		ss.clear();
	}

	delete parse;
	delete searcher;
	input.close();
	inQuery.close();
	output.close();


	return 1;


}