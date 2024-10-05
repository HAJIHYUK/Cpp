#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class Player {
public:
    int score[3];
    string name;

    Player() { // ������.
        for (int i = 0; i < 3; i++) {
            score[i] = 0;
        }
    }

    void makeScore() {
        for (int i = 0; i < 3; i++) {
            score[i] = rand() % 3; // 0, 1, 2 ���� ���� ����
        }
    }
};

class GamblingGame {
public:
    Player players[2]; // ���� �迭
    string input;

    GamblingGame() { // ������
    }

    void play() {
     
        cout << "ù��° ���� �̸�>>";
        cin >> players[0].name;
        cout << "�ι�° ���� �̸�>>";
        cin >> players[1].name;

        cin.ignore(); // ���ۿ� ���� �ִ� ���� ���� ����

        while (true) {
            for (int i = 0; i < 2; i++) {
                players[i].makeScore();
                while (true) {
                    cout << players[i].name << ": <Enter>" << endl;
                    getline(cin, input);

                    if (input.empty()) { //<Enter>�� üũ
                        cout << players[i].name << "�� ����: " << players[i].score[0] << " " << players[i].score[1] << " " << players[i].score[2] << endl;

                        if (players[i].score[0] == players[i].score[1] && players[i].score[1] == players[i].score[2]) {
                            cout << players[i].name << "���� �¸�!!" << endl;
                            return; // 3�� ���� �����ϰ�� ����
                        }
                        else {
                            cout << "�ƽ�����!" << endl;
                            break; // 3�� ���ϼ��� �ƴҰ�� ���� ������
                        }
                    }
                    else {
                        cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
                        continue; // �� �ƴҽ� �ٽùݺ�
                    }
                }
            }
        }
    }
};


int main() {
    srand(static_cast<unsigned int>(time(0))); // ���� �õ� �ʱ�ȭ
    GamblingGame game;

    cout << "**** ���� ������ �����մϴ�. ****" << endl;
    game.play();

    return 0; 
}
