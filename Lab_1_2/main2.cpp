#include <iostream>
#include <cctype>
#include "m.h"
#include <locale>
using namespace std;
bool isValid(const string& s)
{
	for(auto c:s)
		if (!iswalpha(c) || !iswupper(c))
			return false;
	return true;
}

int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	bool isTrue = true;
	wcout << L"����� ���������� � ��������� ��� ����������." << endl;
	int key;
	wstring text;
	wstring action;
	wcout<<L"������� ����: ";
	wcin>>key;
	if (!wcin.good()) {
		wcerr<< L"���� ��������!\n";
		return 1;
	}

	m cipher(key);
	do {
		wcin>>action;
		wcout<<L"������� �������� (exit, encrypt, decrypt): ";
		if (action != L"encrypt" && action != L"decrypt" && action != L"exit") {
			wcout << L"������� ����� ������������������ ��������, ����� ����������.\n";
			wcin >> action;
		}

		if (action == L"encrypt") {
			wcout << L"������� ������:"<<endl;
			wcin>> text;
			wcout << L"������������� ������:"<<cipher.encrypt(text)<<endl;
		}
		if (action == L"decrypt") {
			wcout << L"������� ������:"<<endl;
			wcin>> text;
			wcout << L"�������������� ������:"<<cipher.decrypt(text)<<endl;
		}
		if (action == L"exit") {
			wcout << L"��������� ��������� ������." << endl;
			isTrue = false;
			break;
		}


	} while (isTrue != false);
	return 0;
}
