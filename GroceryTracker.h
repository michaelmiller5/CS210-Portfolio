#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

// GroceryTracker class declaration
// Handles reading item data, frequency lookup, display, and file output
class GroceryTracker {
public:
    // Constructor: loads input file and writes frequency.dat backup
    GroceryTracker(const std::string& inputFileName);

    // Menu Option 1: Returns frequency of a single item (case-sensitive)
    int GetItemFrequency(const std::string& item) const;

    // Menu Option 2: Prints all items with their numeric frequency
    void PrintAllFrequencies() const;

    // Menu Option 3: Prints all items as a text-based histogram using asterisks
    void PrintHistogram() const;

private:
    // Stores each item and the number of times it was purchased
    std::map<std::string, int> itemFrequencyMap;

    // Reads the input file and populates itemFrequencyMap
    void LoadDataFromFile(const std::string& inputFileName);

    // Writes frequency data to frequency.dat for backup
    void WriteFrequencyFile() const;
};

#endif // GROCERYTRACKER_H
