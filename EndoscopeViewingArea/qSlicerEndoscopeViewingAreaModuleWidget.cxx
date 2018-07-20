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

// Qt includes
#include <QDebug>

// SlicerQt includes
#include "qSlicerEndoscopeViewingAreaModuleWidget.h"
#include "ui_qSlicerEndoscopeViewingAreaModuleWidget.h"
#include "qSlicerLayoutManager.h"
#include "qSlicerApplication.h"

//MRML includes
#include <vtkMRMLViewNode.h>
#include <vtkMRMLCameraNode.h>
#include <vtkMRMLModelNode.h>
#include <qMRMLThreeDView.h>
#include <qMRMLThreeDWidget.h>

// VTK includes
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRendererCollection.h>
#include <vtkHardwareSelector.h>
#include <vtkDataObject.h>
#include <vtkSelection.h>
#include <vtkExtractSelection.h>
#include <vtkProperty.h>

#include <vtkSphereSource.h>

#include <vtkObjectFactory.h>

#include <vtkDataSetMapper.h>



//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerEndoscopeViewingAreaModuleWidgetPrivate: public Ui_qSlicerEndoscopeViewingAreaModuleWidget
{
public:
  qSlicerEndoscopeViewingAreaModuleWidgetPrivate();
};

//-----------------------------------------------------------------------------
// qSlicerEndoscopeViewingAreaModuleWidgetPrivate methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeViewingAreaModuleWidgetPrivate::qSlicerEndoscopeViewingAreaModuleWidgetPrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerEndoscopeViewingAreaModuleWidget methods

//-----------------------------------------------------------------------------
qSlicerEndoscopeViewingAreaModuleWidget::qSlicerEndoscopeViewingAreaModuleWidget(QWidget* _parent)
  : Superclass( _parent )
  , d_ptr( new qSlicerEndoscopeViewingAreaModuleWidgetPrivate )
{
}

//-----------------------------------------------------------------------------
qSlicerEndoscopeViewingAreaModuleWidget::~qSlicerEndoscopeViewingAreaModuleWidget()
{
}

//-----------------------------------------------------------------------------
void qSlicerEndoscopeViewingAreaModuleWidget::setup()
{
  Q_D(qSlicerEndoscopeViewingAreaModuleWidget);
  d->setupUi(this);
  this->Superclass::setup();
  
  connect(d->runButton, SIGNAL(clicked()), this, SLOT(onRun()));
}

//-----------------------------------------------------------------------------
void qSlicerEndoscopeViewingAreaModuleWidget::onRun()
{
  Q_D(qSlicerEndoscopeViewingAreaModuleWidget);
  qSlicerApplication* app = qSlicerApplication::application();
  
  
  vtkMRMLScene* scene = this->mrmlScene();
  if (scene)
    {
    vtkMRMLModelNode* modelNode = vtkMRMLModelNode::SafeDownCast(d->modelNodeComboBox->currentNode());
    vtkPolyData* polyData = modelNode->GetPolyData();

    vtkRenderWindow* renderWindow = vtkRenderWindow::SafeDownCast(app->layoutManager()->threeDWidget(0)->threeDView()->renderWindow());
    //renderWindow->SetGlobalMaximumNumberOfMultiSamples(0); //vtkWin32OpenGLRenderWindow
    vtkRenderer* renderer = renderWindow->GetRenderers()->GetFirstRenderer();
    
    vtkSmartPointer<vtkHardwareSelector> selector = vtkSmartPointer<vtkHardwareSelector>::New();
    selector->SetRenderer(renderer);

    int* windowSize = renderWindow->GetSize();
    
    selector->SetArea(0, 0, windowSize[0], windowSize[1]);
    selector->SetFieldAssociation(vtkDataObject::FIELD_ASSOCIATION_CELLS);
    vtkSelection* selection = selector->Select();

    vtkSmartPointer<vtkExtractSelection> extractor = vtkSmartPointer<vtkExtractSelection>::New();
    extractor->SetInputData(0, polyData);
    extractor->SetInputData(1, selection);
    extractor->Update();

    //Previewing by adding actor
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputConnection(extractor->GetOutputPort());
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(1, 0, 0);
    renderer->AddActor(actor);
    }
  else
    {
    qWarning("invalid scene");
    return;
    }
  
  //d->logic()->
  
}
