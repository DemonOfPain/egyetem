/**
 * @file familyFilm.cpp
 * @brief Implementation of the FamilyFilm class for the Filmtár project
 *
 * This file contains the implementation of methods declared in the FamilyFilm class.
 */

#include "familyFilm.h"
#include <cstring>
#include <iostream>

FamilyFilm::FamilyFilm() : Film(), ageLimit(0) {
    // Default constructor body
}

FamilyFilm::FamilyFilm(const char *title, int duration, int year, int ageLimit)
    : Film(title, duration, year) {
    // Validate ageLimit
    if (ageLimit < 0) {
        throw std::invalid_argument("Age limit cannot be negative");
    }
    this->ageLimit = ageLimit;
}

FamilyFilm::FamilyFilm(const FamilyFilm &other) : Film(other), ageLimit(other.ageLimit) {
    // Copy constructor body
}

FamilyFilm &FamilyFilm::operator=(const FamilyFilm &other) {
    if (this != &other) {
        // Call base class operator=
        Film::operator=(other);

        // Copy the age limit
        ageLimit = other.ageLimit;
    }
    return *this;
}

FamilyFilm::~FamilyFilm() {
    // No additional cleanup needed beyond base class destructor
}

int FamilyFilm::getAgeLimit() const {
    return ageLimit;
}

void FamilyFilm::setAgeLimit(int ageLimit) {
    if (ageLimit < 0) {
        throw std::invalid_argument("Age limit cannot be negative");
    }
    this->ageLimit = ageLimit;
}

void FamilyFilm::print() const {
    // Print common film details and age limit
    std::cout << getId() << "\tfamily\t" << getTitle() << "\t"
              << getDuration() << "\t" << getYear() << "\t" << ageLimit << std::endl;
}

bool FamilyFilm::save(std::ofstream &out) const {
    if (!out.good()) {
        return false;
    }

    // Create safe title (replace spaces with underscores)
    std::string safeTitle(getTitle());
    for (size_t i = 0; i < safeTitle.length(); i++) {
        if (safeTitle[i] == ' ') {
            safeTitle[i] = '_';
        }
    }

    // Write family film data to file
    out << "family " << safeTitle << " " << getDuration() << " " << getYear() << " " << ageLimit << std::endl;
    return out.good();
}

bool FamilyFilm::load(std::ifstream &in) {
    if (!in.good()) {
        return false;
    }

    // Read film data
    std::string tempTitle;
    int tempDuration, tempYear, tempAgeLimit;

    in >> tempTitle >> tempDuration >> tempYear >> tempAgeLimit;

    if (in.fail()) {
        return false;
    }

    // Replace underscores with spaces in title
    for (size_t i = 0; i < tempTitle.length(); i++) {
        if (tempTitle[i] == '_') {
            tempTitle[i] = ' ';
        }
    }

    // Set the attributes
    try {
        setTitle(tempTitle.c_str());
        setDuration(tempDuration);
        setYear(tempYear);
        setAgeLimit(tempAgeLimit);
        return true;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error loading family film: " << e.what() << std::endl;
        return false;
    }
}

bool FamilyFilm::match(const char *key, const char *value) const {
    if (key == nullptr || value == nullptr) {
        return false;
    }

    // Check if the base class can match
    if (Film::match(key, value)) {
        return true;
    }

    // Match by age limit
    if (strcmp(key, "agelimit") == 0) {
        return ageLimit == atoi(value);
    }

    // Match by type (override base class behavior)
    if (strcmp(key, "type") == 0) {
        return strcmp(value, "family") == 0;
    }

    return false;
}

Film *FamilyFilm::clone() const {
    return new FamilyFilm(*this);
}