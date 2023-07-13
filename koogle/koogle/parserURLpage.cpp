#include "parserURLpage.h"
#include <iostream>
#include <regex>

void parserURLpage::makeListOfLinksFromPage(string& webpageText, vector<string>& list_of_links)
{
    std::regex linkRegex(R"((http|https)://[^\s]+)");
    std::smatch match;
    // Iterate over matches
    std::string::const_iterator searchStart(webpageText.cbegin());
    while (std::regex_search(searchStart, webpageText.cend(), match, linkRegex)) {
        std::string link = match.str();
        list_of_links.push_back(link);
        //std::cout << "Link: " << link << std::endl;
        searchStart = match.suffix().first;  // Update search position
    }
}
