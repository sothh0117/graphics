////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	m_Model = 0;
	m_Model_1 = 0;
	m_Model_2 = 0;
	m_Model_3 = 0;
	m_Model_4 = 0;
	m_Model_5 = 0;
	m_Model_6 = 0;
	m_Model_7 = 0;
	m_Model_8 = 0;
	m_Model_9 = 0;
	m_Model_10 = 0;
	m_Model_11 = 0;
	m_Model_12 = 0;
	m_Model_13 = 0;
	m_Model_14 = 0;
	m_Model_15 = 0;
	m_Model_16 = 0;
	m_Model_17 = 0;
	m_Model_18 = 0;
	m_Model_19 = 0;
	m_Model_1u = 0;
	m_Model_2u = 0;
	m_Model_3u = 0;
	m_Model_4u = 0;
	m_Model_5u = 0;
	m_Model_6u = 0;
	m_Model_7u = 0;
	m_Model_8u = 0;
	m_Model_9u = 0;
	m_Model_10u = 0;
	m_Model_11u = 0;
	m_Model_12u = 0;
	m_Model_13u = 0;
	m_Model_14u = 0;
	m_Model_15u = 0;
	m_Model_16u = 0;
	m_Model_17u = 0;
	m_Model_18u = 0;
	m_Model_19u = 0;
	m_Model_cable = 0;
	m_Model_water = 0;
	

	m_LightShader = 0;
	m_Light = 0;
	m_Light_1 = 0;
	m_Light_2 = 0;
	m_Light_3 = 0;
	m_Light_4 = 0;

	m_TextureShader = 0;
	m_Bitmap = 0;

	m_Text = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	XMMATRIX baseViewMatrix;

	// Create the Direct3D object.
	m_D3D = new D3DClass;
	if(!m_D3D)
	{
		return false;
	}

	// Initialize the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize Direct3D.", L"Error", MB_OK);
		return false;
	}

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 50.0f, -70.0f);
		
	// Create the model object.
	m_Model = new ModelClass;
	if(!m_Model)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model->Initialize(m_D3D->GetDevice(), L"./data/mount.obj", L"./data/grass.dds");
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the model object.", L"Error", MB_OK);
		return false;
	}

	m_Model_1 = new ModelClass;
	if (!m_Model_1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_1->Initialize(m_D3D->GetDevice(), L"./data/tree1_down.obj", L"./data/tree.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_1 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_2 = new ModelClass;
	if (!m_Model_2)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_2->Initialize(m_D3D->GetDevice(), L"./data/tree2_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_2 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_3 = new ModelClass;
	if (!m_Model_3)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_3->Initialize(m_D3D->GetDevice(), L"./data/tree3_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_3 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_4 = new ModelClass;
	if (!m_Model_4)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_4->Initialize(m_D3D->GetDevice(), L"./data/tree4_down.obj", L"./data/tree.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_4 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_5 = new ModelClass;
	if (!m_Model_5)
	{
		return false;
	}
	result = m_Model_5->Initialize(m_D3D->GetDevice(), L"./data/tree5_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_5 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_6 = new ModelClass;
	if (!m_Model_6)
	{
		return false;
	}
	result = m_Model_6->Initialize(m_D3D->GetDevice(), L"./data/tree6_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_6 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_7 = new ModelClass;
	if (!m_Model_7)
	{
		return false;
	}
	result = m_Model_7->Initialize(m_D3D->GetDevice(), L"./data/tree7_down.obj", L"./data/tree.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_7 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_8 = new ModelClass;
	if (!m_Model_8)
	{
		return false;
	}
	result = m_Model_8->Initialize(m_D3D->GetDevice(), L"./data/tree8_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_8 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_9 = new ModelClass;
	if (!m_Model_9)
	{
		return false;
	}
	result = m_Model_9->Initialize(m_D3D->GetDevice(), L"./data/tree9_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_9 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_10 = new ModelClass;
	if (!m_Model_10)
	{
		return false;
	}
	result = m_Model_10->Initialize(m_D3D->GetDevice(), L"./data/tree10_down.obj", L"./data/tree.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_10 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_11 = new ModelClass;
	if (!m_Model_11)
	{
		return false;
	}
	result = m_Model_11->Initialize(m_D3D->GetDevice(), L"./data/tree11_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_11 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_12 = new ModelClass;
	if (!m_Model_12)
	{
		return false;
	}
	result = m_Model_12->Initialize(m_D3D->GetDevice(), L"./data/tree12_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_12 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_13 = new ModelClass;
	if (!m_Model_13)
	{
		return false;
	}
	result = m_Model_13->Initialize(m_D3D->GetDevice(), L"./data/tree13_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_13 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_14 = new ModelClass;
	if (!m_Model_14)
	{
		return false;
	}
	result = m_Model_14->Initialize(m_D3D->GetDevice(), L"./data/tree14_down.obj", L"./data/tree.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_14 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_15 = new ModelClass;
	if (!m_Model_15)
	{
		return false;
	}
	result = m_Model_15->Initialize(m_D3D->GetDevice(), L"./data/tree15_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_15 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_16 = new ModelClass;
	if (!m_Model_16)
	{
		return false;
	}
	result = m_Model_16->Initialize(m_D3D->GetDevice(), L"./data/tree16_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_16 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_17 = new ModelClass;
	if (!m_Model_17)
	{
		return false;
	}
	result = m_Model_17->Initialize(m_D3D->GetDevice(), L"./data/tree17_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_17 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_18 = new ModelClass;
	if (!m_Model_18)
	{
		return false;
	}
	result = m_Model_18->Initialize(m_D3D->GetDevice(), L"./data/tree18_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_18 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_19 = new ModelClass;
	if (!m_Model_19)
	{
		return false;
	}
	result = m_Model_19->Initialize(m_D3D->GetDevice(), L"./data/tree19_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_19 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_1u = new ModelClass;
	if (!m_Model_1u)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_1u->Initialize(m_D3D->GetDevice(), L"./data/tree1_up.obj", L"./data/leaf.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_1u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_2u = new ModelClass;
	if (!m_Model_2u)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_2u->Initialize(m_D3D->GetDevice(), L"./data/tree2_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_2u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_3u = new ModelClass;
	if (!m_Model_3u)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_3u->Initialize(m_D3D->GetDevice(), L"./data/tree3_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_3u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_4u = new ModelClass;
	if (!m_Model_4u)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_4u->Initialize(m_D3D->GetDevice(), L"./data/tree4_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_4u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_5u = new ModelClass;
	if (!m_Model_5u)
	{
		return false;
	}
	result = m_Model_5u->Initialize(m_D3D->GetDevice(), L"./data/tree5_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_5u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_6u = new ModelClass;
	if (!m_Model_6u)
	{
		return false;
	}
	result = m_Model_6u->Initialize(m_D3D->GetDevice(), L"./data/tree6_up.obj", L"./data/leaf.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_6u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_7u = new ModelClass;
	if (!m_Model_7u)
	{
		return false;
	}
	result = m_Model_7u->Initialize(m_D3D->GetDevice(), L"./data/tree7_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_7u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_8u = new ModelClass;
	if (!m_Model_8u)
	{
		return false;
	}
	result = m_Model_8u->Initialize(m_D3D->GetDevice(), L"./data/tree8_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_8u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_9u = new ModelClass;
	if (!m_Model_9u)
	{
		return false;
	}
	result = m_Model_9u->Initialize(m_D3D->GetDevice(), L"./data/tree9_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_9u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_10u = new ModelClass;
	if (!m_Model_10u)
	{
		return false;
	}
	result = m_Model_10u->Initialize(m_D3D->GetDevice(), L"./data/tree10_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_10u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_11u = new ModelClass;
	if (!m_Model_11u)
	{
		return false;
	}
	result = m_Model_11u->Initialize(m_D3D->GetDevice(), L"./data/tree11_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_11u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_12u = new ModelClass;
	if (!m_Model_12u)
	{
		return false;
	}
	result = m_Model_12u->Initialize(m_D3D->GetDevice(), L"./data/tree12_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_12u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_13u = new ModelClass;
	if (!m_Model_13u)
	{
		return false;
	}
	result = m_Model_13u->Initialize(m_D3D->GetDevice(), L"./data/tree13_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_13u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_14u = new ModelClass;
	if (!m_Model_14u)
	{
		return false;
	}
	result = m_Model_14u->Initialize(m_D3D->GetDevice(), L"./data/tree14_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_14u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_15u = new ModelClass;
	if (!m_Model_15u)
	{
		return false;
	}
	result = m_Model_15u->Initialize(m_D3D->GetDevice(), L"./data/tree15_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_15u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_16u = new ModelClass;
	if (!m_Model_16u)
	{
		return false;
	}
	result = m_Model_16u->Initialize(m_D3D->GetDevice(), L"./data/tree16_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_16u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_17u = new ModelClass;
	if (!m_Model_17u)
	{
		return false;
	}
	result = m_Model_17u->Initialize(m_D3D->GetDevice(), L"./data/tree17_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_17u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_18u = new ModelClass;
	if (!m_Model_18u)
	{
		return false;
	}
	result = m_Model_18u->Initialize(m_D3D->GetDevice(), L"./data/tree18_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_18u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_19u = new ModelClass;
	if (!m_Model_19u)
	{
		return false;
	}
	result = m_Model_19u->Initialize(m_D3D->GetDevice(), L"./data/tree19_up.obj", L"./data/leaves.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_19u object.", L"Error", MB_OK);
		return false;
	}

	m_Model_cable = new ModelClass;
	if (!m_Model_cable)
	{
		return false;
	}
	result = m_Model_cable->Initialize(m_D3D->GetDevice(), L"./data/cable.obj", L"./data/leaf.dds"); // ÄÉÀÌºíÄ«·Î ¹Ù²ã¾ß´ï
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_cable object.", L"Error", MB_OK);
		return false;
	}

	m_Model_water = new ModelClass;
	if (!m_Model_water)
	{
		return false;
	}
	result = m_Model_water->Initialize(m_D3D->GetDevice(), L"./data/water.obj", L"./data/wa.dds"); // ÅØ½ºÃÄ ¹°·Î ¹Ù²ã¾ß´ï
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_water object.", L"Error", MB_OK);
		return false;
	}

	// Create the light shader object.
	m_LightShader = new LightShaderClass;
	if (!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
		return false;
	}

	// Create the light object.
	m_Light = new LightClass;
	if (!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(1.0f, 0.0f, 1.0f);
	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(32.0f);

	m_Light_1 = new LightClass;
	if (!m_Light_1)
	{
		return false;
	}

	// Initialize the light object.
	m_Light_1->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light_1->SetDiffuseColor(0.0f, 1.0f, 0.0f, 1.0f);
	m_Light_1->SetDirection(1.0f, 0.0f, 1.0f);
	m_Light_1->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_1->SetSpecularPower(32.0f);

	m_Light_2 = new LightClass;
	if (!m_Light_2)
	{
		return false;
	}

	// Initialize the light object.
	m_Light_2->SetAmbientColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_2->SetDiffuseColor(0.0f, 0.0f, 1.0f, 1.0f);
	m_Light_2->SetDirection(1.0f, 1.0f, 1.0f);
	m_Light_2->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_2->SetSpecularPower(32.0f);

	m_Light_3 = new LightClass;
	if (!m_Light_3)
	{
		return false;
	}

	// Initialize the light object.
	m_Light_3->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light_3->SetDiffuseColor(0.5f, 0.0f, 0.0f, 1.0f);
	m_Light_3->SetDirection(1.0f, 1.0f, 1.0f);
	m_Light_3->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_3->SetSpecularPower(32.0f);

	m_Light_4 = new LightClass;
	if (!m_Light_4)
	{
		return false;
	}

	// Initialize the light object.
	m_Light_4->SetAmbientColor(0.15f, 0.15f, 0.15f, 1.0f);
	m_Light_4->SetDiffuseColor(0.5f, 0.5f, 0.0f, 1.0f);
	m_Light_4->SetDirection(1.0f, 1.0f, 1.0f);
	m_Light_4->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_4->SetSpecularPower(32.0f);

	// Create the texture shader object.
	m_TextureShader = new TextureShaderClass;
	if (!m_TextureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}


	// Create the bitmap object.
	m_Bitmap = new BitmapClass;
	if (!m_Bitmap)
	{
		return false;
	}

	// Initialize the bitmap object.
	result = m_Bitmap->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight, L"./data/grass.dds", 256, 256);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the bitmap object.", L"Error", MB_OK);
		return false;
	}

	// Initialize a base view matrix with the camera for 2D user interface rendering.
//	m_Camera->SetPosition(0.0f, 0.0f, -1.0f);
	m_Camera->Render();
	m_Camera->GetViewMatrix(baseViewMatrix);

	// Create the text object.
	m_Text = new TextClass;
	if (!m_Text)
	{
		return false;
	}

	// Initialize the text object.
	result = m_Text->Initialize(m_D3D->GetDevice(), m_D3D->GetDeviceContext(), hwnd, screenWidth, screenHeight, baseViewMatrix);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the text object.", L"Error", MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the model object.
	if(m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = 0;
	}

	if (m_Model_1)
	{
		m_Model_1->Shutdown();
		delete m_Model_1;
		m_Model_1 = 0;
	}

	if (m_Model_2)
	{
		m_Model_2->Shutdown();
		delete m_Model_2;
		m_Model_2 = 0;
	}

	if (m_Model_3)
	{
		m_Model_3->Shutdown();
		delete m_Model_3;
		m_Model_3 = 0;
	}

	if (m_Model_4)
	{
		m_Model_4->Shutdown();
		delete m_Model_4;
		m_Model_4 = 0;
	}

	if (m_Model_5)
	{
		m_Model_5->Shutdown();
		delete m_Model_5;
		m_Model_5 = 0;
	}

	if (m_Model_6)
	{
		m_Model_6->Shutdown();
		delete m_Model_6;
		m_Model_6 = 0;
	}

	if (m_Model_7)
	{
		m_Model_7->Shutdown();
		delete m_Model_7;
		m_Model_7 = 0;
	}

	if (m_Model_8)
	{
		m_Model_8->Shutdown();
		delete m_Model_8;
		m_Model_8 = 0;
	}

	if (m_Model_9)
	{
		m_Model_9->Shutdown();
		delete m_Model_9;
		m_Model_9 = 0;
	}

	if (m_Model_10)
	{
		m_Model_10->Shutdown();
		delete m_Model_10;
		m_Model_10 = 0;
	}

	if (m_Model_11)
	{
		m_Model_11->Shutdown();
		delete m_Model_11;
		m_Model_11 = 0;
	}

	if (m_Model_12)
	{
		m_Model_12->Shutdown();
		delete m_Model_12;
		m_Model_12 = 0;
	}

	if (m_Model_13)
	{
		m_Model_13->Shutdown();
		delete m_Model_13;
		m_Model_13 = 0;
	}

	if (m_Model_14)
	{
		m_Model_14->Shutdown();
		delete m_Model_14;
		m_Model_14 = 0;
	}

	if (m_Model_15)
	{
		m_Model_15->Shutdown();
		delete m_Model_15;
		m_Model_15 = 0;
	}
	if (m_Model_16)
	{
		m_Model_16->Shutdown();
		delete m_Model_16;
		m_Model_16 = 0;
	}
	if (m_Model_17)
	{
		m_Model_17->Shutdown();
		delete m_Model_17;
		m_Model_17 = 0;
	}
	if (m_Model_18)
	{
		m_Model_18->Shutdown();
		delete m_Model_18;
		m_Model_18 = 0;
	}
	if (m_Model_19)
	{
		m_Model_19->Shutdown();
		delete m_Model_19;
		m_Model_19 = 0;
	}

	if (m_Model_1u)
	{
		m_Model_1u->Shutdown();
		delete m_Model_1u;
		m_Model_1u = 0;
	}

	if (m_Model_2u)
	{
		m_Model_2u->Shutdown();
		delete m_Model_2u;
		m_Model_2u = 0;
	}

	if (m_Model_3u)
	{
		m_Model_3u->Shutdown();
		delete m_Model_3u;
		m_Model_3u = 0;
	}

	if (m_Model_4u)
	{
		m_Model_4u->Shutdown();
		delete m_Model_4u;
		m_Model_4u = 0;
	}

	if (m_Model_5u)
	{
		m_Model_5u->Shutdown();
		delete m_Model_5u;
		m_Model_5u = 0;
	}

	if (m_Model_6u)
	{
		m_Model_6u->Shutdown();
		delete m_Model_6u;
		m_Model_6u = 0;
	}

	if (m_Model_7u)
	{
		m_Model_7u->Shutdown();
		delete m_Model_7u;
		m_Model_7u = 0;
	}

	if (m_Model_8u)
	{
		m_Model_8u->Shutdown();
		delete m_Model_8u;
		m_Model_8u = 0;
	}

	if (m_Model_9u)
	{
		m_Model_9u->Shutdown();
		delete m_Model_9u;
		m_Model_9u = 0;
	}

	if (m_Model_10u)
	{
		m_Model_10u->Shutdown();
		delete m_Model_10u;
		m_Model_10u = 0;
	}

	if (m_Model_11u)
	{
		m_Model_11u->Shutdown();
		delete m_Model_11u;
		m_Model_11u = 0;
	}

	if (m_Model_12u)
	{
		m_Model_12u->Shutdown();
		delete m_Model_12u;
		m_Model_12u = 0;
	}

	if (m_Model_13u)
	{
		m_Model_13u->Shutdown();
		delete m_Model_13u;
		m_Model_13u = 0;
	}

	if (m_Model_14u)
	{
		m_Model_14u->Shutdown();
		delete m_Model_14u;
		m_Model_14u = 0;
	}

	if (m_Model_15u)
	{
		m_Model_15u->Shutdown();
		delete m_Model_15u;
		m_Model_15u = 0;
	}
	if (m_Model_16u)
	{
		m_Model_16u->Shutdown();
		delete m_Model_16u;
		m_Model_16u = 0;
	}
	if (m_Model_17u)
	{
		m_Model_17u->Shutdown();
		delete m_Model_17u;
		m_Model_17u = 0;
	}
	if (m_Model_18u)
	{
		m_Model_18u->Shutdown();
		delete m_Model_18u;
		m_Model_18u = 0;
	}
	if (m_Model_19u)
	{
		m_Model_19u->Shutdown();
		delete m_Model_19u;
		m_Model_19u = 0;
	}
	if (m_Model_cable)
	{
		m_Model_cable->Shutdown();
		delete m_Model_cable;
		m_Model_cable = 0;
	}
	if (m_Model_water)
	{
		m_Model_water->Shutdown();
		delete m_Model_water;
		m_Model_water = 0;
	}

	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the D3D object.
	if(m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	// Release the light object.
	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}
	if (m_Light_1)
	{
		delete m_Light_1;
		m_Light_1 = 0;
	}
	if (m_Light_2)
	{
		delete m_Light_2;
		m_Light_2 = 0;
	}
	if (m_Light_3)
	{
		delete m_Light_3;
		m_Light_3 = 0;
	}
	if (m_Light_4)
	{
		delete m_Light_4;
		m_Light_4 = 0;
	}

	// Release the light shader object.
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}
	
	// Release the bitmap object.
	if (m_Bitmap)
	{
		m_Bitmap->Shutdown();
		delete m_Bitmap;
		m_Bitmap = 0;
	}

	// Release the texture shader object.
	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = 0;
	}

	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	static float rotation = 0.0f;


	// Update the rotation variable each frame.
	rotation += XM_PI * 0.005f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Render the graphics scene.
	result = Render(rotation);
	if(!result)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::Frame(int fps, int cpu)
{
	bool result;
	static float rotation = 0.0f;

	// Update the rotation variable each frame.
	rotation += (float)XM_PI * 0.005f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Set the frames per second.
	result = m_Text->SetFPS(fps, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the cpu usage.
	result = m_Text->SetCPU(cpu, m_D3D->GetDeviceContext());
	if (!result)
	{
		return false;
	}

	// Set the location of the mouse.
	

	// Render the graphics scene.
	result = Render(rotation);
	if (!result)
	{
		return false;
	}

	// Set the position of the camera.
//	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);

	return true;
}

bool GraphicsClass::Render(float rotation)
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix;
	bool result;
	
	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);

	m_D3D->GetOrthoMatrix(orthoMatrix);

	// Turn off the Z buffer to begin all 2D rendering.
	m_D3D->TurnZBufferOff();

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	result = m_Bitmap->Render(m_D3D->GetDeviceContext(), 200, 200);
	if (!result)
	{
		return false;
	}

	// Render the bitmap with the texture shader.
	result = m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Bitmap->GetIndexCount(), worldMatrix, viewMatrix, orthoMatrix, m_Bitmap->GetTexture());
	if (!result)
	{
		return false;
	}

	// Turn on the alpha blending before rendering the text.
	m_D3D->TurnOnAlphaBlending();

	// Render the text strings.
	result = m_Text->Render(m_D3D->GetDeviceContext(), worldMatrix, orthoMatrix);
	if (!result)
	{
		return false;
	}

	// Turn off alpha blending after rendering the text.
	m_D3D->TurnOffAlphaBlending();

	// Turn the Z buffer back on now that all 2D rendering has completed.
	m_D3D->TurnZBufferOn();

	// Rotate the world matrix by the rotation value so that the triangle will spin.
	//worldMatrix = XMMatrixRotationY(rotation);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model->GetIndexCount(), 
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model->GetTexture(), 
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_3->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_4->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_5->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_6->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_7->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_7->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_7->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_8->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_8->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_8->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_9->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_9->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_9->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_10->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_10->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_10->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_11->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_11->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_11->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_12->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_12->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_12->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_13->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_13->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_13->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_14->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_14->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_14->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_15->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_15->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_15->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_16->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_16->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_16->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_17->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_17->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_17->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_18->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_18->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_18->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_19->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_19->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_19->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_3u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3u->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_4u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4u->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_5u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_6u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_7u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_7u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_7u->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_8u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_8u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_8u->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_9u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_9u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_9u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_10u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_10u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_10u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_11u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_11u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_11u->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_12u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_12u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_12u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_13u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_13u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_13u->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_14u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_14u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_14u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_15u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_15u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_15u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_16u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_16u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_16u->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_17u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_17u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_17u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_18u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_18u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_18u->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_19u->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_19u->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_19u->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_cable->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_cable->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_cable->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_water->Render(m_D3D->GetDeviceContext());
	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_water->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_water->GetTexture(),
		m_Light_2->GetDirection(), m_Light_2->GetAmbientColor(), m_Light_2->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_2->GetSpecularColor(), m_Light_2->GetSpecularPower());
	
	if(!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}