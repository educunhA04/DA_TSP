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