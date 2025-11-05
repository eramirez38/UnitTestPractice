/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_leading_letters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aab");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, three_leading_letters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaab");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, no_leading_repeats)
{
	Password my_password;
	int actual = my_password.count_leading_characters("abcd");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, all_same_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaaaaaa");
	ASSERT_EQ(9, actual);
}

TEST(PasswordTest, leading_numbers)
{
	Password my_password;
	int actual = my_password.count_leading_characters("111abc");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, mixed_case_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AaBc");
	ASSERT_EQ(2, actual);
}