#ifndef DA_TSP_MENU_H
#define DA_TSP_MENU_H
#include "Parser.h"

class Menu {
    protected:
        GraphInterface graph;
    private:
        void chooseTypeofGraph();
        void realWorldGraphMenu();
        void extraGraphMenu();
        void toyGraphMenu();


    public:
    explicit Menu(GraphInterface graph);
    void init();
        static void end();
};


#endif //DA_TSP_MENU_H
