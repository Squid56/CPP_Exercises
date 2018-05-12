#pragma once

namespace com{
	namespace sabre{
		namespace as{
			namespace lm{

/*
	Implement reverseString 
*/
		char* reverseString(char* input){
			unsigned int orig_len = strlen(input);
			char *tmp = new char[orig_len + 1];
			memset(tmp, 0x00, orig_len +1);
			for (unsigned int x = 1; x <= orig_len; x++) {
				tmp[x-1] = input[orig_len - x];
			}
			return tmp;
				}
			}
		}
	}
}
