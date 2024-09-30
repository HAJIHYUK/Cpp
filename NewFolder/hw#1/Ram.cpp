#include <iostream>
using namespace std;
#include "Ram.h"
Ram::Ram() {
	size = 100 * 1024;
}//`
Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address) {
	if (address < 0 || address >= size) {
		cout << "유효하지 않은 주소입니다."<<endl;
		return '0';
	}
	return mem[address];
	
}
void Ram::write(int address, char value) {
	if (address >= 0 && address < size) {	
		mem[address] = value;
	}
	else {
		cout << "유효하지 않은 값 입니다." << endl;
	}

}