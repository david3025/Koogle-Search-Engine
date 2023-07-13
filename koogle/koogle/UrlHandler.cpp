#include "UrlHandler.h"
#include <cctype> // for std::tolower
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