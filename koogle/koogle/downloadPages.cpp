
#pragma comment(lib, "urlmon.lib")

#include "downloadPages.h"
#include <urlmon.h>
#include <cstdio>
#include <iostream>
#include <fstream>


#define getURL URLOpenBlockingStreamA
downloadPages* downloadPages::downloadPages_ = nullptr;;
downloadPages* downloadPages::getInstance()
{
    if (downloadPages_ == nullptr) {
        downloadPages_ = new downloadPages();
    }
    return downloadPages_;
}

void downloadPages::writeURLTextToFile(const char* file_path, const char* URL)
{
    string s;
    writeURLtextToString(URL, s);
    writeStringToFile(file_path,&s);
}


void downloadPages::printURL(const char* URL)
{
    string s;
    writeURLtextToString(URL, s);
    cout << s<<endl;
}

void downloadPages::writeStringToFile(const char* filePath, const string* content)
{
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << *content;
        file.close();
        std::cout << "Successfully wrote the string to the file.\n";
    }
    else {
        std::cerr << "Unable to open the file for writing.\n";
    }
}

void downloadPages::writeURLtextToString(const char* URL, string &s)
{
    // Windows IStream interface 
    IStream* stream;

    // make a call to the URL 
    // a non-zero return means some error 
    if (getURL(0, URL, &stream, 0, 0))
    {

        cout << "Error occured.";

        cout << "Check internet";

        cout << "Check URL. Is it correct?";

    }

    // this char array will be cyclically 
    // filled with bytes from URL 
    char buff[100];

    unsigned long bytesRead;

    while (true)
    {

        // Reads a specified number of bytes 
        // from the stream object into char 
        // array and stores the actual 
        // bytes read to "bytesRead" 
        stream->Read(buff, 100, &bytesRead);

        if (0U == bytesRead)
        {

            break;

        }

        // append and collect to the string 
        s.append(buff, bytesRead);

    };

    // release the interface 
    // good programming practice 
    stream->Release();
}
