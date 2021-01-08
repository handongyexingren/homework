#include "myitksnap.h"
#include "stdafx.h"
#include <QtWidgets/QApplication>
#include <vtkOutputWindow.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);

#pragma execution_character_set("utf-8")
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

int main(int argc, char *argv[])
{
    //≤ªœ‘ æoutputwindow
    vtkOutputWindow::SetGlobalWarningDisplay(0);   
    QApplication a(argc, argv);
    myitksnap w;
    w.show();
    return a.exec();

}
