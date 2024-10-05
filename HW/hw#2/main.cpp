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
    Player player1;
    Player player2;
    string input;

    GamblingGame() { // ������
    }

    void play() {
        cout << "ù ��° ���� �̸�>> ";
        cin >> player1.name;
        cout << "�� ��° ���� �̸�>> ";
        cin >> player2.name;

        // cin.ignore()�� ����Ͽ� ���ۿ� ���� �ִ� ���� ���� ����
        cin.ignore();

        while (true) {
            // ù ��° ������ ���� ���� �� �Է� ó��
            player1.makeScore();
            while (true) {
                cout << player1.name << ": <Enter>" << endl;
                getline(cin, input);

                if (input.empty()) { //<Enter>�� üũ , �� �ƴ� �� �ٽ� �ݺ�
                    cout << player1.name << "�� ����: " << player1.score[0]<<" " << player1.score[1] <<" " << player1.score[2] << endl;
                        

                    if (player1.score[0] == player1.score[1] && player1.score[1] == player1.score[2]) {
                        cout << player1.name << "���� �¸�!!" << endl;
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

            // �� ��° ������ ���� ���� �� �Է� ó��
            player2.makeScore();
            while (true) {
                cout << player2.name << ": <Enter>" << endl;
                getline(cin, input);

                if (input.empty()) { //<Enter>�� üũ , �� �ƴ� �� �ٽ� �ݺ�
                    cout << player2.name << "�� ����: " << player2.score[0] << " " << player2.score[1] << " " << player2.score[2] << endl;

                    if (player2.score[0] == player2.score[1] && player2.score[1] == player2.score[2]) {
                        cout << player2.name << "���� �¸�!!" << endl;
                        return; // 3�� ���� �����ϰ�� ����
                    }
                    else {
                        cout << "�ƽ�����!" << endl;
                        break;  // 3�� ���ϼ��� �ƴҰ�� ���� ������
                    }
                }
                else {
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
                    continue; // �� �ƴҽ� �ٽùݺ�
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
