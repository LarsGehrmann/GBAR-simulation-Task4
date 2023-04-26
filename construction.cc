#include "construction.hh"


DetectorConstruction::DetectorConstruction(G4double argRNeonBlock, G4double argDNeonBlockFront, G4double argDNeonBlockTotal)  // todo: * -> &
{
    rNeonBlock = argRNeonBlock;
    dNeonBlockFront = argDNeonBlockFront;
    dNeonBlockTotal = argDNeonBlockTotal;
    DetectorConstruction::DefineMaterials();
}

void DetectorConstruction::DefineMaterials()
{
    G4NistManager* nist = G4NistManager::Instance();
    G4double a, density;

    // Define solid neon
    a = 20.18 * g / mole;
    elNe = new G4Element("Neon", "Ne", 10, a);
    density = 0.9 * g / cm3;
    Ne = new G4Material("Solid neon", density, 1);
    Ne->AddElement(elNe, 1);
}


DetectorConstruction::~DetectorConstruction()   // destructor
{
}


void DetectorConstruction::SetMaterials()
{
    G4NistManager* nist = G4NistManager::Instance();
    blockMaterial = Ne;
    worldMat = nist->FindOrBuildMaterial("G4_Galactic");
}


G4VPhysicalVolume *DetectorConstruction::Construct()
{
    G4bool testOverlap = true;
    DetectorConstruction::SetMaterials();

    G4double worldVertices = 100 * mm; // world length
    G4double heightWorld = worldVertices;
    G4double lengthWorld = worldVertices;
    G4double widthWorld = worldVertices;
    solidWorld = new G4Box("soldidWorld", lengthWorld, heightWorld, widthWorld);
    logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicVWorld");
    physicalWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physicalWorld", 0, false, 0, testOverlap);

    solidNeonBlockFront = new G4Tubs("solidNeonBlockFront", 0., rNeonBlock, dNeonBlockFront/2, 0, 360);
    solidNeonBlockBack = new G4Tubs("solidNeonBlockBack", 0., rNeonBlock, (dNeonBlockTotal - dNeonBlockFront)/2, 0, 360);

    logicNeonBlockFront = new G4LogicalVolume(solidNeonBlockFront, blockMaterial, "logicNeonBlockFront");
    logicNeonBlockBack = new G4LogicalVolume(solidNeonBlockBack, blockMaterial, "logicNeonBlockBack");

    physicalNeonBlockFront = new G4PVPlacement(0, G4ThreeVector(0, 0, dNeonBlockFront / 2), logicNeonBlockFront,
        "physicalNeonBlockFront", logicWorld, false, 1, testOverlap);
    physicalNeonBlockBack = new G4PVPlacement(0, G4ThreeVector(0, 0, dNeonBlockFront + (dNeonBlockTotal - dNeonBlockFront)/2), logicNeonBlockBack,
        "physicalNeonBlockBack", logicWorld, false, 1, testOverlap);
	return physicalWorld;
}
