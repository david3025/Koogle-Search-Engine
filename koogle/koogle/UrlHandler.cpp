#include "UrlHandler.h"
#include <algorithm>
#include <iostream>
#include <cctype> // for std::tolower
#include <queue>
UrlHandler::UrlHandler()
{
    parserURLpage* parser = new parserURLpage();
    downloadPages* downloadPage = new downloadPages();
}
UrlHandler* UrlHandler::instance = nullptr;
UrlHandler* UrlHandler::getInastance()
{
    if (!instance) {
        instance = new UrlHandler();
    }
    return instance;
}

UrlHandler::~UrlHandler()
{
    delete parser;
    delete downloadPage;
}

vector<string>* UrlHandler::getListOfLinks()
{
    string webpageText;
    vector<string>* list_of_links = new vector<string>;
    downloadPage->writeURLtextToString(urlPath.c_str(), webpageText);
    parser->makeListOfLinksFromPage(webpageText, *list_of_links);
    return list_of_links;
}

void UrlHandler::createLinksMap(int maxPages)
{
    /*
    parser->makeListOfLinksFromPage(urlPath, MAP[urlPath], maxPages);
   
    for (int i = 0; i < MAP[urlPath].size(); i++) {
        //if the page already exist continue
        if (std::count(MAP[urlPath].begin(), MAP[urlPath].end(), MAP[urlPath][i]), maxPages) {
            continue;
        }
        //if alredy pages remaind to add to map
        if (maxPages) {
            parser->makeListOfLinksFromPage(MAP[urlPath][i], MAP[MAP[urlPath][i]], maxPages);
        }  
    }*/

    //Initialization vector to save the uniq url's
    queue<string> queue;
    queue.push(urlPath);
    while (!queue.empty()) {
        size_t size = MAP.size();
        if (size >= maxPages) {
            cout << "max of page :" << size << endl;
            break;
        }
        //add the url to the map
        string webpageText ;
        cout << "\n\npage :" << size << endl;
        downloadPage->writeURLtextToString(urlPath.c_str(), webpageText);
        parser->makeListOfLinksFromPage(webpageText, MAP[queue.front()]);
        for (int i = 0; i < MAP[queue.front()].size(); i++) {
            queue.push(MAP[queue.front()][i]);
       }
        queue.pop();
    }
    

    //Initialization variable counter to 1, and total to be 1
    //go over all vectors from counter to total, and for each of them add him to map provided it does not appear on the map, total++
    //after all the links have been added to the map - counter++
    //if total -- counter or total--max return



}


std::string UrlHandler::extractFirstWordAfterDoubleSlash(const std::string& url) {
    std::size_t doubleSlashPos = url.find("//");
    if (doubleSlashPos == std::string::npos) {
        // "//" not found, return an empty string or handle the error as needed
        return "";
    }

    std::size_t startWordPos = doubleSlashPos + 2; // Position of the character after "//"
    std::size_t dotPos = url.find(".", startWordPos);

    if (dotPos == std::string::npos) {
        // Dot not found, return an empty string or handle the error as needed
        return "";
    }

    std::size_t wordLength = dotPos - startWordPos;
    std::string word = url.substr(startWordPos, wordLength);

    return word;
}