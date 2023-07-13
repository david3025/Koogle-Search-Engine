#pragma once
#ifndef _parserURLpage_
#define _parserURLpage_
#include <vector>
#include <string>
using namespace std;
class parserURLpage
{
public:
	void makeListOfLinksFromPage(string&, vector<string>&);
};

#endif // _parserURLpage_