# Trie
- Pronounced as `"try"`
- Specialized `tree-like data structure` used to store `a dynamic set of strings`
  - where the keys are usually strings
- Particularly useful for tasks involving `prefix matching and autocompletion`
  - an excellent choice for implementing `dictionaries, spell checkers, and search engines`


Key Characteristics of Tries
---
- **Node Structure**: Each node represents a `single character` of a string
  - The `root` node is typically `empty` or represents the `start` of the string
- **Edges**: Each edge represents a `character transition` from one node to another
- **End of Word**: Nodes may also have a `flag` indicating whether they represent the end of a valid word or string in the Trie
- **Alphabet Size**: The number of children a node has is typically equal to the number of possible characters (alphabet size)
  - e.g., for the English alphabet, each node can have up to 26 children


Operations on Tries
---
- **Insertion** inserts a word into a Trie:
  1. Start from the root node
  2. For each character in the word, check if there is an edge (child node) corresponding to the character
  3. If the edge exists, move to the child node. If not, create a new node and add it as a child
  4. Mark the final node of the word as an end of word node
- **Search** searches for a word in a Trie:
  1. Start from the root node
  2. For each character in the word, move to the corresponding child node
  3. If at any point, the required child node does not exist, the word is not in the Trie
  4. If you reach the end of the word, check if the current node is marked as the end of a word
- **Deletion** deletes a word from a Trie:
  1. Searching for the word
  2. If the word is found, unmark the end of the word flag
  3. Optionally, remove nodes that are no longer part of any word (pruning)


Advantages and Disadvantages of Tries
---
- **Advantages**
  - **Fast Lookup**: Provides fast lookup times for words, typically O(m), where m is the length of the word
  - **Prefix Matching**: Efficiently supports prefix matching and autocompletion
  - **Memory Efficient**: Can be more memory efficient for storing many words with common prefixes
- **Disadvantages**
  - **Space Complexity**: Can use a lot of memory if the set of strings does not share many common prefixes
  - **Implementation Complexity**: More complex to implement compared to other data structures like hash tables


💡Intuition
---
- [Animate a trie](https://www.cs.usfca.edu/~galles/visualization/Trie.html)


🏃 Implementation based on map
---
```c++
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class TrieNode
{
public:
  std::unordered_map<char, TrieNode *> children;
  bool isEndOfWord;

  TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
  TrieNode *root;
  static int constexpr ALPHABET_SIZE = 26;

  bool deleteHelper(TrieNode *currentNode, const std::string &word, int depth)
  {
    if (depth == word.size())
    {
      // If the end of the word is reached, mark it as not end of word
      if (!currentNode->isEndOfWord)
      {
        return false; // Word not found
      }
      currentNode->isEndOfWord = false;
      return currentNode->children.empty(); // If no children, this node can be deleted
    }

    char ch = word[depth];
    TrieNode *childNode = currentNode->children[ch];
    if (childNode == nullptr)
    {
      return false; // Word not found
    }

    bool shouldDeleteChild = deleteHelper(childNode, word, depth + 1);

    if (shouldDeleteChild)
    {
      currentNode->children.erase(ch);
      delete childNode;
      return currentNode->children.empty() && !currentNode->isEndOfWord;
    }
    return false;
  }

  void draw(std::string indent, TrieNode *tree, char sign = ' ')
  {
    int n = tree->children.size();
    int m = n / 2, c = 0, i = 0;
    /*
    if (tree)
    {
      for (; i < ALPHABET_SIZE; i++)
      {
        if (tree->children.count((char)(i + 'a')))
        {
          if (c < m)
          {
            std::cout << indent + sign + "--" << (char)(i + 'a') << "(" << std::noboolalpha << tree->children[(char)(i + 'a')]->isEndOfWord << ")" << std::endl;
            draw(indent + "   ", tree->children[(char)(i + 'a')], '`');
          }
          else
          {
            std::cout << indent + sign + "--" << (char)(i + 'a') << "(" << std::noboolalpha << tree->children[(char)(i + 'a')]->isEndOfWord << ")" << std::endl;
            draw(indent + "   ", tree->children[(char)(i + 'a')], '`');
          }

          c++;
        }
      }
    }
    */
    for (auto it : tree->children)
    {
      if (c < m)
      {
        std::cout << indent + sign + "--" << it.first << "(" << std::noboolalpha << it.second->isEndOfWord << ")" << std::endl;
        draw(indent + "   ", it.second, '`');
      }
      else
      {
        std::cout << indent + sign + "--" << it.first << "(" << std::noboolalpha << it.second->isEndOfWord << ")" << std::endl;
        draw(indent + "   ", it.second, '`');
      }
    }
  }

  void print(TrieNode *node, std::string prefix) const
  {
    if (node->isEndOfWord)
    {
      std::cout << prefix << " ";
    }
    for (auto it : node->children)
    {
      print(it.second, prefix + it.first);
    }
  }

  void collectWords(TrieNode *node, std::string prefix, std::vector<std::string> &words)
  {
    if (node->isEndOfWord)
    {
      words.push_back(prefix);
    }
    for (auto it : node->children)
    {
      collectWords(it.second, prefix + it.first, words);
    }
  }

public:
  Trie()
  {
    root = new TrieNode();
  }

  ~Trie()
  {
    // Destructor to clean up dynamically allocated memory
    deleteTrie(root);
  }

  void deleteTrie(TrieNode *node)
  {
    if (!node)
      return;
    for (auto &pair : node->children)
    {
      deleteTrie(pair.second);
    }
    delete node;
  }

  void insert(const std::string &word)
  {
    TrieNode *currentNode = root;
    for (char ch : word)
    {
      if (currentNode->children.find(ch) == currentNode->children.end())
      {
        currentNode->children[ch] = new TrieNode();
      }
      currentNode = currentNode->children[ch];
    }
    currentNode->isEndOfWord = true;
  }

  bool search(const std::string &word)
  {
    TrieNode *currentNode = root;
    for (char ch : word)
    {
      if (currentNode->children.find(ch) == currentNode->children.end())
      {
        return false;
      }
      currentNode = currentNode->children[ch];
    }
    return currentNode->isEndOfWord;
  }

  bool startsWith(const std::string &prefix)
  {
    TrieNode *currentNode = root;
    for (char ch : prefix)
    {
      if (currentNode->children.find(ch) == currentNode->children.end())
      {
        return false;
      }
      currentNode = currentNode->children[ch];
    }
    return true;
  }

  bool deleteWord(const std::string &word)
  {
    return deleteHelper(root, word, 0);
  }

  void draw()
  {
    std::cout << "Stored words: ";
    print();
    draw("", root);
    std::cout << std::endl;
  }

  void getAllWords(std::vector<std::string> &words)
  {
    collectWords(root, "", words);
  }

  void print()
  {
    print(root, "");
    std::cout << std::endl;
  }
};

int main()
{
  Trie trie;
  trie.draw();
  trie.insert("cat");
  trie.draw();
  trie.insert("car");
  trie.draw();
  trie.insert("dog");
  trie.draw();

  std::cout << std::boolalpha;
  std::cout << "Search for 'cat': " << trie.search("cat") << std::endl;    // true
  std::cout << "Search for 'cap': " << trie.search("cap") << std::endl;    // false
  std::cout << "Starts with 'ca': " << trie.startsWith("ca") << std::endl; // true
  std::cout << "Starts with 'do': " << trie.startsWith("do") << std::endl; // true
  std::cout << "Starts with 'da': " << trie.startsWith("da") << std::endl; // false

  std::cout << "Delete 'cat': " << trie.deleteWord("cat") << std::endl; // true
  trie.draw();
  std::cout << "Search for 'cat' after deletion: " << trie.search("cat") << std::endl;          // false
  std::cout << "Search for 'car' after deletion of 'cat': " << trie.search("car") << std::endl; // true
  std::cout << "Search for 'dog': " << trie.search("dog") << std::endl;                         // true

  return 0;
}
```

🏃 Implementation based on array
---
```c++
#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define ALPHABET_SIZE 26

class TrieNode
{
public:
  TrieNode()
  {
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
      // index [0-25] <--> letter [a-z]
      children[i] = nullptr;
    }

    endOfWord = false;
  }

  // data member
  TrieNode *children[ALPHABET_SIZE];
  bool endOfWord;
};

class Trie
{
public:
  Trie();
  ~Trie();
  void insert(const std::string &word);
  bool search(const std::string &word) const;

  Trie(const std::vector<std::string> &);
  int count_words() const;
  int count_words_by_length() const;
  void print() const;
  int longest_word_length() const;
  std::string longest_word() const;
  void longest_word(TrieNode *node, std::string &curwd, std::string &longwd) const;
  std::vector<std::string> words_of_length(int len) const;

private:
  TrieNode *root;
  void print(TrieNode *node, std::string prefix) const;
  void deleteTrie(TrieNode *node);
  int count_words(TrieNode *node) const;
  int longest_word_length(TrieNode *node, int curlen) const;
  void words_of_length(TrieNode *node, std::string curword, std::vector<std::string> &result, int len) const;
};

Trie::Trie(const std::vector<std::string> &words) : root(nullptr)
{
  for (auto w : words)
  {
    insert(w);
  }
}

int Trie::count_words() const
{
  return count_words(root);
}
int Trie::count_words(TrieNode *node) const
{
  if (node == nullptr)
    return 0;

  int cw = 0;

  if (node->endOfWord)
  {
    cw++;
  }

  for (size_t i = 0; i < ALPHABET_SIZE; i++)
  {
    if (node->children[i])
    {
      cw += count_words(node->children[i]);
    }
  }

  return cw;
}

std::string Trie::longest_word() const
{
  std::string cw, lw;
  longest_word(root, cw, lw);

  return lw;
}
void Trie::longest_word(TrieNode *node, std::string &curwd, std::string &longwd) const
{
  if (node == nullptr)
    return;

  if (node->endOfWord)
  {
    if (curwd.length() > longwd.length())
    {
      longwd = curwd;
    }
  }

  for (size_t i = 0; i < ALPHABET_SIZE; i++)
  {
    if (node->children[i])
    {
      curwd += 'a' + i;
      longest_word(node->children[i], curwd, longwd);
      curwd.pop_back();
    }
  }
}

std::vector<std::string> Trie::words_of_length(int len) const
{
  std::vector<std::string> rst;
  std::string cw;
  words_of_length(root, cw, rst, len);

  return rst;
}
void Trie::words_of_length(TrieNode *node, std::string curword, std::vector<std::string> &result, int len) const
{
  if (node == nullptr)
    return;

  if (curword.length() == len && node->endOfWord)
    result.push_back(curword);

  if (curword.length() < len)
  {
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
      if (node->children[i])
      {
        curword += 'a' + i;
        words_of_length(node->children[i], curword, result, len);
        curword.pop_back();
      }
    }
  }
}

int Trie::longest_word_length(TrieNode *node, int curlen) const
{
  if (node == nullptr)
  {
    return 0;
  }

  if (node->endOfWord)
  {
    return curlen;
  }

  int maxlen = curlen;
  for (size_t i = 0; i < ALPHABET_SIZE; i++)
  {
    if (node->children[i])
    {
      maxlen = std::max(maxlen, longest_word_length(node->children[i], curlen + 1));
    }
  }

  return maxlen;
}

int Trie::longest_word_length() const
{
  return longest_word_length(root, 0);
}

void Trie::print() const
{
  print(root, "");
}

void Trie::print(TrieNode *node, std::string prefix) const
{
  if (node)
  {
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
      if (node->children[i])
      {
        if (node->children[i]->endOfWord)
          std::cout << prefix + (char)('a' + i) << std::endl;

        print(node->children[i], prefix + (char)('a' + i));
      }
    }
  }
}

Trie::Trie() : root(nullptr) {}
Trie::~Trie() { deleteTrie(root); }
void Trie::deleteTrie(TrieNode *node)
{
  if (node)
  { // post order
    for (size_t i = 0; i < ALPHABET_SIZE; i++)
    {
      if (node->children[i])
        deleteTrie(node->children[i]);
    }
    delete node;
  }
}

void Trie::insert(const std::string &word)
{
  if (root == nullptr)
  {
    root = new TrieNode();
  }
  TrieNode *cur = root;

  for (int i = 0; i < word.size(); i++)
  {
    // index [0-25] <--> letter [a-z]
    int index = word[i] - 'a';
    if (cur->children[index] == nullptr)
    {
      cur->children[index] = new TrieNode();
    }
    // move down
    cur = cur->children[index];
  }
  cur->endOfWord = true;
}

bool Trie::search(const std::string &word) const
{
  if (root == nullptr)
  {
    return false;
  }
  TrieNode *cur = root;

  for (int i = 0; i < word.size(); i++)
  {
    // index [0-25] <--> letter [a-z]
    int index = word[i] - 'a';
    if (cur->children[index] == nullptr)
    {
      return false;
    }

    cur = cur->children[index];
  }

  return (cur->endOfWord);
}

int main()
{
  std::vector<std::string> words = {
      "florida", "virginia", "texas", "wisconsin",
      "mexico", "washington", "carolina", "georgia",
      "michigan", "hawaii"};

  Trie tr(words);
  std::cout << "There are " << tr.count_words() << " words in the Trie" << std::endl;
  std::cout << "Here are the words:\n";
  tr.print();
  std::cout << "The longest word has " << tr.longest_word_length() << " characters\n";
  std::cout << "The longest word is " << tr.longest_word() << std::endl;

  int wl = 6;
  auto res = tr.words_of_length(wl);
  std::cout << "Words of length " << wl << ": ";
  for (auto w : res)
  {
    std::cout << w << " ";
  }
  std::cout << std::endl;

  return 0;
}
```