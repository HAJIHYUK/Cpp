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
            cout << "더 이상 도형을 추가할 수 없습니다!" << endl;
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
            cout << "잘못된 입력입니다!" << endl;
            return;
        }
        shapes[shapeCount++] = shape; 
        
    }

    
    void showAllShapes() {
        if (shapeCount == 0) {
            cout << "저장된 도형이 없습니다!" << endl;
            return;
        }
        for (int i = 0; i < shapeCount; ++i) {
            cout << i + 1 << ": ";
            shapes[i]->draw();
        }
    }

    
    void deleteShape(int index) {
        if (index < 1 || index > shapeCount) {
            cout << "잘못된 인덱스입니다!" << endl;
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
        cout << "종료합니다." << endl;
    }
};

int main() {
    GraphicEditor editor;
    int choice; 

    cout << "그래픽 에디터입니다." << endl;
    while (true) {
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
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
            cout << "삭제할 도형의 인덱스 >> ";
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
            cout << "잘못된 선택입니다!" << endl;
            break;
        }
    }
}
