#include <iostream>
#include <string>

int match(const std::string &text, const std::string &pattern);
int findLastIndex(char ch, int j, const std::string &pattern);

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
  int i = pattern.length() - 1;
  while (i < text.length())
  {
    int k = i;
    int j = pattern.length() - 1;
    while (j >= 0)
    {
      if (text[k] == pattern[j])
      {
        k--;
        j--;
      }
      else
      {
        break;
      }
    }

    if (j < 0)
      return i - pattern.length() + 1;

    int u = findLastIndex(text[k], j - 1, pattern);
    if (u >= 0)
    {
      i = k + pattern.length() - 1 - u;
    }
    else
    {
      i = k + pattern.length();
    }
  }

  return -1;
}

int findLastIndex(char ch, int j, const std::string &pattern)
{
  for (int k = j; k >= 0; k--)
  {
    if (ch == pattern[k])
    {
      return k;
    }
  }

  return -1;
}
