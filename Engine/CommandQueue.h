#pragma once

class SwapChain;
class DescriptorHeap;


class CommandQueue
{
public:
	~CommandQueue();
	//�ʱ�ȭ
	void init(ComPtr<ID3D12Device> device, shared_ptr<SwapChain> swapChain, shared_ptr<DescriptorHeap> descHeap);
	//����ȭ
	void WaitSync();

	void RenderBegin(const D3D12_VIEWPORT* vp, const D3D12_RECT* rect);
	void RenderEnd();
	ComPtr<ID3D12CommandQueue> GetCmdQueue() { return _cmdQueue; }
private:
	//command queue : dx12�� ����
	//-���ָ� ��û�� ��, �ϳ��� ��û�ϸ� ��ȿ����
	//-���� ��Ͽ� �ϰ��� �������� ����ߴٰ� �ѹ��� ��û
	ComPtr<ID3D12CommandQueue>			_cmdQueue;
	ComPtr<ID3D12CommandAllocator>		_cmdAlloc;
	ComPtr<ID3D12GraphicsCommandList>	_cmdList;

	//Fence : ��Ÿ��
	//CPU/GPU ����ȭ�� ���� ����
	ComPtr<ID3D12Fence>			_fence;
	uint32						_fenceValue;
	HANDLE						_fenceEvent = INVALID_HANDLE_VALUE;
	shared_ptr<SwapChain>			_swapChain;
	shared_ptr<DescriptorHeap>	_descHeap;
};

