#ifndef COOLINGSTATION_FACTORY_H_
#define COOLINGSTATION_FACTORY_H_

#include "CoolingStation.h"
#include "IEntityFactory.h"

/**
 *@brief CoolingStation Factory to produce CoolingStations class.
 **/
class CoolingStationFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for CoolingStationFactory class.
   **/
  virtual ~CoolingStationFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* createEntity(const JsonObject& entity);
};

#endif
