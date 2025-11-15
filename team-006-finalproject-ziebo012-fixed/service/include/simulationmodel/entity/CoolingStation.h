#ifndef CoolingStation_H_
#define CoolingStation_H_

#include "IEntity.h"
#include "CoolerDecorator.h"

class CoolingStation : public IEntity {
 public:
  /**
   * @brief CoolingStations are created
   * @param obj JSON object containing the drone's information
   */
  CoolingStation(const JsonObject& obj);
  /**
  * @brief sets the package temp
  * @param p pointer to the coolerdecorator being used
  */
  void setPackageTemp(CoolerDecorator* p);
  /**
  * @brief updates the cooling station during the simulation
  * @param dt Delta time
  */
  void update(double dt);
/**
  * @brief gets the temperature
  */
  int getTemperature();


 private:
  int stationTemperature = 32;
};

#endif
