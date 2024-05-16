//
// Created by edumr on 16/05/2024.
//

#ifndef DA_TSP_GRAPH_H
#define DA_TSP_GRAPH_H
#include <string>
#include <vector>

using namespace std;
class Edge;

class Node {
    public:
        Node(int index, double latitude, double longitude);
        Node(int index);
        bool operator<(Node & node) const; // // required by MutablePriorityQueue
        int queueIndex = 0;

        int getIndex();
        double getLatitude() const;
        double getLongitude() const;
        std::vector<Edge *> getAdj() ;
        bool isVisited() const;
        unsigned int getIndegree() const;
        double getDist() const;
        Edge *getPath() const;
        std::vector<Edge *> getIncoming() ;

        void setVisited(bool visited);
        void setIndegree(unsigned int indegree);
        void setDist(double dist);
        void setPath(Edge *path);
        Edge * addEdge(Node *dest, double w);
        bool removeEdge(int id);
        void deleteEdge(Edge *edge);
        void removeOutgoingEdges();

    private:
        int index;
        std::string label;
        double latitude;
        double longitude;
        double dist = 0;
        bool visited = false;
        Edge *path = nullptr;
        unsigned int indegree;
        std::vector<Edge*> adj;
        std::vector<Edge*> incoming;
};


class Edge {
    public:
        Edge(Node *orig, Node *dest, double w);
        Edge(double w);

        Node * getDest() ;
        double getWeight() ;
        Node * getOrig() ;
        Edge *getReverse() ;

        void setReverse(Edge *reverse);

    private:
        Node * dest; // destination vertex
        double weight; // edge weight, can also be used for capacity

        // auxiliary fields
        bool selected = false;

        // used for bidirectional edges
        Node *orig;
        Edge *reverse = nullptr;

        double flow; // for flow-related problems
};

#endif //DA_TSP_GRAPH_H
