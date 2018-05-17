#pragma once
#include<iostream>

struct HistoryEntry{
        char *url;
        int month;

        HistoryEntry();
        HistoryEntry(char* url, int month);
        HistoryEntry(HistoryEntry const& other);
        ~HistoryEntry();
        HistoryEntry& operator=(HistoryEntry const& other);

        void print() const;
        void printMonth(int) const;
        void createEntry();

    private:
        void copy(HistoryEntry const& other);
        void copyData(char* url, int month);
        void erase();
};
