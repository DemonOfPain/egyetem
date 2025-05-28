/**
 * @file film.h
 * @brief Film class declaration
 */

#ifndef FILM_H
#define FILM_H

#include "memtrace.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <stdexcept>

/**
 * @class Film
 * @brief Base class for all film types
 *
 * Film is an abstract class that contains common film attributes and methods.
 * It provides the interface for all derived film classes.
 */
class Film {
private:
    int id;            ///< Unique identifier for the film
    char *title;       ///< Film title
    int duration;      ///< Film duration in minutes
    int year;          ///< Release year
    static int nextId; ///< Static counter for generating unique IDs

public:
    /**
     * @brief Default constructor
     */
    Film();

    /**
     * @brief Parameterized constructor
     * @param title The film title
     * @param duration The film duration in minutes
     * @param year The release year
     * @throws std::invalid_argument if title is null/empty or if duration/year are invalid
     */
    Film(const char *title, int duration, int year);

    /**
     * @brief Copy constructor
     * @param other The film to copy
     */
    Film(const Film &other);

    /**
     * @brief Assignment operator
     * @param other The film to assign from
     * @return Reference to this film
     */
    Film &operator=(const Film &other);

    /**
     * @brief Virtual destructor
     */
    virtual ~Film();

    /**
     * @brief Get the film ID
     * @return The film ID
     */
    int getId() const;

    /**
     * @brief Get the film title
     * @return The film title
     */
    const char *getTitle() const;

    /**
     * @brief Get the film duration
     * @return The film duration in minutes
     */
    int getDuration() const;

    /**
     * @brief Get the film year
     * @return The release year
     */
    int getYear() const;

    /**
     * @brief Set the film title
     * @param title The new film title
     * @throws std::invalid_argument if title is null or empty
     */
    void setTitle(const char *title);

    /**
     * @brief Set the film duration
     * @param duration The new film duration
     * @throws std::invalid_argument if duration is less than or equal to 0
     */
    void setDuration(int duration);

    /**
     * @brief Set the film year
     * @param year The new release year
     * @throws std::invalid_argument if year is less than 1888 (first film ever)
     */
    void setYear(int year);

    /**
     * @brief Print film details to standard output
     */
    virtual void print() const;

    /**
     * @brief Save film details to a file
     * @param out Output file stream
     * @return true if successful, false otherwise
     */
    virtual bool save(std::ofstream &out) const;

    /**
     * @brief Load film details from a file
     * @param in Input file stream
     * @return true if successful, false otherwise
     */
    virtual bool load(std::ifstream &in);

    /**
     * @brief Check if film matches a search criteria
     * @param key The search key (e.g., "title", "year")
     * @param value The search value
     * @return true if matches, false otherwise
     */
    virtual bool match(const char *key, const char *value) const;

    /**
     * @brief Create a deep copy of this film
     * @return Pointer to a new film object
     */
    virtual Film *clone() const;

    /**
     * @brief Create a film from file data
     * @param in Input file stream
     * @return Pointer to a new film object or nullptr if failed
     */
    static Film *createFromFile(std::ifstream &in);
};

#endif // FILM_H