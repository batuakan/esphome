#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"

class SignalK;

namespace esphome {
namespace signalk {

class SignalkSensor : public sensor::Sensor, public Component {
 public:
  void setup() override;
  void dump_config() override;

  void on_delta_received(float value);

  void set_path(std::string path) { path_ = path; }
  void set_period(int period) { period_ = period; }
  void set_format(std::string format) { format_ = format; }
  void set_policy(std::string policy) { policy_ = policy; }
  void set_min_period(int min_period) { min_period_ = min_period; }

  //  void get_parent() { return parent_; }
  std::string get_path() { return path_; }
  int get_period() { return period_; }
  std::string get_format() { return format_; }
  std::string get_policy() { return policy_; }
  int get_min_period() { return min_period_; }

 protected:
  std::string path_;
  int period_;
  std::string format_;
  std::string policy_;
  int min_period_;
};

}  // namespace signalk
}  // namespace esphome
