#include "CoolerDecorator.h"

CoolerDecorator::CoolerDecorator(Package* p, double t)
    : PackageDecorator(p), temperature(t) {}

void CoolerDecorator::setTemperature(double temp) {
    temperature = temp;
}

double CoolerDecorator::getTemperature() {
  return temperature;
}

void CoolerDecorator::increaseTemperature(double dt, double envTemp) {
  if (temperature < envTemp) {
    temperature += 0.1 * dt;
  }
}
