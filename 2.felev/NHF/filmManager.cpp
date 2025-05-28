/**
 * @file filmManager.cpp
 * @brief Implementation of the FilmManager class for the Filmtár project
 *
 * This file contains the implementation of methods declared in the FilmManager class.
 */

#include "filmManager.h"
#include "documentaryFilm.h"
#include "familyFilm.h"
#include "memtrace.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>

FilmManager::FilmManager(int initialCapacity) : films(nullptr), count(0), capacity(0) {
    if (initialCapacity <= 0) {
        throw std::invalid_argument("Initial capacity must be greater than 0");
    }

    // Allocate memory for the films array
    capacity = initialCapacity;
    films = new Film *[capacity];

    // Initialize all pointers to nullptr
    for (int i = 0; i < capacity; i++) {
        films[i] = nullptr;
    }
}

FilmManager::FilmManager(const FilmManager &other) : films(nullptr), count(0), capacity(other.capacity) {
    // Allocate memory for the films array
    films = new Film *[capacity];

    // Initialize all pointers to nullptr
    for (int i = 0; i < capacity; i++) {
        films[i] = nullptr;
    }

    // Deep copy all films using clone
    for (int i = 0; i < other.count; i++) {
        films[i] = other.films[i]->clone();
        count++;
    }
}

FilmManager &FilmManager::operator=(const FilmManager &other) {
    if (this != &other) {
        // Delete existing films
        for (int i = 0; i < count; i++) {
            delete films[i];
        }
        delete[] films;

        // Copy capacity and allocate new memory
        capacity = other.capacity;
        count = 0;
        films = new Film *[capacity];

        // Initialize all pointers to nullptr
        for (int i = 0; i < capacity; i++) {
            films[i] = nullptr;
        }

        // Deep copy all films using clone
        for (int i = 0; i < other.count; i++) {
            films[i] = other.films[i]->clone();
            count++;
        }
    }
    return *this;
}

FilmManager::~FilmManager() {
    // Delete all films
    for (int i = 0; i < count; i++) {
        delete films[i];
    }
    delete[] films;
}

void FilmManager::expandCapacity() {
    // Calculate new capacity
    int newCapacity = capacity * 2;

    // Allocate new memory
    Film **newFilms = new Film *[newCapacity];

    // Copy existing film pointers
    for (int i = 0; i < count; i++) {
        newFilms[i] = films[i];
    }

    // Initialize remaining pointers to nullptr
    for (int i = count; i < newCapacity; i++) {
        newFilms[i] = nullptr;
    }

    // Delete old array (but not the films)
    delete[] films;

    // Update members
    films = newFilms;
    capacity = newCapacity;
}

Film *FilmManager::createFilm(const char *type, const char *title, int duration, int year, const char *extraData) {
    // Validate parameters
    if (type == nullptr || title == nullptr) {
        return nullptr;
    }

    try {
        // Create film based on type
        if (strcmp(type, "normal") == 0) {
            return new Film(title, duration, year);
        } else if (strcmp(type, "family") == 0) {
            // For family films, extraData is the age limit
            int ageLimit = (extraData != nullptr) ? atoi(extraData) : 0;
            return new FamilyFilm(title, duration, year, ageLimit);
        } else if (strcmp(type, "documentary") == 0) {
            // For documentary films, extraData is the description
            const char *description = (extraData != nullptr) ? extraData : "No description";
            return new DocumentaryFilm(title, duration, year, description);
        }
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error creating film: " << e.what() << std::endl;
    }

    return nullptr;
}

bool FilmManager::addFilm(Film *film) {
    // Validate parameters
    if (film == nullptr) {
        return false;
    }

    // Check if we need to expand the array
    if (count >= capacity) {
        expandCapacity();
    }

    // Add the film
    films[count++] = film;
    return true;
}

bool FilmManager::addFilm(const char *type, const char *title, int duration, int year, const char *extraData) {
    // Create and add the film
    Film *film = createFilm(type, title, duration, year, extraData);
    if (film != nullptr) {
        return addFilm(film);
    }
    return false;
}

bool FilmManager::deleteFilm(int id) {
    // Find the film with the given ID
    for (int i = 0; i < count; i++) {
        if (films[i]->getId() == id) {
            // Delete the film
            delete films[i];

            // Shift remaining films
            for (int j = i; j < count - 1; j++) {
                films[j] = films[j + 1];
            }

            // Clear the last element and decrement count
            films[count - 1] = nullptr;
            count--;

            return true;
        }
    }

    return false;
}

void FilmManager::listFilms() const {
    if (count == 0) {
        std::cout << "No films in the collection." << std::endl;
        return;
    }

    // Print all films
    for (int i = 0; i < count; i++) {
        films[i]->print();
    }
}

void FilmManager::searchFilms(const char *query) const {
    if (query == nullptr) {
        std::cerr << "Error: Search query is null" << std::endl;
        return;
    }

    if (count == 0) {
        std::cout << "No films in the collection." << std::endl;
        return;
    }

    // If query is empty or doesn't contain any key=value pairs,
    // it's an error condition
    if (strlen(query) == 0 || strchr(query, '=') == nullptr) {
        std::cerr << "Error: Invalid search format. Must be in format key=value" << std::endl;
        return;
    }

    // Parse query
    // Format: key1=value1&key2=value2...
    char *queryCopy = new char[strlen(query) + 1];
    strcpy(queryCopy, query);

    // Split by '&'
    char *context = nullptr;
    char *token = strtok_r(queryCopy, "&", &context);

    // Array to store criteria (key-value pairs)
    char **keys = new char *[10]; // Max 10 criteria
    char **values = new char *[10];
    int criteriaCount = 0;

    // Parse each token
    while (token != nullptr && criteriaCount < 10) {
        // Split by '='
        char *subContext = nullptr;
        char *key = strtok_r(token, "=", &subContext);
        char *value = strtok_r(nullptr, "=", &subContext);

        if (key != nullptr && value != nullptr) {
            // Validate key and value
            if (strlen(key) == 0 || strlen(value) == 0) {
                std::cerr << "Error: Empty key or value in search criteria" << std::endl;

                // Free memory
                for (int i = 0; i < criteriaCount; i++) {
                    delete[] keys[i];
                    delete[] values[i];
                }
                delete[] keys;
                delete[] values;
                delete[] queryCopy;
                return;
            }

            // Check if key is one of the allowed values
            if (strcmp(key, "title") != 0 && strcmp(key, "year") != 0 && strcmp(key, "type") != 0 &&
                strcmp(key, "agelimit") != 0 && strcmp(key, "description") != 0) {
                std::cerr << "Error: Invalid search key: " << key << std::endl;

                // Free memory
                for (int i = 0; i < criteriaCount; i++) {
                    delete[] keys[i];
                    delete[] values[i];
                }
                delete[] keys;
                delete[] values;
                delete[] queryCopy;
                return;
            }

            // Store key-value pair
            keys[criteriaCount] = new char[strlen(key) + 1];
            values[criteriaCount] = new char[strlen(value) + 1];
            strcpy(keys[criteriaCount], key);
            strcpy(values[criteriaCount], value);
            criteriaCount++;
        } else {
            std::cerr << "Error: Invalid search criteria format" << std::endl;

            // Free memory
            for (int i = 0; i < criteriaCount; i++) {
                delete[] keys[i];
                delete[] values[i];
            }
            delete[] keys;
            delete[] values;
            delete[] queryCopy;
            return;
        }

        // Get next token
        token = strtok_r(nullptr, "&", &context);
    }

    // If no valid criteria were found, it's an error
    if (criteriaCount == 0) {
        std::cerr << "Error: No valid search criteria found" << std::endl;

        // Free memory
        delete[] keys;
        delete[] values;
        delete[] queryCopy;
        return;
    }

    // Find matching films
    bool found = false;
    for (int i = 0; i < count; i++) {
        bool matches = true;

        // Check all criteria
        for (int j = 0; j < criteriaCount; j++) {
            if (!films[i]->match(keys[j], values[j])) {
                matches = false;
                break;
            }
        }

        // Print if matches
        if (matches) {
            films[i]->print();
            found = true;
        }
    }

    // If no films were found
    if (!found) {
        std::cout << "No films matching the criteria." << std::endl;
    }

    // Free memory
    for (int i = 0; i < criteriaCount; i++) {
        delete[] keys[i];
        delete[] values[i];
    }
    delete[] keys;
    delete[] values;
    delete[] queryCopy;
}

bool FilmManager::saveFilms(const char *filename) const {
    if (filename == nullptr) {
        return false;
    }

    // Open file for writing
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return false;
    }

    // Save all films
    for (int i = 0; i < count; i++) {
        if (!films[i]->save(outFile)) {
            outFile.close();
            std::cerr << "Error saving film ID " << films[i]->getId() << std::endl;
            return false;
        }
    }

    // Close file
    outFile.close();
    return true;
}

bool FilmManager::loadFilms(const char *filename) {
    if (filename == nullptr) {
        return false;
    }

    // Open file for reading
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return false;
    }

    // Clear existing films
    for (int i = 0; i < count; i++) {
        delete films[i];
        films[i] = nullptr;
    }
    count = 0;

    // Load films
    while (inFile.good() && !inFile.eof()) {
        // Check for empty position
        if (inFile.peek() == std::ifstream::traits_type::eof()) {
            break;
        }

        // Try to read a film
        Film *film = Film::createFromFile(inFile);
        if (film != nullptr) {
            addFilm(film);
        }

        // Skip any remaining characters on the line
        std::string line;
        std::getline(inFile, line);
    }

    // Close file
    inFile.close();
    return true;
}

int FilmManager::getCount() const {
    return count;
}

const Film *FilmManager::getFilm(int index) const {
    if (index < 0 || index >= count) {
        return nullptr;
    }
    return films[index];
}

const Film *FilmManager::getFilmById(int id) const {
    for (int i = 0; i < count; i++) {
        if (films[i]->getId() == id) {
            return films[i];
        }
    }
    return nullptr;
}