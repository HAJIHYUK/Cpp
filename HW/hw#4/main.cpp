#include <iostream>
#include <string>
using namespace std;

// 프린터의 기본 클래스
class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount) : model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {}

    void print(int pages) {
        if (pages <= availableCount) {
            printedCount += pages;
            availableCount -= pages;
            cout << model << " " << manufacturer << ", 남은 종이 " << availableCount << "장" << endl;
        }
        else {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
        }
    }

   
};

// 잉크젯 프린터 클래스
class InkjetPrinter : public Printer {
private:
    int availableInk;

public:
    InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk) : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    void print(int pages) {
        if (pages <= availableCount && pages <= availableInk) {
            printedCount += pages;
            availableCount -= pages;
            availableInk -= pages;
            cout << model << " " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk << endl;
        }
        else {
            cout << "용지 또는 잉크가 부족하여 프린트할 수 없습니다." << endl;
        }
    }

    void show() {
        cout << model << " " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk << endl;
    }
};

// 레이저 프린터 클래스
class LaserPrinter : public Printer {
private:
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner) : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    void print(int pages) {
        if (pages <= availableCount && pages <= availableToner) {
            printedCount += pages;
            availableCount -= pages;
            availableToner -= pages;
            cout << model << " " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 토너 " << availableToner << endl;
        }
        else {
            cout << "용지 또는 토너가 부족하여 프린트할 수 없습니다." << endl;
        }
    }

    void show() {
        cout << model << " " << manufacturer << ", 남은 종이 " << availableCount << "장, 남은 토너 " << availableToner << endl;
    }
};

int main() {
    InkjetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    inkjet.show();
    laser.show();
    cout << "\n";

    int choice, pages;
    while (true) {
        cout << "프린터(1: 잉크젯, 2: 레이저)와 매수 입력>> ";
        cin >> choice >> pages;

        if (choice == 1) {
            inkjet.print(pages);
        }
        else if (choice == 2) {
            laser.print(pages);
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
            continue;
        }

        char cont;
        cout << "계속 프린트 하시겠습니까(y/n)>> ";
        cin >> cont;
        if (cont == 'n' || cont == 'N') break;
    }

    return 0;
}
