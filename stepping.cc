#include "stepping.hh"

MySteppingAction::MySteppingAction(MyEventAction* eventAction)
{
	man = G4AnalysisManager::Instance();
	man->SetVerboseLevel(0);
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step* aStep)
{
	if (aStep->GetPostStepPoint()->GetProcessDefinedStep()) {
		const G4String& procName = aStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
		if (procName == "annihil") {
			G4String volumeName = aStep->GetPostStepPoint()->GetPhysicalVolume()->GetName();
			if (volumeName == "physicalNeonBlockFront") {
				x = aStep->GetPostStepPoint()->GetPosition().getX();
				y = aStep->GetPostStepPoint()->GetPosition().getY();
				z = aStep->GetPostStepPoint()->GetPosition().getZ();
				E = aStep->GetPostStepPoint()->GetKineticEnergy();
				man->FillNtupleDColumn(0, 0, x);
				man->FillNtupleDColumn(0, 1, y);
				man->FillNtupleDColumn(0, 2, z);
				man->FillNtupleDColumn(0, 3, E);
				man->AddNtupleRow(0);
			}
		}
	}
}	