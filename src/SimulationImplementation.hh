/*
 * Copyright (C) 2022 Open Source Robotics Foundation
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

#ifndef GZ_SIM_SIMULATIONIMPLEMENTATION_HH_
#define GZ_SIM_SIMULATIONIMPLEMENTATION_HH_

#include <gz/sim/Clock.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Simulation.hh>
#include <gz/sim/SystemLoader.hh>

namespace gz::sim
{

class Simulation::Implementation
{
  public: const sdf::World *world {nullptr};

  public: std::shared_ptr<Clock> wallClock {nullptr};

  public: std::shared_ptr<Clock> simClock {nullptr};

  public: std::shared_ptr<SystemLoader> systemLoader {nullptr};

  public: std::shared_ptr<EntityComponentManager> entityComponentMgr {nullptr};

  public: std::shared_ptr<EntityComponentManager> initialEntityCompMgr {nullptr};
};

}  // namespace gz::sim


#endif  // GZ_SIM_SIMULATIONIMPLEMENTATION_HH_
