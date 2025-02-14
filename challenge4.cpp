//
// Created by thoma on 14/02/2025.
//
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class WorldWeatherAPI {
public:
    tuple<float, float, string> getWeather(string location) {
        cout << "Calling worldWeather with location: " << location << endl;
        float temperature = 20.0f;
        float windSpeed = 5.5f;
        string shortDescription = "Sunny";
        return make_tuple(temperature, windSpeed, shortDescription);
    }
};

class FreeWeather {
public:
    tuple<float, string> retrieve_weather(string location) {
        cout << "Calling freeWeather with location: " << location << endl;
        float temperature = 22.0f;
        string shortDescription = "Sunny";
        return make_tuple(temperature, shortDescription);
    }
};

class RealtimeWeatherService {
public:
    tuple<float, float, string> weatherConditions(string location) {
        cout << "Calling realtimeWeather with location: " << location << endl;
        float temperature = 19.5f;
        float humidity = 60.0f;
        string shortDescription = "Partly cloudy with a chance of rain";
        return make_tuple(temperature, humidity, shortDescription);
    }
};

class WeatherServiceFacade {
public:
    WeatherServiceFacade() : worldWeatherAPI(), freeWeather(), realtimeWeatherService() {
    }

    string currentWeather(const string &location) {
        auto world = worldWeatherAPI->getWeather(location);
        auto free = freeWeather->retrieve_weather(location);
        auto realtime = realtimeWeatherService->weatherConditions(location);

        stringstream result;
        float temp = (get<0>(world) + get<0>(free) + get<0>(realtime)) / 3;
        float humidity = (get<1>(world) + get<1>(realtime)) / 2.0;
        result << "Weather for " << location << endl
                << "  Temperature : " << temp << " deg C" << endl
                << "  Humidity    : " << humidity << " %" << endl
                << "  " << get<2>(realtime) << endl;
        return result.str();
    }

private:
    WorldWeatherAPI *worldWeatherAPI;
    FreeWeather *freeWeather;
    RealtimeWeatherService *realtimeWeatherService;
};
