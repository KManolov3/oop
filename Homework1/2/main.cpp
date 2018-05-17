#include <iostream>
#include "BrowserHistory.cpp"
int main(){
    BrowserHistory history(4);
    history.addHistoryEntry(HistoryEntry("Facebook.com",5));
    history.addHistoryEntry(HistoryEntry("Google.com",2));
    history.addHistoryEntry(HistoryEntry("Youtube.com",2));
    history.addHistoryEntry(HistoryEntry("Gosho4.html",2)); //Fill the history with a few objects

    std::cout<<"Now we are going to try to go over the history limit:\n";
    history.addHistoryEntry(HistoryEntry("InvalidObject.com", 5));

    std::cout<<"Let's try to create a history object with over 100 elements:\n";
    BrowserHistory largeHistory(105);

    history.removeNewestEntry();
    history.addHistoryEntry(HistoryEntry("InvalidMonth.com", 15)); //Adding an address with an invalid month

    std::cout<<"Print our history:\n";
    history.print();

    std::cout<<"Let's find the number of websites visited in February.\nExpected Result: 2\nActual Result: "<<history.findNumberOfEntriesDuring(2)<<std::endl;

    std::cout<<"Month with the most websites visited: \n"<<history.findBiggestTrafficMonth()<<std::endl;

    BrowserHistory firefoxHistory;
    firefoxHistory.addHistoryEntry(HistoryEntry("ForgotIncognitoMode.giggity", 9));

    std::cout<<"Concatenate histories and print them\n";

    BrowserHistory combined = history + firefoxHistory;
    combined.print();

    return 0;
}
