#ifndef DA_TSP_PARSER_H
#define DA_TSP_PARSER_H

#include "GraphInterface.h"

extern GraphInterface *finalGraph;

/**
 * @brief Generate a toy graph from a CSV file.
 * @details This function generates a toy graph from a CSV file containing node and edge data.
 * The CSV file format should have three columns: source node, destination node, and edge weight.
 * @param filepath The file path of the CSV file.
 * @return A pointer to the generated graph.
 * @note The time complexity of this function is O(N), where N is the number of entries in the CSV file.
 */
GraphInterface *toyGraph(const string& filepath);

/**
 * @brief Generate a real-world graph from separate node and edge files.
 * @details This function generates a real-world graph from separate node and edge files.
 * The node file should contain node coordinates (latitude, longitude), and the edge file
 * should contain source node, destination node, and edge weight.
 * @param nodesFile The file path of the node file.
 * @param edgesFile The file path of the edge file.
 * @return A pointer to the generated graph.
 * @note The time complexity of this function is O(N + M), where N is the number of nodes
 * and M is the number of edges.
 */
GraphInterface *realWorldGraph(const string& nodesFile, const string& edgesFile);

/**
 * @brief Generate an extra graph from an edge file.
 * @details This function generates an extra graph from an edge file.
 * The file name should contain the number of nodes, and the edge file should contain source node,
 * destination node, and edge weight.
 * @param edgesFile The file path of the edge file.
 * @return A pointer to the generated graph.
 * @note The time complexity of this function is O(N + M), where N is the number of nodes
 * and M is the number of edges.
 */
GraphInterface *extraGraph(const string& edgesFile);

#endif //DA_TSP_PARSER_H
