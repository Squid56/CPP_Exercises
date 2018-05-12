#include "WordRepetitionCounter.h"
#include <map>

/*
 Implement getCountOf method and add the necessary code to solve the repetition count problem.
 All tests should pass after implementing the getCountOf method
 */
WordRepetitionCounter::WordRepetitionCounter(const std::string& paragraph): paragraph(paragraph){
	char *softcopy = _strdup(paragraph.c_str());
	char delimiters[] = " ,.!?:\"";
	char* next = NULL;
	char* token = strtok_s(softcopy, delimiters, &next);


	while (token != NULL) {
		if (counts.find(token) != counts.end())
			counts[token]++;
		else
			counts[token] = 1;
		token = strtok_s(NULL, delimiters, &next);
	}
	free(softcopy);
}

int WordRepetitionCounter::getCountOf(const std::string& word){
	if (counts.find(word) != counts.end())
		return counts[word];
	else
		return 0;
}