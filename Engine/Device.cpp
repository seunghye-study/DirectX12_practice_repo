#include "pch.h"
#include "Device.h"

void Device::init()
{
	// D3D12 ������� Ȱ��ȭ
	// - VC++ ��� â�� ����� �޼��� ���
	// - riid : ����̽��� com id
	// - ppDevice : ������ ��ġ�� �Ű������� ����
	// - IID_PPV_ARGS : 
#ifdef _DEBUG
	::D3D12GetDebugInterface
	(IID_PPV_ARGS(&_debugController));
	_debugController->EnableDebugLayer();
#endif // _DEBUG
	// DXGI (���̷�ƮX Graphics Infrastructure)
	// - directx3d�� �Բ� ���̴� API
	// - ��üȭ�� ��� ��ȯ
	// - �����Ǵ� ���÷��� ��� ����
	// Create DXGI Factory
	// - riid : ����̽��� com id
	// - ppDevice : ������ ��ġ�� �Ű������� ����
	::CreateDXGIFactory(IID_PPV_ARGS(&_dxgi));

	// CreateDevice
	// - ���÷��� �����(�׷���ī��)�� ��Ÿ���� ��ü
	// - pAdaptor : nullptr �����ϸ� �ý��� �⺻ ���÷��� �����
	// - MinumumFeatureLevel : ���� ���Ϸ��� �䱸�ϴ� �ּ� ��� ����(���ڴٸ� �ɷ�����)
	// - riid : ����̽��� com id
	// - ppDevice : ������ ��ġ�� �Ű������� ����
	::D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&_device));
}
