ModelInfo_t* pModel = new ModelInfo_t;

	D3DXMATRIX matrix, m1;
	D3DXVECTOR4 position;
	D3DXVECTOR4 input;
	Device->GetViewport(&g_ViewPort);
	Device->GetVertexShaderConstantF(0, matrix, 4); //many games use 0

	input.y = (float)aimheight;

	D3DXMatrixTranspose(&matrix, &matrix);
	D3DXVec4Transform(&position, &input, &matrix);
	//or this (depends on the game)
	//D3DXMatrixTranspose(&m1, &matrix);
	//D3DXVec4Transform(&position, &input, &m1);

	position.x = input.x * matrix._11 + input.y * matrix._21 + input.z * matrix._31 + matrix._41;
	position.y = input.x * matrix._12 + input.y * matrix._22 + input.z * matrix._32 + matrix._42;
	position.z = input.x * matrix._13 + input.y * matrix._23 + input.z * matrix._33 + matrix._43;
	position.w = input.x * matrix._14 + input.y * matrix._24 + input.z * matrix._34 + matrix._44;

	pModel->Position2D.x = ((position.x / position.w) * (g_ViewPort.Width / 12)) + g_ViewPort.X + (g_ViewPort.Width / 12);
	pModel->Position2D.y = g_ViewPort.Y + (g_ViewPort.Height / 2) - ((position.y / position.w) * (g_ViewPort.Height / 2));

	ModelInfo.push_back(pModel);