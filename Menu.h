/**
 * @file Menu.h
 * @brief Definition of the Menu class for user interaction.
 *
 * This file contains the definition of the Menu class, which manages the user interface for the application. It provides
 * methods for displaying the main menu, handling user selections, and triggering the appropriate actions based on user input.
 */

#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include "GraphInterface.h" // Include the GraphInterface to interact with the graph
#include "headers.h"

/**
 * @class Menu
 * @brief Manages user interactions and provides a menu-driven interface.
 *
 * The Menu class provides a simple console-based interface for users to interact with the water distribution
 * system. It allows users to view maximum flow statistics, general statistics about the network, and the reliability
 * of the water distribution system through various menu options.
 */
class Menu {
private:
    /**
     * @brief Displays the maximum flow in the network.
     *
     * This method calculates and shows the maximum flow possible from sources to sinks in the water distribution network.
     */
    void showMaxFlow();

    /**
     * @brief Displays statistics about the water distribution network.
     *
     * Presents various statistics related to the water distribution network, such as total water supply, demand, and efficiency.
     */
    void showStats();

    /**
     * @brief Evaluates and displays the reliability of the water distribution system.
     *
     * Assesses and reports on the reliability of the water distribution system, considering factors like redundancy and resilience.
     */
    void reliability();

public:
    /**
     * @brief Constructs a new Menu object.
     *
     * Initializes the Menu, setting up the necessary environment for user interaction.
     */
    Menu();

    /**
     * @brief Initializes the menu system.
     *
     * Starts the menu system, displaying the main menu and processing user input.
     */
    void init();

    /**
     * @brief Ends the application.
     *
     * Provides a static method to gracefully exit the application.
     */
    static void end();
};

#endif // UNTITLED_MENU_H
