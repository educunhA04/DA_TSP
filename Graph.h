
#ifndef DA_TSP_GRAPH_H
#define DA_TSP_GRAPH_H

#include <string>
#include <vector>

using namespace std;

class Edge;

/**
 * @brief Class representing a node in the graph.
 */
class Node {
public:
    /**
     * @brief Constructor for Node with latitude and longitude.
     * @param index The index of the node.
     * @param latitude The latitude of the node.
     * @param longitude The longitude of the node.
     */
    Node(int index, double latitude, double longitude);

    /**
     * @brief Constructor for Node with index only.
     * @param index The index of the node.
     */
    Node(int index);

    /**
     * @brief Overloaded less than operator.
     * @details Required by MutablePriorityQueue.
     * @param node The node to compare with.
     * @return True if this node is less than the other node, else false.
     */
    bool operator<(Node & node) const;

    int queueIndex = 0;

    /**
     * @brief Get the index of the node.
     * @return The index of the node.
     */
    int getIndex();

    /**
     * @brief Get the latitude of the node.
     * @return The latitude of the node.
     */
    double getLatitude() const;

    /**
     * @brief Get the longitude of the node.
     * @return The longitude of the node.
     */
    double getLongitude() const;

    /**
     * @brief Get the adjacent edges of the node.
     * @return The adjacent edges of the node.
     */
    std::vector<Edge *> getAdj();

    /**
     * @brief Check if the node is visited.
     * @return True if the node is visited, else false.
     */
    bool isVisited() const;

    /**
     * @brief Get the indegree of the node.
     * @return The indegree of the node.
     */
    unsigned int getIndegree() const;

    /**
     * @brief Get the distance of the node.
     * @return The distance of the node.
     */
    double getDist() const;

    /**
     * @brief Get the path of the node.
     * @return The path of the node.
     */
    Edge *getPath() const;

    /**
     * @brief Get the incoming edges of the node.
     * @return The incoming edges of the node.
     */
    std::vector<Edge *> getIncoming();

    /**
     * @brief Set the visited flag of the node.
     * @param visited The value to set.
     */
    void setVisited(bool visited);

    /**
     * @brief Set the indegree of the node.
     * @param indegree The value to set.
     */
    void setIndegree(unsigned int indegree);

    /**
     * @brief Set the distance of the node.
     * @param dist The value to set.
     */
    void setDist(double dist);

    /**
     * @brief Set the path of the node.
     * @param path The path to set.
     */
    void setPath(Edge *path);

    /**
     * @brief Add an edge to the node.
     * @param dest The destination node.
     * @param w The weight of the edge.
     * @return The created edge.
     */
    Edge * addEdge(Node *dest, double w);

    /**
     * @brief Remove an edge from the node.
     * @param id The index of the destination node of the edge to remove.
     * @return True if the edge is removed, else false.
     */
    bool removeEdge(int id);

    /**
     * @brief Delete an edge from the node.
     * @param edge The edge to delete.
     */
    void deleteEdge(Edge *edge);

    /**
     * @brief Remove all outgoing edges from the node.
     */
    void removeOutgoingEdges();

private:
    int index; ///< The index of the node.
    std::string label; ///< The label of the node.
    double latitude; ///< The latitude of the node.
    double longitude; ///< The longitude of the node.
    double dist = 0; ///< The distance of the node.
    bool visited = false; ///< Flag indicating if the node is visited.
    Edge *path = nullptr; ///< The path of the node.
    unsigned int indegree; ///< The indegree of the node.
    std::vector<Edge*> adj; ///< The adjacent edges of the node.
    std::vector<Edge*> incoming; ///< The incoming edges of the node.
};


/**
 * @brief Class representing an edge in the graph.
 */
class Edge {
public:
    /**
     * @brief Constructor for Edge with origin, destination, and weight.
     * @param orig The origin node of the edge.
     * @param dest The destination node of the edge.
     * @param w The weight of the edge.
     */
    Edge(Node *orig, Node *dest, double w);

    /**
     * @brief Constructor for Edge with weight only.
     * @param w The weight of the edge.
     */
    Edge(double w);

    /**
     * @brief Get the destination node of the edge.
     * @return The destination node of the edge.
     */
    Node * getDest();

    /**
     * @brief Get the weight of the edge.
     * @return The weight of the edge.
     */
    double getWeight();

    /**
     * @brief Get the origin node of the edge.
     * @return The origin node of the edge.
     */
    Node * getOrig();

    /**
     * @brief Get the reverse edge.
     * @return The reverse edge.
     */
    Edge *getReverse();

    /**
     * @brief Set the reverse edge.
     * @param reverse The reverse edge to set.
     */
    void setReverse(Edge *reverse);

private:
    Node *dest; ///< The destination node of the edge.
    double weight; ///< The weight of the edge.
    Node *orig; ///< The origin node of the edge.
    Edge *reverse = nullptr; ///< The reverse edge.
};

#endif //DA_TSP_GRAPH_H

