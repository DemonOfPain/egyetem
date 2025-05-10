/**
 * @file film.cpp
 * @brief Implementation of the Film class for the Filmtár project
 *
 * This file contains the implementation of methods declared in the Film class.
 */

#include "film.h"
#include "documentaryFilm.h"
#include "familyFilm.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

// Initialize static member
int Film::nextId = 1;

Film::Film() : id(nextId++), title(nullptr), duration(0), year(0) {
    // Allocate memory for an empty title
    title = new char[1];
    title[0] = '\0';
}

Film::Film(const char *title, int duration, int year) : id(nextId++) {
    // Validate input parameters
    if (title == nullptr || strlen(title) == 0) {
        throw std::invalid_argument("Film title cannot be empty");
    }
    if (duration <= 0) {
        throw std::invalid_argument("Film duration must be greater than 0");
    }
    if (year < 1888) { // First film was made in 1888
        throw std::invalid_argument("Film year must be 1888 or later");
    }

    // Allocate memory and copy the title
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    // Set other attributes
    this->duration = duration;
    this->year = year;
}

Film::Film(const Film &other) : id(nextId++) {
    // Deep copy of title
    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);

    // Copy other attributes
    duration = other.duration;
    year = other.year;
}

Film &Film::operator=(const Film &other) {
    if (this != &other) {
        // Free existing memory
        delete[] title;

        // Deep copy of title
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        // Copy other attributes (but keep the same id)
        duration = other.duration;
        year = other.year;
    }
    return *this;
}

Film::~Film() {
    delete[] title;
}

int Film::getId() const {
    return id;
}

const char *Film::getTitle() const {
    return title;
}

int Film::getDuration() const {
    return duration;
}

int Film::getYear() const {
    return year;
}

void Film::setTitle(const char *title) {
    if (title == nullptr || strlen(title) == 0) {
        throw std::invalid_argument("Film title cannot be empty");
    }

    // Free existing memory and allocate new memory
    delete[] this->title;
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);
}

void Film::setDuration(int duration) {
    if (duration <= 0) {
        throw std::invalid_argument("Film duration must be greater than 0");
    }
    this->duration = duration;
}

void Film::setYear(int year) {
    if (year < 1888) { // First film was made in 1888
        throw std::invalid_argument("Film year must be 1888 or later");
    }
    this->year = year;
}

void Film::print() const {
    std::cout << id << "\tnormal\t" << title << "\t" << duration << "\t" << year << std::endl;
}

bool Film::save(std::ofstream &out) const {
    if (!out.good()) {
        return false;
    }

    // Create safe title (replace spaces with underscores)
    std::string safeTitle(title);
    for (size_t i = 0; i < safeTitle.length(); i++) {
        if (safeTitle[i] == ' ') {
            safeTitle[i] = '_';
        }
    }

    // Write film data to file
    out << "normal " << safeTitle << " " << duration << " " << year << std::endl;
    return out.good();
}

bool Film::load(std::ifstream &in) {
    if (!in.good()) {
        return false;
    }

    // Read film data
    std::string tempTitle;
    int tempDuration, tempYear;

    in >> tempTitle >> tempDuration >> tempYear;

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
        return true;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error loading film: " << e.what() << std::endl;
        return false;
    }
}

bool Film::match(const char *key, const char *value) const {
    if (key == nullptr || value == nullptr) {
        return false;
    }

    // Match by title (case-sensitive)
    if (strcmp(key, "title") == 0) {
        return strstr(title, value) != nullptr;
    }

    // Match by year
    if (strcmp(key, "year") == 0) {
        return year == atoi(value);
    }

    // Match by type
    if (strcmp(key, "type") == 0) {
        return strcmp(value, "normal") == 0;
    }

    return false;
}

Film *Film::clone() const {
    return new Film(*this);
}

Film *Film::createFromFile(std::ifstream &in) {
    if (!in.good()) {
        return nullptr;
    }

    // Read film type
    std::string type;
    in >> type;

    if (in.fail() || in.eof()) {
        return nullptr;
    }

    // Create the appropriate film type
    if (type == "normal") {
        Film *film = new Film();
        if (film->load(in)) {
            return film;
        }
        delete film;
    } else if (type == "family") {
        FamilyFilm *film = new FamilyFilm();
        if (film->load(in)) {
            return film;
        }
        delete film;
    } else if (type == "documentary") {
        DocumentaryFilm *film = new DocumentaryFilm();
        if (film->load(in)) {
            return film;
        }
        delete film;
    }

    return nullptr;
}