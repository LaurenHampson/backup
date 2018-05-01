#ifndef QUERYSEARCH_H
#define QUERYSEARCH_H

#include <map>
#include <vector>
#include <string>
#include <queue>
#include "webpage.h"
#include "parser.h"
#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <string>
#include <exception>
#include <set>
#include <iterator>



class QuerySearch
{
	public:
		QuerySearch();
		~QuerySearch();
		
		void pageParser (std::ifstream &input, Parser* parser);
		int query (const std::string n, std::queue<std::string> &q, std::ofstream &output);
		void search(const std::string n, std::ofstream &output);
		//void setMaker(const std::string n, std::set<std::string> &s );
		std::set<std::string> intersection(std::set<std::string> &s1, std::set<std::string> &s2);
		void andQ(std::queue<std::string> &q, std::ofstream &output);
		void orQ(std::queue<std::string> &q, std::ofstream &output);
		void inc(std::string n, std::ofstream &output);
		void out(std::string n, std::ofstream &output);
		//void printPage(std::string n, std::ofstream &output);

	private:
		std::map<std::string, std::set<std::string> > wordFilesMap; // maybe change from word to webpage
		//std::map<std::string, std::string > wordFilesMap; // maybe change from word to webpage
		std::map<std::string, WebPage *> fileWebPageMap;
};

#endif