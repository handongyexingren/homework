#include "myitksnap.h"
#include "stdafx.h"
#include "ReadDicomSeries.h"

myitksnap::myitksnap(QWidget *parent)
    : QMainWindow(parent),imageViewer1(vtkSmartPointer<vtkImageViewer2>::New()),
    imageViewer2(vtkSmartPointer<vtkImageViewer2>::New()),
    imageViewer3(vtkSmartPointer<vtkImageViewer2>::New()),
    imageViewer4(vtkSmartPointer<vtkImageViewer2>::New())
{
    ui.setupUi(this);
    this->setWindowTitle("MyItkSnap");
    ui.statusBar->setSizeGripEnabled(false);

    reader = vtkSmartPointer<vtkDICOMImageReader>::New();

    //将vtk的imageviewer与qt的qvtkwidget绑定
    imageViewer1->SetRenderWindow(ui.qvw1->GetRenderWindow());
    imageViewer2->SetRenderWindow(ui.qvw2->GetRenderWindow());
    imageViewer3->SetRenderWindow(ui.qvw3->GetRenderWindow());
    imageViewer4->SetRenderWindow(ui.qvw4->GetRenderWindow());

    imageViewer1->GetRenderer()->SetBackground(0.0, 0.0, 0.0);
    //imageViewer1->Render();
    imageViewer1->GetRenderer()->ResetCamera();
    imageViewer1->Render();

    imageViewer2->GetRenderer()->SetBackground(0.0, 0.0, 0.0);
    //imageViewer2->Render();
    imageViewer2->GetRenderer()->ResetCamera();
    imageViewer2->Render();

    imageViewer3->GetRenderer()->SetBackground(0.0, 0.0, 0.0);
    //imageViewer3->Render();
    imageViewer3->GetRenderer()->ResetCamera();
    imageViewer3->Render();

    imageViewer4->GetRenderer()->SetBackground(0.0, 0.0, 0.0);
    //imageViewer4->Render();
    imageViewer4->GetRenderer()->ResetCamera();
    imageViewer4->Render();
}

void myitksnap::on_actionOpen_triggered()
{
    filename = QFileDialog::getExistingDirectory(this, "Open folder", "C:/");
    if (filename.isEmpty())
    {
        return;
    }
    else {
        qDebug() << filename[0] <<endl;
    }

    QByteArray ba = filename.toLocal8Bit();
    //const char* fileName_str = ba.data();

    std::string folder = filename.toStdString();
    reader->SetDirectoryName(folder.c_str());
    reader->Update();

    imageViewer1->SetColorWindow(4000);
    imageViewer1->SetColorLevel(0);
    imageViewer2->SetColorWindow(4000);
    imageViewer2->SetColorLevel(0);
    imageViewer3->SetColorWindow(4000);
    imageViewer3->SetColorLevel(0);

    imageViewer1->SetInputConnection(reader->GetOutputPort());
    //显示水平面
    imageViewer1->SetSliceOrientationToXY();
    //从中部显示
    imageViewer1->SetSlice((int)imageViewer1->GetSliceMax() * 0.5);

    imageViewer2->SetInputConnection(reader->GetOutputPort());
    //矢状面
    imageViewer2->SetSliceOrientationToYZ();
    imageViewer2->SetSlice((int)imageViewer2->GetSliceMax() * 0.5);

    imageViewer3->SetInputConnection(reader->GetOutputPort());
    //冠状面
    imageViewer3->SetSliceOrientationToXZ();
    imageViewer3->SetSlice((int)imageViewer3->GetSliceMax() * 0.5);

    myVtkInteractorStyleImage::image_coordinate[0] = (int)imageViewer2->GetSliceMax() * 0.5;//x
    myVtkInteractorStyleImage::image_coordinate[1] = (int)imageViewer3->GetSliceMax() * 0.5;//y
    myVtkInteractorStyleImage::image_coordinate[2] = (int)imageViewer1->GetSliceMax() * 0.5;//z
    //imageViewer4->SetInputConnection(reader->GetOutputPort());

    //交互器
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor1 = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor2 = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor3 = vtkSmartPointer<vtkRenderWindowInteractor>::New();
   // vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor4 = vtkSmartPointer<vtkRenderWindowInteractor>::New();

    vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle1 = vtkSmartPointer<myVtkInteractorStyleImage>::New();
    vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle2 = vtkSmartPointer<myVtkInteractorStyleImage>::New();
    vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle3 = vtkSmartPointer<myVtkInteractorStyleImage>::New();
   // vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle4 = vtkSmartPointer<myVtkInteractorStyleImage>::New();

    myVtkInteractorStyleImage::mvisiArray[0] = myInteractorStyle1;
    myVtkInteractorStyleImage::mvisiArray[1] = myInteractorStyle2;
    myVtkInteractorStyleImage::mvisiArray[2] = myInteractorStyle3;


    myInteractorStyle1->SetImageViewer(imageViewer1,ui,reader);
    myInteractorStyle2->SetImageViewer(imageViewer2,ui,reader);
    myInteractorStyle3->SetImageViewer(imageViewer3,ui,reader);
  //  myInteractorStyle4->SetImageViewer(imageViewer4,ui,reader);

    ui.label1->setText(QString::number((int)imageViewer1->GetSlice(), 10) + " of " + QString::number((int)imageViewer1->GetSliceMax(), 10));
    ui.label2->setText(QString::number((int)imageViewer2->GetSlice(), 10) + " of " + QString::number((int)imageViewer2->GetSliceMax(), 10));
    ui.label3->setText(QString::number((int)imageViewer3->GetSlice(), 10) + " of " + QString::number((int)imageViewer3->GetSliceMax(), 10));

    imageViewer1->SetupInteractor(renderWindowInteractor1);
    imageViewer2->SetupInteractor(renderWindowInteractor2);
    imageViewer3->SetupInteractor(renderWindowInteractor3);
    //imageViewer4->SetupInteractor(renderWindowInteractor4);

    renderWindowInteractor1->SetInteractorStyle(myInteractorStyle1);
    renderWindowInteractor2->SetInteractorStyle(myInteractorStyle2);
    renderWindowInteractor3->SetInteractorStyle(myInteractorStyle3);
    //renderWindowInteractor4->SetInteractorStyle(myInteractorStyle4);
    //qDebug() << "2";
    imageViewer1->Render();
    imageViewer2->Render();
    imageViewer3->Render();
  //  imageViewer4->Render();
    //qDebug() << "1";
    myInteractorStyle1->interactor = imageViewer1->GetRenderWindow()->GetInteractor();
    myInteractorStyle2->interactor = imageViewer2->GetRenderWindow()->GetInteractor();
    myInteractorStyle3->interactor = imageViewer3->GetRenderWindow()->GetInteractor();
   // myInteractorStyle4->interactor = imageViewer4->GetRenderWindow()->GetInteractor();

    myInteractorStyle1->renderer = imageViewer1->GetRenderWindow()->GetRenderers()->GetFirstRenderer();
    myInteractorStyle2->renderer = imageViewer2->GetRenderWindow()->GetRenderers()->GetFirstRenderer();
    myInteractorStyle3->renderer = imageViewer3->GetRenderWindow()->GetRenderers()->GetFirstRenderer();
  //  myInteractorStyle4->renderer = imageViewer4->GetRenderWindow()->GetRenderers()->GetFirstRenderer();

    firstDrawLine();

    renderWindowInteractor1->Initialize();
    renderWindowInteractor2->Initialize();
    renderWindowInteractor3->Initialize();
   // renderWindowInteractor4->Initialize();
    renderWindowInteractor1->Start();
    renderWindowInteractor2->Start();
    renderWindowInteractor3->Start();
   // renderWindowInteractor4->Start();

}

myitksnap::~myitksnap()
{
}

void myitksnap::firstDrawLine()
{
    //qDebug() << myVtkInteractorStyleImage::image_coordinate[0] << " " << myVtkInteractorStyleImage::image_coordinate[1] << " " << myVtkInteractorStyleImage::image_coordinate[2] << endl;
    myVtkInteractorStyleImage::mvisiArray[0]->DrawLine();
    myVtkInteractorStyleImage::mvisiArray[1]->DrawLine();
    myVtkInteractorStyleImage::mvisiArray[2]->DrawLine();
}

void myitksnap::on_action3D_triggered()
{
    if (filename.isEmpty())
    {
        QMessageBox::information(nullptr, "Error", "No files!");
    }
    else
    {
        QMessageBox::information(nullptr, "Tips", "Unfinished!");
    }
}

void myitksnap::on_actionClose_triggered()
{
    exit(0);
    //qApp->quit();
}

void myitksnap::on_actionThreshold_triggered()
{

    if (filename.isEmpty())
    {
        QMessageBox::information(nullptr, "Error", "No files!");
    }
    else
    {
        vtkSmartPointer<vtkImageData> imgData = imageViewer1->GetInput();
        double range[2];
        //获得像素值的范围，最小值，最大值
        imgData->GetScalarRange(range);

        QDialog dialog(this);
        QFormLayout form(&dialog);
        form.addRow(new QLabel("User input:"));

        // Value1
        QString lower = QString("lower: ");
        QSpinBox* spinbox1 = new QSpinBox(&dialog);
        spinbox1->setRange(range[0], range[1]);
        spinbox1->setValue(0);
        form.addRow(lower, spinbox1);

        // Value2
        QString upper = QString("upper: ");
        QSpinBox* spinbox2 = new QSpinBox(&dialog);
        spinbox2->setRange(range[0], range[1]);
        spinbox2->setValue(0);
        form.addRow(upper, spinbox2);

        QString inside = QString("inside value: ");
        QSpinBox* spinbox3 = new QSpinBox(&dialog);
        spinbox3->setRange(-10000, 10000);
        spinbox3->setValue(2000);
        form.addRow(inside, spinbox3);

        QString outside = QString("outside value: ");
        QSpinBox* spinbox4 = new QSpinBox(&dialog);
        spinbox4->setRange(-10000, 10000);
        spinbox4->setValue(0);
        form.addRow(outside, spinbox4);

        // Add Cancel and OK button
        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
            Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

        // Process when OK button is clicked
        if (dialog.exec() == QDialog::Accepted) {
            // Do something here


            //下面这两句是不需要的，这三个imageviewer接受的输入都是一样的，只不过显示的部分不同罢了
            /*
            vtkSmartPointer<vtkImageData> imgData2 = imageViewer2->GetInput();
            vtkSmartPointer<vtkImageData> imgData3 = imageViewer3->GetInput();
            */
            vtkSmartPointer<vtkImageThreshold> thresholdFilter = vtkSmartPointer<vtkImageThreshold>::New();

            //用阈值分割过滤器对原始图像进行处理
            thresholdFilter->SetInputData(imgData);
            thresholdFilter->ThresholdBetween(spinbox1->value(), spinbox2->value());
            //thresholdFilter->ReplaceInOn();//阈值内的像素值替换
            //thresholdFilter->ReplaceOutOn();//阈值外的像素值替换
            thresholdFilter->SetInValue(spinbox3->value());//阈值内像素值全部替换成
            thresholdFilter->SetOutValue(spinbox4->value());//阈值外像素值全部替换成
            thresholdFilter->Update();

            //将处理结果再传回到imageViewer中
            imageViewer1->SetInputConnection(thresholdFilter->GetOutputPort());
            imageViewer2->SetInputConnection(thresholdFilter->GetOutputPort());
            imageViewer3->SetInputConnection(thresholdFilter->GetOutputPort());
            imageViewer1->Render();
            imageViewer2->Render();
            imageViewer3->Render();
        }
    }
}

void myitksnap::on_actionRegionGrowing_triggered()
{
    if (filename.isEmpty())
    {
        QMessageBox::information(nullptr, "Error", "No files!");
    }
    else
    {
        QMessageBox::information(NULL, "RegionGrowing", "Press the left mouse button to decide a seed,then press the 's' key to start segmenting!");
    }
}

void myitksnap::on_actionWindow_triggered()
{
    if (filename.isEmpty())
    {
        QMessageBox::information(nullptr, "Error", "No files!");
    }
    else
    {
        vtkSmartPointer<vtkImageData> imgData = imageViewer1->GetInput();
        double range[2];
        //获得像素值的范围，最小值，最大值
        imgData->GetScalarRange(range);

        QDialog dialog(this);
        QFormLayout form(&dialog);
        form.addRow(new QLabel("User input:"));

        // Value1
        QString wide = QString("wide: ");
        QSpinBox* spinbox1 = new QSpinBox(&dialog);
        spinbox1->setRange(-10000, 10000);
        spinbox1->setValue(0);
        form.addRow(wide, spinbox1);

        // Value2
        QString level = QString("level: ");
        QSpinBox* spinbox2 = new QSpinBox(&dialog);
        spinbox2->setRange(-10000, 10000);
        spinbox2->setValue(0);
        form.addRow(level, spinbox2);


        // Add Cancel and OK button
        QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
            Qt::Horizontal, &dialog);
        form.addRow(&buttonBox);
        QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
        QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));


        if (dialog.exec() == QDialog::Accepted)
        {
            /*
            //原图灰度值范围
            double l = range[1] - range[0];
            //窗宽
            double w = spinbox1->value();
            qDebug() << range[0] << " " << range[1] << " " << spinbox1->value() << " " << spinbox2->value() << endl;
            vtkImageShiftScale* shifter = vtkImageShiftScale::New();
            //设置一下，不然输出范围是0~255，很坑
            shifter->SetOutputScalarTypeToDouble();
            shifter->SetInputData(imgData);
            double _min = spinbox2->value() - (w / 2);
            double _MIN = range[0];
            double scale = w / l;

            shifter->SetShift(double((-1) * _MIN + (_min) * l/w));
            //调节比例
            shifter->SetScale(scale);
            qDebug() << shifter->GetShift() << " " << shifter->GetScale() << " " << w << " " << l << " " << (-1) * range[0] + ((spinbox2->value() - (w / 2)) * w / l) << " " << w / l << endl;
            shifter->SetOutputScalarTypeToUnsignedChar();
            shifter->Update();

            //将处理结果再传回到imageViewer中
            imageViewer1->SetInputConnection(shifter->GetOutputPort());
            imageViewer2->SetInputConnection(shifter->GetOutputPort());
            imageViewer3->SetInputConnection(shifter->GetOutputPort());
            imageViewer1->Render();
            imageViewer2->Render();
            imageViewer3->Render();

            qDebug() << imageViewer1->GetInput()->GetScalarRange()[0] << " " << imageViewer1->GetInput()->GetScalarRange()[1] << endl;
            */
            //啊啊啊，上面这个太蠢了，窗宽窗位不需要自己写

            imageViewer1->SetColorWindow(spinbox1->value());
            imageViewer1->SetColorLevel(spinbox2->value());
            imageViewer2->SetColorWindow(spinbox1->value());
            imageViewer2->SetColorLevel(spinbox2->value());
            imageViewer3->SetColorWindow(spinbox1->value());
            imageViewer3->SetColorLevel(spinbox2->value());
            imageViewer1->Render();
            imageViewer2->Render();
            imageViewer3->Render();
        }
    }
}


void myVtkInteractorStyleImage::SetImageViewer(vtkImageViewer2* imageViewer, Ui::myitksnapClass ui,vtkDICOMImageReader* reader)
{
    _ImageViewer = imageViewer;
    _MinSlice = imageViewer->GetSliceMin();
    _MaxSlice = imageViewer->GetSliceMax();
    _Nowslice = imageViewer->GetSlice();
    _Slice = _Nowslice;
    _ui = ui;
    _Reader = reader;

    propPicker = vtkSmartPointer<vtkPropPicker>::New();
    propPicker->PickFromListOn();
    propPicker->AddPickList(_ImageViewer->GetImageActor());
    Picker = vtkSmartPointer<vtkPropPicker>::New();
    actor = _ImageViewer->GetImageActor();
    actor->ForceOpaqueOn();
    _actor = vtkSmartPointer<vtkActor>::New();

    //interactor = _ImageViewer->GetRenderWindow()->GetInteractor();
    //renderer = _ImageViewer->GetRenderWindow()->GetRenderers()->GetFirstRenderer();
    //this->SetDefaultRenderer(_ImageViewer->GetRenderer());
}

void myVtkInteractorStyleImage::OnMouseWheelBackward()
{
    MoveSliceBackward();
}

void myVtkInteractorStyleImage::OnMouseWheelForward()
{
    MoveSliceForward();
}

void myVtkInteractorStyleImage::MoveSliceForward()
{
    //_Slice = _ImageViewer->GetSlice();
    if (_Slice < _MaxSlice)
    {
        _Slice += 1;
        _ImageViewer->SetSlice(_Slice);
        _ImageViewer->Render();
    }
    int axis = _ImageViewer->GetSliceOrientation();
    switch (axis)
    {
    case vtkImageViewer2::SLICE_ORIENTATION_XY:
        image_coordinate[2] = _Slice;
        _ui.label1->setText(QString::number((int)_Slice, 10) + " of " + QString::number((int)_MaxSlice, 10));
        break;
    case vtkImageViewer2::SLICE_ORIENTATION_YZ:
        image_coordinate[0] = _Slice;
        _ui.label2->setText(QString::number((int)_Slice, 10) + " of " + QString::number((int)_MaxSlice, 10));
        break;
    default:  // vtkImageViewer2::SLICE_ORIENTATION_XZ
        image_coordinate[1] = _Slice;
        _ui.label3->setText(QString::number((int)_Slice, 10) + " of " + QString::number((int)_MaxSlice, 10));
        break;
    }
    //qDebug() << myVtkInteractorStyleImage::image_coordinate[0] << " " << myVtkInteractorStyleImage::image_coordinate[1] << " " << myVtkInteractorStyleImage::image_coordinate[2] << endl;
    mvisiArray[0]->DrawLine();
    mvisiArray[1]->DrawLine();
    mvisiArray[2]->DrawLine();
}

void myVtkInteractorStyleImage::MoveSliceBackward()
{
    //_Slice = _ImageViewer->GetSlice();
    if (_Slice > _MinSlice)
    {
        _Slice -= 1;
        _ImageViewer->SetSlice(_Slice);
        _ImageViewer->Render();
    }
    int axis = _ImageViewer->GetSliceOrientation();
    switch (axis)
    {
    case vtkImageViewer2::SLICE_ORIENTATION_XY:
        image_coordinate[2] = _Slice;
        _ui.label1->setText(QString::number((int)_Slice, 10) + " of " + QString::number((int)_MaxSlice, 10));
        break;
    case vtkImageViewer2::SLICE_ORIENTATION_YZ:
        image_coordinate[0] = _Slice;
        _ui.label2->setText(QString::number((int)_Slice, 10) + " of " + QString::number((int)_MaxSlice, 10));
        break;
    default:  // vtkImageViewer2::SLICE_ORIENTATION_XZ
        image_coordinate[1] = _Slice;
        _ui.label3->setText(QString::number((int)_Slice, 10) + " of " + QString::number((int)_MaxSlice, 10));
        break;
    }
    //qDebug() << myVtkInteractorStyleImage::image_coordinate[0] << " " << myVtkInteractorStyleImage::image_coordinate[1] << " " << myVtkInteractorStyleImage::image_coordinate[2] << endl;
    mvisiArray[0]->DrawLine();
    mvisiArray[1]->DrawLine();
    mvisiArray[2]->DrawLine();
}

void myVtkInteractorStyleImage::OnKeyDown()
{
    std::string key = GetInteractor()->GetKeySym();
    if (key.compare("Up") == 0)
    {
        MoveSliceForward();
    }
    else if (key.compare("Down") == 0)
    {
        MoveSliceBackward();
    }
    else if (key.compare("s") == 0)
    {
        m_itkImage = ImageType::New();
        m_pixelIndex = { 0,0,0 };
        //qDebug() << pos[0] << " " << pos[1] << " " << pos[2];
        //qDebug() << QString::number(image_coordinate[0],10) << " " << QString::number(image_coordinate[1],10) << " " << QString::number(image_coordinate[2],10);
        //qDebug() << (double)image_coordinate[0] << " " << (double)image_coordinate[1] << " " << (double)image_coordinate[2];


        std::string pixelValue = "";
        switch (_ImageViewer->GetInput()->GetScalarType())
        {
            vtkTemplateMacro(
                (vtkValueMessageTemplate<VTK_TT>(_ImageViewer->GetInput(), image_coordinate, pixelValue)));

        default:
            return;
        }

        int pixelvalue = atoi(pixelValue.c_str());
        //qDebug() << pixelvalue << endl;
        double range[2];
        //获得像素值的范围，最小值，最大值
        _ImageViewer->GetInput()->GetScalarRange(range);

        //qDebug() << pixelvalue << range[0] << " " << range[1];

        RegionGrowingByConnectedThredholdFilter(_Reader, _Reader->GetOutput(), image_coordinate, pixelvalue - 100, pixelvalue + 100, range[1]);
    }
    
    vtkInteractorStyleImage::OnKeyDown();
}

void myVtkInteractorStyleImage::OnLeftButtonDown()
{
    Picker = propPicker;
    vtkImageData* image = _ImageViewer->GetInput();

#if VTK_MAJOR_VERSION <= 5
    image->Update();
#endif

    Picker->Pick(interactor->GetEventPosition()[0],
        interactor->GetEventPosition()[1], 0.0, renderer);
    //int* a = interactor->GetEventPosition();
    //qDebug() << "a" << interactor->GetEventPosition()[0] << " " << interactor->GetEventPosition()[1] << endl;
    vtkAssemblyPath* path = Picker->GetPath();
    bool validPick = false;

    if (path)
    {
        vtkCollectionSimpleIterator sit;
        path->InitTraversal(sit);
        vtkAssemblyNode* node;
        for (int i = 0; i < path->GetNumberOfItems() && !validPick; ++i)
        {
            node = path->GetNextNode(sit);
            if (actor == vtkImageActor::SafeDownCast(node->GetViewProp()))
            {
                validPick = true;
            }
        }
    }
    else {
        auto img = _ImageViewer->GetInput();
        long num = img->GetActualMemorySize();
        int* t = _ImageViewer->GetSize();
    }
    if (!validPick)
    {
        //this->Annotation->SetText(0, "Off Image");
        //interactor->Render();
        // Pass the event further on
        //style->OnMouseMove();
        //qDebug() << "no files" << endl;
        return;
    }

    Picker->GetPickPosition(pos);

    int axis = _ImageViewer->GetSliceOrientation();
    switch (axis)
    {
    case vtkImageViewer2::SLICE_ORIENTATION_XZ:
        image_coordinate[0] = vtkMath::Round(pos[0] / image->GetSpacing()[0]);
        image_coordinate[1] = _ImageViewer->GetSlice();
        image_coordinate[2] = vtkMath::Round(pos[2] / image->GetSpacing()[2]);
        DrawLine();
        mvisiArray[0]->DrawLine();
        mvisiArray[1]->DrawLine();//移动十字线的位置
        break;
    case vtkImageViewer2::SLICE_ORIENTATION_YZ:
        image_coordinate[0] = _ImageViewer->GetSlice();
        image_coordinate[1] = vtkMath::Round(pos[1] / image->GetSpacing()[1]);
        image_coordinate[2] = vtkMath::Round(pos[2] / image->GetSpacing()[2]);
        DrawLine();
        mvisiArray[0]->DrawLine();
        mvisiArray[2]->DrawLine();
        break;
    default: // vtkImageViewer2::SLICE_ORIENTATION_XY
        image_coordinate[0] = vtkMath::Round(pos[0] / image->GetSpacing()[0]);
        image_coordinate[1] = vtkMath::Round(pos[1] / image->GetSpacing()[1]);
        image_coordinate[2] = _ImageViewer->GetSlice();
        DrawLine();
        mvisiArray[1]->DrawLine();
        mvisiArray[2]->DrawLine();
        break;
    }

    std::string pixelValue = "";
    switch (image->GetScalarType())
    {
        vtkTemplateMacro(
            (vtkValueMessageTemplate<VTK_TT>(_ImageViewer->GetInput(), image_coordinate, pixelValue)));

    default:
        return;
    }

    if (path)
    {
        _ui.label11->setText("[" + QString::number(image_coordinate[0], 10) + "," +
            QString::number(image_coordinate[1], 10) + "," +
            QString::number(image_coordinate[2], 10) + "]" +
            " value:" + QString::fromStdString(pixelValue));

        /*
        switch (axis)
        {
        case vtkImageViewer2::SLICE_ORIENTATION_XZ:
            _ui.label11->setText("");
            _ui.label22->setText("");
            _ui.label33->setText("[" + QString::number(image_coordinate[0], 10) + "," +
                QString::number(image_coordinate[1], 10) + "," +
                QString::number(image_coordinate[2], 10) + "]" +
                " value:" + QString::fromStdString(pixelValue));
            break;
        case vtkImageViewer2::SLICE_ORIENTATION_YZ:
            _ui.label11->setText("");
            _ui.label22->setText("[" + QString::number(image_coordinate[0], 10) + "," +
                QString::number(image_coordinate[1], 10) + "," +
                QString::number(image_coordinate[2], 10) + "]" +
                " value:" + QString::fromStdString(pixelValue));
            _ui.label33->setText("");
            break;
        default: // vtkImageViewer2::SLICE_ORIENTATION_XY
            _ui.label11->setText("[" + QString::number(image_coordinate[0], 10) + "," +
                QString::number(image_coordinate[1], 10) + "," +
                QString::number(image_coordinate[2], 10) + "]" +
                " value:" + QString::fromStdString(pixelValue));
            _ui.label22->setText("");
            _ui.label33->setText("");
            break;
        }
        */
    }
    SetOtherWindows();
}

void myVtkInteractorStyleImage::SetOtherWindows()
{

    //xy
    if (this == mvisiArray[0])
    {

        mvisiArray[1]->_Slice = image_coordinate[0];//x
        mvisiArray[1]->_ImageViewer->SetSlice(mvisiArray[1]->_Slice);
        _ui.label2->setText(QString::number((int)mvisiArray[1]->_Slice, 10) + " of " + QString::number((int)mvisiArray[1]->_MaxSlice, 10));

        mvisiArray[2]->_Slice = image_coordinate[1];//y
        mvisiArray[2]->_ImageViewer->SetSlice(mvisiArray[2]->_Slice);
        _ui.label3->setText(QString::number((int)mvisiArray[2]->_Slice, 10) + " of " + QString::number((int)mvisiArray[2]->_MaxSlice, 10));
    }
    //yz
    if (this == mvisiArray[1])
    {
        mvisiArray[0]->_Slice = image_coordinate[2];//z
        mvisiArray[0]->_ImageViewer->SetSlice(mvisiArray[0]->_Slice);
        _ui.label1->setText(QString::number((int)mvisiArray[0]->_Slice, 10) + " of " + QString::number((int)mvisiArray[0]->_MaxSlice, 10));

        mvisiArray[2]->_Slice = image_coordinate[1];//y
        mvisiArray[2]->_ImageViewer->SetSlice(mvisiArray[2]->_Slice);
        _ui.label3->setText(QString::number((int)mvisiArray[2]->_Slice, 10) + " of " + QString::number((int)mvisiArray[2]->_MaxSlice, 10));
    }
    //xz
    if (this == mvisiArray[2])
    {
        mvisiArray[0]->_Slice = image_coordinate[2];//z
        mvisiArray[0]->_ImageViewer->SetSlice(mvisiArray[0]->_Slice);
        _ui.label1->setText(QString::number((int)mvisiArray[0]->_Slice, 10) + " of " + QString::number((int)mvisiArray[0]->_MaxSlice, 10));

        mvisiArray[1]->_Slice = image_coordinate[0];//x
        mvisiArray[1]->_ImageViewer->SetSlice(mvisiArray[1]->_Slice);
        _ui.label2->setText(QString::number((int)mvisiArray[1]->_Slice, 10) + " of " + QString::number((int)mvisiArray[1]->_MaxSlice, 10));
    }
}

void myVtkInteractorStyleImage::DrawLine()
{
    int b[3];
    b[0] = image_coordinate[0];
    b[1] = image_coordinate[1];
    b[2] = image_coordinate[2];
    vtkSmartPointer<vtkPolyData> linesPolyData = vtkSmartPointer<vtkPolyData>::New();
    double* bc = _Reader->GetDataSpacing();
    int* dimen = _Reader->GetOutput()->GetDimensions();

    // Create a vtkPoints container and store the points in it
    vtkSmartPointer<vtkPoints> pts = vtkSmartPointer<vtkPoints>::New();

    if (this == mvisiArray[0])//xy
    {
        b[0] = b[0] * bc[0];
        b[1] = b[1] * bc[1];
        b[2] = 1 + b[2] * bc[2];//为了看到线，把线画在图像上方,太大了也不好，太大了反倒看不到线了
        double origin[3] = { (double)b[0],(double)b[1],(double)b[2] };
        double p0[3] = { (double)(bc[0] * dimen[0]), (double)b[1],(double)b[2] };
        double p1[3] = { (double)b[0],(double)(bc[1] * dimen[1]), (double)b[2] };
        double p2[3] = { (double)0.,(double)b[1],(double)b[2] };
        double p3[3] = { (double)b[0],0.,(double)b[2] };

        pts->InsertNextPoint(origin);
        pts->InsertNextPoint(p0);
        pts->InsertNextPoint(p1);
        pts->InsertNextPoint(p2);
        pts->InsertNextPoint(p3);
    }
    if (this == mvisiArray[1])//yz
    {
        b[0] = 1 + b[0] * bc[0];//为了看到线，把线画在图像上方
        b[1] = b[1] * bc[1];
        b[2] = b[2] * bc[2];
	    double origin[3] = { (double)b[0], (double)b[1],             (double)b[2] };
	    double p0[3] = { (double)b[0], (double)b[1],             (double)(bc[2] * dimen[2]) };
	    double p1[3] = { (double)b[0], (double)(bc[1] * dimen[1]), (double)b[2] };
	    double p2[3] = { (double)b[0], (double)b[1],             0. };
	    double p3[3] = { (double)b[0], 0.,                       (double)b[2] };

        pts->InsertNextPoint(origin);
        pts->InsertNextPoint(p0);
        pts->InsertNextPoint(p1);
        pts->InsertNextPoint(p2);
        pts->InsertNextPoint(p3);
    }
    if (this == mvisiArray[2])//xz
    {
        b[0] = b[0] * bc[0];
        b[1] = b[1] * bc[1] - 1;//为了看到线，把线画在图像上方，这一方向和另外两个不一样，这个写出的效果是，我们是站在低数层看的
        b[2] = b[2] * bc[2];
        double origin[3] = { (double)b[0],             (double)b[1], (double)b[2] };
        double p0[3] = { (double)b[0],             (double)b[1], (double)(bc[2] * dimen[2]) };
        double p1[3] = { (double)(bc[0] * dimen[0]), (double)b[1], (double)b[2] };
        double p2[3] = { (double)b[0],             (double)b[1], 0. };
        double p3[3] = { 0.,                       (double)b[1], (double)b[2] };

        pts->InsertNextPoint(origin);
        pts->InsertNextPoint(p0);
        pts->InsertNextPoint(p1);
        pts->InsertNextPoint(p2);
        pts->InsertNextPoint(p3);
    }
    // Add the points to the polydata container
    linesPolyData->SetPoints(pts);
    // Create the first line (between Origin and P0)
    vtkSmartPointer<vtkLine> line0 = vtkSmartPointer<vtkLine>::New();
    line0->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
    line0->GetPointIds()->SetId(1, 1); // the second 1 is the index of P0 in linesPolyData's points
    // Create the second line (between Origin and P1)
    vtkSmartPointer<vtkLine> line1 = vtkSmartPointer<vtkLine>::New();
    line1->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
    line1->GetPointIds()->SetId(1, 2); // 2 is the index of P1 in linesPolyData's points

    // Create the second line (between Origin and P1)
    vtkSmartPointer<vtkLine> line2 = vtkSmartPointer<vtkLine>::New();
    line2->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
    line2->GetPointIds()->SetId(1, 3); // 3 is the index of P1 in linesPolyData's points
    // Create the second line (between Origin and P1)
    vtkSmartPointer<vtkLine> line3 = vtkSmartPointer<vtkLine>::New();
    line3->GetPointIds()->SetId(0, 0); // the second 0 is the index of the Origin in linesPolyData's points
    line3->GetPointIds()->SetId(1, 4); // 4 is the index of P1 in linesPolyData's points

    // Create a vtkCellArray container and store the lines in it
    vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
    lines->InsertNextCell(line0); 
    lines->InsertNextCell(line1);
    lines->InsertNextCell(line2); 
    lines->InsertNextCell(line3);
    // Add the lines to the polydata container
    linesPolyData->SetLines(lines);
    vtkSmartPointer<vtkOpenGLPolyDataMapper>mapper1 = vtkSmartPointer<vtkOpenGLPolyDataMapper>::New();
    mapper1->AddShaderReplacement(
        vtkShader::Fragment,  // in the fragment shader
        "//VTK::TCoord::Impl", // replace the tcoord block
        true, // before the standard replacements
        "//VTK::TCoord::Impl\n" // we still want the default calc
        //but we add this to make a checkrboard pattern
        "  if ((int(gl_FragCoord.x/6) % 2) + (int(gl_FragCoord.y/6) % 2) == 1) { discard; }\n",
        false // only do it once
    );
    mapper1->SetInputData(linesPolyData);
    _actor->SetMapper(mapper1);
    _actor->GetProperty()->SetColor(0, 0, 1);
    _actor->GetProperty()->SetLineWidth(2);
    renderer->RemoveActor(_actor);
    renderer->AddActor(_actor);

    if (this == mvisiArray[0])
    {
        _ui.qvw1->GetRenderWindow()->AddRenderer(this->renderer);
        _ui.qvw1->GetRenderWindow()->Render();
    }
    if (this == mvisiArray[1])
    {
        _ui.qvw2->GetRenderWindow()->AddRenderer(this->renderer);
        _ui.qvw2->GetRenderWindow()->Render();
    }
    if (this == mvisiArray[2])
    {
        _ui.qvw3->GetRenderWindow()->AddRenderer(this->renderer);
        _ui.qvw3->GetRenderWindow()->Render();
    }
}


void myVtkInteractorStyleImage::ConstructITKImage(vtkImageData* originalImageData)
{
    double imageSpacing[3] = { 0.0 };
    double imageOrigin[3] = { 0.0 };
    int imageDimension[3] = { 0 };
    originalImageData->GetSpacing(imageSpacing);
    originalImageData->GetOrigin(imageOrigin);
    originalImageData->GetDimensions(imageDimension);


    const ImageType::SizeType  size = { {(unsigned long long)imageDimension[0],
                                         (unsigned long long)imageDimension[1],
                                         (unsigned long long)imageDimension[2]} }; //Size along {X,Y,Z}
    const ImageType::IndexType start = { {0,0,0} }; // First index on {X,Y,Z}

    ImageType::RegionType region;
    region.SetSize(size);
    region.SetIndex(start);

    //Types for converting between ITK and VTK
    typedef itk::VTKImageToImageFilter<ImageType> VTKImageToImageType;

    //Converting to ITK Image Format
    VTKImageToImageType::Pointer vtkImageToImageFilter = VTKImageToImageType::New();

    vtkImageToImageFilter->SetInput(originalImageData);
    vtkImageToImageFilter->Update();
    //将vtk的图像转化为itk的图像，以便利用itk的分割算法进行分割.
    m_itkImage->SetRegions(region);
    m_itkImage->Allocate();
    m_itkImage = const_cast<itk::Image<short, kDimension>*>(vtkImageToImageFilter->GetOutput());

    ImageType::SpacingType spacing;
    spacing[0] = imageSpacing[0]; // spacing along X
    spacing[1] = imageSpacing[1]; // spacing along Y
    spacing[2] = imageSpacing[2]; // spacing along Z
    m_itkImage->SetSpacing(spacing);

    ImageType::PointType newOrigin;
    newOrigin[0] = imageOrigin[0];
    newOrigin[1] = imageOrigin[1];
    newOrigin[2] = imageOrigin[2];
    m_itkImage->SetOrigin(newOrigin);

    ImageType::DirectionType direction;
    direction.SetIdentity();
    m_itkImage->SetDirection(direction);
    m_itkImage->UpdateOutputInformation();
}

bool myVtkInteractorStyleImage::CheckSeedPointInsideImage(vtkDICOMImageReader* reader, int worldSeedPoint[3])
{
    typedef itk::Point< double, ImageType::ImageDimension > PointType;
    PointType point;
    point[0] = worldSeedPoint[0];    // x coordinate
    point[1] = worldSeedPoint[1];    // y coordinate
    point[2] = worldSeedPoint[2];    // z coordinate

    //qDebug() << point[0] << " " << point[1] << " " << point[2];
    //根据选取的种子点的世界坐标，获取这个种子点在itk图像中的像素索引值.
    bool isInside = m_itkImage->TransformPhysicalPointToIndex(point, m_pixelIndex);
    //    ImageType::PixelType value = this->m_itkImage->GetPixel(m_pixelIndex);
    m_pixelIndex[0] = m_pixelIndex[0] * reader->GetDataSpacing()[0];
    m_pixelIndex[1] = m_pixelIndex[1] * reader->GetDataSpacing()[1];
    m_pixelIndex[2] = m_pixelIndex[2] * reader->GetDataSpacing()[2];
    return isInside;
}

void myVtkInteractorStyleImage::RegionGrowingByConnectedThredholdFilter(vtkDICOMImageReader* reader, vtkImageData* pImage, int worldSeedPoint[3], int lower, int upper, int max)
{

    ConstructITKImage(pImage);

    bool isSeedPointInsideImage = CheckSeedPointInsideImage(reader, worldSeedPoint);
    if (!isSeedPointInsideImage)
    {
        qDebug() << "outside";
        return ;
    }
    typedef itk::Image<short, kDimension > InternalImageType;
    typedef itk::ConnectedThresholdImageFilter< InternalImageType, InternalImageType > ConnectedFilterType;
    ConnectedFilterType::Pointer connectedThreshold = ConnectedFilterType::New();
    connectedThreshold->SetInput(m_itkImage);

    connectedThreshold->SetLower(lower);
    connectedThreshold->SetUpper(upper);
    connectedThreshold->SetReplaceValue(max);
    connectedThreshold->AddSeed(m_pixelIndex);
    connectedThreshold->Update();

    typedef itk::ImageToVTKImageFilter<ImageType> ConnectorType;
        //Converting Back from ITK to VTK Image for Visualization.
    
    ConnectorType::Pointer connector = ConnectorType::New();
    connector->SetInput(connectedThreshold->GetOutput());
    connector->Update();

    mvisiArray[0]->_ImageViewer->SetInputData(connector->GetOutput());
    mvisiArray[1]->_ImageViewer->SetInputData(connector->GetOutput());
    mvisiArray[2]->_ImageViewer->SetInputData(connector->GetOutput());
    mvisiArray[0]->_ImageViewer->SetSliceOrientationToXY();
    mvisiArray[1]->_ImageViewer->SetSliceOrientationToYZ();
    mvisiArray[2]->_ImageViewer->SetSliceOrientationToXZ();
    mvisiArray[0]->_ImageViewer->Render();
    mvisiArray[1]->_ImageViewer->Render();
    mvisiArray[2]->_ImageViewer->Render();
}