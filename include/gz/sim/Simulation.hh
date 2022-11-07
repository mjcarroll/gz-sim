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

#ifndef GZ_SIM_SIMULATION_HH_
#define GZ_SIM_SIMULATION_HH_

#include <sdf/Model.hh>

#include <gz/utils/ImplPtr.hh>

namespace gz::sim
{

class SimulationBuilder;

class Simulation
{
  public: Simulation() = delete;

  public: void AddModel(const sdf::Model *_model);

  public: void Step();

  public: void Reset();

  public: friend class SimulationBuilder;

  public: class Implementation;

  private: ::gz::utils::ImplPtr<Simulation::Implementation> dataPtr;

  private: Simulation(::gz::utils::ImplPtr<Simulation::Implementation> _impl);
};

}  // namespace gz::sim

#endif  // GZ_SIM_SIMULATION_HH_
