#include <Book.h>

Book::Book(const std::string& title ):title(title){
}

std::string Book::read(){
	return std::string("Read book: " + title);
}