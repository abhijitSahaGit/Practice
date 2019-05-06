#include <stdio.h>
#include<iostream>
using namespace std;
class SingleTon {
    private:
        SingleTon() {}
        SingleTon(const SingleTon&) {}  
        SingleTon& operator=(const SingleTon&) {}
        
        static SingleTon* SingleTonInstance;
        // note static, static func can only access static member variables
        //static because this instance will be shared by all objects, we can not make it non-static
    public:
        static SingleTon* getInstance();
};

SingleTon* SingleTon::SingleTonInstance=NULL;
//Definition must be outside of class for static-member, Don't mention static in definition, mention return-type

SingleTon* SingleTon::getInstance() {
    if(SingleTonInstance == NULL) {
        SingleTonInstance = new SingleTon();// or  new SingleTon;
        cout << "SingleTon object created\n";
    }
    return SingleTonInstance;
}

int main()
{
    cout << "SingleTon Demo\n";
    SingleTon *inst1 = SingleTon::getInstance();
    SingleTon *inst2 = SingleTon::getInstance();
    cout << "inst1=" << inst1 << ", inst2=" << inst2 << endl;
    return 0;
}

/*
SingleTon Demo                                                                                                                 
SingleTon object created                                                                                                       
inst1=0xa17c20, inst2=0xa17c20
*/