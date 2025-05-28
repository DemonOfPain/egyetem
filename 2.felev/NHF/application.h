/**
 * @file application.h
 * @brief Application class declaration for the Filmtár project
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "filmManager.h"
#include "memtrace.h"
#include <iostream>
#include <sstream>
#include <string>

/**
 * @class Application
 * @brief Class for handling user interaction
 *
 * Application provides functionality for processing user commands
 * and managing the overall flow of the program.
 */
class Application {
private:
    FilmManager filmManager; ///< Film manager instance
    bool running;            ///< Flag indicating if the application is running

    /**
     * @brief Process a user command
     * @param command The command to process
     */
    void processCommand(const char *command);

    /**
     * @brief Add a new film
     * Prompts user for film details and adds to collection
     */
    void addFilm();

    /**
     * @brief Delete a film
     * Prompts user for film ID and deletes from collection
     */
    void deleteFilm();

    /**
     * @brief List all films
     */
    void listFilms() const;

    /**
     * @brief Search for films
     * Prompts user for search criteria and displays results
     */
    void searchFilms() const;

    /**
     * @brief Save films to a file
     * Prompts user for filename and saves collection
     * @param filename Optional filename, uses default if not provided
     */
    void saveFilms(const char *filename = nullptr) const;

    /**
     * @brief Load films from a file
     * Prompts user for filename and loads collection
     * @param filename Optional filename, uses default if not provided
     */
    void loadFilms(const char *filename = nullptr);

    /**
     * @brief Read a line of text from the user
     * @param prompt The prompt to display
     * @param buffer The buffer to store the input
     * @param size The size of the buffer
     * @return true if successful, false otherwise
     */
    bool readLine(const char *prompt, char *buffer, int size) const;

    /**
     * @brief Read an integer from the user
     * @param prompt The prompt to display
     * @return The integer value or -1 if input is invalid
     */
    int readInt(const char *prompt) const;

public:
    /**
     * @brief Constructor
     */
    Application();

    /**
     * @brief Destructor
     */
    ~Application();

    /**
     * @brief Run the application
     *
     * Main loop that handles user input and program execution.
     */
    void run();
};

#endif // APPLICATION_H