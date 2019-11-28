#include "testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<testApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

testApp::testApp(InputParameters parameters) : MooseApp(parameters)
{
  testApp::registerAll(_factory, _action_factory, _syntax);
}

testApp::~testApp() {}

void
testApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"testApp"});
  Registry::registerActionsTo(af, {"testApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
testApp::registerApps()
{
  registerApp(testApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
testApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testApp::registerAll(f, af, s);
}
extern "C" void
testApp__registerApps()
{
  testApp::registerApps();
}
