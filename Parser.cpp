//
// Created by edumr on 16/05/2024.
//

#include "Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
using namespace std;

GraphInterface *finalGraph;

GraphInterface *toyGraph(const string &filepath) {
    GraphInterface *graph = new GraphInterface();
    ifstream file(filepath);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return nullptr;
    }

    string line;

    if (!getline(file, line)) {
        cerr << "Empty file" << endl;
        delete graph;
        return nullptr;
    }

    // Determine the number of columns in the CSV file
    char delimiter = ',';
    int num_columns = count(line.begin(), line.end(), delimiter) + 1;

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string source, dest, distance, label_source, label_dest;

        if (num_columns == 3) { // for shipping.csv and stadiums.csv
            getline(ss, source, ',');
            getline(ss, dest, ',');
            getline(ss, distance, ',');
        }
        else if (num_columns == 5) { // for tourism.csv
            getline(ss, source, ',');
            getline(ss, dest, ',');
            getline(ss, distance, ',');

            getline(ss, label_source, ','); // not being used
            getline(ss, label_dest,','); // not being used
        }
        else {
            cerr << "Invalid number of columns in CSV file" << endl;
            delete graph;
            return nullptr;
        }

        // Add nodes and edges to the graph
        graph->addNode(stoi(source));
        graph->addNode(stoi(dest));
        graph->addBidirectionalEdge(stoi(source), stoi(dest), stod(distance));
    }
    finalGraph = graph;
    return graph;
}


GraphInterface *realWorldGraph(const string& nodesFile, const string& edgesFile) {
    GraphInterface *graph = new GraphInterface();

// load and parse nodes
    ifstream nodes_file(nodesFile);
    if (!nodes_file.is_open()) {
        cerr << "Error opening nodes file" << endl;
        delete graph;
        return nullptr;
    }

    string line;
    getline(nodes_file, line);

    while (getline(nodes_file, line)) {
        istringstream iss(line);

        string id, latitude, longitude;

        getline(iss, id, ',');
        getline(iss, longitude, ',');
        getline(iss, latitude, ',');

        graph->addNode(stoi(id), stod(latitude), stod(longitude));
    }
    nodes_file.close();

// load and parse edges
    ifstream edges_file(edgesFile);
    if (!edges_file.is_open()) {
        cerr << "Error opening edges file" << endl;
        delete graph;
        return nullptr;
    }

    getline(edges_file, line);

    while (getline(edges_file, line)) {
        istringstream iss(line);
        string source, dest, distance;

        getline(iss, source, ',');
        getline(iss, dest, ',');
        getline(iss, distance, ',');

        graph->addNode(stoi(source));
        graph->addNode(stoi(dest));

        graph->addBidirectionalEdge(stoi(source), stoi(dest), stod(distance));
    }
    edges_file.close();
    finalGraph = graph;
    return graph;
}


GraphInterface *extraGraph(const string& edgesFile) {

    // Extract the number of nodes from the file name
    filesystem::path edges_file_path(edgesFile);
    string fileName = edges_file_path.filename().string();

    size_t start = fileName.find_first_of("0123456789");
    size_t end = fileName.find_first_not_of("0123456789", start);

    string num_nodes_file = fileName.substr(start, end - start);
    int num_nodes = stoi(num_nodes_file);

    GraphInterface *graph = new GraphInterface();

    for (int i = 0; i < num_nodes; ++i) {
        graph->addNode(i);  // Assuming node IDs start from 0
    }

// load and parse edges
    ifstream edges_file(edgesFile);
    if (!edges_file.is_open()) {
        cerr << "Error opening edges file" << endl;
        delete graph;
        return nullptr;
    }

    string line;

    while (getline(edges_file, line)) {
        istringstream iss(line);
        string source, dest, distance;

        getline(iss, source, ',');
        getline(iss, dest, ',');
        getline(iss, distance, ',');

        graph->addNode(stoi(source));
        graph->addNode(stoi(dest));

        graph->addBidirectionalEdge(stoi(source), stoi(dest), stod(distance));
    }
    edges_file.close();

    finalGraph = graph;
    return graph;
}

