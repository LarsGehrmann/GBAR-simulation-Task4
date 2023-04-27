#include "run.hh"


#include <filesystem>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

MyRunAction::MyRunAction(int argRunNo, G4String argFileName)
{
	runNo = argRunNo;

	std::stringstream strRunID;
	strRunID << runNo;

	G4cout << "Run number: " << runNo << G4endl;
	man = G4AnalysisManager::Instance();
	man->SetVerboseLevel(0);

	fileName = argFileName + strRunID.str() + ".csv";
	man->OpenFile(fileName);
}

MyRunAction::~MyRunAction()
{
	delete G4AnalysisManager::Instance();
}

void MyRunAction::BeginOfRunAction(const G4Run* run) 
{

}


void MyRunAction::EndOfRunAction(const G4Run* run) 
{
	man = G4AnalysisManager::Instance();
	man->SetVerboseLevel(0);

	man->Write();
	man->CloseFile();

	G4int runID = run->GetRunID();

}
