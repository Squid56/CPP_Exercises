#pragma once
#include <string>
#include <map>

class WordRepetitionCounter {
public:
	WordRepetitionCounter(const std::string& paragraph);
	int getCountOf(const std::string& word);
private:
	std::string paragraph;
	std::map<std::string, unsigned int> counts;
};