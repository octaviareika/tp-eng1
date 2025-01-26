#ifndef FLOW_HPP
#define FLOW_HPP

#include <string> // Adicione esta linha para incluir o cabeçalho <string>
#include "system.hpp" // Certifique-se de que o cabeçalho do System está incluído

class Flow {
protected:
    // std::string idFlow; ///< Flow identifier
    // System *source; ///< Source system
    // System *target; ///< Target system
    // double flowAmount; ///< Flow amount

public: 
 

    /**
     * @brief Get the Id Flow object
     * 
     * @return std::string Flow identifier
     */
    virtual std::string getIdFlow() = 0; // Use std::string

    /**
     * @brief Get the Source object
     * 
     * @return System* Source system
     */
    virtual System *getSource() = 0;

    /**
     * @brief Get the Target object
     * 
     * @return System* Target system
     */
    virtual System *getTarget() = 0;

    /**
     * @brief Get the Flow Amount object
     * 
     * @return double Flow amount
     */
    virtual double getFlowAmount() = 0;

    /**
     * @brief Set the Id Flow object
     * 
     * @param idFlow Flow identifier
     */
    virtual void setIdFlow(std::string idFlow) = 0; // Use std::string

    /**
     * @brief Set the Source object
     * 
     * @param source Source system (pointer)
     */
    virtual void setSource(System *source) = 0;

    /**
     * @brief Set the Target object
     * 
     * @param target Target system (pointer)
     */
    virtual void setTarget(System *target) = 0;

    /**
     * @brief Set the Flow Amount object
     * 
     * @param flowAmount Flow amount (double)
     */
    virtual void setFlowAmount(double flowAmount) = 0;

    /**
     * @brief Calculate the flow. This method is pure virtual and must be implemented by the subclasses
     * 
     * @return double Flow amount
     */
    virtual double calculate() = 0;
};

#endif