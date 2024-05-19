#ifndef DA_TSP_MENU_H
#define DA_TSP_MENU_H
#include "Parser.h"

class Menu {
    private:
        void chooseAlgorithm();
        void realWorldGraphMenu();
        void extraGraphMenu();
        void toyGraphMenu();
        void backtracking();
        void triang();
        void heuristic();

    public:
    Menu();
    void init();
    static void end();
};


#endif //DA_TSP_MENU_H
