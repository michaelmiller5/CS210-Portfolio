#include <iostream>
#include <string>
#include <limits>
#include "GroceryTracker.h"

// Displays the main menu options to the user
void DisplayMenu() {
    std::cout << "========================================" << std::endl;
    std::cout << "         Corner Grocer Item Tracker     " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "1. Search for item frequency" << std::endl;
    std::cout << "2. Display all item frequencies" << std::endl;
    std::cout << "3. Display frequency histogram" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Enter your choice (1-4): ";
}

int main() {
    // Initialize tracker: reads input file and writes frequency.dat automatically
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int userChoice = 0;

    // Main program loop: continues until the user selects option 4 to exit
    do {
        DisplayMenu();

        // Input validation: ensure user enters an integer
        if (!(std::cin >> userChoice)) {
            // Clear the error state and discard invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nInvalid input. Please enter a number between 1 and 4.\n" << std::endl;
            continue;
        }

        // Discard any remaining characters on the input line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (userChoice) {
            case 1: {
                // Menu Option 1: Search for a specific item's frequency
                std::string searchItem;
                std::cout << "\nEnter the item name to search: ";
                std::getline(std::cin, searchItem);

                int frequency = tracker.GetItemFrequency(searchItem);

                if (frequency > 0) {
                    std::cout << "\n" << searchItem << " was purchased " << frequency << " time(s).\n" << std::endl;
                } else {
                    std::cout << "\n\"" << searchItem << "\" was not found in today's records.\n" << std::endl;
                }
                break;
            }
            case 2:
                // Menu Option 2: Display all items with their purchase counts
                tracker.PrintAllFrequencies();
                break;

            case 3:
                // Menu Option 3: Display the text-based histogram
                tracker.PrintHistogram();
                break;

            case 4:
                // Menu Option 4: Exit the program
                std::cout << "\nThank you for using Corner Grocer Item Tracker. Goodbye!\n" << std::endl;
                break;

            default:
                // Handle any number outside the valid range
                std::cout << "\nInvalid choice. Please enter a number between 1 and 4.\n" << std::endl;
                break;
        }

    } while (userChoice != 4);

    return 0;
}
