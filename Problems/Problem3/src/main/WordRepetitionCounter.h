#pragma once
#include <string>

class WordRepetitionCounter {
public:
	WordRepetitionCounter(const std::string& paragraph);
	int getCountOf(const std::string& word);
private:
	std::string paragraph;
};