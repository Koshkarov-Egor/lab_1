#pragma once
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cctype>
#include <locale>
#include <codecvt>
class m
{
private:
	int kluch; // ���-�� ��������
public:
	m()=delete; // ������ ������������ ��� ����������
	m(const int& key) :kluch(key) {};
	std::wstring encrypt(const std::wstring& open_text); // ������������
	std::wstring decrypt(const std::wstring& cipher_text); // �������������
};
