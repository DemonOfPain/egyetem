/**
 * @file application.cpp
 * @brief Implementation of the Application class for the Filmtár project
 *
 * This file contains the implementation of methods declared in the Application class.
 */

#include "application.h"
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

// Default filenames
const char *DEFAULT_FILENAME = "filmek.dat";

Application::Application() : filmManager(), running(false) {
    // Constructor body
}

Application::~Application() {
    // Destructor body
}

void Application::run() {
    // Welcome message
    std::cout << "======================================" << std::endl;
    std::cout << "Welcome to Filmtar - Film Database" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Available commands:" << std::endl;
    std::cout << "  add - Add a new film" << std::endl;
    std::cout << "  delete - Delete a film" << std::endl;
    std::cout << "  list - List all films" << std::endl;
    std::cout << "  search - Search for films" << std::endl;
    std::cout << "  save - Save films to a file" << std::endl;
    std::cout << "  load - Load films from a file" << std::endl;
    std::cout << "  exit - Exit the program" << std::endl;
    std::cout << "======================================" << std::endl;

    // Main loop
    running = true;
    while (running) {
        char command[256];
        if (readLine("Enter command: ", command, sizeof(command))) {
            processCommand(command);
        }
    }

    // Goodbye message
    std::cout << "Thank you for using Filmtar!" << std::endl;
}

void Application::processCommand(const char *command) {
    if (command == nullptr || strlen(command) == 0) {
        return;
    }

    // Extract the first word (the command)
    std::string cmdStr(command);
    std::string cmd;
    std::string args;

    // Find the first space
    size_t spacePos = cmdStr.find(' ');
    if (spacePos != std::string::npos) {
        cmd = cmdStr.substr(0, spacePos);
        args = cmdStr.substr(spacePos + 1);
    } else {
        cmd = cmdStr;
        args = "";
    }

    // Process the command
    if (cmd == "add") {
        addFilm();
    } else if (cmd == "delete") {
        deleteFilm();
    } else if (cmd == "list") {
        listFilms();
    } else if (cmd == "search") {
        searchFilms();
    } else if (cmd == "save") {
        // Check if filename was provided
        if (!args.empty()) {
            saveFilms(args.c_str());
        } else {
            saveFilms();
        }
    } else if (cmd == "load") {
        // Check if filename was provided
        if (!args.empty()) {
            loadFilms(args.c_str());
        } else {
            loadFilms();
        }
    } else if (cmd == "exit") {
        running = false;
    } else {
        std::cerr << "Unknown command: " << cmd << std::endl;
    }
}

void Application::addFilm() {
    std::cout << "Adding a new film..." << std::endl;

    // Get film type
    char typeStr[32];
    if (!readLine("Enter film type (normal, family, documentary): ", typeStr, sizeof(typeStr))) {
        return;
    }

    // Convert to lowercase for case-insensitive comparison
    for (size_t i = 0; i < strlen(typeStr); ++i) {
        typeStr[i] = tolower(typeStr[i]);
    }

    // Validate film type with exact match
    if (strcmp(typeStr, "normal") != 0 &&
        strcmp(typeStr, "family") != 0 &&
        strcmp(typeStr, "documentary") != 0) {
        std::cerr << "Error: Invalid film type. Must be exactly 'normal', 'family', or 'documentary'." << std::endl;
        return;
    }

    // Get film title
    char title[128];
    if (!readLine("Enter film title: ", title, sizeof(title))) {
        return;
    }

    // Validate title
    if (strlen(title) == 0) {
        std::cerr << "Error: Title cannot be empty" << std::endl;
        return;
    }

    // Get film duration with strict validation
    int duration = readInt("Enter film duration (minutes): ");
    if (duration <= 0) {
        std::cerr << "Error: Invalid duration. Must be greater than 0." << std::endl;
        return;
    }

    // Get film year with strict validation
    int year = readInt("Enter release year: ");
    if (year < 1888) {
        std::cerr << "Error: Invalid year. Must be 1888 or later." << std::endl;
        return;
    }

    // Get type-specific data
    char extraData[1024] = {0};

    if (strcmp(typeStr, "family") == 0) {
        int ageLimit = readInt("Enter age limit: ");
        if (ageLimit < 0) {
            std::cerr << "Error: Invalid age limit. Must be 0 or greater." << std::endl;
            return;
        }

        // Convert ageLimit to string using std::to_string
        std::string ageLimitStr = std::to_string(ageLimit);

        // Copy to extraData
        strcpy(extraData, ageLimitStr.c_str());
    } else if (strcmp(typeStr, "documentary") == 0) {
        if (!readLine("Enter description: ", extraData, sizeof(extraData))) {
            return;
        }

        // Validate description
        if (strlen(extraData) == 0) {
            std::cerr << "Error: Description cannot be empty" << std::endl;
            return;
        }
    }

    // Add the film
    try {
        if (filmManager.addFilm(typeStr, title, duration, year, *extraData ? extraData : nullptr)) {
            std::cout << "Film added successfully." << std::endl;
        } else {
            std::cerr << "Error: Failed to add film." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error adding film: " << e.what() << std::endl;
    }
}

void Application::deleteFilm() {
    // Get film ID with validation
    int id = 0;
    char idStr[32];
    if (!readLine("Enter film ID to delete: ", idStr, sizeof(idStr))) {
        return;
    }

    // Validate that the input contains only digits
    for (size_t i = 0; i < strlen(idStr); ++i) {
        if (!isdigit(idStr[i])) {
            std::cerr << "Error: ID must contain only digits." << std::endl;
            return;
        }
    }

    // Convert to integer
    try {
        id = std::stoi(idStr);
    } catch (...) {
        std::cerr << "Error: Invalid ID format." << std::endl;
        return;
    }

    // Validate that the ID is positive
    if (id <= 0) {
        std::cerr << "Error: ID must be a positive number." << std::endl;
        return;
    }

    // Delete the film
    if (filmManager.deleteFilm(id)) {
        std::cout << "Film deleted successfully." << std::endl;
    } else {
        std::cerr << "Failed to delete film. ID not found." << std::endl;
    }
}

void Application::listFilms() const {
    std::cout << "Listing all films..." << std::endl;
    filmManager.listFilms();
}

void Application::searchFilms() const {
    std::cout << "Searching for films..." << std::endl;
    std::cout << "Search formats:" << std::endl;
    std::cout << "  title=value - Search by title" << std::endl;
    std::cout << "  year=value - Search by year" << std::endl;
    std::cout << "  type=value - Search by type (normal, family, documentary)" << std::endl;
    std::cout << "  Multiple criteria can be combined with '&', e.g., title=Star&year=1977" << std::endl;

    // Get search query
    char query[256];
    if (!readLine("Enter search query: ", query, sizeof(query))) {
        return;
    }

    // Validate the query
    if (strlen(query) == 0) {
        std::cerr << "Error: Search query cannot be empty" << std::endl;
        return;
    }

    // Check if the query contains at least one '=' character
    bool hasEqualSign = false;
    for (size_t i = 0; i < strlen(query); ++i) {
        if (query[i] == '=') {
            hasEqualSign = true;
            break;
        }
    }

    if (!hasEqualSign) {
        std::cerr << "Error: Invalid search format. Must contain '=' (e.g., title=Matrix)" << std::endl;
        return;
    }

    // Perform search with the validated query
    filmManager.searchFilms(query);
}

void Application::saveFilms(const char *filename) const {
    // Get filename if not provided
    char filenameBuffer[256];
    if (filename == nullptr) {
        if (!readLine("Enter filename (default: filmek.dat): ", filenameBuffer, sizeof(filenameBuffer))) {
            return;
        }

        // Use default if empty
        if (strlen(filenameBuffer) == 0) {
            strcpy(filenameBuffer, DEFAULT_FILENAME);
        }

        filename = filenameBuffer;
    }

    // Save films
    if (filmManager.saveFilms(filename)) {
        std::cout << "Films saved successfully to " << filename << std::endl;
    } else {
        std::cerr << "Failed to save films to " << filename << std::endl;
    }
}

void Application::loadFilms(const char *filename) {
    // Get filename if not provided
    char filenameBuffer[256];
    if (filename == nullptr) {
        if (!readLine("Enter filename (default: filmek.dat): ", filenameBuffer, sizeof(filenameBuffer))) {
            return;
        }

        // Use default if empty
        if (strlen(filenameBuffer) == 0) {
            strcpy(filenameBuffer, DEFAULT_FILENAME);
        }

        filename = filenameBuffer;
    }

    // Load films
    if (filmManager.loadFilms(filename)) {
        std::cout << "Films loaded successfully from " << filename << std::endl;
    } else {
        std::cerr << "Failed to load films from " << filename << std::endl;
    }
}

bool Application::readLine(const char *prompt, char *buffer, int size) const {
    if (prompt != nullptr) {
        std::cout << prompt;
    }

    // Clear input buffer
    std::cin.clear();

    // Read input
    std::cin.getline(buffer, size);

    // Check for input failure
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cerr << "Input error." << std::endl;
        return false;
    }

    return true;
}

int Application::readInt(const char *prompt) const {
    if (prompt != nullptr) {
        std::cout << prompt;
    }

    // Read input
    std::string input;
    std::getline(std::cin, input);

    // Check for empty input
    if (input.empty()) {
        std::cerr << "Error: Input cannot be empty." << std::endl;
        return -1; // Error indicator
    }

    // Validate that input contains only digits
    for (size_t i = 0; i < input.length(); ++i) {
        if (!isdigit(input[i]) && !(i == 0 && input[i] == '-')) {
            std::cerr << "Error: Input must contain only digits." << std::endl;
            return -1; // Error indicator
        }
    }

    // Try to convert to integer
    try {
        return std::stoi(input);
    } catch (...) {
        std::cerr << "Error: Invalid number format." << std::endl;
        return -1; // Error indicator
    }
}