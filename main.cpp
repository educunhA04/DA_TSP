#include <iostream>
#include "Menu.h"

int main() {
    GraphInterface graph;
    Menu menu(graph);
    menu.init();
    menu.end();
    return 0;
}
