#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4GenericMessenger.hh"
#include <fstream>
#include <iostream>
#include <random>
#include <string>

/* -------------------------------------------------------------------- */
class TestPositrons : public G4VUserPrimaryGeneratorAction
{
public:
	TestPositrons(G4double E);
	~TestPositrons();
	virtual void GeneratePrimaries(G4Event*);
private:
	G4double E;
	G4ParticleGun* fParticleGun;
};
#endif