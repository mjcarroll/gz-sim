#include <gz/sim/SimulationBuilder.hh>
#include <gz/sim/Clock.hh>

#include <sdf/Root.hh>



int main(int argc, char** argv)
{
  auto simClock = std::make_shared<gz::sim::SimulationClock>();
  auto wallClock = std::make_shared<gz::sim::WallClock>();
  auto ecm = std::make_shared<gz::sim::EntityComponentManager>();

  gz::sim::SimulationBuilder builder;

  sdf::Root sdfRoot;
  auto errors = sdfRoot.Load("empty.sdf");
  auto world = sdfRoot.WorldByIndex(0);


  auto sim = gz::sim::Simulation(
      gz::sim::SimulationBuilder()
      .SimulationClock(simClock)
      .WallClock(wallClock)
      .EntityComponentManager(ecm)
  );

  return 0;
}
