
#include <iostream>
#include "UrlHandler.h"

using namespace std;
void printVector(const std::vector<std::string>& strings) {
    for (const std::string& str : strings) {
        std::cout << str << std::endl;
    }
}
int main()
{
    const char* file_path = "C:\\Users\\levi3\\Desktop\\david\\Koogle Search Engine\\url.txt";
    const char* url = "https://harrypotter.fandom.com/wiki/Main_Page";

    UrlHandler * handler = UrlHandler::getInastance();
    handler->setUrlPath(url);
    vector<string> *list = handler->getListOfLinks();
    printVector(*list);

    
}
