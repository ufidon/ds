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


🏃 Implementation
---
```c++
#include <iostream>
#include <unordered_map>
#include <string>

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

    int getnchilds(TrieNode *node)
    {
        if (node)
        {
            return node->children.size();
        }
        else
            return 0;
    }

    void draw(std::string indent, TrieNode *tree, char sign = ' ')
    {
        int n = getnchilds(tree);
        int m = n / 2, c = 0, i = 0;
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
        draw("", root);
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