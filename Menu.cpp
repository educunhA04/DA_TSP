#include "Menu.h"

#include <iostream>
Menu::Menu(){
    init();
}

void Menu::init() {
    string inp;
    while (true) {
        cout <<"###################################" << "\n"
             <<"#     Select an algorithm:        #" << "\n"
             <<"#---------------------------------#" << "\n"
             <<"#   1 -> Backtracking Algorithm   #" << "\n"
             <<"#   2 -> Triangular Approximation #" << "\n"
             <<"#   3 -> Other Heuristics         #" << "\n"
             <<"#   E -> EXIT                     #" << "\n"
             <<"#                                 #" << "\n"
             <<"###################################" << "\n"
             <<"Option: "<<endl;

        cin >> inp;

        if (inp == "1") {
            chooseTypeofGraph();
        }
        else if (inp == "2") {
            chooseTypeofGraph();
        }
        else if (inp == "3") {
            chooseTypeofGraph();
        }

        else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        }

        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            init();
        }
    }
}


// Choose graph type
void Menu::chooseTypeofGraph() {
    string inp;
    while (true) {
        cout <<"###################################" << "\n"
             <<"#     Select an algorithm:        #" << "\n"
             <<"#---------------------------------#" << "\n"
             <<"#   1 -> Toy Graph                #" << "\n"
             <<"#   2 -> Real World Graph         #" << "\n"
             <<"#   3 -> Extra Medium-Size Graph  #" << "\n"
             <<"#   E -> EXIT                     #" << "\n"
             <<"#                                 #" << "\n"
             <<"###################################" << "\n"
             <<"Option: "<<endl;

        cin >> inp;

        if (inp == "1") {
            toyGraphMenu();
        }
        else if (inp == "2") {
            realWorldGraphMenu();
        }
        else if (inp == "3") {
            extraGraphMenu();
        }

        else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        }

        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            init();
        }
    }
}


void Menu::realWorldGraphMenu() {
    string inp;
    while (true) {
        cout <<"###################################" << "\n"
             <<"#     Select an algorithm:        #" << "\n"
             <<"#---------------------------------#" << "\n"
             <<"#   1 -> graph1                   #" << "\n"
             <<"#   2 -> graph2                   #" << "\n"
             <<"#   3 -> graph3                   #" << "\n"
             <<"#   E -> EXIT                     #" << "\n"
             <<"#                                 #" << "\n"
             <<"###################################" << "\n"
             <<"Option: "<<endl;

        cin >> inp;

        if (inp == "1") {

        }
        else if (inp == "2") {
            realWorldGraph("../data_sets/Real-world Graphs/graph1/nodes.csv", "../data_sets/Real-world Graphs/graph1/edges.csv");
        }
        else if (inp == "3") {
            extraGraph();
        }

        else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        }

        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            init();
        }
    }
}

void Menu::end() {
    cout <<"###################################" << "\n"
         <<"#             THANKS!!!           #" << "\n"
         <<"###################################" << "\n" << endl;
}