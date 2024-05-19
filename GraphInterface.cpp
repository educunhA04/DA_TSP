#include "GraphInterface.h"
#include <cfloat>
#include <cmath>
#include <algorithm>

// Find a node by its index
Node* GraphInterface::findNode(int index) {
    for (auto v : nodes) {
        if (v->getIndex() == index) {
            return v;
        }
    }
    return nullptr;
}

// Get a node by its index
Node* GraphInterface::getNode(const int& index) {
    return findNode(index);
}

// Get all nodes
std::vector<Node*> GraphInterface::getNodes() {
    return nodes;
}

// Clear all nodes
void GraphInterface::clearAllNodes() {
    for (auto& node : nodes) {
        node->setPath(nullptr);
    }
    for (auto it = nodes.begin(); it != nodes.end();) {
        auto node = *it;
        node->removeOutgoingEdges();
        for (auto u : nodes) {
            u->removeEdge(node->getIndex());
        }
        it = nodes.erase(it);
        delete node;
    }
}

// Add a node
bool GraphInterface::addNode(const int& index, double latitude, double longitude) {
    if (findNode(index) == nullptr) {
        nodes.push_back(new Node(index, latitude, longitude));
        return true;
    }
    return false;
}

// Add a bidirectional edge
bool GraphInterface::addBidirectionalEdge(const int& node1, const int& node2, double w) {
    Node* n1 = findNode(node1);
    Node* n2 = findNode(node2);
    if (n1 != nullptr && n2 != nullptr) {
        n1->addEdge(n2, w);
        n2->addEdge(n1, w);
        return true;
    }
    return false;
}

// Backtracking algorithm for TSP
void GraphInterface::backtrackTSP(Node* current_node, unsigned int current_index, double total_distance, std::vector<Node*>& current_path, double& best_distance, std::vector<Node*>& best_path) {
    current_node->setVisited(true);
    current_path[current_index - 1] = current_node;

    if (current_index == nodes.size()) { // reached all nodes
        current_node->setVisited(false);
        // see if there is an edge back to the start node
        for (auto edge : current_node->getAdj()) {
            if (edge->getDest()->getIndex() == 0) {
                double return_edge_weight = edge->getWeight();
                double total = total_distance + return_edge_weight;
                if (total < best_distance) {
                    best_distance = total;
                    best_path = current_path;
                }
                break;
            }
        }
        return;
    }

    for (auto edge : current_node->getAdj()) {
        Node* next_node = edge->getDest();
        double edge_weight = edge->getWeight();
        if (!next_node->isVisited() && total_distance + edge_weight < best_distance) {
            backtrackTSP(next_node, current_index + 1, total_distance + edge_weight, current_path, best_distance, best_path);
        }
    }

    current_node->setVisited(false);
}

// Solve TSP using backtracking
double GraphInterface::solveTSPBacktracking(std::vector<Node*>& path) {
    std::vector<Node*> current_path(nodes.size());
    double shortest_distance = DBL_MAX;

    for (auto node : nodes) {
        node->setVisited(false);
    }

    backtrackTSP(nodes[0], 1, 0.0, current_path, shortest_distance, path);
    return shortest_distance;
}

// Convert degrees to radians
double GraphInterface::toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Haversine formula to calculate distance between two points
double GraphInterface::haversine(double lat1, double lon1, double lat2, double lon2) {
    double earth_radius = 6371000; // meters

    double rad_lat1 = toRadians(lat1);
    double rad_lon1 = toRadians(lon1);
    double rad_lat2 = toRadians(lat2);
    double rad_lon2 = toRadians(lon2);

    double delta_lat = rad_lat2 - rad_lat1;
    double delta_lon = rad_lon2 - rad_lon1;

    double aux = sin(delta_lat / 2) * sin(delta_lat / 2) +
                 cos(rad_lat1) * cos(rad_lat2) *
                 sin(delta_lon / 2) * sin(delta_lon / 2);

    double c = 2.0 * atan2(sqrt(aux), sqrt(1.0 - aux));

    return earth_radius * c;
}

// Triangular approximation heuristic for TSP
double GraphInterface::triangularApproximationHeuristic(std::vector<Node*>& path) {
    double approx_distance = 0.0;

    Node* current_node = findNode(0);
    current_node->setVisited(true);
    path.push_back(current_node);

    while (path.size() < nodes.size()) {
        double min_distance = DBL_MAX;
        Node* next_node = nullptr;

        for (auto edge : current_node->getAdj()) {
            Node* neighbor_node = edge->getDest();
            if (!neighbor_node->isVisited()) {
                double distance = edge->getWeight();
                if (distance < min_distance) {
                    min_distance = distance;
                    next_node = neighbor_node;
                }
            }
        }

        if (next_node != nullptr) {
            approx_distance += min_distance;
            next_node->setVisited(true);
            path.push_back(next_node);
            current_node = next_node;
        }

        else {
            break;
        }
    }

    for (auto edge : current_node->getAdj()) {
        if (edge->getDest()->getIndex() == 0) {
            approx_distance += edge->getWeight();
            path.push_back(findNode(0));
            break;
        }
    }

    return approx_distance;
}

// Nearest neighbor heuristic for TSP
double GraphInterface::nearestNeighborHeuristic(std::vector<Node*>& path) {
    double total_distance = 0.0;
    std::vector<bool> visited(nodes.size(), false);

    Node* current_node = nodes[0];
    path.push_back(current_node);
    visited[current_node->getIndex()] = true;

    while (path.size() < nodes.size()) {
        Node* next_node = nullptr;
        double shortest_distance = DBL_MAX;

        for (auto edge : current_node->getAdj()) {
            Node* neighbor = edge->getDest();
            if (!visited[neighbor->getIndex()]) {
                double dist = edge->getWeight();
                if (dist < shortest_distance) {
                    shortest_distance = dist;
                    next_node = neighbor;
                }
            }
        }

        if (next_node) {
            total_distance += shortest_distance;
            current_node = next_node;
            path.push_back(current_node);
            visited[current_node->getIndex()] = true;
        } else {
            break;
        }
    }

    total_distance += haversine(current_node->getLatitude(), current_node->getLongitude(), nodes[0]->getLatitude(), nodes[0]->getLongitude());
    path.push_back(nodes[0]);

    total_distance = twoOptOptimization(path, total_distance);

    return total_distance;
}

// 2-opt optimization to improve the initial tour
double GraphInterface::twoOptOptimization(std::vector<Node*>& path, double current_distance) {
    bool improvement = true;

    while (improvement) {
        improvement = false;
        for (size_t i = 1; i < path.size() - 2; i++) {
            for (size_t j = i + 1; j < path.size() - 1; j++) {
                double new_distance = current_distance -
                                      haversine(path[i-1]->getLatitude(), path[i-1]->getLongitude(), path[i]->getLatitude(), path[i]->getLongitude()) -
                                      haversine(path[j]->getLatitude(), path[j]->getLongitude(), path[j+1]->getLatitude(), path[j+1]->getLongitude()) +
                                      haversine(path[i-1]->getLatitude(), path[i-1]->getLongitude(), path[j]->getLatitude(), path[j]->getLongitude()) +
                                      haversine(path[i]->getLatitude(), path[i]->getLongitude(), path[j+1]->getLatitude(), path[j+1]->getLongitude());

                if (new_distance < current_distance) {
                    std::reverse(path.begin() + i, path.begin() + j + 1);
                    current_distance = new_distance;
                    improvement = true;
                }
            }
        }
    }

    return current_distance;
}
