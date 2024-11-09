#include <iostream>
#include <string>
using namespace std;

// �������� �⺻ Ŭ����
class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount)
: model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {}

    void print(int pages) {
        if (pages <= availableCount) {
            printedCount += pages;
            availableCount -= pages;
            cout << model << " " << manufacturer << ", ���� ���� " << availableCount << "��" << endl;
        }
        else {
            cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }
};

// ��ũ�� ������ Ŭ����
class InkjetPrinter : public Printer {
private:
    int availableInk;

public:
    InkjetPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    void print(int pages) {
        if (pages <= availableCount && pages <= availableInk) {
            printedCount += pages;
            availableCount -= pages;
            availableInk -= pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
        else {
            cout << "���� �Ǵ� ��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }

    void printInkJet() {
        cout << model << " " << manufacturer << ", ���� ���� " << availableCount << "��, ���� ��ũ " << availableInk << endl;
    }
};

// ������ ������ Ŭ����
class LaserPrinter : public Printer {
private:
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    void print(int pages) {
        if (pages <= availableCount && pages <= availableToner) {
            printedCount += pages;
            availableCount -= pages;
            availableToner -= pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
         
        }
        else {
            cout << "���� �Ǵ� ��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }

    void printLaser() {
        cout << model << " " << manufacturer << ", ���� ���� " << availableCount << "��, ���� ��� " << availableToner << endl;
    }
};

int main() {
    InkjetPrinter* inkjet = new InkjetPrinter("Officejet V40", "HP", 5, 10);
    LaserPrinter* laser = new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20);

    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
    inkjet->printInkJet();
    laser->printLaser();
    cout << "\n";

    int choice, pages;
    while (true) {
        cout << "������(1: ��ũ��, 2: ������)�� �ż� �Է�>> ";
        cin >> choice >> pages;

        if (choice == 1) {
            inkjet->print(pages);
            inkjet->printInkJet();
            laser->printLaser();
            
            
        }
        }
        else if (choice == 2) {
            laser->print(pages);
            inkjet->printInkJet();
            laser->printLaser();
            cout << endl;
        }
        else {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���." << endl;
            continue;
        }

        char cont;
        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>> ";
        cin >> cont;
        if (cont == 'n' || cont == 'N') {
            break;
        }
        cout << endl;
    }

    delete inkjet;
    delete laser;

    return 0;
}
