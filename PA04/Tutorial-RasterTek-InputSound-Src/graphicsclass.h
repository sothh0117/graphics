////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "d3dclass.h"
#include "cameraclass.h"
#include "modelclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"

#include "textureshaderclass.h"
#include "bitmapclass.h"
#include "textclass.h"

/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
	bool Frame(int, int);
	bool Render(float);
	bool isZbuffer = false;

	LightClass* m_Light;
	LightClass* m_Light_1;
	LightClass* m_Light_2;
	LightClass* m_Light_3;
	LightClass* m_Light_4;
	LightClass* m_Light_5;
	CameraClass* m_Camera;
	D3DClass* m_D3D;

private:
	

private:
	
	ModelClass* m_Model_mount;
	ModelClass* m_Model_1;
	ModelClass* m_Model_2;
	ModelClass* m_Model_3;
	ModelClass* m_Model_4;
	ModelClass* m_Model_5;
	ModelClass* m_Model_6;
	ModelClass* m_Model_cable;
	ModelClass* m_Model_water;
	ModelClass* m_Model_back;


	LightShaderClass* m_LightShader;

	TextureShaderClass* m_TextureShader;
	BitmapClass* m_Bitmap;

	TextClass* m_Text;
};

#endif