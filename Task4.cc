    #include <iostream>
#include <chrono>
#include <string.h>
#include <iomanip>
#include <sstream>



#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "QGSP_BERT.hh"
#include "G4ScoringManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"


#include "physics.hh"
#include "action.hh"

#include "construction.hh"
#include "createTuples.hh"

int main(int argc, char** argv)
{
    bool showVis = false;
    G4int noEvents = 100000;
    G4double dNeonBlockFront = 0.5 * mm;
    G4String fileName = "500micron";
    G4double rNeonBlock = 1*cm;
    G4double dNeonBlockTotal = 1.5 * cm;

    G4RunManager* runMan = new G4RunManager;
    runMan->SetUserInitialization(new MyPhysicsList());
    createTuples();
    G4double E;

    int runNo = 0;
    int noEnergies = 20;
    G4double EStart = 100 * keV;
    G4double EStep = 100 * keV;

    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    if (!showVis) {
        for (runNo = 0; runNo < noEnergies; ++runNo) {
            E = EStart + runNo * EStep;
            runMan->SetUserInitialization(new MyActionInitialization(runNo, E, fileName));
            runMan->SetUserInitialization(new DetectorConstruction(rNeonBlock, dNeonBlockFront, dNeonBlockTotal));
            runMan->Initialize();
            runMan->BeamOn(noEvents);

        }
    }
    else {
        E = 0.5 * MeV;
        runMan->SetUserInitialization(new MyActionInitialization(runNo, E, fileName));
        runMan->SetUserInitialization(new DetectorConstruction(rNeonBlock, dNeonBlockFront, dNeonBlockTotal));
        runMan->Initialize();
        G4VisManager* visManager = new G4VisExecutive();
        visManager->Initialize();
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }

    G4cout << "Before end of main" << G4endl;

    delete runMan;
    return EXIT_SUCCESS;
}

