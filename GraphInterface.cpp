#include "GraphInterface.h"
#include <cfloat>

Node *GraphInterface::findNode(int index){
    for (auto v : getNodes()) {
        if (v->getIndex() == index) {
            return v;
        }
    }
    return nullptr;
}

Node *GraphInterface::getNode(const int &index){
    return findNode(index);
}

vector<Node *> GraphInterface::getNodes(){
    return nodes;
}

void GraphInterface::clearAllNodes() {
    for (auto & node : nodes){
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

bool GraphInterface::addNode(const int &index, double latitude, double longitude){
    if (findNode(index) == nullptr) {
            nodes.push_back(new Node(index, latitude, longitude));
            return true;
        }
    return false;
}

bool GraphInterface::addBidirectionalEdge(const int &node1, const int &node2, double w){
    Node *n1 = findNode(node1);
    Node *n2 = findNode(node2);
    if (n1 != nullptr && n2 != nullptr) {
        n1->addEdge(n2, w);
        n2->addEdge(n1, w);
        return true;
    }
    return false;
}

// functions for backtracking (T2.1)

void GraphInterface::backtrackTSP(Node* current_node, unsigned int current_index, double total_distance, vector<Node*>& current_path, double& best_distance, vector<Node*>& best_path) {

    current_node->setVisited(true);
    current_path[current_index - 1] = current_node;

    if (current_index == nodes.size()) { // reached all nodes
        current_node->setVisited(false);

        // see if there is an edge back to the start node
        Edge* return_edge = nullptr;
        for (auto edge : current_node->getAdj()) {
            if (edge->getDest()->getIndex() == 0) {
                return_edge = edge;
                break;
            }
        }

        // if there is a return edge
        if (return_edge) {
            double return_edge_weight = return_edge->getWeight();
            total_distance = total_distance + return_edge_weight;

            if (total_distance < best_distance) {
                best_distance = total_distance;
                best_path = current_path;
            }
        }
        return;
    }

    // explore the other nodes
    for (auto edge : current_node->getAdj()) {
        Node* next_node = edge->getDest();

        double edge_weight = edge->getWeight();
        double sum_of_distances = total_distance + edge_weight;

        if (!next_node->isVisited() && sum_of_distances < best_distance) {
            backtrackTSP(next_node, current_index + 1, best_distance + edge->getWeight(), current_path, best_distance, best_path);
        }
    }

    current_node->setVisited(false);  // unmark current node
}

double GraphInterface::solveTSPBacktracking(vector<Node*>& path) {

    vector<Node*> current_path(nodes.size());
    double shortest_distance = DBL_MAX; // max value

    for (auto node : nodes) {
        node->setVisited(false);
    }

    // starts from the first node
    backtrackTSP(nodes[0], 1, 0.0, current_path, shortest_distance, path);

    return shortest_distance;
}

// functions for triangular approximation heuristic (T2.2)

// given in appendix A
double GraphInterface::toRadians(double degrees) {
    double result = degrees * M_PI / 180.0;
    return result;
}

// given in appendix A
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