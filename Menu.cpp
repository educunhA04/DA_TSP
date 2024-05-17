#include "Menu.h"
#include <iostream>
Menu::Menu() {
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
            //chooseTypeofGraph("Backtracking");
        }
        else if (inp == "2") {
            //chooseTypeofGraph("Triangular");
        }
        else if (inp == "3") {
            //chooseTypeofGraph("Other");
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
void Menu::chooseTypeofGraph(const std::string &algorithm) {
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
            //chooseTypeofGraph("Backtracking");
        }
        else if (inp == "2") {
            //chooseTypeofGraph("Triangular");
        }
        else if (inp == "3") {
            //chooseTypeofGraph("Other");
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