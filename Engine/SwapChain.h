#pragma once


// ��ȯ �罽 -> ���� ���۸�
// [���� ����]
// - ���� ���� ���� �ִ� ��Ȳ�� ����
// - � �������� ��� ������� ������
// - GPU�� ������ ���( ����)
// - ������� �޾Ƽ� ȭ�鿡 �׷��ش�


// [���� �����] �� ��� ����?
// - � ���̿�(BUFFER) �׷��� �ǳ��޶�� �ϱ�
// - Ư�� ���̸� ���� ó���� �ǳ��ְ� ������� �ش� ���̿� �޴´�
// - �츮 ȭ�鿡 Ư�� ����(�����)�� ����Ѵ�

// [������]
// - �׷��� ȭ�鿡 ���� ����� ����ϴ� ����, ���� ȭ�鵵 ���ָ� �ðܾ���
// - ���� ȭ�� ������� �̹� ȭ�� ��¿� �����
// - Ư�� ���̸� 2�� ���� �ϳ��� ���� ȭ���� �׸���, �ϳ��� ���� �ñ��
// - DOUBLE BUFFERING

// [ 1 ] ���� ȭ��
// [ 2 ] �׸��� �۾����� ȭ��

class SwapChain
{
public:
	void init(const windowInfo& info, ComPtr<IDXGIFactory> dxgi, ComPtr<ID3D12CommandQueue> cmdQueue);
private:
	ComPtr<IDXGISwapChain>		_swapChain;
	ComPtr<ID3D12Resource>		_renderTarget[SWAP_CHAIN_BUFFER_COUNT];
	uint32						_backBufferIndex = 0; // ���� ����۰� ����
};

