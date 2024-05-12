#include <iostream>
#include <string>

int match(const std::string &text, const std::string &pattern);
bool isMatched(int i, const std::string &text, const std::string &pattern);

int main()
{
  std::string text, pattern;
  std::cout << "Enter a string text: ";
  std::getline(std::cin, text);
  std::cout << "Enter a string pattern: ";
  std::getline(std::cin, pattern);

  int index = match(text, pattern);
  if (index >= 0)
    std::cout << "matched at index " << index << std::endl;
  else
    std::cout << "unmatched" << std::endl;

  return 0;
}

int match(const std::string &text, const std::string &pattern)
{
  for (int i = 0; i <= text.length() - pattern.length(); i++)
  {
    if (isMatched(i, text, pattern))
      return i;
  }
  return -1;
}

bool isMatched(int i, const std::string &text, const std::string &pattern)
{
  for (int k = 0; k < pattern.length(); k++)
  {
    if (pattern[k] != text[i + k])
    {
      return false;
    }
  }
  return true;
}
