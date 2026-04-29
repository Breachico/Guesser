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

/*** Basic Match Tests ***/
TEST(GuesserTest, secret_match_true)
{
  string pass = "secret";
  Guesser object(pass);
  ASSERT_EQ( object.match(pass), true );
}
TEST(GuesserTest, secret_match_false)
{
  string pass = "secret";
  Guesser object(pass);
  ASSERT_EQ( object.match("secert"), false );
}

TEST(GuesserTest, secret_match_three_strikes_lockout)
{
  string pass = "secret";
  Guesser object(pass);
  ASSERT_EQ( object.match("secert"), false );
  ASSERT_EQ( object.match("secert"), false );
  ASSERT_EQ( object.match("secert"), false );
  ASSERT_EQ( object.match(pass), false );
}

/*** Distance Tests ***/
TEST(GuesserTest, secret_distance_match)
{
  string pass = "secret";
  Guesser object(pass);
  ASSERT_EQ( object.distance(pass), 0 );
}

TEST(GuesserTest, secret_match_distance_1_replaced)
{
  string pass = "secret";
  Guesser object(pass);
  ASSERT_EQ( object.distance("secert"), 1 );
}

TEST(GuesserTest, secret_match_distance_1_char_shorter)
{
  string pass = "secret";
  Guesser object(pass);
  ASSERT_EQ( object.distance("secre"), 1 );
}


/*** Other Constructer Test ***/
TEST(GuesserTest, secret_constructer_max_length_32)
{
  string pass = "secretsecretsecretsecretsecretsecretsecretsecretsecretsecretsecretsecret";
  Guesser object(pass);
  ASSERT_EQ( object.match(pass.substr(0,32)), true );
}


TEST(GuesserTest, secret_match_leading_spaces)
{
  string pass = "    secret";
  Guesser object(pass);
  ASSERT_EQ( object.match(pass), true );
}

TEST(GuesserTest, secret_match_trailing_spaces)
{
  string pass = "secret    ";
  Guesser object(pass);
  ASSERT_EQ( object.match(pass), true );
}

TEST(GuesserTest, secret_match_empty_string)
{
  string pass = "";
  Guesser object(pass);
  ASSERT_EQ( object.match(pass), true );
}

TEST(GuesserTest, secret_match_newline_character)
{
  string pass = "\n";
  Guesser object(pass);
  ASSERT_EQ( object.match(pass), true );
}



/***  ***/
TEST(GuesserTest, secret_match)
{
  string pass = "secret";
  Guesser object(pass);
  ASSERT_EQ( object.match("secert"), false );
}


