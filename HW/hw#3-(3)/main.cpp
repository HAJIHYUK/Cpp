#include <iostream>
using namespace std;

class Dept {
    int size; // scores 배열의 크기
    int* scores; // 동적 할당 받을 정수 배열의 주소
public:
    Dept(int size) { // 생성자
        this->size = size;
        scores = new int[size];
    }

    ~Dept() { // 소멸자
        delete[] scores;
    }

    int getSize() const { return size; } // const 추가

    void read() {
        cout << "10개점수입력:";
        for (int i = 0; i < size; i++) {
            cin >> scores[i];
        }
    } // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장

    bool isOver60(int index) const { // const 추가
        return scores[index] > 60;
    } // index의 학생 성적이 60보다 크면 True 리턴
};

int countPass(const Dept& dept) { // dept 학과에 60점 이상으로 통과하는 학생의 수 리턴
    int count = 0;
    for (int i = 0; i < dept.getSize(); i++) {
        if (dept.isOver60(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    Dept com(10); // 총 10명이 있는 학과 com
    com.read(); // 총 10명의 학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
    int n = countPass(com); // com 학과에 60점 이상으로 통과한 학생의 수를 리턴
    cout << "60점 이상은 " << n << "명";
}
