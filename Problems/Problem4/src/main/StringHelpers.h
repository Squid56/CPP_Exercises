#pragma once

#include <string>
#include <regex>
#include <sstream>
#include <stdexcept>

class StringHelpers{
public:
	static inline bool equalsIgnoreCase(const std::string& lhs, const std::string& rhs){
		return toUpper(lhs) == toUpper(rhs);
	}

	static inline std::string toUpper(const std::string& str){
		std::string s(str);
		std::transform(s.begin(), s.end(), s.begin(), toupper);
		return s;
	}

	static inline  std::string replace(const std::string& str, const std::string& findStr, const std::string& replaceStr){
		if (findStr.length() != replaceStr.length()){
			std::stringstream buf;
			buf << "Find String: " << findStr << " and Replacement String: " << replaceStr << " should be of same length";
			throw std::runtime_error(buf.str());
		}

		std::string s(str);
		size_t index = s.find(findStr);
		while (index != std::string::npos){
			s.replace(index, replaceStr.length(), replaceStr);
			index = s.find(findStr);
		}
		return s;
	}

	static inline std::string ltrim(const std::string &str) {
		std::string s(str);
		s.erase(0,s.find_first_not_of(' '));
		return s;

	}
	static bool isNotSpace(char c){
		return !std::isspace(c, std::locale());
	}
	static inline std::string rtrim(const std::string &str) {
		std::string s(str);
		s.erase(std::find_if(s.rbegin(), s.rend(), isNotSpace).base(), s.end());
		return s;

	}

	static inline std::string trim(const std::string& str){
		return rtrim(ltrim(str));
	}

};