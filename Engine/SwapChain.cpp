#include "pch.h"
#include "SwapChain.h"

void SwapChain::init(const windowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue)
{
	_swapChain.Reset();

	DXGI_SWAP_CHAIN_DESC sd;
	dxgi->CreateSwapChain(cmdQueue.Get(), &sd, &_swapChain);
	for (int32 i = 0; i < SWAP_CHAIN_BUFFER_COUNT; i++) {
		_swapChain->GetBuffer(i, IID_PPV_ARGS(&_renderTarget[i]));
	}
}
