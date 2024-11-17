#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; 
};

class Line : public Shape {
public:
    void draw() {
        cout << "Line" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Circle" << endl;
    }
};

class Rect : public Shape {
public:
    void draw() {
        cout << "Rectangle" << endl;
    }
};

class GraphicEditor {
private:
    Shape* shapes[100]; 
    int shapeCount;     

public:
    GraphicEditor() : shapeCount(0) {} 

    void insertShape(int shapeType) {
        if (shapeCount >= 100) {
            cout << "�� �̻� ������ �߰��� �� �����ϴ�!" << endl;
            return;
        }
        Shape* shape;
        switch (shapeType) {
        case 1:
            shape = new Line();
            break;
        case 2:
            shape = new Circle();
            break;
        case 3:
            shape = new Rect();
            break;
        default:
            cout << "�߸��� �Է��Դϴ�!" << endl;
            return;
        }
        shapes[shapeCount++] = shape; 
        
    }

    
    void showAllShapes() {
        if (shapeCount == 0) {
            cout << "����� ������ �����ϴ�!" << endl;
            return;
        }
        for (int i = 0; i < shapeCount; ++i) {
            cout << i + 1 << ": ";
            shapes[i]->draw();
        }
    }

    
    void deleteShape(int index) {
        if (index < 1 || index > shapeCount) {
            cout << "�߸��� �ε����Դϴ�!" << endl;
            return;
        }
        delete shapes[index - 1];

        
        for (int i = index; i < shapeCount; ++i) {
            shapes[i - 1] = shapes[i];
        }
        shapeCount--;
        
    }

  
    void exitEditor() {
        for (int i = 0; i < shapeCount; ++i) {
            delete shapes[i]; 
        }
        shapeCount = 0;
        cout << "�����մϴ�." << endl;
    }
};

int main() {
    GraphicEditor editor;
    int choice; 

    cout << "�׷��� �������Դϴ�." << endl;
    while (true) {
        cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int shapeType;
            cout << "1: Line, 2: Circle, 3: Rectangle >> ";
            cin >> shapeType;
            editor.insertShape(shapeType);
            break;
        }
        case 2: {
            int index;
            cout << "������ ������ �ε��� >> ";
            cin >> index;
            editor.deleteShape(index);
            break;
        }
        case 3:
            editor.showAllShapes();
            break;
        case 4:
            editor.exitEditor();
            return 0;
        default:
            cout << "�߸��� �����Դϴ�!" << endl;
            break;
        }
    }
}