/**
 * @file GraphInterface.h
 * @brief Interface for managing a graph that connects water reservoirs, pumping stations, and cities.
 *
 * This class provides the functionality to load entities such as water reservoirs, pumping stations, and cities
 * from files and create a graph representing their connections. It allows for adding these entities to the graph,
 * retrieving them, and managing their connections through pipelines.
 */

#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H

#include "Graph.h" // Include the Graph template definition
#include "WaterReservoir.h"
#include "PumpingStation.h"
#include "City.h"
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include "headers.h"

/**
 * @class GraphInterface
 * @brief Manages a graph representing the connections between water reservoirs, pumping stations, and cities.
 *
 * GraphInterface facilitates the loading of data from files to populate the graph with vertices representing
 * water reservoirs, pumping stations, and cities, and edges representing pipelines. It provides access to the
 * graph and its elements for querying and manipulation.
 */
class GraphInterface {
private:
    Graph<std::string> graph; ///< The graph holding all connections between entities.
    std::unordered_map<std::string, WaterReservoir*> reservoirs; ///< Maps entity identifiers to WaterReservoir objects.
    std::unordered_map<std::string, PumpingStation*> pumpingStations; ///< Maps entity identifiers to PumpingStation objects.
    std::unordered_map<std::string, City*> cities; ///< Maps entity identifiers to City objects.

public:
    /**
     * @brief Constructs a new GraphInterface object.
     * Initializes a new instance of GraphInterface, potentially setting up for data loading.
     */
    GraphInterface();

    /**
     * @brief Loads water reservoirs from a specified file and adds them to the graph.
     * @param filename Path to the file containing water reservoirs data.
     */
    void loadReservoirs(const std::string& filename);

    /**
     * @brief Loads pumping stations from a specified file and adds them to the graph.
     * @param filename Path to the file containing pumping stations data.
     */
    void loadPumpingStations(const std::string& filename);

    /**
     * @brief Loads cities from a specified file and adds them to the graph.
     * @param filename Path to the file containing cities data.
     */
    void loadCities(const std::string& filename);

    /**
     * @brief Loads pipelines from a specified file, creating edges between entities in the graph.
     * @param filename Path to the file containing pipeline data.
     */
    void loadPipelines(const std::string& filename);

    /**
     * @brief Removes all entities and connections from the graph.
     */
    void removeAll();

    /**
     * @brief Retrieves the loaded water reservoirs.
     * @return A map of identifiers to WaterReservoir pointers.
     */
    std::unordered_map<std::string, WaterReservoir*> getReservoirs();

    /**
     * @brief Retrieves the loaded pumping stations.
     * @return A map of identifiers to PumpingStation pointers.
     */
    std::unordered_map<std::string, PumpingStation*> getPumpingStations();

    /**
     * @brief Retrieves the loaded cities.
     * @return A map of identifiers to City pointers.
     */
    std::unordered_map<std::string, City*> getCities();

    /**
     * @brief Retrieves the graph.
     * @return The graph representing the connections between entities.
     */
    Graph<std::string> getGraph();
};

#endif // GRAPHINTERFACE_H

