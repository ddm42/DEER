//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DEERTestApp.h"
#include "DEERApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
DEERTestApp::validParams()
{
  InputParameters params = DEERApp::validParams();
  return params;
}

DEERTestApp::DEERTestApp(InputParameters parameters) : MooseApp(parameters)
{
  DEERTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

DEERTestApp::~DEERTestApp() {}

void
DEERTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  DEERApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"DEERTestApp"});
    Registry::registerActionsTo(af, {"DEERTestApp"});
  }
}

void
DEERTestApp::registerApps()
{
  registerApp(DEERApp);
  registerApp(DEERTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DEERTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DEERTestApp::registerAll(f, af, s);
}
extern "C" void
DEERTestApp__registerApps()
{
  DEERTestApp::registerApps();
}
