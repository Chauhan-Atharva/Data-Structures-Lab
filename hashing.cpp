#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

// Hash Table class using Separate Chaining for collision resolution
class HashTable {
private:
    int tableSize;
    vector<list<pair<int, string>>> table;  // Each bucket contains a list of key-value pairs
    
    // Hash function
    int hashFunction(int key) {
        return key % tableSize;
    }
    
public:
    // Constructor
    HashTable(int size) {
        tableSize = size;
        table.resize(tableSize);
    }
    
    // Insert a key-value pair
    void insert(int key, string value) {
        int index = hashFunction(key);
        
        // Check if key already exists, update if found
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;
                cout << "Updated key " << key << " with value: " << value << endl;
                return;
            }
        }
        
        // Insert new key-value pair
        table[index].push_back({key, value});
        cout << "Inserted key " << key << " at index " << index << endl;
    }
    
    // Search for a key
    bool search(int key, string& result) {
        int index = hashFunction(key);
        
        // Search in the chain at this index
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                result = pair.second;
                return true;
            }
        }
        
        return false;  // Key not found
    }
    
    // Display the hash table
    void display() {
        cout << "\n--- Hash Table ---" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << "Index " << i << ": ";
            if (table[i].empty()) {
                cout << "Empty";
            } else {
                for (auto& pair : table[i]) {
                    cout << "[" << pair.first << ": " << pair.second << "] ";
                }
            }
            cout << endl;
        }
        cout << "------------------\n" << endl;
    }
};

int main() {
    // Create hash table with size 10
    HashTable ht(10);
    
    // Insert elements
    ht.insert(15, "Alice");
    ht.insert(25, "Bob");
    ht.insert(35, "Charlie");
    ht.insert(5, "David");
    ht.insert(45, "Eve");
    ht.insert(55, "Frank");
    
    // Display hash table
    ht.display();
    
    // Search for elements
    cout << "--- Search Operations ---" << endl;
    string result;
    
    if (ht.search(25, result)) {
        cout << "Key 25 found! Value: " << result << endl;
    } else {
        cout << "Key 25 not found!" << endl;
    }
    
    if (ht.search(100, result)) {
        cout << "Key 100 found! Value: " << result << endl;
    } else {
        cout << "Key 100 not found!" << endl;
    }
    
    if (ht.search(35, result)) {
        cout << "Key 35 found! Value: " << result << endl;
    } else {
        cout << "Key 35 not found!" << endl;
    }
    
    cout << endl;
    return 0;
}
