#include <gtest/gtest.h>
#include "stringReverse.h"

using namespace com::sabre::as::lm;

/*
Make sure that the tests below pass
*/

	
TEST(stringReverseTests, givenAStringReverseShouldReturnReversedInputString){
	EXPECT_EQ(std::string("LOAD"), std::string(reverseString("DAOL")));
	EXPECT_EQ(std::string("INTERVIEW"), std::string(reverseString("WEIVRETNI")));
	EXPECT_EQ(std::string(""), std::string(reverseString("")));
}