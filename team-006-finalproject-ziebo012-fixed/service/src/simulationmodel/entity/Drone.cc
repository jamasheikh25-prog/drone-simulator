#define _USE_MATH_DEFINES
#include "Drone.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "BfsStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "Package.h"
#include "SimulationModel.h"
#include "SpinDecorator.h"
#include "CoolingStation.h"
#include <string>
#include <iostream>
#include <sstream>


Drone::Drone(const JsonObject& obj) : IEntity(obj) { available = true; }

Drone::~Drone() {
  if (toPackage) delete toPackage;
  if (toFinalDestination) delete toFinalDestination;
  if (toCoolingStation) delete toCoolingStation;
}

void Drone::getNextDelivery() {
  if (model && model->scheduledDeliveries.size() > 0) {
    package = model->scheduledDeliveries.front();
    model->scheduledDeliveries.pop_front();

    if (package) {
      std::string message = getName() + " heading to: " + package->getName();
      notifyObservers(message);
      available = false;
      pickedUp = false;

      Vector3 packagePosition = package->getPosition();
      Vector3 finalDestination = package->getDestination();
      Vector3 finalDestination2 = package->getDestination();
      Vector3 toCoolingStation = {-30, 250, -228.623};

      toPackage = new BeelineStrategy(position, packagePosition);

      std::string strat = package->getStrategyName();
      if (strat == "cooling") {
        toFinalDestination2 =
            new BeelineStrategy(packagePosition, toCoolingStation);
            packagePosition = toCoolingStation;
      }
      if (strat == "astar") {
        toFinalDestination = new JumpDecorator(new AstarStrategy(
            packagePosition, finalDestination, model->getGraph()));
      } else if (strat == "dfs") {
        toFinalDestination =
            new SpinDecorator(new JumpDecorator(new DfsStrategy(
                packagePosition, finalDestination, model->getGraph())));
      } else if (strat == "bfs") {
        toFinalDestination =
            new SpinDecorator(new SpinDecorator(new BfsStrategy(
                packagePosition, finalDestination, model->getGraph())));
      } else if (strat == "dijkstra") {
        toFinalDestination =
            new JumpDecorator(new SpinDecorator(new DijkstraStrategy(
                packagePosition, finalDestination, model->getGraph())));
      }  else {
        toFinalDestination =
            new BeelineStrategy(packagePosition, finalDestination);
      }
    }
  }
}

void Drone::update(double dt) {
  if (available) getNextDelivery();

  if (toPackage) {
    toPackage->move(this, dt);

    if (toPackage->isCompleted()) {
      std::string message = getName() + " picked up: " + package->getName();
      notifyObservers(message);
      delete toPackage;
      toPackage = nullptr;
      pickedUp = true;
    }
  } else if (toFinalDestination2) {
    toFinalDestination2->move(this, dt);

    if (package && pickedUp) {
      package->setPosition(position);
      package->setDirection(direction);
    }

    if (toFinalDestination2->isCompleted()) {
      std::string message = getName() + " chilled: " + package->getName();
      notifyObservers(message);
      delete toFinalDestination2;
      toFinalDestination2 = nullptr;
    }
  } else if (toFinalDestination) {
    toFinalDestination->move(this, dt);

    if (package && pickedUp) {
      package->setPosition(position);
      package->setDirection(direction);
    }

    if (toFinalDestination->isCompleted()) {
      std::string message = getName() + " dropped off: " + package->getName();
      notifyObservers(message);
      delete toFinalDestination;
      toFinalDestination = nullptr;
      package->handOff();
      package = nullptr;
      available = true;
      pickedUp = false;
    }
  }
  // add strtaegy to seek out coolingstation
/*
  //the idea is to get a cooling station (cooler) and go to it
  std::cout << cooler << std::endl;
   for (auto& [id, entity] : entities) {
    if (name + "_coolingstation" == entity->getName()) {
      if (CoolingStation* p = dynamic_cast<CoolingStation*>(entity)) {
          package = p;
          break;
      }
    }
  }
   if(cooler) {
     Vector3 stationPosition = cooler->getPosition();
      Vector3 finalDestination = package->getDestination();
      toCoolingStation = new BeelineStrategy(position,stationPosition);

      if(fridge->getTemperature() > 31.0) {
        std::cout << "temptest";
       if(toCoolingStation) {
          toCoolingStation->move(this,dt);
          if(toCoolingStation->isCompleted()) {
          //this will need to be updated
          std::cout << "settemptest";
          fridge->setTemperature(32);

          }
          delete toCoolingStation;
          toCoolingStation = nullptr;
        }
      }
    }
  }*/
}
