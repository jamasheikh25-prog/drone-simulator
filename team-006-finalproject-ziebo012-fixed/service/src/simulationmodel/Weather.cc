#include "Weather.h"
#include "IPublisher.h"

// ignore this, testing pushing only
Weather::Weather() :temperature(32) {}
Weather::~Weather() {}
double Weather::getTemperature() {
    return temperature;
}
void Weather::setTemperature(double temp) {
    temperature = temp;
}
Weather& Weather::getInstance() {
    static Weather instance;
    return instance;
}
void Weather::setSky(std::string sky2) {
    sky = sky2;
}
void Weather::updateTemperature() {
  if (sky == "Sunny") {
    temperature = 50.0;
    std::string message = "The Weather is Sunny";
  } else if (sky == "Cloudy") {
    temperature = 65.0;
    std::string message = "The Weather is Cloudy";
  } else if (sky == "Rainy") {
    temperature = 45.0;
    std::string message = "The Weather is Rainy";
  } else if (sky == "Snowy") {
    temperature = 30.0;
    std::string message = "The Weather is Snowy";
  } else {
    temperature = 80.0;
    std::string message = "The Weather is Sunny";
  }
}

void Weather::randomWeather() {
  int weather = std::rand() % 4;
  switch (weather) {
    case 0: setSky("Sunny"); break;
    case 1: setSky("Cloudy"); break;
    case 2: setSky("Rainy"); break;
    case 3: setSky("Snowy"); break;
  }
}
