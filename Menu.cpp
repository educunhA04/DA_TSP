#include "Menu.h"
#include <chrono>
#include <iostream>

Menu::Menu() {
    GraphInterface *graph;
    init();
}

// Choose graph type
void Menu::init() {
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

void Menu::chooseAlgorithm() {
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
            backtracking();
        }

        else if (inp == "2") {
            triang();
        }
        else if (inp == "3") {
            heuristic();
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
            realWorldGraph("../data_to_test/Real-world Graphs/graph1/nodes.csv", "/data_to_test/Real-world Graphs/graph1/edges.csv");
            chooseAlgorithm();
        }
        else if (inp == "2") {
            realWorldGraph("../data_to_test/Real-world Graphs/graph2/nodes.csv", "/data_to_test/Real-world Graphs/graph2/edges.csv");
            chooseAlgorithm();
        }
        else if (inp == "3") {
            realWorldGraph("../data_to_test/Real-world Graphs/graph3/nodes.csv", "/data_to_test/Real-world Graphs/graph3/edges.csv");
            chooseAlgorithm();
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
            chooseAlgorithm();
        }
        else if (inp == "2") {
            toyGraph("../data_to_test/Toy-graphs/stadiums.csv");
            chooseAlgorithm();
        }
        else if (inp == "3") {
            toyGraph("../data_to_test/Toy-graphs/tourism.csv");
            chooseAlgorithm();
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

        if (inp == "25" || inp == "50" || inp == "75" || inp == "100" ||
            inp == "200" || inp == "300" || inp == "400" || inp == "500" ||
            inp == "600" || inp == "700" || inp == "800" || inp == "900") {
            extraGraph("../data_to_test/Extra_Fully_Connected_Graphs/edges_" + inp + ".csv");
            chooseAlgorithm();
        }
        else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        }
        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
        }
    }
}

void Menu::backtracking() {
    std::vector<Node*> path;
    auto start = std::chrono::high_resolution_clock::now();
    double minDistance = finalGraph->solveTSPBacktracking(path);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::string minDistanceString = std::to_string(minDistance);


    std::cout << "|-----------------------------------------------------------|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| The shortest path found has a distance of ";

    std::cout << minDistance;
    std::cout << " meters";

    for(int i = 0; i < 5; i++){
        std::cout << " ";
    }

    std::cout << "|\n";
    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds";
    for(int i = 0; i < 59 - 29 - std::to_string(elapsed.count()).length(); i++){
        std::cout << " ";
    }
    std::cout << "|\n";
    std::cout << "|                                                           |\n";
    std::cout << "| Do you wish to see the path?                              |\n";
    std::cout << "| Enter here your choice (yes/no): ";
    std::string choice;
    while (true){
        std::getline(std::cin, choice);
        if(choice == "yes"){
            int charCounter = 1;
            std::cout << "|                                                           |\n";
            std::cout << "| The path is:                                              |\n";
            std::cout << "| ";
            for(int i = 0; i < path.size(); i++){
                charCounter += (4 + std::to_string(path[i]->getIndex()).length());
                if (charCounter > 58){
                    for(int j = 0; j < 59 - charCounter + std::to_string(path[i]->getIndex()).length() + 4; j++){
                        std::cout << " ";
                    }
                    std::cout << "|\n";
                    std::cout << "| ";
                    charCounter = (1 + 4 + std::to_string(path[i]->getIndex()).length());
                }
                if(i == path.size() - 1){
                    std::cout << path[i]->getIndex();
                    charCounter -= 4;
                }
                else{
                    std::cout << path[i]->getIndex() << " -> ";
                }
            }
            charCounter += 5;
            if(charCounter > 58){
                for(int j = 0; j < 59 - charCounter; j++){
                    std::cout << " ";
                }
                std::cout << "| \n";
                charCounter = 5;
            }

            std::cout << " -> 0";
            for(int j = 0; j < 59 - charCounter; j++){
                std::cout << " ";
            }

            std::cout << "|\n";
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - BACKTRACKING MENU -                                     |\n";
            break;
        }
        else if(choice == "no"){
            std::cout << "|                                                           |\n";
            std::cout << "|-----------------------------------------------------------|\n";
            std::cout << "|                                                           |\n";
            std::cout << "| - BACKTRACKING MENU -                                     |\n";
            break;
        }
        else{
            std::cout << "|                                                           |\n";
            std::cout << "| Not a valid input, please try again                       |\n";
            std::cout << "|                                                           |\n";
            std::cout << "| Do you wish to see the path?                              |\n";
            std::cout << "| Enter here your choice (yes/no): ";
        }
    }
}

void Menu::triang() {

}

void Menu::heuristic() {


}

void Menu::end() {
    cout <<"###################################" << "\n"
         <<"#             THANKS!!!           #" << "\n"
         <<"###################################" << "\n" << endl;
}