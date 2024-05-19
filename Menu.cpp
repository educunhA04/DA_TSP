#include "Menu.h"
#include "Parser.h"
#include <chrono>
#include <iostream>

Menu::Menu() {
    init();
}

// Choose graph type
void Menu::init() {
    std::string inp;
    while (true) {
        std::cout << "###################################" << "\n"
                  << "#     Select an option:           #" << "\n"
                  << "#---------------------------------#" << "\n"
                  << "#   1 -> Toy Graph                #" << "\n"
                  << "#   2 -> Real World Graph         #" << "\n"
                  << "#   3 -> Extra Medium-Size Graph  #" << "\n"
                  << "#   E -> EXIT                     #" << "\n"
                  << "#                                 #" << "\n"
                  << "###################################" << "\n"
                  << "Option: " << std::endl;

        std::cin >> inp;

        if (inp == "1") {
            toyGraphMenu();
        } else if (inp == "2") {
            realWorldGraphMenu();
        } else if (inp == "3") {
            extraGraphMenu();
        } else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        } else {
            std::cout << "Insert a valid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::chooseAlgorithm() {
    std::string inp;
    while (true) {
        std::cout << "###################################" << "\n"
                  << "#     Select an algorithm:        #" << "\n"
                  << "#---------------------------------#" << "\n"
                  << "#   1 -> Backtracking Algorithm   #" << "\n"
                  << "#   2 -> Triangular Approximation #" << "\n"
                  << "#   3 -> Other Heuristics         #" << "\n"
                  << "#   B -> BACK                     #" << "\n"
                  << "#   E -> EXIT                     #" << "\n"
                  << "#                                 #" << "\n"
                  << "###################################" << "\n"
                  << "Option: " << std::endl;

        std::cin >> inp;

        if (inp == "1") {
            backtracking();
        } else if (inp == "2") {
            triang();
        } else if (inp == "3") {
            heuristic();
        }
        else if (inp == "B" || inp == "b") {
            init();
        }
        else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        } else {
            std::cout << "Insert a valid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::realWorldGraphMenu() {
    std::string inp;
    while (true) {
        std::cout << "###################################" << "\n"
                  << "#     Select an option:           #" << "\n"
                  << "#---------------------------------#" << "\n"
                  << "#   1 -> graph1                   #" << "\n"
                  << "#   2 -> graph2                   #" << "\n"
                  << "#   3 -> graph3                   #" << "\n"
                  << "#   B -> BACK                     #" << "\n"
                  << "#   E -> EXIT                     #" << "\n"
                  << "#                                 #" << "\n"
                  << "###################################" << "\n"
                  << "Option: " << std::endl;

        std::cin >> inp;

        if (inp == "1") {
            if (finalGraph) finalGraph->clearAllNodes();
            realWorldGraph("../data_to_test/Real-world Graphs/graph1/nodes.csv", "../data_to_test/Real-world Graphs/graph1/edges.csv");
            chooseAlgorithm();
        } else if (inp == "2") {
            if (finalGraph) finalGraph->clearAllNodes();
            realWorldGraph("../data_to_test/Real-world Graphs/graph2/nodes.csv", "../data_to_test/Real-world Graphs/graph2/edges.csv");
            chooseAlgorithm();
        } else if (inp == "3") {
            if (finalGraph) finalGraph->clearAllNodes();
            realWorldGraph("../data_to_test/Real-world Graphs/graph3/nodes.csv", "../data_to_test/Real-world Graphs/graph3/edges.csv");
            chooseAlgorithm();
        } else if (inp == "B" || inp == "b") {
            init();
        } else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        } else {
            std::cout << "Insert a valid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::toyGraphMenu() {
    std::string inp;
    while (true) {
        std::cout << "###################################" << "\n"
                  << "#     Select an option:           #" << "\n"
                  << "#---------------------------------#" << "\n"
                  << "#   1 -> shipping                 #" << "\n"
                  << "#   2 -> stadiums                 #" << "\n"
                  << "#   3 -> tourism                  #" << "\n"
                  << "#   B -> BACK                     #" << "\n"
                  << "#   E -> EXIT                     #" << "\n"
                  << "#                                 #" << "\n"
                  << "###################################" << "\n"
                  << "Option: " << std::endl;

        std::cin >> inp;

        if (inp == "1") {
            if (finalGraph) finalGraph->clearAllNodes();
            toyGraph("../data_to_test/Toy-graphs/shipping.csv");
            chooseAlgorithm();
        } else if (inp == "2") {
            if (finalGraph) finalGraph->clearAllNodes();
            toyGraph("../data_to_test/Toy-graphs/stadiums.csv");
            chooseAlgorithm();
        } else if (inp == "3") {
            if (finalGraph) finalGraph->clearAllNodes();
            toyGraph("../data_to_test/Toy-graphs/tourism.csv");
            chooseAlgorithm();
        }
        else if (inp == "B" || inp == "b") {
            init();
        }
        else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        } else {
            std::cout << "Insert a valid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::extraGraphMenu() {
    std::string inp;
    while (true) {
        std::cout << "#####################################" << "\n"
                  << "#     Insert one of the values:     #" << "\n"
                  << "#-----------------------------------#" << "\n"
                  << "#   25 |  50  |  75  |  100  |  200 #" << "\n"
                  << "#  300 | 400  | 500  |  600  |  700 #" << "\n"
                  << "#            800 | 900              #" << "\n"
                  << "#                                   #" << "\n"
                  << "#   B -> BACK                       #" << "\n"
                  << "#   E -> EXIT                       #" << "\n"
                  << "#####################################" << "\n"
                  << "Option: " << std::endl;

        std::cin >> inp;

        if (inp == "25" || inp == "50" || inp == "75" || inp == "100" ||
            inp == "200" || inp == "300" || inp == "400" || inp == "500" ||
            inp == "600" || inp == "700" || inp == "800" || inp == "900") {
            if (finalGraph) finalGraph->clearAllNodes();
            extraGraph("../data_to_test/Extra_Fully_Connected_Graphs/edges_" + inp + ".csv");
            chooseAlgorithm();
        } else if (inp == "e" || inp == "E") {
            end();
            exit(0);
        }
        else if (inp == "B" || inp == "b") {
            init();
        }
        else {
            std::cout << "Insert a valid input!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::backtracking() {
    std::vector<Node *> path;
    auto start = std::chrono::high_resolution_clock::now();
    double distance = finalGraph->solveTSPBacktracking(path);
    distance = finalGraph->twoOptOptimization(path, distance);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "| The heuristic found a distance of " << distance << " meters";

    std::cout << std::string(5, ' ') << "\n";
    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds"
              << std::string(59 - 29 - std::to_string(elapsed.count()).length(), ' ') << "\n";

    std::cout << "| The path is:\n";
    cout << "0";
    for (int i = 1; i < path.size(); i++) {
        std::cout << " -> " << path[i]->getIndex();
    }
    cout << endl;

}

void Menu::triang() {
    std::vector<Node *> path;
    auto start = std::chrono::high_resolution_clock::now();
    double distance = finalGraph->triangularApproximationHeuristic(path);
    distance = finalGraph->twoOptOptimization(path, distance);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "| The heuristic found a distance of " << distance << " meters";

    std::cout << std::string(5, ' ') << "\n";
    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds"
              << std::string(59 - 29 - std::to_string(elapsed.count()).length(), ' ') << "\n";

    std::cout << "| The path is:\n";
    cout << "0";
    for (int i = 1; i < path.size(); i++) {
        std::cout << " -> " << path[i]->getIndex();
    }
    cout << endl;
}

void Menu::heuristic() {
    std::vector<Node *> path;
    auto start = std::chrono::high_resolution_clock::now();
    double distance = finalGraph->nearestNeighborHeuristic(path);
    distance = finalGraph->twoOptOptimization(path, distance);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "| The heuristic found a distance of " << distance << " meters";

    std::cout << std::string(5, ' ') << "\n";
    std::cout << "| Total time elapsed: " << elapsed.count() << " seconds"
              << std::string(59 - 29 - std::to_string(elapsed.count()).length(), ' ') << "\n";

    std::cout << "| The path is:\n";
    cout << "0";
    for (int i = 1; i < path.size(); i++) {
        std::cout << " -> " << path[i]->getIndex();
    }
    cout << endl;
}

void Menu::end() {
    std::cout << "###################################" << "\n"
              << "#             THANKS!!!           #" << "\n"
              << "###################################" << "\n" << std::endl;
}
