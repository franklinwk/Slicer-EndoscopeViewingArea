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

#ifndef __qSlicerEndoscopeViewingAreaModuleWidget_h
#define __qSlicerEndoscopeViewingAreaModuleWidget_h

// SlicerQt includes
#include "qSlicerAbstractModuleWidget.h"

#include "qSlicerEndoscopeViewingAreaModuleExport.h"

class qSlicerEndoscopeViewingAreaModuleWidgetPrivate;
class vtkMRMLNode;

/// \ingroup Slicer_QtModules_ExtensionTemplate
class Q_SLICER_QTMODULES_ENDOSCOPEVIEWINGAREA_EXPORT qSlicerEndoscopeViewingAreaModuleWidget :
  public qSlicerAbstractModuleWidget
{
  Q_OBJECT

public:

  typedef qSlicerAbstractModuleWidget Superclass;
  qSlicerEndoscopeViewingAreaModuleWidget(QWidget *parent=0);
  virtual ~qSlicerEndoscopeViewingAreaModuleWidget();

public slots:
  void onRun();
  


protected:
  QScopedPointer<qSlicerEndoscopeViewingAreaModuleWidgetPrivate> d_ptr;

  virtual void setup();

private:
  Q_DECLARE_PRIVATE(qSlicerEndoscopeViewingAreaModuleWidget);
  Q_DISABLE_COPY(qSlicerEndoscopeViewingAreaModuleWidget);
};

#endif
