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


	LightClass* m_Light;
	LightClass* m_Light_1;
	LightClass* m_Light_2;
	LightClass* m_Light_3;
	LightClass* m_Light_4;
	CameraClass* m_Camera;

private:
	bool Render(float);

private:
	D3DClass* m_D3D;
	ModelClass* m_Model;
	ModelClass* m_Model_1;
	ModelClass* m_Model_2;
	ModelClass* m_Model_3;
	ModelClass* m_Model_4;
	ModelClass* m_Model_5;
	ModelClass* m_Model_6;
	ModelClass* m_Model_7;
	ModelClass* m_Model_8;
	ModelClass* m_Model_9;
	ModelClass* m_Model_10;
	ModelClass* m_Model_11;
	ModelClass* m_Model_12;
	ModelClass* m_Model_13;
	ModelClass* m_Model_14;
	ModelClass* m_Model_15;
	ModelClass* m_Model_16;
	ModelClass* m_Model_17;
	ModelClass* m_Model_18;
	ModelClass* m_Model_19;
	ModelClass* m_Model_1u;
	ModelClass* m_Model_2u;
	ModelClass* m_Model_3u;
	ModelClass* m_Model_4u;
	ModelClass* m_Model_5u;
	ModelClass* m_Model_6u;
	ModelClass* m_Model_7u;
	ModelClass* m_Model_8u;
	ModelClass* m_Model_9u;
	ModelClass* m_Model_10u;
	ModelClass* m_Model_11u;
	ModelClass* m_Model_12u;
	ModelClass* m_Model_13u;
	ModelClass* m_Model_14u;
	ModelClass* m_Model_15u;
	ModelClass* m_Model_16u;
	ModelClass* m_Model_17u;
	ModelClass* m_Model_18u;
	ModelClass* m_Model_19u;
	ModelClass* m_Model_cable;
	ModelClass* m_Model_water;


	LightShaderClass* m_LightShader;

	TextureShaderClass* m_TextureShader;
	BitmapClass* m_Bitmap;

	TextClass* m_Text;
};

#endif