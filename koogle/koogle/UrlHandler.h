#pragma once
#ifndef _UrlHandler_
#define _UrlHandler_
#include "downloadPages.h"
#include "parserURLpage.h"
#include <string>
#include <vector>
#include <unordered_map>
class UrlHandler
{
public:
	static UrlHandler* getInastance();
	~UrlHandler();
	vector<string>* getListOfLinks();
	void setUrlPath(const char* URL) { urlPath.assign(URL); }
	void createLinksMap(int );
private:
	UrlHandler();
	parserURLpage* parser;
	downloadPages* downloadPage;
	string getNameOfSite();
	string urlPath;
	string extractFirstWordAfterDoubleSlash(const string& url);
	static  UrlHandler* instance;
	unordered_map<string, vector<string>> MAP;
};

#endif // _UrlHandler_