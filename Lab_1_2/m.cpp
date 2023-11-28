#include "m.h"

using namespace std;

std::wstring m::encrypt(const std::wstring& open_text) // ����������
{
	wstring tabl = open_text;
	int dlina, kolichestvo, index, x;
	dlina = open_text.length(); // ��������� �����
	kolichestvo = (dlina - 1) / kluch + 1; // ���������� ��������
	x = 0;
	for (int i = kluch; i > 0; i--) { // �������
		for (int j = 0; j < kolichestvo; j++) { // ������
			index = i+kluch*j;
			if (index-1 < dlina) {
				tabl[x] = open_text[index-1];
				x++;
			}
		}
	}
	return tabl;
}

std::wstring m::decrypt(const std::wstring& cipher_text) // �������������
{
	wstring tabl = cipher_text;
	int dlina, kolichestvo, index, x;
	dlina = cipher_text.length();
	kolichestvo = (dlina - 1) / kluch + 1; // ���������� ��������
	x = 0;
	for (int i = kluch; i > 0; i--) { // �������
		for (int j = 0; j < kolichestvo; j++) { // ������
			index = i+kluch*j;
			if (index-1 < dlina) {
				tabl[index-1] = cipher_text[x];
				x++;
			}
		}
	}
	return tabl;
}
