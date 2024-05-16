#ifndef DA_TSP_GRAPHINTERFACE_H
#define DA_TSP_GRAPHINTERFACE_H
#include "Graph.h"

class GraphInterface {
    public:
        //Parser
        int realWorldGraph(const string& nodesFile, const string& edgesFile);

        int extraGraph(const string& edgesFile);

        int toyGraph(const string& filepath);

        //Graph Operations
        Node *findNode(int index);
        bool addNode(const int &index, double latitude = 0, double longitude = 0);
        bool addBidirectionalEdge(const int &node1, const int &node2, double w);
        Node *getNode(const int &index);
        vector<Node *> getNodes();
        void clearAllNodes();


        //Algorithms
    private:
        std::vector<Node*> nodes;

};


#endif //DA_TSP_GRAPHINTERFACE_H
