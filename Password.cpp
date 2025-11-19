#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/

// Implementation B
#include <cctype>
bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}


/* Receives a string and returns a count of how many case-sensitive unique characters there are. If there are duplicate instances of the same character it should only count as a single character. Even if characters look similar, as long as they have distinct ASCII values, they should qualify as unique characters. */
unsigned int Password::unique_characters(string str)
{
  bool char_set[256] = {false};
  unsigned int count = 0;
  for (char c : str)
  {
    if (!char_set[(unsigned char)c])
    {
      char_set[(unsigned char)c] = true;
      count++;
    }
  }
  return count;
}