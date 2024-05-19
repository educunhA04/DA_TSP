#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H

#include <vector>
#include "Graph.h"

class GraphInterface {
public:
    Node* findNode(int index);
    Node* getNode(const int& index);
    std::vector<Node*> getNodes();
    void clearAllNodes();
    bool addNode(const int& index, double latitude = 0, double longitude = 0);
    bool addBidirectionalEdge(const int& node1, const int& node2, double w);

    // Algorithms
    double solveTSPBacktracking(std::vector<Node*>& path);
    double triangularApproximationHeuristic(std::vector<Node*>& path);
    double nearestNeighborHeuristic(std::vector<Node*>& path);
    double twoOptOptimization(std::vector<Node*>& path, double current_distance);

private:
    std::vector<Node*> nodes;
    void backtrackTSP(Node* current_node, unsigned int current_index, double total_distance, std::vector<Node*>& current_path, double& best_distance, std::vector<Node*>& best_path);
    double toRadians(double degrees);
    double haversine(double lat1, double lon1, double lat2, double lon2);
};

#endif // GRAPHINTERFACE_H
