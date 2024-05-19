#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H

#include <vector>
#include "Graph.h"

/**
 * @brief Interface for interacting with the graph and implementing graph algorithms.
 */
class GraphInterface {
public:
    /**
     * @brief Find a node by its index.
     *
     * @param index The index of the node to find.
     * @return A pointer to the found node, or nullptr if not found.
     * @details Time complexity: O(n), where n is the number of nodes.
     */
    Node* findNode(int index);

    /**
     * @brief Get a node by its index.
     *
     * @param index The index of the node to get.
     * @return A pointer to the node with the given index, or nullptr if not found.
     * @details Time complexity: O(n), where n is the number of nodes.
     */
    Node* getNode(const int& index);

    /**
     * @brief Get all nodes in the graph.
     *
     * @return A vector containing pointers to all nodes in the graph.
     * @details Time complexity: O(1).
     */
    std::vector<Node*> getNodes();

    /**
     * @brief Clear all nodes from the graph.
     *
     * @details Removes all nodes and their associated edges from the graph.
     * @details Time complexity: O(n^2), where n is the number of nodes.
     */
    void clearAllNodes();

    /**
     * @brief Add a node to the graph.
     *
     * @param index The index of the new node.
     * @param latitude The latitude of the new node.
     * @param longitude The longitude of the new node.
     * @return True if the node was added successfully, false if a node with the same index already exists.
     * @details Time complexity: O(n), where n is the number of nodes.
     */
    bool addNode(const int& index, double latitude = 0, double longitude = 0);

    /**
     * @brief Add a bidirectional edge between two nodes.
     *
     * @param node1 The index of the first node.
     * @param node2 The index of the second node.
     * @param w The weight of the edge.
     * @return True if the edge was added successfully, false if one or both nodes do not exist.
     * @details Time complexity: O(n), where n is the number of nodes.
     */
    bool addBidirectionalEdge(const int& node1, const int& node2, double w);



    /**
     * @brief Solve the Traveling Salesman Problem (TSP) using backtracking.
     *
     * @param path Output parameter to store the shortest path found.
     * @return The total distance of the shortest path.
     * @details Time complexity: O(n!), where n is the number of nodes.
     */
    double solveTSPBacktracking(std::vector<Node*>& path);

    /**
     * @brief Approximate the solution to TSP using the Triangular Approximation heuristic.
     *
     * @param path Output parameter to store the approximate shortest path found.
     * @return The approximate total distance of the shortest path.
     * @details Time complexity: O(n^2), where n is the number of nodes.
     */
    double triangularApproximationHeuristic(std::vector<Node*>& path);

    /**
     * @brief Approximate the solution to TSP using the Nearest Neighbor heuristic.
     *
     * @param path Output parameter to store the approximate shortest path found.
     * @return The approximate total distance of the shortest path.
     * @details Time complexity: O(n^2), where n is the number of nodes.
     */
    double nearestNeighborHeuristic(std::vector<Node*>& path);

    /**
     * @brief Optimize the initial tour using the 2-opt optimization algorithm.
     *
     * @param path The initial tour to optimize.
     * @param current_distance The current total distance of the initial tour.
     * @return The optimized total distance of the tour.
     * @details Time complexity: O(n^2), where n is the number of nodes.
     */
    double twoOptOptimization(std::vector<Node*>& path, double current_distance);

private:
    std::vector<Node*> nodes;

    // Helper methods...

    void backtrackTSP(Node* current_node, unsigned int current_index, double total_distance, std::vector<Node*>& current_path, double& best_distance, std::vector<Node*>& best_path);

    double toRadians(double degrees);

    double haversine(double lat1, double lon1, double lat2, double lon2);
};

#endif // GRAPHINTERFACE_H
