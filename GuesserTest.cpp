/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};



//--------------------------REMAINING() TESTS-------------------

TEST(GuesserTest, all_remaining){
	Guesser g = Guesser("hello");
	int actual = g.remaining();
	ASSERT_EQ(3, actual);
}

TEST(GuesserTest, 2_remaining){
	Guesser g = Guesser("hello");
	g.match("wrong");
	int actual = g.remaining();
	ASSERT_EQ(2, actual);
}

TEST(GuesserTest, 1_remaining){
	Guesser g = Guesser("hello");
	g.match("wrong");
	g.match("wrong");

	int actual = g.remaining();
	ASSERT_EQ(1, actual);
}

TEST(GuesserTest, 0_remaining){
	Guesser g = Guesser("hello");
	g.match("wrong");
	g.match("wrong");
	g.match("wrong");
	int actual = g.remaining();
	ASSERT_EQ(0, actual);
}

TEST(GuesserTest, less_than_0_remaining){
	Guesser g = Guesser("hello");
	g.match("wrong");
	g.match("wrong");
	g.match("wrong");
	g.match("wrong");
	int actual = g.remaining();
	ASSERT_EQ(0, actual);
}

TEST(GuesserTest, reset_remaining){
	Guesser g = Guesser("hello");
	g.match("wrong");
	g.match("hello");
	int actual = g.remaining();
	ASSERT_EQ(3, actual);
}

TEST(GuesserTest, remaining_after_lockout){
	Guesser g = Guesser("hello");
	g.match("wrong");
	g.match("wrong");
	g.match("wrong");
	g.match("hello");
	int actual = g.remaining();
	ASSERT_EQ(0, actual);
}


//--------------------MATCH() TESTS--------------------

TEST(GuesserTest, correct_guess){
	Guesser g = Guesser("hello");
	bool actual = g.match("hello");
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, incorrect_guess){
	Guesser g = Guesser("hello");
	bool actual = g.match("wrong");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, incorrect_guess_length){
	Guesser g = Guesser("hello");
	bool actual = g.match("hellooooo");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, correct_guess_after_incorrect){
	Guesser g = Guesser("hello");
	g.match("wrong");
	bool actual = g.match("hello");
	
	ASSERT_EQ(true, actual);
}

TEST(GuesserTest, correct_guess_after_lockout){
	Guesser g = Guesser("hello");
	g.match("wrong");
	g.match("wrong");
	g.match("wrong");
	bool actual = g.match("hello");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, 1_distance_guess){
	Guesser g = Guesser("hello");
	bool actual = g.match("hel1o");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, 1_distance_guess_uppercase){
	Guesser g = Guesser("hello");
	bool actual = g.match("Hello");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, 1_distance_guess_larger){
	Guesser g = Guesser("hello");
	bool actual = g.match("helloo");
	ASSERT_EQ(false, actual);
}

TEST(GuesserTest, 1_distance_guess_smaller){
	Guesser g = Guesser("hello");
	bool actual = g.match("hell");
	ASSERT_EQ(false, actual);
}


TEST(GuesserTest, secret_too_long){
	Guesser g = Guesser("hellohellohellohellohellohellohello");
	bool actual = g.match("hellohellohellohellohellohellohe");
	ASSERT_EQ(true, actual);
}