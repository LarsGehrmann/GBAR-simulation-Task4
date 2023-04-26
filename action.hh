#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"
#include "generator.hh"
#include "run.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
	public:
		MyActionInitialization(int argRunNo, G4double argE, G4String argFileName);
		~MyActionInitialization();
		virtual void Build() const;
private:
	int runNo;
	G4double E;
	G4String fileName;

};

#endif
