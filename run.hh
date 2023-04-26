#ifndef RUN_HH
#define RUN_HH

#include "G4UserRunAction.hh"
#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4LogicalVolume.hh"
#include "G4GenericMessenger.hh"


class MyRunAction : public G4UserRunAction
{
public:
	MyRunAction(int argRunNo, G4String argFileName);
	~MyRunAction();
	G4AnalysisManager* man;
	virtual void BeginOfRunAction(const G4Run* run);
	virtual void EndOfRunAction(const G4Run*);

private:
	int runNo;
	G4String fileName;
};

#endif

