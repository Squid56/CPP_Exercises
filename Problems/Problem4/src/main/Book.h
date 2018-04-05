#pragma once
#include <string>

class Book{
public:
	Book(const std::string& title);

	std::string read();

private:
	std::string title;
};