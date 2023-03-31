#pragma once

//�η� �繫��
class Device
{
public:
	void init(); // �ʱ�ȭ �Լ�
	ComPtr<IDXGIFactory> GetDXGI() { return _dxgi; }
	ComPtr<ID3D12Device> GetDevice() { return _device; }
private:
	// COM : Component Object Model
	// DX�� ���α׷��� ��� �������� ���� ȣ�ϼ��� �����ϰ� �ϴ� ���
	// COM ��ü�� ���, ���λ����� Private
	// ComPtr : ������ ����Ʈ ������
	ComPtr<ID3D12Debug> _debugController;
	ComPtr<IDXGIFactory> _dxgi; // ȭ�� ���� ���
	ComPtr<ID3D12Device> _device; // ���� ��ü ����

};

