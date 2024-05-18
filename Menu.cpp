#include "Menu.h"

#include <iostream>
Menu::Menu(GraphInterface graph): graph(graph){};

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
             <<"#     Select an option:           #" << "\n"
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
             <<"#     Select an option:           #" << "\n"
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
            realWorldGraph("../data_to_test/Real-world Graphs/graph1/nodes.csv", "../data_to_test/Real-world Graphs/graph1/edges.csv");
        }
        else if (inp == "2") {
            realWorldGraph("../data_to_test/Real-world Graphs/graph2/nodes.csv", "../data_to_test/Real-world Graphs/graph2/edges.csv");
        }
        else if (inp == "3") {
            realWorldGraph("../data_to_test/Real-world Graphs/graph3/nodes.csv", "../data_to_test/Real-world Graphs/graph3/edges.csv");
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

void Menu::toyGraphMenu() {
    string inp;
    while (true) {
        cout <<"###################################" << "\n"
             <<"#     Select an option:           #" << "\n"
             <<"#---------------------------------#" << "\n"
             <<"#   1 -> shipping                 #" << "\n"
             <<"#   2 -> stadiums                 #" << "\n"
             <<"#   3 -> tourism                  #" << "\n"
             <<"#   E -> EXIT                     #" << "\n"
             <<"#                                 #" << "\n"
             <<"###################################" << "\n"
             <<"Option: "<<endl;

        cin >> inp;

        if (inp == "1") {
            toyGraph("../data_to_test/Toy-graphs/shipping.csv");
        }
        else if (inp == "2") {
            toyGraph("../data_to_test/Toy-graphs/stadiums.csv");
        }
        else if (inp == "3") {
            toyGraph("../data_to_test/Toy-graphs/tourism.csv");
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

void Menu::extraGraphMenu() {
    string inp;
    while (true) {
        cout <<"#####################################" << "\n"
             <<"#     Insert one of the values:     #" << "\n"
             <<"#-----------------------------------#" << "\n"
             <<"#   25 |  50  |  75  |  100  |  200 #" << "\n"
             <<"#  300 | 400  | 500  |  600  |  700 #" << "\n"
             <<"#            800 | 900              #" << "\n"
             <<"#                                   #" << "\n"
             <<"#####################################" << "\n"
             <<"Option: "<<endl;

        cin >> inp;

        if (inp != "25" || inp != "50" ||inp != "75" ||inp != "100" ||inp != "200" ||inp != "300" ||inp != "400" ||inp != "500" ||inp != "600" ||inp != "700" ||inp != "800" ||inp != "900") {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            extraGraphMenu();
        }

        else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        }

        else {
            extraGraph("../data_sets/Extra_Fully_Connected_Graphs/edges_" + inp + ".csv");

        }
    }
}

void Menu::end() {
    cout <<"###################################" << "\n"
         <<"#             THANKS!!!           #" << "\n"
         <<"###################################" << "\n" << endl;
}