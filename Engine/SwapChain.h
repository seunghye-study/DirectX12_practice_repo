#pragma once


// 교환 사슬 -> 더블 버퍼링
// [외주 과정]
// - 현재 게임 세상에 있는 상황을 묘사
// - 어떤 공식으로 어떻게 계산할지 던져줌
// - GPU가 열심히 계산( 외주)
// - 결과물을 받아서 화면에 그려준다


// [외주 결과물] 을 어디에 받지?
// - 어떤 종이에(BUFFER) 그려서 건내달라고 하기
// - 특수 종이를 만들어서 처음에 건내주고 결과물을 해당 종이에 받는다
// - 우리 화면에 특수 종이(결과물)을 출력한다

// [프레임]
// - 그런데 화면에 현재 결과를 출력하는 와중, 다음 화면도 외주를 맡겨야함
// - 현재 화면 결과물은 이미 화면 출력에 사용중
// - 특수 종이를 2개 만들어서 하나는 현재 화면을 그리고, 하나는 외주 맡기기
// - DOUBLE BUFFERING

// [ 1 ] 현재 화면
// [ 2 ] 그리는 작업중인 화면

class SwapChain
{
public:
	void init(const windowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
private:
	ComPtr<IDXGISwapChain>		_swapChain;
	ComPtr<ID3D12Resource>		_renderTarget[SWAP_CHAIN_BUFFER_COUNT];
	uint32						_backBufferIndex = 0; // 현재 백버퍼가 뭔지
};

