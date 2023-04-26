#include "action.hh"
#include "event.hh"
#include "stepping.hh"

MyActionInitialization::MyActionInitialization(int argRunNo, G4double argE, G4String argFileName)
{
	runNo = argRunNo;
	E = argE;
	fileName = argFileName;
}

MyActionInitialization::~MyActionInitialization()
{
}



void MyActionInitialization::Build()const{

	TestPositrons* testPositrons = new TestPositrons(E);
	SetUserAction(testPositrons);

	MyRunAction* runAction = new MyRunAction(runNo, fileName);
	SetUserAction(runAction);

	MyEventAction* eventAction = new MyEventAction(runAction);
	SetUserAction(eventAction);

	MySteppingAction* steppingAction = new MySteppingAction(eventAction);
	SetUserAction(steppingAction);
}