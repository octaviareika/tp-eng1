#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <string>

/**
 * @brief System class
 * 
 * The System class represents a system in the simulation environment. A system has a name and an accumulator
 * 
 */
class System {
// private:
//     std::string name; ///< System name
//     double accumulator; ///< System accumulator

public:

    // /**
    //  * @brief Construct a new System object. Default constructor
    //  * 
    //  */
    // System();

    // /**
    //  * @brief Construct a new System object. Copy constructor
    //  * 
    //  * @param other System to be copied
    //  */
    // System(const System &other);


    // /**
    //  * @brief Construct a new System object
    //  * 
    //  * @param name System name
    //  * @param accumulator System accumulator
    //  */
    // System(std::string name, double accumulator);

    // /**
    //  * @brief Construct a new System object
    //  * 
    //  * @param name System name
    //  */
    // System(std::string name);

    // /**
    //  * @brief Destroy the System object
    //  * 
    //  */
    // ~System();

    /**
     * @brief Get the name of the system
     * 
     * @return std::string System name
     */

    virtual std::string getName() = 0;

    /**
     * @brief Get the accumulator of the system
     * 
     * @return double System accumulator
     */
    virtual double getAccumulator() = 0;

    /**
     * @brief Set the name of the system
     * 
     * @param name System name
     */
    virtual void setName(std::string name) = 0;

    /**
     * @brief Set the accumulator of the system
     * 
     * @param accumulator System accumulator
     */
    virtual void setAccumulator(double accumulator) = 0;


};

#endif // SYSTEM_HPP