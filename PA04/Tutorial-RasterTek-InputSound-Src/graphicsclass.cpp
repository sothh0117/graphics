////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;

	m_Model_mount = 0;
	m_Model_1 = 0;
	m_Model_2 = 0;
	m_Model_3 = 0;
	m_Model_4 = 0;
	m_Model_5 = 0;
	m_Model_6 = 0;
	m_Model_cable = 0;
	m_Model_water = 0;
	m_Model_back = 0;
	

	m_LightShader = 0;
	m_Light = 0;
	m_Light_1 = 0;
	m_Light_2 = 0;
	m_Light_3 = 0;
	m_Light_4 = 0;
	m_Light_5 = 0;

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
	m_Model_mount = new ModelClass;
	if(!m_Model_mount)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_mount->Initialize(m_D3D->GetDevice(), L"./data/mount.obj", L"./data/grass.dds");
	if(!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_mount object.", L"Error", MB_OK);
		return false;
	}

	m_Model_1 = new ModelClass;
	if (!m_Model_1)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model_1->Initialize(m_D3D->GetDevice(), L"./data/tree1_up.obj", L"./data/leaf.dds");
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
	result = m_Model_2->Initialize(m_D3D->GetDevice(), L"./data/tree1_down.obj", L"./data/wood.dds");
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
	result = m_Model_3->Initialize(m_D3D->GetDevice(), L"./data/tree2_up.obj", L"./data/leaves.dds");
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
	result = m_Model_4->Initialize(m_D3D->GetDevice(), L"./data/tree2_down.obj", L"./data/tree.dds");
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
	result = m_Model_5->Initialize(m_D3D->GetDevice(), L"./data/tree3_up.obj", L"./data/leaves.dds");
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
	result = m_Model_6->Initialize(m_D3D->GetDevice(), L"./data/tree3_down.obj", L"./data/wood.dds");
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_6 object.", L"Error", MB_OK);
		return false;
	}

	m_Model_cable = new ModelClass;
	if (!m_Model_cable)
	{
		return false;
	}
	result = m_Model_cable->Initialize(m_D3D->GetDevice(), L"./data/cable.obj", L"./data/cable.dds"); // ÄÉÀÌºíÄ«·Î ¹Ù²ã¾ß´ï
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

	m_Model_back = new ModelClass;
	if (!m_Model_back)
	{
		return false;
	}
	result = m_Model_back->Initialize(m_D3D->GetDevice(), L"./data/background.obj", L"./data/sky.dds"); // ÅØ½ºÃÄ ÇÏ´Ã·Î
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the model_back object.", L"Error", MB_OK);
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

	m_Light_5 = new LightClass;
	if (!m_Light_4)
	{
		return false;
	}

	// Initialize the light object.
	m_Light_5->SetAmbientColor(0.5f, 0.5f, 0.5f, 1.0f);
	m_Light_5->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_5->SetDirection(1.0f, 0.0f, 0.0f);
	m_Light_5->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light_5->SetSpecularPower(32.0f);

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
	result = m_Bitmap->Initialize(m_D3D->GetDevice(), screenWidth, screenHeight, L"./data/bit.dds", 512, 512);
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
	if(m_Model_mount)
	{
		m_Model_mount->Shutdown();
		delete m_Model_mount;
		m_Model_mount = 0;
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

	if (m_Model_back)
	{
		m_Model_back->Shutdown();
		delete m_Model_back;
		m_Model_back = 0;
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
	if (m_Light_5)
	{
		delete m_Light_5;
		m_Light_5 = 0;
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
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix, orthoMatrix, translateMatrix;
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
	/*if (isZbuffer) {
		m_D3D->TurnZBufferOff();
	}
	else m_D3D->TurnZBufferOn();*/
	m_D3D->TurnZBufferOn();
	

	// Put the bitmap vertex and index buffers on the graphics pipeline to prepare them for drawing.
	if (!isZbuffer)
	{
		result = m_Bitmap->Render(m_D3D->GetDeviceContext(), 100, 100);
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
	m_Model_mount->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_mount->GetIndexCount(), 
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_mount->GetTexture(), 
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_back->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(0.0f, 0.0f, 45.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_back->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_back->GetTexture(),
		m_Light_5->GetDirection(), m_Light_5->GetAmbientColor(), m_Light_5->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_5->GetSpecularColor(), m_Light_5->GetSpecularPower());

	m_Model_water->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-6.5f, 4.2f, -51.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_water->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_water->GetTexture(),
		m_Light_2->GetDirection(), m_Light_2->GetAmbientColor(), m_Light_2->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_2->GetSpecularColor(), m_Light_2->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(30.5f, -4.2f, -2.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-16.0f, 0.0f, 47.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-28.0f, 0.0f, -69.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(0.0f, 8.3f, 52.5f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(20.0f, 4.2f, -22.5f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(17.9f, -3.0f, -19.8f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_1->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-2.9f, -4.5f, -13.2f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_1->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_1->GetTexture(),
		m_Light_1->GetDirection(), m_Light_1->GetAmbientColor(), m_Light_1->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_1->GetSpecularColor(), m_Light_1->GetSpecularPower());

	m_Model_2->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_2->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());


	m_Model_3->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-29.0f, 6.0f, 29.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_4->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_3->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(25.0f, 5.0f, 7.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_4->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_3->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(14.2f, -15.0f, 27.7f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_4->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_3->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-13.6f, 7.5f, -8.1f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_4->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_3->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-30.6f, -1.0f, -20.6f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_4->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_3->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(16.0f, 0.2f, 15.4f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_3->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_3->GetTexture(),
		m_Light_4->GetDirection(), m_Light_4->GetAmbientColor(), m_Light_4->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_4->GetSpecularColor(), m_Light_4->GetSpecularPower());

	m_Model_4->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_4->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());



	m_Model_5->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(9.0f, 8.8f, -34.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_6->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_5->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-23.0f, -7.0f, 31.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_6->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_5->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-4.0f, -4.0f, -20.6f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_6->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_5->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(13.3f, 6.2f, 19.2f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_6->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_5->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(24.4f, 0.3f, 1.1f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_6->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	m_Model_5->Render(m_D3D->GetDeviceContext());

	translateMatrix = XMMatrixTranslation(-24.2f, -4.0f, -38.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_5->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_5->GetTexture(),
		m_Light_3->GetDirection(), m_Light_3->GetAmbientColor(), m_Light_3->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light_3->GetSpecularColor(), m_Light_3->GetSpecularPower());

	m_Model_6->Render(m_D3D->GetDeviceContext());

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_6->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());

	

	m_Model_cable->Render(m_D3D->GetDeviceContext());

	worldMatrix = XMMatrixRotationY(rotation);
	translateMatrix = XMMatrixTranslation(-25.0f, 19.3f, -28.0f);
	worldMatrix = XMMatrixMultiply(worldMatrix, translateMatrix);

	result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model_cable->GetIndexCount(),
		worldMatrix, viewMatrix, projectionMatrix,
		m_Model_cable->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
	

	//worldMatrix = XMMatrixRotationY(rotation);
	

	if(!result)
	{
		return false;
	}

	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}