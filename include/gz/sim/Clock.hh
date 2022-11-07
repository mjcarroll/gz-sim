/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GZ_SIM_CLOCK_HH_
#define GZ_SIM_CLOCK_HH_

namespace gz::sim
{
class Clock
{
  public: Clock() = default;
  public: virtual ~Clock() = 0;
};

class WallClock: public Clock
{
  public: WallClock() = default;
  public: ~WallClock() override = default;
};

class SimulationClock: public Clock
{
  public: SimulationClock() = default;
  public: ~SimulationClock() override = default;
};
}  // namespace gz::sim

#endif  // GZ_SIM_CLOCK_HH_
