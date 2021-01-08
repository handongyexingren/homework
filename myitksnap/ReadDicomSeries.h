#pragma once

#include <vtkSmartPointer.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkActor.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>
#include <vtkInteractorStyleImage.h>
#include <vtkActor2D.h>
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <vtkPropPicker.h>
#include <sstream>
#include <vtkInteractorStyleImage.h>
#include <vtkImageViewer2.h>

#include <vtkImageData.h>
#include <itkVTKImageToImageFilter.h>
#include <itkConnectedThresholdImageFilter.h>
#include <itkImageToVTKImageFilter.h>
#include <itkMathDetail.h>
#include <itkImage.h>
#include <itkNeighborhoodConnectedImageFilter.h>
#include <vtkDICOMImageReader.h>
#include <vtkCellArray.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkLine.h>
#include <vtkOpenGLPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>

#include <vtkPolyDataMapper.h>
#include <vtkTextProperty.h>
#include <vtkLineSource.h>
#include <vtkNamedColors.h>
#include <vtkPolyData.h>
#include <vtkUnsignedCharArray.h>
#include <vtkContourFilter.h>
#include <vtkPolyDataNormals.h>
#include <vtkOutlineFilter.h>
#include <QGraphicsView>
#include <vtkCallbackCommand.h>
#include<vtkImageDataToPointSet.h>
#include <vtkRendererCollection.h>
#include <vtkImageFlip.h>
#include <vtkTextActor.h>
#include <vtkTextWidget.h>
#include <vtkCamera.h>
#include <vtkLookupTable.h>
#include <vtkImageMapToColors.h>
#include <vtkPolyDataConnectivityFilter.h>
#include <vtkTextRepresentation.h>
#include <QDebug>

#define kDimension 3
typedef itk::Image<short, kDimension> ImageType;
typedef ImageType::IndexType PixelIndexType;

class myVtkInteractorStyleImage : public vtkInteractorStyleImage
{
public:
	static myVtkInteractorStyleImage* New();
	vtkTypeMacro(myVtkInteractorStyleImage, vtkInteractorStyleImage);
	
	friend class myitksnap;

	static myVtkInteractorStyleImage* mvisiArray[3];
	static int image_coordinate[3];
	static double pos[3];
	vtkSmartPointer<vtkDICOMImageReader> _Reader;
	vtkImageViewer2* _ImageViewer;
	vtkTextMapper* _StatusMapper;
	int _Slice;
	int _MinSlice;
	int _MaxSlice;
	int _Nowslice;
	vtkSmartPointer<vtkPropPicker> propPicker;
	vtkSmartPointer<vtkPropPicker> Picker;
	vtkSmartPointer<vtkImageActor> actor;
	vtkSmartPointer<vtkRenderWindowInteractor> interactor;
	vtkSmartPointer<vtkRenderer> renderer;
	vtkSmartPointer<vtkActor> _actor;

	ImageType::Pointer m_itkImage;
	ImageType::IndexType m_pixelIndex;

	Ui::myitksnapClass _ui;

	void SetImageViewer(vtkImageViewer2* imageViewer, Ui::myitksnapClass ui,vtkDICOMImageReader* reader);
	//int GetSlice();

	void MoveSliceForward();
	void MoveSliceBackward();
	void OnKeyDown();
	void OnMouseWheelForward();
	void OnMouseWheelBackward();
	
	void OnLeftButtonDown();

	void DrawLine();
	//void OnLeftButtonUp();
	void SetOtherWindows();
	void ConstructITKImage(vtkImageData* originalImageData);

	bool CheckSeedPointInsideImage(vtkDICOMImageReader* reader, int worldSeedPoint[3]);
	void RegionGrowingByConnectedThredholdFilter(vtkDICOMImageReader* reader, vtkImageData* pImage, int worldSeedPoint[3], int lower, int upper, int max);

	template<typename T> // 模板，初始化时才知道其类型
		// 形参为图像，位置和信息
	void vtkValueMessageTemplate(vtkImageData* image, int* position, std::string& message)
	{
		T* tuple = ((T*)image->GetScalarPointer(position)); // 返回一个指向image的位置指针
		int components = image->GetNumberOfScalarComponents(); // 获取点的标量分量的数量
		for (int c = 0; c < components; ++c)
		{
			//cout << "pixel_value: " << pixel_value << endl;
			message += vtkVariant(tuple[c]).ToString();
			if (c != (components - 1))
			{
				message += ", ";
			}
		}
		//cout << "pixel value: " << message.c_str() << endl;
	}
};

vtkStandardNewMacro(myVtkInteractorStyleImage);

//静态成员数组初始化
myVtkInteractorStyleImage* myVtkInteractorStyleImage::mvisiArray[3] = { nullptr,nullptr,nullptr };
int myVtkInteractorStyleImage::image_coordinate[3] = { 0,0,0 };
double myVtkInteractorStyleImage::pos[3] = { 0,0,0 };