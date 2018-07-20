/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// EndoscopeViewingArea Logic includes
#include <vtkSlicerEndoscopeViewingAreaLogic.h>

// EndoscopeViewingArea includes
#include "qSlicerEndoscopeViewingAreaModule.h"
#include "qSlicerEndoscopeViewingAreaModuleWidget.h"

//-----------------------------------------------------------------------------
#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
#include <QtPlugin>
Q_EXPORT_PLUGIN2(qSlicerEndoscopeViewingAreaModule, qSlicerEndoscopeViewingAreaModule);
#endif

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerEndoscopeViewingAreaModulePrivate
{
public:
  qSlicerEndoscopeViewingAreaModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerEndoscopeViewingAreaModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeViewingAreaModulePrivate::qSlicerEndoscopeViewingAreaModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerEndoscopeViewingAreaModule methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeViewingAreaModule::qSlicerEndoscopeViewingAreaModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerEndoscopeViewingAreaModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerEndoscopeViewingAreaModule::~qSlicerEndoscopeViewingAreaModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerEndoscopeViewingAreaModule::helpText() const
{
  return "This is a loadable module that can be bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerEndoscopeViewingAreaModule::acknowledgementText() const
{
  return "This work was partially funded by NIH grant NXNNXXNNNNNN-NNXN";
}

//-----------------------------------------------------------------------------
QStringList qSlicerEndoscopeViewingAreaModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("John Doe (AnyWare Corp.)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerEndoscopeViewingAreaModule::icon() const
{
  return QIcon(":/Icons/EndoscopeViewingArea.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerEndoscopeViewingAreaModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerEndoscopeViewingAreaModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerEndoscopeViewingAreaModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerEndoscopeViewingAreaModule
::createWidgetRepresentation()
{
  return new qSlicerEndoscopeViewingAreaModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerEndoscopeViewingAreaModule::createLogic()
{
  return vtkSlicerEndoscopeViewingAreaLogic::New();
}
