#ifndef DA_TSP_GRAPHINTERFACE_H
#define DA_TSP_GRAPHINTERFACE_H
#include "Graph.h"

class GraphInterface {
public:
    // Graph Operations
    Node *findNode(int index);
    bool addNode(const int &index, double latitude = 0, double longitude = 0);
    bool addBidirectionalEdge(const int &node1, const int &node2, double w);
    Node *getNode(const int &index);
    std::vector<Node *> getNodes();
    void clearAllNodes();

// algorithms
    double solveTSPBacktracking(vector<Node*>& path);

    double triangularApproximationHeuristic(vector<Node*>& path);

    double nearestNeighborHeuristic(vector<Node*>& path);
    double twoOptOptimization(vector<Node*>& path, double current_distance);

private:
    vector<Node*> nodes;

    void backtrackTSP(Node* current_node, unsigned int level, double total_distance, vector<Node*>& current_path, double& best_distance, vector<Node*>& best_path);

    double toRadians(double degrees);
    double haversine(double lat1, double lon1, double lat2, double lon2);
};

#endif // DA_TSP_GRAPHINTERFACE_H
