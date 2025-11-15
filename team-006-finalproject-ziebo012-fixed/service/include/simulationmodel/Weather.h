#ifndef WEATHER_H_
#define WEATHER_H_

#include <string>
#include "IPublisher.h"

class Weather {
 private:
  double weatherTemp = 60;
    int temperature;
    std::string sky;
    /**
  * @brief Constructor for weather
  */
    Weather();
    /**
  * @brief Deconstructor for weather
  */
    ~Weather();
    /**
  * @brief Initializes the singleton
  */
    Weather* instance();

 public:
 /**
  * @brief updates the temperature
  */
  void updateTemperature();
 /**
  * @brief gets the weather condition
  */
    Weather getWeather();
    /**
  * @brief gets the singleton instance
  */
    static Weather& getInstance();
    /**
  * @brief gets the temperature
  */
    double getTemperature();
    /**
  * @brief sets the temperature
  * @param temp temperature to be set to
  */
    void setTemperature(double temp);
    /**
  * @brief sets the sky condition
  * @param sky the sky type to be set to
  */
    void setSky(std::string sky);
    /**
  * @brief randomly picks the sky and temperature
  */
    void randomWeather();
};

#endif
