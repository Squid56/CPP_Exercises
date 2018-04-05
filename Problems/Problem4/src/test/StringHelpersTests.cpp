#include <StringHelpers.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(StringHelpersTests, testEqualsIgnoreCase){
	EXPECT_TRUE(StringHelpers::equalsIgnoreCase("sImPle DeSIGn", "Simple Design"));
	EXPECT_FALSE(StringHelpers::equalsIgnoreCase("sImPle DeSIGn", "Cimple Design"));
}

TEST(StringHelpersTests, testToUpper){
	EXPECT_STREQ("SIMPLE DESIGN", StringHelpers::toUpper("sImPle DeSIGn").c_str());
	EXPECT_STREQ("SIMPLE?*&!2", StringHelpers::toUpper("sImPle?*&!2").c_str());
}

TEST(StringHelpersTests, testLtrim){
	EXPECT_STREQ("SIMPLE DESIGN    ", StringHelpers::ltrim("    SIMPLE DESIGN    ").c_str());
}

TEST(StringHelpersTests, testRtrim){
	EXPECT_STREQ("    SIMPLE DESIGN", StringHelpers::rtrim("    SIMPLE DESIGN    ").c_str());
}

TEST(StringHelpersTests, testTrim){
	EXPECT_STREQ("SIMPLE DESIGN", StringHelpers::trim("    SIMPLE DESIGN    ").c_str());
}


TEST(StringHelpersTests, testReplace){
	EXPECT_STREQ("Simple Design", StringHelpers::replace("Coplex Design", "Coplex", "Simple").c_str());
	EXPECT_STREQ("COPLEX Design", StringHelpers::replace("COPLEX Design", "Coplex", "Simple").c_str());
}


TEST(StringHelpersTests, testReplace_NotEqualStrings){
	EXPECT_THROW(StringHelpers::replace("COMPLEX Design", "Complex", "Simple"), std::runtime_error);
}
