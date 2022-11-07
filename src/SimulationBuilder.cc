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

#include <memory>

#include <gz/sim/Clock.hh>
#include <gz/sim/SimulationBuilder.hh>
#include "SimulationImplementation.hh"
#include "gz/sim/EntityComponentManager.hh"

namespace gz::sim
{

SimulationBuilder::SimulationBuilder():
  dataPtr(gz::utils::MakeImpl<Simulation::Implementation>())
{
}

SimulationBuilder::operator Simulation()
{
  if (nullptr == this->dataPtr->simClock)
  {
    this->dataPtr->simClock =
      std::make_shared<gz::sim::SimulationClock>();
  }

  if (nullptr == this->dataPtr->wallClock)
  {
    this->dataPtr->wallClock =
      std::make_shared<gz::sim::WallClock>();
  }

  if (nullptr == this->dataPtr->entityComponentMgr)
  {
    this->dataPtr->entityComponentMgr =
      std::make_shared<gz::sim::EntityComponentManager>();
  }

  if (nullptr == this->dataPtr->initialEntityCompMgr)
  {
    this->dataPtr->initialEntityCompMgr =
      std::make_shared<gz::sim::EntityComponentManager>();
  }

  return {std::move(this->dataPtr)};
}

auto SimulationBuilder::World(const sdf::World *_world) -> SimulationBuilder&
{
  this->dataPtr->world = _world;
  return *this;
}

auto SimulationBuilder::SimulationClock(std::shared_ptr<Clock> _clock) -> SimulationBuilder&
{
  this->dataPtr->simClock = std::move(_clock);
  return *this;
}

auto SimulationBuilder::WallClock(std::shared_ptr<Clock> _clock) -> SimulationBuilder&
{
  this->dataPtr->wallClock = std::move(_clock);
  return *this;
}

auto SimulationBuilder::EntityComponentManager(std::shared_ptr<gz::sim::EntityComponentManager> _ecm) -> SimulationBuilder&
{
  this->dataPtr->entityComponentMgr = std::move(_ecm);
  return *this;

}

}  // namespace gz::sim
