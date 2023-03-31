#include "pch.h"
#include "Engine.h"
#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "DescriptorHeap.h"

void Engine::init(const windowInfo& info)
{
	_window = info;
	ResizeWindow(info.width, info.height);
	//�׷��� ȭ�� ũ�⸦ ����
	_viewport = { 0,0,static_cast<FLOAT>(info.width),static_cast<FLOAT>(info.height), 0.0f, 1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, info.width, info.height);
	
	_device = make_shared<Device>();
	_cmdQueue = make_shared<CommandQueue>();
	_swapChain = make_shared<SwapChain>();
	_descHeap = make_shared<DescriptorHeap>();

	_device->init();
	_cmdQueue->init(_device->GetDevice(), _swapChain, _descHeap);
}

void Engine::Render()
{

}

void Engine::ResizeWindow(int32 width, int32 height)
{
	_window.width = width;
	_window.height = height;

	// �۷ι� ���ӽ����̽�(��������) : ǥ�� ���̺귯������ �����ϴ� ������ ���� �Լ�
	RECT rect = { 0,0, width, height };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(_window.hwnd, 0, 100, 100, width, height, 0);
}
