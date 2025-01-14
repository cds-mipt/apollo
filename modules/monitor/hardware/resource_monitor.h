/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <string>
#include <unordered_map>

#include "modules/dreamview/proto/hmi_mode.pb.h"
#include "modules/monitor/common/recurrent_runner.h"
#include "modules/monitor/proto/system_status.pb.h"

namespace apollo {
namespace monitor {

class ResourceMonitor : public RecurrentRunner {
 public:
  ResourceMonitor();
  void RunOnce(const double current_time) override;

 private:
  static void UpdateStatus(
      const apollo::dreamview::ResourceMonitorConfig& config,
      ComponentStatus* status);
  static void CheckDiskSpace(
      const apollo::dreamview::ResourceMonitorConfig& config,
      ComponentStatus* status);
  static void CheckCPUUsage(
      const int pid, const apollo::dreamview::ResourceMonitorConfig& config,
      ComponentStatus* status);
  static void CheckMemoryUsage(
      const int pid, const apollo::dreamview::ResourceMonitorConfig& config,
      ComponentStatus* status);
  static std::unordered_map<std::string, uint64_t> prev_jiffies_map_;
};

}  // namespace monitor
}  // namespace apollo
