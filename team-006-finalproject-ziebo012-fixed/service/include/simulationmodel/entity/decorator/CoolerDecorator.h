#ifndef COOLER_DECORATOR_H_
#define COOLER_DECORATOR_H_

#include "CoolerDecorator.h"
#include "PackageDecorator.h"
#include "Weather.h"

class CoolerDecorator : public PackageDecorator {
 public:
  /**
  * @brief Constructor for coolerdecorator
  * @param p package pointer, initialized as null
  * @param t double value for temperature, initalized as 32
  */
  CoolerDecorator(Package* p = NULL, double t = 32);
   /**
  * @brief sets the temp
  * @param tempeature the temperature to be set to
  */
  void setTemperature(double temperature);
   /**
  * @brief gets the package temp
  */
  double getTemperature();
   /**
  * @brief Increases the temperature as simulation runs
  * @param dt delta time, the time increment of the simulation
  * @param envTemp temperature of the enviroment
  */
  void increaseTemperature(double dt, double envTemp);

 private:
  double temperature;
  Package* package;
};
#endif
