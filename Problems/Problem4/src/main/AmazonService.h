#pragma once
#include <memory>

class Book;

class AmazonService{
public:
	static AmazonService* getInstance();
	bool checkout(std::shared_ptr<Book> book);
private:
	static AmazonService *amazonService;
};