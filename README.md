# CS210-Portfolio
# CS 210 Project Three: Corner Grocer Item-Tracking Program

## Project Summary

This project is a C++ console application built for a fictional grocery store called Corner Grocer. The program solves a real-world business problem: the store needed a way to analyze which produce items were being purchased most frequently throughout the day. The program reads a text file containing a chronological list of purchased items, calculates how often each item appears, and presents that data to the user through an interactive four-option menu. It also automatically generates a backup data file (`frequency.dat`) on startup so the frequency data is always saved for later use.

## What I Did Particularly Well

I think the overall structure and organization of the code was one of my strongest areas in this project. I separated the program into three files — `GroceryTracker.h`, `GroceryTracker.cpp`, and `main.cpp` — following object-oriented design principles and keeping the interface, implementation, and program logic cleanly separated. I also wrote thorough inline comments throughout the code, making each function's purpose clear at a glance. My choice of `std::map` as the core data structure worked well here: it automatically sorts items alphabetically, prevents duplicates, and allows efficient lookups, all of which made the implementation straightforward and clean.

## Where I Could Enhance the Code

A few improvements could make this program more robust and user-friendly. First, the item search (Menu Option 1) is currently case-sensitive, meaning "Apples" and "apples" would return different results. Adding case-insensitive comparison logic would make it more forgiving for users. Second, the input file name is hardcoded in `main.cpp`, which limits flexibility — allowing the user to specify a file at runtime or via a command-line argument would make the program more adaptable. Finally, replacing the simple `std::map` with an `std::unordered_map` could improve lookup performance for very large datasets, since hash-based lookups are generally faster than tree-based ones.

## Most Challenging Parts and How I Overcame Them

The trickiest part was getting the input validation in the main menu loop right. Handling non-integer input with `std::cin` requires clearing the error state and flushing the input buffer before re-prompting, and getting that logic correct without causing infinite loops or skipped prompts took some careful testing. I worked through it by reviewing C++ stream documentation and testing different invalid inputs systematically until the behavior was consistent. The histogram alignment was also a small challenge — I used padding logic to keep the asterisks lined up regardless of item name length, which required some trial and error to get looking clean.

## Transferable Skills

This project reinforced several skills that will carry into future coursework and beyond. Object-oriented design — splitting a program into a class header, implementation, and driver — is a pattern I'll use in virtually every project going forward. Working with file I/O (`ifstream` and `ofstream`) is fundamental to real-world programming, and this project gave me solid hands-on practice with it. Input validation is another skill that applies universally; any program that accepts user input needs to handle bad data gracefully. Finally, thinking about data structure choice (why `std::map` here rather than a vector or array) built my habit of reasoning about the right tool for the job rather than defaulting to the first option.

## Maintainability, Readability, and Adaptability

I made the program maintainable by encapsulating all data and logic inside the `GroceryTracker` class, so changes to how frequencies are tracked or displayed don't require touching `main.cpp`. Readability was addressed through consistent naming conventions (PascalCase for class methods, camelCase for variables), clear inline comments above each function, and a clean menu display function that keeps the UI logic separate from the core logic. Adaptability is supported by the class design itself — adding a new menu option or a new output format would only require adding a method to `GroceryTracker` without restructuring the rest of the program.
