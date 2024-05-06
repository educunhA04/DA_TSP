
#include <string>
#include <iostream>
#include "Menu.h"
#include "GraphInterface.h"
#include "Functions.h"
#include "headers.h"
using namespace std;



Menu::Menu() {
    std::cout << "   .#######.              " << std::endl;
    std::cout << "  |        |------######." << std::endl;
    std::cout << "   |                   |" << std::endl;
    std::cout << "    |                 |  " << std::endl;
    std::cout << "     |               | " << std::endl;
    std::cout << "     |               | " << std::endl;
    std::cout << "     |               |" << std::endl;
    std::cout << "     |               |" << std::endl;
    std::cout << "    |              |" << std::endl;
    std::cout << "   |                 |" << std::endl;
    std::cout << "  |                    /" << std::endl;
    std::cout << " <                    |" << std::endl;
    std::cout << "  |                 |" << std::endl;
    std::cout << "    |             |" << std::endl;
    std::cout << "    |               |" << std::endl;
    std::cout << "     |               |" << std::endl;
    std::cout << "    |              |" << std::endl;
    std::cout << "   |               |" << std::endl;
    std::cout << "  |               |" << std::endl;
    std::cout << " |____---___-------." << std::endl;
    string inp;
    while (true) {
        cout <<"################################" << "\n"
             <<"#     Select a dataset:        #" << "\n"
             <<"#------------------------------#" << "\n"
             <<"#   1 -> Small dataset         #" << "\n"
             <<"#   2 -> Large dataset         #" << "\n"
             <<"#   E -> EXIT                  #" << "\n"
             <<"#                              #" << "\n"
             <<"################################" << "\n"
             <<"Option: "<<endl;

        cin >> inp;

        if (inp == "1") {
            loadData(1);

            init();
        }

        else if (inp == "2") {
            // Load data from files located in ../Project1LargeDataSet/
            loadData(2);

            init();
        }

        else if (inp == "e" || inp == "E") exit(0);
        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            Menu();
        }

    }

}


void Menu::init() {
    string inp;
    while (true) {
        cout <<"################################" << "\n"
             <<"#      Select an option:       #" << "\n"
             <<"#------------------------------#" << "\n"
             <<"#   1 -> Database              #" << "\n"
             <<"#   2 -> Max Flow              #" << "\n"
             <<"#   3 -> Reliability           #" << "\n"
             <<"#   B -> BACK                  #" << "\n"
             <<"#   E -> EXIT                  #" << "\n"
             <<"#                              #" << "\n"
             <<"################################" << "\n"

             <<"Option: ";

        cin >> inp;

        if (inp == "1") showStats();

        else if (inp == "2") showMaxFlow();

        else if (inp == "3") reliability();

        else if (inp == "B" || inp == "b") Menu();

        else if (inp == "e" || inp == "E") exit(0);

        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            init();
        }

    }
}
void Menu::showStats() {
    string inp;
    while (true) {
        cout <<"################################" << "\n"
             <<"#      Select an option:       #" << "\n"
             <<"#------------------------------#" << "\n"
             <<"#   1 -> Reservoirs            #" << "\n"
             <<"#   2 -> Pumping Stations      #" << "\n"
             <<"#   3 -> Cities                #" << "\n"
             <<"#   4 -> Pipelines             #" << "\n"
             <<"#   B -> BACK                  #" << "\n"
             <<"#   E -> EXIT                  #" << "\n"
             <<"#                              #" << "\n"
             <<"################################" << "\n"

             <<"Option: ";

        cin >> inp;

        if (inp == "1") showReservoirs();

        else if (inp == "2") showPumpSt();

        else if (inp == "3") showCities();

        else if (inp == "4") showPipelines();

        else if (inp == "B" || inp == "b") init();

        else if (inp == "e" || inp == "E") exit(0);

        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            showStats();
        }

    }
}
void Menu::showMaxFlow() {
    string inp;
    while (true) {
        cout <<"################################" << "\n"
             <<"#      Select an option:       #" << "\n"
             <<"#------------------------------#" << "\n"
             <<"#   1 -> Specific City         #" << "\n"
             <<"#   2 -> All Cities            #" << "\n"
             <<"#   3 -> Water Needs           #" << "\n"
             <<"#   4 -> Total Max Flow        #" << "\n"
             <<"#   5 -> Balancing             #" << "\n"
             <<"#   B -> BACK                  #" << "\n"
             <<"#   E -> EXIT                  #" << "\n"
             <<"#                              #" << "\n"
             <<"################################" << "\n"

             <<"Option: ";

        cin >> inp;


        if (inp == "1") {

            cityMaxFlow();

        }
        else if (inp == "2") {
            allcities();
        }
        else if (inp == "3") {
            needs();
        }

        else if (inp == "4") {
            totalMaxFlow();
        }

        else if (inp == "5") {
            demonstrateImprovement();
        }

        else if (inp == "B" || inp == "b") init();
        else if (inp == "e" || inp == "E") exit(0);
        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            showMaxFlow();
        }
    }
}

void Menu::reliability() {
    string inp;
    while (true) {
        cout <<"################################" << "\n"
             <<"#      Select an option:       #" << "\n"
             <<"#------------------------------#" << "\n"
             <<"#   1 -> Remove Reservoir      #" << "\n"
             <<"#   2 -> Remove Station        #" << "\n"
             <<"#   3 -> Remove Pipeline       #" << "\n"
             <<"#   B -> BACK                  #" << "\n"
             <<"#   E -> EXIT                  #" << "\n"
             <<"#                              #" << "\n"
             <<"################################" << "\n"

             <<"Option: ";

        cin >> inp;

        if (inp == "1") {
            canWaterReservoirBeTakenOutOfService();
        }
        if (inp == "2") {
            canPumpingStationBeTakenOutOfService();
        }
        if (inp == "3") {
            assessPipelineImpacts();
        }

        else if (inp == "B" || inp == "b") init();
        else if (inp == "e" || inp == "E") exit(0);
        else {
            cout << "Insert a valid input!" << endl;
            cin.clear();
            reliability();
        }
    }
}
void Menu::end() {
    cout << "-------------" << endl;
}
