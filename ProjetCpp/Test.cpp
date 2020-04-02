
#include "Test.h"

#include <iostream>
#include "Article.h"
#include "Date.h"

bool Test::doTests()
{
	testArticle();
	testProvider();
    testDate();
	//TODO
	return true;
}

bool Test::testArticle() {

    //TODO test Article add and remove child
    Article a1("content");
    Article a2("a2 content", a1);
    Article a3("a3 content");
    Article a4("a4 content", std::vector<Article>{a2, a3});
    Article a5("a4 content", std::vector<Article>{a2, a3});

    std::cout
        << "===~===Test Article===~===" << std::endl
        << "a1 : " << a1.toString() << std::endl
        << "a2 : " << a2.toString() << std::endl
        << "a3 : " << a3.toString() << std::endl
        << "a4 : " << a4.toString() << std::endl
        << "a5 : " << a5.toString() << std::endl
        << "a1 == a4 : " << (a1 == a4 ? "true" : "false") << std::endl
        << "a4 == a5 : " << (a4 == a5 ? "true" : "false") << std::endl
        << std::endl;
    //TODO
    return true;
}

//TODO
bool Test::testProvider() {
    std::cout
        << "===~===Test Provider===~===" << std::endl;
    //TODO
    return true;
}

bool Test::testDate() {
    
    Date date = Date::today();
    std::cout 
        << "===~===Test Date===~===" << std::endl
        << "Today's date : " << date.toString() << std::endl;
    //TODO
    return true;
}

bool testGUI() {
    return true;
}

