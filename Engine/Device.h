#pragma once

//인력 사무소
class Device
{
public:
	void init(); // 초기화 함수
	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }
private:
	// COM : Component Object Model
	// DX의 프로그래밍 언어 독립성과 하위 호완성을 가능하게 하는 기술
	// COM 객체를 사용, 세부사항은 Private
	// ComPtr : 일종의 스마트 포인터
	ComPtr<ID3D12Debug> _debugController;
	ComPtr<IDXGIFactory> _dxgi; // 화면 관련 기능
	ComPtr<ID3D12Device> _device; // 각종 객체 생성

};

