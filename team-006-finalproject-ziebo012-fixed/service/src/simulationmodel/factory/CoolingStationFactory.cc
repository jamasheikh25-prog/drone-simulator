#include "CoolingStationFactory.h"

IEntity* CoolingStationFactory::createEntity(const JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("coolingStation") == 0) {
    std::cout << "Cooling Station Created" << std::endl;
    return new CoolingStation(entity);
  }
  return nullptr;
}
