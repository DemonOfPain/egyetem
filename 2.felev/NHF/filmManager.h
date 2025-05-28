/**
 * @file filmManager.h
 * @brief FilmManager class declaration for the Filmtár project
 *
 * This file contains the declaration of the FilmManager class which
 * manages a heterogeneous collection of films.
 */

#ifndef FILMMANAGER_H
#define FILMMANAGER_H

#include "film.h"
#include "memtrace.h"
#include <fstream>
#include <string>

/**
 * @class FilmManager
 * @brief Class for managing a collection of films
 *
 * FilmManager provides functionality for adding, removing, searching,
 * saving, and loading films. It maintains a heterogeneous collection of
 * Film objects.
 */
class FilmManager {
private:
    Film **films; ///< Dynamic array of film pointers
    int count;    ///< Current number of films
    int capacity; ///< Current capacity of the array

    /**
     * @brief Expand the capacity of the films array
     *
     * Doubles the capacity of the array when it becomes full.
     */
    void expandCapacity();

    /**
     * @brief Create a film based on type
     * @param type The type of film ("normal", "family", "documentary")
     * @param title The film title
     * @param duration The film duration in minutes
     * @param year The release year
     * @param extraData Additional data specific to the film type
     * @return Pointer to the created film or nullptr if failed
     */
    Film *createFilm(const char *type, const char *title, int duration, int year, const char *extraData);

public:
    /**
     * @brief Constructor
     * @param initialCapacity Initial capacity of the films array
     */
    FilmManager(int initialCapacity = 10);

    /**
     * @brief Copy constructor
     * @param other The film manager to copy
     */
    FilmManager(const FilmManager &other);

    /**
     * @brief Assignment operator
     * @param other The film manager to assign from
     * @return Reference to this film manager
     */
    FilmManager &operator=(const FilmManager &other);

    /**
     * @brief Destructor
     */
    ~FilmManager();

    /**
     * @brief Add a film to the collection
     * @param film Pointer to the film to add
     * @return true if successful, false otherwise
     */
    bool addFilm(Film *film);

    /**
     * @brief Create and add a film to the collection
     * @param type The type of film ("normal", "family", "documentary")
     * @param title The film title
     * @param duration The film duration in minutes
     * @param year The release year
     * @param extraData Additional data specific to the film type
     * @return true if successful, false otherwise
     */
    bool addFilm(const char *type, const char *title, int duration, int year, const char *extraData = nullptr);

    /**
     * @brief Delete a film from the collection
     * @param id The ID of the film to delete
     * @return true if successful, false otherwise
     */
    bool deleteFilm(int id);

    /**
     * @brief List all films in the collection
     */
    void listFilms() const;

    /**
     * @brief Search films based on query string
     * @param query The search query (format: "key1=value1&key2=value2...")
     */
    void searchFilms(const char *query) const;

    /**
     * @brief Save all films to a file
     * @param filename The name of the file to save to
     * @return true if successful, false otherwise
     */
    bool saveFilms(const char *filename) const;

    /**
     * @brief Load films from a file
     * @param filename The name of the file to load from
     * @return true if successful, false otherwise
     */
    bool loadFilms(const char *filename);

    /**
     * @brief Get the number of films in the collection
     * @return The number of films
     */
    int getCount() const;

    /**
     * @brief Get a film by index
     * @param index The index of the film to get
     * @return Pointer to the film or nullptr if index is out of bounds
     */
    const Film *getFilm(int index) const;

    /**
     * @brief Get a film by ID
     * @param id The ID of the film to get
     * @return Pointer to the film or nullptr if not found
     */
    const Film *getFilmById(int id) const;
};

#endif // FILMMANAGER_H