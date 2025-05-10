// Mivel labon is a feladatokban angolul voltak tobbnyire a nevek meg minden mas is(feladatszovegtol eltekintve),
// gondoltam nem problema ha angolul csinalom a kommenteket is, egyreszt mert nem kell bajlodni az ekezetekkel,
// masreszt pedig en nekem szemelyesen nem tetszik amikor 2 nyelv nagyon keveredik, foleg az ekezetnelkuli magyar az angollal

/**
 * @file main.cpp
 * @brief Main entry point for the app
 */

#include "application.h"
#include <iostream>

/**
 * @brief Main function
 * @return Program exit code
 */
int main() {
    try {
        // Create and run the app
        Application app;
        app.run();

        return 0;
    } catch (const std::exception &e) { // Handle all errors
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 2;
    }
}