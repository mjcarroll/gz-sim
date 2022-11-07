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

#ifndef GZ_SIM_SIMULATIONBUILDER_HH_
#define GZ_SIM_SIMULATIONBUILDER_HH_

#include <gz/sim/Clock.hh>
#include <gz/sim/EntityComponentManager.hh>
#include <gz/sim/Simulation.hh>
#include <gz/sim/SystemLoader.hh>

#include <sdf/World.hh>
#include <gz/utils/ImplPtr.hh>

namespace gz::sim
{

class SimulationBuilder
{
  public: SimulationBuilder();

  public: auto World(const sdf::World *_world) -> SimulationBuilder&;

  public: auto SimulationClock(std::shared_ptr<Clock> _clock) -> SimulationBuilder&;

  public: auto WallClock(std::shared_ptr<Clock> _clock) -> SimulationBuilder&;

  public: auto EntityComponentManager(std::shared_ptr<EntityComponentManager> _ecm) -> SimulationBuilder&;

  public: auto SystemLoader(std::shared_ptr<SystemLoader> _loader) -> SimulationBuilder&;

  public: operator Simulation();

  private: ::gz::utils::ImplPtr<Simulation::Implementation> dataPtr;
};


}  // namespace gz::sim

#endif  // GZ_SIM_SIMULATIONBUILDER_HH_
