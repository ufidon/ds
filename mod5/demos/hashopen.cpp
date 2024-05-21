#include <iostream>
#include <vector>
#include <optional>

enum class EntryState
{
  Empty,
  Occupied,
  Deleted
};

template <typename K, typename V>
class HashTable
{
public:
  HashTable(size_t size = 101) : table(size), currentSize(0) {}

  bool insert(const K &key, const V &value)
  {
    if (currentSize >= table.size() / 2)
    {
      rehash();
    }

    size_t idx = findPos(key);
    if (table[idx].state == EntryState::Occupied)
    {
      return false; // Key already exists
    }

    table[idx] = {key, value, EntryState::Occupied};
    currentSize++;
    return true;
  }

  bool remove(const K &key)
  {
    size_t idx = findPos(key);
    if (table[idx].state != EntryState::Occupied)
    {
      return false;
    }

    table[idx].state = EntryState::Deleted;
    currentSize--;
    return true;
  }

  std::optional<V> find(const K &key) const
  {
    size_t idx = findPos(key);
    if (table[idx].state == EntryState::Occupied)
    {
      return table[idx].value;
    }
    return std::nullopt;
  }

private:
  struct HashEntry
  {
    K key;
    V value;
    EntryState state = EntryState::Empty;
  };

  std::vector<HashEntry> table;
  size_t currentSize;

  size_t hashFunc(const K &key) const
  {
    std::hash<K> hashFn;
    return hashFn(key) % table.size();
  }

  size_t findPos(const K &key) const
  {
    size_t currentPos = hashFunc(key);
    size_t stepSize = 1;

    while (table[currentPos].state != EntryState::Empty &&
           table[currentPos].key != key)
    {
      currentPos += stepSize; // Linear probing
      if (currentPos >= table.size())
      {
        currentPos -= table.size();
      }
    }
    return currentPos;
  }

  void rehash()
  {
    std::vector<HashEntry> oldTable = table;
    table.resize(nextPrime(2 * oldTable.size()));
    for (auto &entry : table)
    {
      entry.state = EntryState::Empty;
    }

    currentSize = 0;
    for (const auto &entry : oldTable)
    {
      if (entry.state == EntryState::Occupied)
      {
        insert(entry.key, entry.value);
      }
    }
  }

  bool isPrime(size_t n) const
  {
    if (n <= 1)
      return false;
    if (n <= 3)
      return true;
    if (n % 2 == 0 || n % 3 == 0)
      return false;
    for (size_t i = 5; i * i <= n; i += 6)
    {
      if (n % i == 0 || n % (i + 2) == 0)
        return false;
    }
    return true;
  }

  size_t nextPrime(size_t n) const
  {
    while (!isPrime(n))
    {
      n++;
    }
    return n;
  }
};

int main()
{
  HashTable<std::string, int> ht;

  ht.insert("Alice", 1);
  ht.insert("Bob", 2);
  ht.insert("Charlie", 3);

  auto result = ht.find("Alice");
  if (result)
  {
    std::cout << "Alice: " << *result << std::endl;
  }
  else
  {
    std::cout << "Alice not found" << std::endl;
  }

  ht.remove("Alice");
  result = ht.find("Alice");
  if (result)
  {
    std::cout << "Alice: " << *result << std::endl;
  }
  else
  {
    std::cout << "Alice not found" << std::endl;
  }

  return 0;
}
