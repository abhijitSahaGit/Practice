#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;

enum ShapeType {
    ST_Circle=1,
    ST_Square=2,
    ST_Rectangle=3  
};

// Abstract Creator or Base Class
class Shape {
    public:
        static Shape* Create(ShapeType shape_choice);
        // factory method, Create should be static, bcoz we will call it without object
        
        virtual void Draw() = 0;
        //pure virtual method, which has different behavior in different sub-class
};

class Circle: public Shape {
    void Draw() {
        cout << "I am a Circle\n";
    }  
};

class Square: public Shape {
    void Draw() {
        cout << "I am a Square\n";
    }  
};

class Rectangle: public Shape {
    void Draw() {
        cout << "I am a Rectangle\n";
    }  
};

//Factory Method: Change is required only in this function to create a new object type
Shape* Shape::Create(ShapeType shape_choice) {
    if(shape_choice == ST_Circle) {
        return new Circle;
    }
    else if(shape_choice == ST_Square) {
        return new Square;
    }
    else if (shape_choice == ST_Rectangle) {
        return new Rectangle;
    }
    else {
        return NULL;
    }
}
int main()
{
    cout << "FactoryPattern Demo\n";
    vector<Shape*> shapesFactory; //Use Factory Interface
    ShapeType myShape;
    int choice;
    
    while(true) {
        cout << "circle(1), square(2), Rectangle(3), Exit(0)\nEnter choice: ";
        cin >> choice;
        myShape = (ShapeType)choice;//explicit int to enum conversion is required
        if(choice == 0) {
            break;
        }
        else {
        //calling factory method from user's code, Create should be static, becoz we will call it without object
            shapesFactory.push_back(Shape::Create(myShape));
        }
    }

    for(int i=0; i < shapesFactory.size(); ++i) {
        shapesFactory[i]->Draw();   
    }
    for(int i=0; i < shapesFactory.size(); ++i) {
        delete shapesFactory[i];//Avoid memory leak
    }
    return 0;
}

/*
Advantage: Without factory, need to change client side code while introducing a new type
    if (choice == 5)
      ptr = new Rhoumbus;
*/