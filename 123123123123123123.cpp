#include <iostream>
#include <cstring>  
#include <Windows.h>

struct Point
{
    int x;
    int y;
};

struct Student {
    char name[80];
    int age = 0;
};

struct Triangle
{
    Point a;
    Point b;
    Point c;
};

struct Piramide
{
    Triangle mainSide;
    double height;
};

void Show(const Piramide& piramide) {
    std::cout << "Height=" << piramide.height << std::endl;
    std::cout << "Main Side A: [" << piramide.mainSide.a.x << "," << piramide.mainSide.a.y << "]" << std::endl;
    std::cout << "Main Side B: [" << piramide.mainSide.b.x << "," << piramide.mainSide.b.y << "]" << std::endl;
    std::cout << "Main Side C: [" << piramide.mainSide.c.x << "," << piramide.mainSide.c.y << "]" << std::endl;
}

void Set(Piramide& piramide) {
    piramide.height = 10.0;
    piramide.mainSide = { {0, 0}, {1, 0}, {0, 1} };
}

void Show(const Piramide piramide[], int size) {
    for (int i = 0; i < size; ++i) {
        Show(piramide[i]);
    }
}

void Set(Piramide piramide[], int size) {
    for (int i = 0; i < size; ++i) {
        Set(piramide[i]);
    }
}

int main() {
	char name[80] = "dGdfg";
	Student demien{ "Demien", 23};
  
    Student copyDemien(demien);

    Point point1{ 10, 20 };
    Point* ptr = &point1;
    std::cout << "x = " << point1.x << std::endl;
    std::cout << "y = " << point1.y << std::endl;

    std::cout << "x = " << (*ptr).x << std::endl;
    std::cout << "y = " << (*ptr).y << std::endl;

    std::cout << "x = " << ptr->x << std::endl;
    std::cout << "y = " << ptr->y << std::endl;

    const int SIZE = 3;

    Point arr[SIZE] =
    {
        Point{ 10, 20 },
        Point{ 30, 40 },
        Point{ 50, 60 }
    };

    Point* pointers[SIZE] =
    {
        &arr[0],
        &arr[1],
        &arr[2],
    };
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Struct #" << i + 1 << ": [" << pointers[i]->x << "," << pointers[i]->y << "]\n";
    }

    Piramide piramide{};
    Set(piramide);
    Show(piramide);

    return 0;
}
