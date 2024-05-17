#ifndef DA_TSP_MENU_H
#define DA_TSP_MENU_H
#include "GraphInterface.h"

class Menu {
    private:
        void chooseTypeofGraph(const string &algorithm);
        void realWorldGraph(const string &algorithm, const string &file);
        void extraGraph(const string &algorithm, const string &file);
        void toyGraph(const string &algorithm, const string &file);


    public:
        Menu();
        void init();
        static void end();
};


#endif //DA_TSP_MENU_H
