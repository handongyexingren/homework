#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_myitksnap.h"

#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <vtkCommand.h>
#include <vtkImageMapper.h>
#include <QFileDialog.h>
#include <QDockWidget>
#include <QListWidget>
#include <QDockWidget>
#include <QStatusBar>
#include <QLabel>
#include <QDebug>
#include <vtkImageThreshold.h>
#include "ui_myitksnap.h"
#include <vtkImageShiftScale.h>
#include <vtkRendererCollection.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkObjectFactory.h>
#include <vtkActor.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkInteractorStyleImage.h>
#include <vtkActor2D.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <vtkEventQtSlotConnect.h>
#include <vtkImageCast.h>
#include <vtkPropPicker.h>
#include <vtkEventQtSlotConnect.h>
#include "vtkAutoInit.h"
#include <vtkAssemblyPath.h>
#include <vtkImageActor.h>
#include <qdebug.h>
#include <vtkMath.h>
#include <vtkImageData.h>
#include <vtkVariant.h>
//VTK_MODULE_INIT(vtkRenderingOpenGL2);
//VTK_MODULE_INIT(vtkInteractionStyle);
//VTK_MODULE_INIT(vtkRenderingFreeType);


class myitksnap : public QMainWindow
{
    Q_OBJECT

public:
    myitksnap(QWidget *parent = Q_NULLPTR);
    //friend class myVtkInteractorStyleImage;
    ~myitksnap();

private slots:
    void firstDrawLine();
    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_action3D_triggered();
    void on_actionThreshold_triggered();
    void on_actionRegionGrowing_triggered();
    void on_actionWindow_triggered();
private:
    QString filename;
    vtkSmartPointer<vtkDICOMImageReader> reader;
    vtkSmartPointer<vtkImageViewer2> imageViewer1;
    vtkSmartPointer<vtkImageViewer2> imageViewer2;
    vtkSmartPointer<vtkImageViewer2> imageViewer3;
    vtkSmartPointer<vtkImageViewer2> imageViewer4;
    //int image_coordinate[3];

    Ui::myitksnapClass ui;

};
