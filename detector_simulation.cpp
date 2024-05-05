// PHYS30762 Programming in C++
// Project - Detector Simulation: Jade Salisbury

#include<iostream>
#include<memory>
#include<vector>
#include<string>
#include<ctime>
#include<chrono>
#include<list>

#include"particle.h"
#include"depositor_particle.h"
#include"collision_event.h"
#include"photon.h"
#include"electron.h"
#include"muon.h"
#include"tau.h"
#include"neutrino.h"
#include"sub_detector.h"
#include"tracker.h"
#include"detector.h"
#include"calorimeter.h"

using std::shared_ptr;
using std::vector;
using std::string;
using std::list;
using std::unique_ptr;

unsigned long long get_ticks()
{
  // Current time in milliseconds for the seed. (https://stackoverflow.com/a/24959236)
  using namespace std::chrono;
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int Particle::numberer=0; // Starts the particle numbering from 0.
int main()
{
  // Seed random number generator
  std::srand(get_ticks()); // use current time as seed for random generator, ensures different answer each time.


  vector<shared_ptr<Particle>> particle_list;
  particle_list.push_back(std::make_shared<Photon>(1500));
  particle_list.push_back(std::make_shared<Electron>(200));
  particle_list.push_back(std::make_shared<Muon>(300, 1));
  particle_list.push_back(std::make_shared<Tau>(400, 1, "hadronic"));
  particle_list.push_back(std::make_shared<Neutrino>(500, 1, 1, false));
  std::cout<<"test"<<std::endl;

  CollisionEvent event1("test");
  event1.add_particle(std::move(particle_list[0]));
  event1.print();

  Detector main_detector; // No arguments means that it will create a perfect detector
  main_detector.start_collision(std::make_unique<CollisionEvent>(event1));
  main_detector.sneak_look();
  list<string> possible_parts = main_detector.guess_particle();
  for (auto it = possible_parts.begin(); it != possible_parts.end(); ++it)
  {
    std::cout << *it << std::endl;
  }
  
  return 0;
}