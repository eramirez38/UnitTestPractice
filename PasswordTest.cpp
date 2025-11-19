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
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AbCdef");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, all_lower_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcdef");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, all_upper_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ABCDEF");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, empty_string_mixed_case)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, lower_and_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abc123");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, lower_upper_symbols_and_numbers)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aB&.123");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, same_characters)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("aaaaaa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, all_unique_characters)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("abcdef");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, same_characters_different_case)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("Aa");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, empty_string_unique_chars)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, numbers_and_symbols)
{
	Password my_password;
	unsigned int actual = my_password.unique_characters("123!@#");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, upper_special_characters)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("A{}");
	ASSERT_EQ(false, actual);
}
