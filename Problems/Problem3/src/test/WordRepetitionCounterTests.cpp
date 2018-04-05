#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <sstream>
#include "WordRepetitionCounter.h"

class WordRepetitionCounterTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
	  std::stringstream stream;
	  stream << "This was my first time. 6:35 AM in the morning. I was awake because of the jetlag, standing in this small hotel room in my PJs and it happened. "
		<< "The hotel moved. As if it were a paper construction. The potential strength of that earthquake was palpable. "
		<< "Like the touch of a giant who has decided not to hurt you but whose \"caress\" still sends you across the room."
		<< "I check the net and the monitoring of earthquakes and sure enough, I find it: a 5.3 magnitude quake off the coast of Japan. "
		<< "Nothing really but enough to make me think that I don't want to die here, that I want to be back home as quickly as possible, surrounded by friends and familiar faces. "
		<< "I've checked. There has been no earthquake recorded in Washington DC for the past 100 years." << std::endl;
	  paragraph = stream.str();

  }

  std::string paragraph;
};


TEST_F(WordRepetitionCounterTest, givenAWordShouldCountTheNumberOfTimesItIsRepeated){
	EXPECT_EQ(5, WordRepetitionCounter(paragraph).getCountOf("hotel")); // check count of hotel
}