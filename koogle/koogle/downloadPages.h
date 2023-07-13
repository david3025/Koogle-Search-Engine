#pragma once
#ifndef _downloadPages_
#define _downloadPages_
using namespace std;
#include <string>
class downloadPages
{
public:
	static downloadPages* getInstance();
	void writeURLTextToFile(const char* file_path, const char* uml);
	void printURL(const char* uml);
	void writeURLtextToString(const char* URL, string& s);
private:
	void writeStringToFile(const char* filePath, const string* content);
	
	static downloadPages* downloadPages_;
};
#endif // _downloadPages_