#include "GraphInterface.h"
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

void GraphInterface::clearAllNodes(){
    nodes.clear();
}

bool addNode(const int &index, double latitude = 0, double longitude = 0){

}
bool addBidirectionalEdge(const int &node1, const int &node2, double w);