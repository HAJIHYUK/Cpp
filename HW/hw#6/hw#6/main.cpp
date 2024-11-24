#include <iostream>
#include <vector> 
using namespace std;

class Shape {
public:
    virtual void draw() = 0; 
    
};

class Line : public Shape {
public:
    void draw()  {
        cout << "Line" << endl;
    }
};

class Circle : public Shape {
public:
    void draw()  {
        cout << "Circle" << endl;
    }
};

class Rect : public Shape {
public:
    void draw()  {
        cout << "Rectangle" << endl;
    }
};

class GraphicEditor {
private:
    vector<Shape*> shapes; 

public:
    GraphicEditor() {}

    ~GraphicEditor() {
        
        for (Shape* shape : shapes) {
            delete shape;
        }
    }

    void insertShape(int shapeType) {
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
        shapes.push_back(shape); 
    }

    void showAllShapes() {
        if (shapes.empty()) {
            cout << "저장된 도형이 없습니다!" << endl;
            return;
        }
        for (size_t i = 0; i < shapes.size(); ++i) {
            cout << i  << ": ";
            shapes[i]->draw();
        }
    }

    void deleteShape(int index) {
        if (index < 1 || index > shapes.size()) {
            cout << "잘못된 인덱스입니다!" << endl;
            return;
        }
        delete shapes[index - 1]; 
        shapes.erase(shapes.begin() + (index - 1)); 
    }

    void exitEditor() {
        for (Shape* shape : shapes) {
            delete shape; 
        }
        shapes.clear();
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
            cout << "선:1, 원:2, 사각형:3 >> ";
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
