//
// Created by edumr on 16/05/2024.
//

#ifndef DA_TSP_PARSER_H
#define DA_TSP_PARSER_H
#include "GraphInterface.h"

extern GraphInterface *finalGraph;

GraphInterface *realWorldGraph(const string& nodesFile, const string& edgesFile);

GraphInterface *extraGraph(const string& edgesFile);

GraphInterface *toyGraph(const string& filepath);

#endif //DA_TSP_PARSER_H
