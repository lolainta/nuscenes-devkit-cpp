#include "Log.hpp"

Log::Log(const std::string& token, const fs::path& logfile,
         const std::string& vehicle, const std::string& date_capetured,
         const Location& location)
    : token(token),
      logfile(logfile),
      vehicle(vehicle),
      date_captured(date_capetured),
      location(location) {}

Log::Log(const json& j)
    : token(j.at("token").get<std::string>()),
      logfile(j.at("logfile").get<std::string>()),
      vehicle(j.at("vehicle").get<std::string>()),
      date_captured(j.at("date_captured").get<std::string>()) {
  auto location = j.at("location").get<std::string>();
  if (location == "boston-seaport") {
    this->location = Location::BostonSeaport;
  } else if (location == "singapore-onenorth") {
    this->location = Location::SingaporeOnenorth;
  } else if (location == "singapore-hollandvillage") {
    this->location = Location::SingaporeHollandvillage;
  } else if (location == "singapore-queenstown") {
    this->location = Location::SingaporeQueenstown;
  } else {
    assert(false);
  }
}

const std::string& Log::get_token() const { return this->token; }

const fs::path& Log::get_logfile() const { return this->logfile; }

const std::string& Log::get_vehicle() const { return this->vehicle; }

const std::string& Log::get_date_captured() const {
  return this->date_captured;
}

const Location& Log::get_location() const { return this->location; }
