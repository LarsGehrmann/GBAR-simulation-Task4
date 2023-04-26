#include "generator.hh"

TestPositrons::TestPositrons(G4double argE)
{
	E = argE;
	fParticleGun = new G4ParticleGun(1);
}
TestPositrons::~TestPositrons()
{
	delete fParticleGun;
}
void TestPositrons::GeneratePrimaries(G4Event* anEvent)
{
	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
	G4double x, y, z;
	G4ParticleDefinition* particle;
	G4ThreeVector pos;
	G4ThreeVector mom;
	x = 0 * cm;
	y = 0 * cm;
	z = -1 * cm;
	particle = particleTable->FindParticle("e+");
	pos.setX(x);
	pos.setY(y);
	pos.setZ(z);
	mom.setX(0.);
	mom.setY(0.);
	mom.setZ(1.);
	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom);
	fParticleGun->SetParticleDefinition(particle);
	fParticleGun->SetParticleEnergy(E);
	fParticleGun->GeneratePrimaryVertex(anEvent);
}

