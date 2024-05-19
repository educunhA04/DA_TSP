#ifndef DA_TSP_MENU_H
#define DA_TSP_MENU_H

#include "Parser.h"

/**
 * @brief A class representing the main menu for the TSP application.
 */
class Menu {
private:
    /**
     * @brief Displays the menu for choosing an algorithm after selecting a graph type.
     */
    void chooseAlgorithm();

    /**
     * @brief Displays the menu for selecting real-world graphs and their specific datasets.
     */
    void realWorldGraphMenu();

    /**
     * @brief Displays the menu for selecting extra medium-size graphs.
     */
    void extraGraphMenu();

    /**
     * @brief Displays the menu for selecting toy graphs and their specific datasets.
     */
    void toyGraphMenu();

    /**
     * @brief Executes the backtracking algorithm for solving the TSP problem.
     */
    void backtracking();

    /**
     * @brief Executes the triangular approximation heuristic for solving the TSP problem.
     */
    void triang();

    /**
     * @brief Executes other heuristic algorithms for solving the TSP problem.
     */
    void heuristic();

public:
    /**
     * @brief Constructs a new Menu object.
     */
    Menu();

    /**
     * @brief Initializes the main menu and handles user input.
     */
    void init();

    /**
     * @brief Displays a closing message when exiting the application.
     */
    static void end();
};

#endif //DA_TSP_MENU_H
