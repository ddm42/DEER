#include "DEERApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DEERApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

DEERApp::DEERApp(InputParameters parameters) : MooseApp(parameters)
{
  DEERApp::registerAll(_factory, _action_factory, _syntax);
}

DEERApp::~DEERApp() {}

void
DEERApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"DEERApp"});
  Registry::registerActionsTo(af, {"DEERApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DEERApp::registerApps()
{
  registerApp(DEERApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DEERApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DEERApp::registerAll(f, af, s);
}
extern "C" void
DEERApp__registerApps()
{
  DEERApp::registerApps();
}
