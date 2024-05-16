#include "Graph.h"

//class Node

Node::Node(int index, double latitude, double longitude) {
    this->index = index;
    this->latitude = latitude;
    this->longitude = longitude;
    this->label = "";
}

Node::Node(int index) {
    this->index = index;
    this->latitude = 0;
    this->longitude = 0;
    this->label = "";
}

int Node::getIndex(){
    return this->index;
}

double Node::getLatitude() const{
    return this->latitude;
}

double Node::getLongitude() const{
    return this->longitude;
}

std::vector<Edge *> Node::getAdj() {
    return this->adj;
}

bool Node::isVisited() const{
    return this->visited;
}

unsigned int Node::getIndegree() const{
    return this->indegree;
}

double Node::getDist() const{
    return this->dist;
}

Edge *Node::getPath() const{
    return this->path;
}

std::vector<Edge *> Node::getIncoming() {
    return this->incoming;
}

void Node::setVisited(bool visited){
    this->visited = visited;
}

void Node::setIndegree(unsigned int indegree){
    this->indegree = indegree;
}

void Node::setDist(double dist){
    this->dist = dist;
}

void Node::setPath(Edge *path){
    this->path = path;
}

Edge * Node::addEdge(Node *dest, double w){
    Edge *edge = new Edge(this, dest, w);
    this->adj.push_back(edge);
    dest->incoming.push_back(edge);
    return edge;
}

bool Node::removeEdge(int id){
    for (int i = 0; i < this->adj.size(); i++){
        if (this->adj[i]->getDest()->getIndex() == id){
            this->adj.erase(this->adj.begin() + i);
            return true;
        }
    }
    return false;
}

void Node::deleteEdge(Edge *edge) {
    Node *dest = edge->getDest();
    // Remove the corresponding edge from the incoming list
    auto it = dest->incoming.begin();
    while (it != dest->incoming.end()) {
        if ((*it)->getOrig()->getIndex() == this->index) {
            it = dest->incoming.erase(it);
        }
        else {
            it++;
        }
    }
    delete edge;
}


void Node::removeOutgoingEdges(){
    for (int i = 0; i < this->adj.size(); i++){
        this->adj[i]->getDest()->removeEdge(this->index);
    }
    this->adj.clear();
}

bool Node::operator<(Node &node) const {
    return this->dist < node.getDist();
}

//class Edge

Edge::Edge(Node *orig, Node *dest, double w) {
    this->dest = dest;
    this->weight = w;
    this->orig = orig;
}

Edge::Edge(double w) {
    this->weight = w;
}

Node * Edge::getDest() {
    return this->dest;
}

double Edge::getWeight() {
    return this->weight;
}

Node * Edge::getOrig() {
    return this->orig;
}

Edge * Edge::getReverse() {
    return this->reverse;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}
