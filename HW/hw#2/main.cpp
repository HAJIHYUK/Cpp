#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player {
public:
    int score[3];
    string name;

    Player() { // 생성자.
        for (int i = 0; i < 3; i++) {
            score[i] = 0;
        }
    }

    void makeScore() {
        for (int i = 0; i < 3; i++) {
            score[i] = rand() % 3; // 0, 1, 2 랜덤 정수 생성
        }
    }
};

class GamblingGame {
public:
    Player players[2]; // 선수 배열
    string input;

    GamblingGame() { // 생성자
    }

    void play() {
     
        cout << "첫번째 선수 이름>>";
        cin >> players[0].name;
        cout << "두번째 선수 이름>>";
        cin >> players[1].name;

        cin.ignore(); // 버퍼에 남아 있는 개행 문자 제거

        while (true) {
            for (int i = 0; i < 2; i++) {
                players[i].makeScore();
                while (true) {
                    cout << players[i].name << ": <Enter>" << endl;
                    getline(cin, input);

                    if (input.empty()) { //<Enter>값 체크
                        cout << players[i].name << "의 점수: " << players[i].score[0] << " " << players[i].score[1] << " " << players[i].score[2] << endl;

                        if (players[i].score[0] == players[i].score[1] && players[i].score[1] == players[i].score[2]) {
                            cout << players[i].name << "님이 승리!!" << endl;
                            return; // 3개 동일 숫자일경우 종료
                        }
                        else {
                            cout << "아쉽군요!" << endl;
                            break; // 3개 동일숫자 아닐경우 다음 선수로
                        }
                    }
                    else {
                        cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
                        continue; // 빈값 아닐시 다시반복
                    }
                }
            }
        }
    }
};


int main() {
    srand(static_cast<unsigned int>(time(0))); // 랜덤 시드 초기화
    GamblingGame game;

    cout << "**** 갬블링 게임을 시작합니다. ****" << endl;
    game.play();

    return 0; 
}
