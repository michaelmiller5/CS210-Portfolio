#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <string>

// Constructor: loads the input file and immediately writes the backup data file
GroceryTracker::GroceryTracker(const std::string& inputFileName) {
    LoadDataFromFile(inputFileName);
    WriteFrequencyFile();
}

// Reads each line (item name) from the input file and counts occurrences
void GroceryTracker::LoadDataFromFile(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        // Notify user if the file cannot be opened
        std::cerr << "Error: Could not open input file: " << inputFileName << std::endl;
        return;
    }

    std::string item;
    // Read one item per line and increment its count in the map
    while (std::getline(inputFile, item)) {
        if (!item.empty()) {
            itemFrequencyMap[item]++;
        }
    }

    inputFile.close();
}

// Writes the item-frequency pairs to frequency.dat as a backup
void GroceryTracker::WriteFrequencyFile() const {
    std::ofstream outputFile("frequency.dat");

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create frequency.dat" << std::endl;
        return;
    }

    // Write each item and its count separated by a space
    for (const auto& pair : itemFrequencyMap) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close();
}

// Returns the frequency of a specific item; returns 0 if item is not found
int GroceryTracker::GetItemFrequency(const std::string& item) const {
    auto it = itemFrequencyMap.find(item);
    if (it != itemFrequencyMap.end()) {
        return it->second;
    }
    return 0; // Item not found in the map
}

// Prints every item with its numeric purchase frequency
void GroceryTracker::PrintAllFrequencies() const {
    std::cout << "\n--- Item Purchase Frequencies ---" << std::endl;
    for (const auto& pair : itemFrequencyMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    std::cout << "---------------------------------\n" << std::endl;
}

// Prints a text-based histogram: item name followed by asterisks representing count
void GroceryTracker::PrintHistogram() const {
    std::cout << "\n--- Purchase Frequency Histogram ---" << std::endl;
    for (const auto& pair : itemFrequencyMap) {
        // Print item name left-aligned, padded to 15 characters for alignment
        std::cout << pair.first;

        // Print a number of spaces to align asterisks
        int padding = 15 - static_cast<int>(pair.first.length());
        if (padding < 1) padding = 1;
        std::cout << std::string(padding, ' ');

        // Print one asterisk per purchase
        std::cout << std::string(pair.second, '*') << std::endl;
    }
    std::cout << "------------------------------------\n" << std::endl;
}
