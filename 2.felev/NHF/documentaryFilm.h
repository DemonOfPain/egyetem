/**
 * @file documentaryFilm.h
 * @brief DocumentaryFilm class declaration
 */

#ifndef DOCUMENTARYFILM_H
#define DOCUMENTARYFILM_H

#include "film.h"
#include <fstream>

/**
 * @class DocumentaryFilm
 * @brief Class representing documentary films
 *
 * DocumentaryFilm extends the Film class with a description attribute
 * to provide information about the documentary's subject.
 */
class DocumentaryFilm : public Film {
private:
    char *description; ///< Textual description of the documentary

public:
    /**
     * @brief Default constructor
     */
    DocumentaryFilm();

    /**
     * @brief Parameterized constructor
     * @param title The film title
     * @param duration The film duration in minutes
     * @param year The release year
     * @param description The documentary description
     * @throws std::invalid_argument if description is null or empty
     */
    DocumentaryFilm(const char *title, int duration, int year, const char *description);

    /**
     * @brief Copy constructor
     * @param other The documentary film to copy
     */
    DocumentaryFilm(const DocumentaryFilm &other);

    /**
     * @brief Assignment operator
     * @param other The documentary film to assign from
     * @return Reference to this documentary film
     */
    DocumentaryFilm &operator=(const DocumentaryFilm &other);

    /**
     * @brief Destructor
     */
    ~DocumentaryFilm() override;

    /**
     * @brief Get the documentary description
     * @return The description text
     */
    const char *getDescription() const;

    /**
     * @brief Set the documentary description
     * @param description The new description
     * @throws std::invalid_argument if description is null or empty
     */
    void setDescription(const char *description);

    /**
     * @brief Print documentary film details to standard output
     * Overrides the base class method to include description
     */
    void print() const override;

    /**
     * @brief Save documentary film details to a file
     * @param out Output file stream
     * @return true if successful, false otherwise
     */
    bool save(std::ofstream &out) const override;

    /**
     * @brief Load documentary film details from a file
     * @param in Input file stream
     * @return true if successful, false otherwise
     */
    bool load(std::ifstream &in) override;

    /**
     * @brief Check if documentary film matches a search criteria
     * @param key The search key
     * @param value The search value
     * @return true if matches, false otherwise
     */
    bool match(const char *key, const char *value) const override;

    /**
     * @brief Create a deep copy of this documentary film
     * @return Pointer to a new documentary film object
     */
    Film *clone() const override;
};

#endif // DOCUMENTARYFILM_H