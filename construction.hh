
#ifndef CONSTRUCTIONTEST_HH
#define CONSTRUCTIONTEST_HH



#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4SubtractionSolid.hh"
#include "globals.hh"


#include "G4Cache.hh"

//#include "G4AnalysisManager.hh"


#include "G4Run.hh"



class globalField;
class ConstructionParameters;


class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
     DetectorConstruction(G4double rNeonBlock, G4double dNeonBlockFront, G4double dNeonBlockTotal);
	~DetectorConstruction();
    virtual G4VPhysicalVolume* Construct();
private:

    G4Material* Ne, * H2, * W;

    void DefineMaterials();
    void SetMaterials();

    G4double rNeonBlock, dNeonBlockFront, dNeonBlockTotal;
    G4Box* solidWorld;
    G4Tubs * solidNeonBlockFront, * solidNeonBlockBack;
    G4Element * elNe;
    G4Material* worldMat, * blockMaterial;
    G4LogicalVolume *logicWorld, *logicNeonBlockFront, * logicNeonBlockBack;
    G4VPhysicalVolume *physicalWorld, *physicalNeonBlockFront, *physicalNeonBlockBack;

};
#endif
