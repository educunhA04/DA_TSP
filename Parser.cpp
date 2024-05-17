//
// Created by edumr on 16/05/2024.
//

#include "Parser.h"
#include <fstream>
#include <sstream>
using namespace std;

GraphInterface *toyGraph(const string &filepath) {
    GraphInterface *graph = new GraphInterface();
    ifstream file(filepath);
    if (!file.is_open()) {
        return nullptr;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string node1, node2, weight;
        getline(ss, node1, ';');
        getline(ss, node2, ';');
        getline(ss, weight, ';');
        graph->addNode(stoi(node1));
        graph->addNode(stoi(node2));
        graph->addBidirectionalEdge(stoi(node1), stoi(node2), stod(weight));
    }
    return graph;
}
