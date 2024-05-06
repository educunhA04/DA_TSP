//
// Created by edumr on 05/04/2024.
//
#include "GraphInterface.h"
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"
#include "headers.h"

GraphInterface::GraphInterface() = default;
void GraphInterface::removeAll() {
    for (auto vertex : graph.getVertexSet()) {
        vertex->removeOutgoingEdges();
    }
    graph.getVertexSet().clear();

}
void GraphInterface::loadReservoirs(const std::string& filename) {
    removeAll();
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string part;
        std::vector<std::string> parts;
        int count = 5;
        // Splitting the line by commas
        while (std::getline(iss, part, ',')) {
            if (count > 0) {
                parts.push_back(part);
            } else {
                break;
            }
            count--;
        }

        if (parts.size() >= 5) { // Ensure we have enough parts
            int id = std::stoi(parts[2]);
            int maxDelivery = std::stoi(parts[4]);
            auto reservoir = new WaterReservoir(parts[0], parts[1], id, parts[3], maxDelivery);
            reservoirs[parts[3]] = reservoir;
            graph.addVertex(parts[3]);
        }

    }
}

void GraphInterface::loadPumpingStations(const std::string& filename) {

    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string part;
        std::vector<std::string> parts;
        int count = 2;
        // Splitting the line by commas
        while (std::getline(iss, part, ',')) {
            //check the last line of the csv
            if (count > 0) {
                parts.push_back(part);
            }
            else {
                break;
            }
            count--;
        }
        if (std::isdigit(parts[0][0])) {
            int id = std::stoi(parts[0]);
            auto pumpingStation = new PumpingStation(id, parts[1]);
            pumpingStations[parts[1]] = pumpingStation;
            graph.addVertex(parts[1]);
        }
    }
}

void GraphInterface::loadCities(const std::string& filename) {

    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string part;
        std::vector<std::string> parts;

        // Splitting the line by commas
        while (std::getline(iss, part, ',')) {
            parts.push_back(part);
        }
        std::string pop;
        int population;
        if (parts.size() == 6) {
            for (auto c : parts[4]) {
                if (c >= '0' && c <= '9') {
                    pop += c;
                }
            }
            for (auto c : parts[5]) {
                if (c >= '0' && c <= '9') {
                    pop += c;
                }
            }
            population = std::stoi(pop);
        }
        else {
            population = std::stoi(parts[4]);
        }
        int id = std::stoi(parts[1]);
        int demand = std::stoi(parts[3]);
        std::string cityName = parts[0];
        std::string code = parts[2];
        auto city = new City(cityName, id, code, demand, population);
        cities[code] = city;
        graph.addVertex(code);
    }
}

void GraphInterface::loadPipelines(const std::string& filename) {

    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // Skip header line

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string part;
        std::vector<std::string> parts;

        // Splitting the line by commas
        while (std::getline(iss, part, ',')) {
            parts.push_back(part);
        }

        std::string sourceCode = parts[0];
        std::string destCode = parts[1];
        double capacity = std::stod(parts[2]);
        int direction = std::stoi(parts[3]);

        graph.addEdge(sourceCode, destCode, capacity);
        if (direction == 0) {
            graph.addEdge(destCode, sourceCode, capacity); // Ensure bidirectional if specified
        }
    }
}

std::unordered_map<std::string, WaterReservoir*> GraphInterface::getReservoirs() {
    return reservoirs;
}

std::unordered_map<std::string, PumpingStation*> GraphInterface::getPumpingStations() {
    return pumpingStations;
}

std::unordered_map<std::string, City*> GraphInterface::getCities() {
    return cities;
}

Graph<std::string> GraphInterface::getGraph() {
    return graph;
}


