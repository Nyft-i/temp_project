// PHYS30762 Programming in C++
// Project - Detector Simulation: Jade Salisbury

#include<iostream>
#include<memory>
#include<vector>

#include"particle.h"
#include"photon.h"
#include"electron.h"
#include"muon.h"
#include"tau.h"
#include"neutrino.h"
#include"sub_detector.h"
#include"tracker.h"
#include"collision_event.h"

using std::shared_ptr;
using std::vector;
using std::string;


int Particle::numberer=0; // Starts the particle numbering from 0.
int main()
{
  vector<shared_ptr<Particle>> particle_list;
  particle_list.push_back(std::make_shared<Photon>(1500, vector<double>{1,2,3,4}));
  particle_list.push_back(std::make_shared<Electron>(200, vector<double>{5,10,15,20}));
  particle_list.push_back(std::make_shared<Muon>(300, 1, 50, 100));
  particle_list.push_back(std::make_shared<Tau>(400, 1, "leptonic"));
  particle_list.push_back(std::make_shared<Neutrino>(500, 1, 1, false));

  /*
  particle_list[0]->print();
  particle_list[1]->print();
  particle_list[2]->print();
  particle_list[3]->print();
  particle_list[4]->print();
  */

  CollisionEvent event1("test");
  event1.add_particle(*particle_list[0]);
  event1.add_particle(*particle_list[1]);

  event1.print();


  return 0;
}