#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include<vector>

class Book{
public:

    std::string id;
    std::string author;
    std::string title;
    int pages;
    Book(std::string id, std::string author, std::string title,
        int pages);
    
    void Display();
    void AddRecord(std::vector<Book>& catalog, const Book& books);
    void EditRecord(Book* Book, const std::string& author, const std::string& title, int pages);
    Book* SearchRecord(std::vector<Book>& catalog, const std::string id);
    void DeleteRecord();

};
/*adding a new record
- viewing all records
- record deletion
- record search
- record editing*/

