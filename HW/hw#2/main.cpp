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
    Player player1;
    Player player2;
    string input;

    GamblingGame() { // 생성자
    }

    void play() {
        cout << "첫 번째 선수 이름>> ";
        cin >> player1.name;
        cout << "두 번째 선수 이름>> ";
        cin >> player2.name;

        // cin.ignore()를 사용하여 버퍼에 남아 있는 개행 문자 제거
        cin.ignore();

        while (true) {
            // 첫 번째 선수의 점수 생성 및 입력 처리
            player1.makeScore();
            while (true) {
                cout << player1.name << ": <Enter>" << endl;
                getline(cin, input);

                if (input.empty()) { //<Enter>값 체크 , 빈값 아닐 시 다시 반복
                    cout << player1.name << "의 점수: " << player1.score[0]<<" " << player1.score[1] <<" " << player1.score[2] << endl;
                        

                    if (player1.score[0] == player1.score[1] && player1.score[1] == player1.score[2]) {
                        cout << player1.name << "님이 승리!!" << endl;
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

            // 두 번째 선수의 점수 생성 및 입력 처리
            player2.makeScore();
            while (true) {
                cout << player2.name << ": <Enter>" << endl;
                getline(cin, input);

                if (input.empty()) { //<Enter>값 체크 , 빈값 아닐 시 다시 반복
                    cout << player2.name << "의 점수: " << player2.score[0] << " " << player2.score[1] << " " << player2.score[2] << endl;

                    if (player2.score[0] == player2.score[1] && player2.score[1] == player2.score[2]) {
                        cout << player2.name << "님이 승리!!" << endl;
                        return; // 3개 동일 숫자일경우 종료
                    }
                    else {
                        cout << "아쉽군요!" << endl;
                        break;  // 3개 동일숫자 아닐경우 다음 선수로
                    }
                }
                else {
                    cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
                    continue; // 빈값 아닐시 다시반복
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
