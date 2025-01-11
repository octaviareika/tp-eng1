#ifndef FLOW_HPP
#define FLOW_HPP

#include <string>
#include "system.hpp"

// Doxygen comments 
/**
 * @brief Classe Flow
 * 
 * The Flow class represents the flow of a system. This class is an abstract class that has the following subclasses: 
 * Exponential, Logistic and NewFlow. The Flow class encapsulates a flow that transfers some quantity between a source system
 * and a target system
 */

class Flow {
protected:
    std::string idFlow;///< Flow identifier
    System *source; ///< Source system
    System *target; ///< Target system
    double flowAmount; ///< Flow amount

public: 
    /**
     * @brief Construct a new Flow object. Default constructor
     */
    Flow();

    /**
     * @brief Construct a new Flow object
     * 
     * @param idFlow Flow identifier
     * @param source Source system
     * @param target Target system
     * @param flowAmount Flow amount
     */
    
    Flow(std::string idFlow, System *source, System *target, double flowAmount);

    /**
     * @brief Destroy the Flow object
     */
    virtual ~Flow();

    /**
     * @brief Construct a new Flow object. Copy constructor
     */
    Flow(const Flow &other); // copy constructor

    /**
     * @brief Copy assignment operator
     */
    Flow& operator=(const Flow &other); 
    /**
     * @brief Move constructor
     * 
     */
    Flow(Flow &&other) noexcept; 

    /**
     * @brief Move assignment operator
     */
    Flow& operator=(Flow &&other) noexcept; // move assignment operator

    /**
     * @brief Get the Id Flow object
     * 
     * @return std::string Flow identifier
     */
    std::string getIdFlow();

    /**
     * @brief Get the Source object
     * 
     * @return System* Source system
     */
    System *getSource();

    /**
     * @brief Get the Target object
     * 
     * @return System* Target system
     */
    System *getTarget();


    /**
     * @brief Get the Flow Amount object
     * 
     * @return double Flow amount
     */
    double getFlowAmount();

    /**
     * @brief Set the Id Flow object
     * 
     * @param idFlow Flow identifier
     */
    void setIdFlow(std::string idFlow);

    /**
     * @brief Set the Source object
     * 
     * @param source Source system
     */
    void setSource(System *source);

    /**
     * @brief Set the Target object
     * 
     * @param target Target system
     */
    void setTarget(System *target);

    /**
     * @brief Set the Flow Amount object
     * 
     * @param flowAmount Flow amount
     */
    void setFlowAmount(double flowAmount);

    /**
     * @brief Calculate the flow. This method is pure virtual and must be implemented by the subclasses
     * 
     * @return double Flow amount
     *
     */
    virtual double calculate() = 0;
};

/**
 * @brief Exponential class
 * 
 * The Exponential class represents a flow that transfers some quantity between a source system and a target system 
 * following an exponential function
 */

class Exponential : public Flow {
public:

    /**
     * @brief Construct a new Exponential object
     * 
     * @param idFlow Flow identifier
     * @param source Source system
     * @param target Target system
     * @param flowAmount Flow amount
     */
    Exponential(std::string idFlow, System *source, System *target, double flowAmount);

    /**
     * @brief Construct a new Exponential object. Default constructor
     * 
     */
    Exponential();

    /**
     * @brief Calculate the flow amount
     * 
     * @return double Flow amount, 0.01 * source accumulator
     */

    double calculate() override;
};

// Logistico

/**
 * @brief Logistic class
 * 
 * The Logistic class represents a flow that transfers some quantity between a source system and a target system
 * following a logistic function
 * 
 */

class Logistic : public Flow {
private:
    double maxCapacity; ///< Maximum capacity

public:

    /**
     * @brief Construct a new Logistic object
     * 
     */
    Logistic();

    /**
     * @brief Construct a new Logistic object
     * 
     * @param idFlow Flow identifier
     * @param source Source system
     * @param target Target system
     * @param flowAmount Flow amount
     * @param maxCapacity Maximum capacity
     */
    Logistic(std::string idFlow, System *source, System *target, double flowAmount, double maxCapacity);

    /**
     * @brief Get the Max Capacity object
     * 
     * @return double Maximum capacity
     */
    double getMaxCapacity();

    /**
     * @brief Set the Max Capacity object
     */
    void setMaxCapacity(double maxCapacity);

    /**
     * @brief Calculate the flow amount
     * 
     * @return double Flow amount, 0.01 * target accumulator * (1 - target accumulator / maxCapacity)
     */
    double calculate() override;
};

/**
 * @brief NewFlow class
 * 
 * The NewFlow class represents a flow that transfers some quantity between a source system and a target system
 * following a new function (complex)
 * 
 */

class NewFlow : public Flow {
public:

/**
 * @brief Construct a new NewFlow object
 */
    NewFlow();

    /**
     * @brief Construct a new NewFlow object
     * 
     * @param idFlow Flow identifier
     * @param source Source system
     * @param target Target system
     * @param flowAmount Flow amount
     */
    NewFlow(std::string idFlow, System *source, System *target, double flowAmount);

    /**
     * @brief Calculate the flow amount
     * 
     * @return 0.01 * source accumulator * target accumulator
     */
    double calculate() override;
};

#endif // FLOW_HPP