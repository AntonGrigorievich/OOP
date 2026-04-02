#include <iostream>

using namespace std;

class Line {
    public:
    int x1, y1, x2, y2;
    void display() {
        printf("x1: %d; y1: %d; x2: %d; y2: %d \n", x1, y2, x2, y2);
    }
    Line() {
        printf("---Конструктор Line без операторов\n");
        x1 = 0;
        y1 = 0;
        x2 = 0;
        y2 = 0;
    }
    Line(int x1, int y1, int x2, int y2) {
        printf("---Конструктор Line с операторами\n");
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    Line(const Line &l) {
        printf("---Конструктор Line копирования\n");
        this->x1 = l.x1+1;
        this->y1 = l.y1;
        this->x2 = l.x2;
        this->y2 = l.y2;
    }
    virtual ~Line(){
        display();
        printf("~~~Деструктор Line\n\n");
    }
    void move(int dx1, int dy1, int dx2, int dy2);
};

void Line::move(int dx1, int dy1, int dx2, int dy2) {
    this->x1+=dx1;
    this->y1+=dy1;
    this->x2+=dx2;
    this->y2+=dy2;
};

class BrokenLine: public Line {
    protected:
        int crack_x, crack_y;
    public:
    void display() {
        printf("Ломано в %d %d\n ", crack_x, crack_y);
    }
    BrokenLine() : Line() {
        printf("------Конструктор BrokenLine без операторов\n");
        crack_x = 0;
        crack_y = 0;
    }
    BrokenLine(int x1, int y1, int x2, int y2, int crack_x, int crack_y) : Line(x1, y1, x2, y2) {
        printf("------Конструктор BrokenLine с операторами\n");
        this->crack_x = crack_x;
        this->crack_y = crack_y;
    }
    BrokenLine(const BrokenLine &l) {
        printf("------Конструктор BrokenLine копирования\n");
        this->x1 = l.x1+1;
        this->y1 = l.y1;
        this->x2 = l.x2;
        this->y2 = l.y2;
        this->crack_x = l.crack_x;
        this->crack_y = l.crack_y;
    }
    ~BrokenLine(){
        display();
        printf("~~~~~~Деструктор BrokenLine\n\n");
    }
};

class Shape {
    public:
    Line l1, l2;
    void display() {
        l1.display();
        l2.display();
    }
    Shape() {
        printf("---------Конструктор Shape без операторов\n");
    }
    Shape(Line *l1, Line *l2) {
        printf("---------Конструктор Shape с операторами\n");
        this->l1 = *l1;
        this->l2 = *l2;
    }
    Shape(const Shape &s) {
        printf("---------Конструктор Shape копирования\n");
        l1 = *new Line(s.l1);
        l2 = *new Line(s.l2);
    }
    virtual ~Shape(){
        // delete l1;
        // delete l2;
        printf("~~~~~~~~~Деструктор Shape\n\n");
    }
};

int main() {

}