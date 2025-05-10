/**
 * @file documentaryFilm.cpp
 * @brief Implementation of the DocumentaryFilm class for the Filmtár project
 *
 * This file contains the implementation of methods declared in the DocumentaryFilm class.
 */

#include "documentaryFilm.h"
#include <cstring>
#include <iostream>

DocumentaryFilm::DocumentaryFilm() : Film(), description(nullptr) {
    // Allocate memory for an empty description
    description = new char[1];
    description[0] = '\0';
}

DocumentaryFilm::DocumentaryFilm(const char *title, int duration, int year, const char *description)
    : Film(title, duration, year), description(nullptr) {
    // Validate description
    if (description == nullptr || strlen(description) == 0) {
        throw std::invalid_argument("Documentary description cannot be empty");
    }

    // Allocate memory and copy the description
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

DocumentaryFilm::DocumentaryFilm(const DocumentaryFilm &other) : Film(other), description(nullptr) {
    // Deep copy of description
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
}

DocumentaryFilm &DocumentaryFilm::operator=(const DocumentaryFilm &other) {
    if (this != &other) {
        // Call base class operator=
        Film::operator=(other);

        // Free existing memory
        delete[] description;

        // Deep copy of description
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
    return *this;
}

DocumentaryFilm::~DocumentaryFilm() {
    delete[] description;
}

const char *DocumentaryFilm::getDescription() const {
    return description;
}

void DocumentaryFilm::setDescription(const char *description) {
    if (description == nullptr || strlen(description) == 0) {
        throw std::invalid_argument("Documentary description cannot be empty");
    }

    // Free existing memory and allocate new memory
    delete[] this->description;
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

void DocumentaryFilm::print() const {
    // Print common film details and description
    std::cout << getId() << "\tdocumentary\t" << getTitle() << "\t"
              << getDuration() << "\t" << getYear() << "\t" << description << std::endl;
}

bool DocumentaryFilm::save(std::ofstream &out) const {
    if (!out.good()) {
        return false;
    }

    // Create safe title and description (replace spaces with underscores)
    std::string safeTitle(getTitle());
    std::string safeDesc(description);

    for (size_t i = 0; i < safeTitle.length(); i++) {
        if (safeTitle[i] == ' ') {
            safeTitle[i] = '_';
        }
    }

    for (size_t i = 0; i < safeDesc.length(); i++) {
        if (safeDesc[i] == ' ') {
            safeDesc[i] = '_';
        }
    }

    // Write documentary film data to file
    out << "documentary " << safeTitle << " " << getDuration() << " " << getYear() << " " << safeDesc << std::endl;
    return out.good();
}

bool DocumentaryFilm::load(std::ifstream &in) {
    if (!in.good()) {
        return false;
    }

    // Read film data
    std::string tempTitle;
    std::string tempDescription;
    int tempDuration, tempYear;

    in >> tempTitle >> tempDuration >> tempYear >> tempDescription;

    if (in.fail()) {
        return false;
    }

    // Replace underscores with spaces in title and description
    for (size_t i = 0; i < tempTitle.length(); i++) {
        if (tempTitle[i] == '_') {
            tempTitle[i] = ' ';
        }
    }

    for (size_t i = 0; i < tempDescription.length(); i++) {
        if (tempDescription[i] == '_') {
            tempDescription[i] = ' ';
        }
    }

    // Set the attributes
    try {
        setTitle(tempTitle.c_str());
        setDuration(tempDuration);
        setYear(tempYear);
        setDescription(tempDescription.c_str());
        return true;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error loading documentary film: " << e.what() << std::endl;
        return false;
    }
}

bool DocumentaryFilm::match(const char *key, const char *value) const {
    if (key == nullptr || value == nullptr) {
        return false;
    }

    // Check if the base class can match
    if (Film::match(key, value)) {
        return true;
    }

    // Match by description (case-sensitive)
    if (strcmp(key, "description") == 0) {
        return strstr(description, value) != nullptr;
    }

    // Match by type (override base class behavior)
    if (strcmp(key, "type") == 0) {
        return strcmp(value, "documentary") == 0;
    }

    return false;
}

Film *DocumentaryFilm::clone() const {
    return new DocumentaryFilm(*this);
}