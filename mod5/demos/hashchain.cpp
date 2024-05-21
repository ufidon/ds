#include <iostream>
#include <vector>
#include <list>
#include <optional>
#include <functional>

template <typename K, typename V>
class HashTable
{
public:
  HashTable(size_t size = 101) : table(size) {}

  bool insert(const K &key, const V &value)
  {
    size_t idx = hashFunc(key);
    for (auto &entry : table[idx])
    {
      if (entry.first == key)
      {
        return false; // Key already exists
      }
    }
    table[idx].emplace_back(key, value);
    return true;
  }

  bool remove(const K &key)
  {
    size_t idx = hashFunc(key);
    auto &entries = table[idx];
    for (auto it = entries.begin(); it != entries.end(); ++it)
    {
      if (it->first == key)
      {
        entries.erase(it);
        return true;
      }
    }
    return false;
  }

  std::optional<V> find(const K &key) const
  {
    size_t idx = hashFunc(key);
    for (const auto &entry : table[idx])
    {
      if (entry.first == key)
      {
        return entry.second;
      }
    }
    return std::nullopt;
  }

private:
  std::vector<std::list<std::pair<K, V>>> table;

  size_t hashFunc(const K &key) const
  {
    std::hash<K> hashFn;
    return hashFn(key) % table.size();
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
