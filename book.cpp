#include "book.h"



Book::Book(std::string id, std::string author, std::string title,
	int pages) {
	this->id = id;
	this->author = author;
	this->title = title;
	this->pages = pages;

}
void Book::Display() {
	std::cout << Book::id << " " << Book::author << " " << Book::title << " " << Book::pages << " ";

}

void Book::AddRecord(std::vector<Book>& catalog, const Book& books)
{
	catalog.push_back(books);
}

void Book::EditRecord(Book * Book,const std::string& author ,const std::string& title,int pages ) {
	if (Book) {
		Book->author = author;
		Book->title = title;
		Book->pages = pages;

	}

}

Book* Book::SearchRecord(std::vector<Book>& catalog, const std::string id) {
	for (auto& Book : catalog) {
		if (Book.id == id) {
			return &Book;
		}
	}
	
	
	return 0;
}

void Book::DeleteRecord() {

}


int main() {

	std::ifstream CBooks;
	CBooks.open("C:\\Users\\Rashad\\Desktop\\git_edu\\book.txt");
	if (CBooks.is_open()) {
		

		CBooks.close();
	}
	else {
		std::cout << "there was a issue while opening the file" << std::endl;
	}
	
	return 0;
}