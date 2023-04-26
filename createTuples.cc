#include "createTuples.hh"


void createTuples() {

    G4AnalysisManager* man = G4AnalysisManager::Instance();
    man->SetVerboseLevel(3);

    man->CreateNtuple("Annihilations", "_");
    man->CreateNtupleDColumn(0, "x");
    man->CreateNtupleDColumn(0, "y");
    man->CreateNtupleDColumn(0, "z");
    man->CreateNtupleDColumn(0, "E");
    man->FinishNtuple(0);


}
