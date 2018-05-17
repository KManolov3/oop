#include "BrowserHistory.h"
#include "NotSTL.h"
#define DEFAULT_HISSTORY_LIMIT 5
#define MAX_HISTORY_LIMIT 100
#define NUMBER_OF_MONTHS 12

BrowserHistory::BrowserHistory(int historyLimit = DEFAULT_HISSTORY_LIMIT){
    if(historyLimit>MAX_HISTORY_LIMIT){
        std::cerr<<"Maximum history limit is "<<MAX_HISTORY_LIMIT<<", setting to "<<MAX_HISTORY_LIMIT<<" by default\n";
        this->historyLimit = MAX_HISTORY_LIMIT;
    } else
        this->historyLimit = historyLimit;
    this->currentHistorySize = 0;
    this->history = new HistoryEntry[historyLimit];
}

BrowserHistory::BrowserHistory(BrowserHistory const& other){
    copy(other);
}

BrowserHistory::~BrowserHistory(){
    erase();
}

BrowserHistory& BrowserHistory::operator=(BrowserHistory const& other){
    if(this!=&other){
        erase();
        copy(other);
    }

    return *this;
}

void BrowserHistory::copy(BrowserHistory const& other){
    this->historyLimit = other.historyLimit;
    this->currentHistorySize = other.currentHistorySize;
    this->history = new HistoryEntry[other.historyLimit];
    for(int i=0; i<other.currentHistorySize; i++){
        history[i] = other.history[i];
    }
}

void BrowserHistory::erase(){
    delete[] history;
}

void BrowserHistory::addHistoryEntry(){
    char cont[2];
    do{
        if(currentHistorySize == historyLimit){
            std::cerr<<"History limit reached!\n";
            return;
        }

        history[currentHistorySize].createEntry();
        currentHistorySize++;

        std::cout<<"Continue? Y/N:";
        std::cin>>cont;
        if(currentHistorySize == historyLimit){
            std::cerr<<"History limit reached!\n";
            return;
        }
    }while(cont[0] == 'Y');
}

void BrowserHistory::addHistoryEntry(HistoryEntry const& historyEntry){
    if(currentHistorySize == historyLimit){
            std::cerr<<"History limit reached!\n";
            return;
    }

    history[currentHistorySize] = historyEntry;
    currentHistorySize++;
}

void BrowserHistory::print() const{
    for(int i=0; i<currentHistorySize; i++){
        history[i].print();
    }
}

int BrowserHistory::findNumberOfEntriesDuring(int month) const{
    int numberOfEntriesDuringMonth = 0;
    for(int i=0; i<currentHistorySize; i++)
        if(history[i].month == month)
            numberOfEntriesDuringMonth++;

    return numberOfEntriesDuringMonth;
}

int BrowserHistory::findBiggestTrafficMonth() const{
    int numberOfEntriesDuringMonths[NUMBER_OF_MONTHS+1] = {0};

    for(int i=0; i<currentHistorySize; i++)
        numberOfEntriesDuringMonths[history[i].month]++;

    int highestTrafficMonth=1, maxEntries=0;
    for(int i=1; i<=NUMBER_OF_MONTHS; i++){
        if(numberOfEntriesDuringMonths[i] > maxEntries){
            maxEntries = numberOfEntriesDuringMonths[i];
            highestTrafficMonth = i;
        }
    }

    return highestTrafficMonth;
}

void BrowserHistory::removeNewestEntry(){
    --currentHistorySize;
}

BrowserHistory BrowserHistory::operator+(BrowserHistory const& other) const{
    if(this->currentHistorySize + other.currentHistorySize > MAX_HISTORY_LIMIT){
        std::cerr<<"Trying to create too large object. Failed operation.\n";
        return BrowserHistory();
    }

    BrowserHistory combinedHistory(this->historyLimit + other.historyLimit);
    combinedHistory.copyHistoryIn(this->history, this->currentHistorySize);
    combinedHistory.copyHistoryIn(other.history, other.currentHistorySize);

    return combinedHistory;
}

void BrowserHistory::copyHistoryIn(HistoryEntry const* history, int historySize){
    for(int i=0; i<historySize; i++)
        this->addHistoryEntry(history[i]);
}
