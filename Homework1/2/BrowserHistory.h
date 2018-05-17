#pragma once
#include "HistoryEntry.cpp"

class BrowserHistory{
    HistoryEntry* history;
    int historyLimit;
    int currentHistorySize;

public:
    BrowserHistory(int historyLimit);
    BrowserHistory(BrowserHistory const&);
    ~BrowserHistory();
    BrowserHistory& operator=(BrowserHistory const&);

    void addHistoryEntry();
    void addHistoryEntry(const HistoryEntry&);
    void print() const;
    int findNumberOfEntriesDuring(int month) const;
    int findBiggestTrafficMonth() const;
    void removeNewestEntry();

    BrowserHistory operator+(BrowserHistory const&) const;

private:
    void copy(BrowserHistory const& other);
    void erase();
    void copyHistoryIn(HistoryEntry const* history, int historySize);
};
