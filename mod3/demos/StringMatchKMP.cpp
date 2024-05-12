#include <iostream>
#include <vector>
#include <string>

std::vector<int> getFailure(const std::string &pattern);
int match(const std::string &text, const std::string &pattern);

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

std::vector<int> getFailure(const std::string &pattern)
{
  std::vector<int> fail(pattern.size());
  int i = 1;
  int k = 0;
  while (i < pattern.size())
  {
    if (pattern[i] == pattern[k])
    {
      fail[i] = k + 1;
      i++;
      k++;
    }
    else if (k > 0)
    {
      k = fail[k - 1];
    }
    else
    {
      i++;
    }
  }
  return fail;
}

int match(const std::string &text, const std::string &pattern)
{
  std::vector<int> fail = getFailure(pattern);
  int i = 0;
  int k = 0;
  while (i < text.size())
  {
    if (text[i] == pattern[k])
    {
      if (k == pattern.size() - 1)
      {
        return i - pattern.size() + 1;
      }
      i++;
      k++;
    }
    else
    {
      if (k > 0)
      {
        k = fail[k - 1];
      }
      else
      {
        i++;
      }
    }
  }
  return -1;
}
