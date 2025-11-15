#include "CoolingStation.h"

CoolingStation::CoolingStation(const JsonObject& obj) : IEntity(obj) {}

void CoolingStation::setPackageTemp(CoolerDecorator* p) {
    p->setTemperature(stationTemperature);
}

int CoolingStation::getTemperature() {
    return stationTemperature;
}

void CoolingStation::update(double dt) {
// just need update since inheriting from entity but we don't use
}
