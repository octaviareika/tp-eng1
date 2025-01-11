#ifndef MYSIM_H
#define MYSIM_H

#include <vector>
#include "system.hpp"
#include "flow.hpp"

/**
 * @brief Simulator class
 * 
 * The Simulator class represents the simulation environment. It contains a list of systems and a list of flows.
 * The Simulator class is responsible for running the simulation
 * 
 */

class Simulator {
private:
    std::vector<System *> systems; ///< List of systems
    std::vector<Flow *> flows; ///< List of flows

public:

    /**
     * @brief Construct a new Simulator object
     * 
     */
    Simulator();

    /**
     * @brief Destroy the Simulator object
     * 
     */
    ~Simulator();

    /**
     * @brief Add a system to the simulator
     * 
     * @param system System to be added
     */
    void add(System *system);

    /**
     * @brief Add a flow to the simulator
     * 
     * @param flow Flow to be added
     */
    void add(Flow *flow);

    /**
     * @brief Get the systems object
     * 
     * @return std::vector<System *> List of systems
     */
    std::vector<System *> getSystems() const;

    /**
     * @brief Get the flows object
     * 
     * @return std::vector<Flow *> List of flows
     */
    std::vector<Flow *> getFlows() const;

    /**
     * @brief Set the systems object
     * 
     * @param systems List of systems
     */
    void setSystems(std::vector<System *> systems);


    /**
     * @brief Set the flows object
     * 
     * @param flows List of flows
     */
    void setFlows(std::vector<Flow *> flows);

    /**
     * @brief Runs the simulation from the initial time to the final time.
     *
     * This method iterates over each time step within the specified range and updates
     * the state of the systems based on the flows. For each time step, it calculates
     * the flow amount and updates the accumulators of the source and target systems.
     *
     * @param initialTime The initial time step of the simulation.
     * @param finalTime The final time step of the simulation.
     */
    void run(int initialTime, int finalTime);
};

#endif // MYSIM_H