#include <iostream>
using namespace std;
#include "Ram.h"
Ram::Ram() {
	size = 100 * 1024;
}//`
Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}
char Ram::read(int address) {
	if (address < 0 || address >= size) {
		cout << "��ȿ���� ���� �ּ��Դϴ�."<<endl;
		return '0';
	}
	return mem[address];
	
}
void Ram::write(int address, char value) {
	if (address >= 0 && address < size) {	
		mem[address] = value;
	}
	else {
		cout << "��ȿ���� ���� �� �Դϴ�." << endl;
	}

}