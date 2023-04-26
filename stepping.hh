#ifndef STEPPING_HH
#define STEPPING_HH

#include "G4UserSteppingAction.hh"
#include "event.hh"
#include "G4Step.hh"
#include "G4SteppingManager.hh"
#include "G4VPhysicalVolume.hh"

#include "G4AnalysisManager.hh"

#include "construction.hh"
#include "G4RunManager.hh"

#include "G4GenericMessenger.hh"

class MySteppingAction : public G4UserSteppingAction
{
public:
	MySteppingAction(MyEventAction* eventAction);
	~MySteppingAction();
	virtual void UserSteppingAction(const G4Step*);
private:
	G4AnalysisManager* man;
	G4double x, y, z, E;
};

#endif
