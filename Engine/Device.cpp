#include "pch.h"
#include "Device.h"

void Device::init()
{
	// D3D12 디버그층 활성화
	// - VC++ 출력 창에 디버깅 메세지 출력
	// - riid : 디바이스의 com id
	// - ppDevice : 생성된 장치가 매개변수에 설정
	// - IID_PPV_ARGS : 
#ifdef _DEBUG
	::D3D12GetDebugInterface
	(IID_PPV_ARGS(&_debugController));
	_debugController->EnableDebugLayer();
#endif // _DEBUG
	// DXGI (다이렉트X Graphics Infrastructure)
	// - directx3d와 함께 쓰이는 API
	// - 전체화면 모드 전환
	// - 지원되는 디스플레이 모드 열거
	// Create DXGI Factory
	// - riid : 디바이스의 com id
	// - ppDevice : 생성된 장치가 매개변수에 설정
	::CreateDXGIFactory(IID_PPV_ARGS(&_dxgi));

	// CreateDevice
	// - 디스플레이 어댑터(그래픽카드)를 나타내는 객체
	// - pAdaptor : nullptr 지정하면 시스템 기본 디스플레이 어댑터
	// - MinumumFeatureLevel : 응용 프록램이 요구하는 최소 기능 수준(구닥다리 걸러내기)
	// - riid : 디바이스의 com id
	// - ppDevice : 생성된 장치가 매개변수에 설정
	::D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&_device));
}
