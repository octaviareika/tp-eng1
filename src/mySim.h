#ifndef MYSIM_H
#define MYSIM_H

#include <vector>
#include "flow.hpp"
#include "system.hpp"

class Simulator {
public:
    virtual ~Simulator() = default;

    /**
     * @brief Add a system to the simulator
     * 
     * @param system System to be added
     */
    virtual void add(System *system) = 0;

    /**
     * @brief Add a flow to the simulator
     * 
     * @param flow Flow to be added
     */
    virtual void add(Flow *flow) = 0;

    /**
     * @brief Get the systems object
     * 
     * @return std::vector<System *> List of systems
     */
    virtual std::vector<System *> getSystems() const = 0;

    /**
     * @brief Get the flows object
     * 
     * @return std::vector<Flow *> List of flows
     */
    virtual std::vector<Flow *> getFlows() const = 0;

    /**
     * @brief Set the systems object
     * 
     * @param systems List of systems
     */
    virtual void setSystems(std::vector<System *> systems) = 0;

    /**
     * @brief Set the flows object
     * 
     * @param flows List of flows
     */
    virtual void setFlows(std::vector<Flow *> flows) = 0;

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
    virtual void run(int initialTime, int finalTime) = 0;
};

#endif // MYSIM_H