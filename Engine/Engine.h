#pragma once

class Engine
{
public:
	void init(const windowInfo& window);
	void Render();
	void ResizeWindow(int32 width, int32 height);
private:
	windowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	shared_ptr<class Device> _device;
	shared_ptr<class CommandQueue> _cmdQueue;
	shared_ptr<class SwapChain> _swapChain;
	shared_ptr<class DescriptorHeap> _descHeap;
};

