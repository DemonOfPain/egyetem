/**
 * @file familyFilm.h
 * @brief FamilyFilm class declaration
 */

#ifndef FAMILYFILM_H
#define FAMILYFILM_H

#include "film.h"
#include "memtrace.h"
#include <fstream>

/**
 * @class FamilyFilm
 * @brief Class representing family films
 *
 * FamilyFilm extends the Film class with an age limit attribute
 * to represent age restrictions for children.
 */
class FamilyFilm : public Film {
private:
    int ageLimit; ///< Age restriction limit in years

public:
    /**
     * @brief Default constructor
     */
    FamilyFilm();

    /**
     * @brief Parameterized constructor
     * @param title The film title
     * @param duration The film duration in minutes
     * @param year The release year
     * @param ageLimit The minimum age required to watch the film
     * @throws std::invalid_argument if ageLimit is negative
     */
    FamilyFilm(const char *title, int duration, int year, int ageLimit);

    /**
     * @brief Copy constructor
     * @param other The family film to copy
     */
    FamilyFilm(const FamilyFilm &other);

    /**
     * @brief Assignment operator
     * @param other The family film to assign from
     * @return Reference to this family film
     */
    FamilyFilm &operator=(const FamilyFilm &other);

    /**
     * @brief Destructor
     */
    ~FamilyFilm() override;

    /**
     * @brief Get the age limit
     * @return The age limit in years
     */
    int getAgeLimit() const;

    /**
     * @brief Set the age limit
     * @param ageLimit The new age limit
     * @throws std::invalid_argument if ageLimit is negative
     */
    void setAgeLimit(int ageLimit);

    /**
     * @brief Print family film details to standard output
     * Overrides the base class method to include age limit
     */
    void print() const override;

    /**
     * @brief Save family film details to a file
     * @param out Output file stream
     * @return true if successful, false otherwise
     */
    bool save(std::ofstream &out) const override;

    /**
     * @brief Load family film details from a file
     * @param in Input file stream
     * @return true if successful, false otherwise
     */
    bool load(std::ifstream &in) override;

    /**
     * @brief Check if family film matches a search criteria
     * @param key The search key
     * @param value The search value
     * @return true if matches, false otherwise
     */
    bool match(const char *key, const char *value) const override;

    /**
     * @brief Create a deep copy of this family film
     * @return Pointer to a new family film object
     */
    Film *clone() const override;
};

#endif // FAMILYFILM_H