#include <stdio.h>
#include<iostream>
using namespace std;
            /* ====== Abstract Target & Source Classes ====== */
//AbstractTarget: The Interface compatible with Client
class AbstractTarget{
    public:
        virtual void RoundPin(){};
        virtual void PinCount()=0;
};

//AbstractSource: Existing Interface
class AbstractSource{
    public:
        virtual void FlatPin(){};
        virtual void PinCount()=0;
};


            /* ====== Concrete Target & Source Classes ====== */
//ConcreteTarget
class Target : public AbstractTarget {
public:
  void RoundPin() {
    cout << " I am Round Pin" << endl;
  }
  void PinCount() {
    cout << " I have two pins" << endl;
  }
};

//ConcreteSource
class Source : public AbstractSource {
public:
  void FlatPin() {
        cout << " Flat Pin" << endl;
  }
  void PinCount() {
        cout << " I have three pins" << endl;
  }
};

//Adapter derives Target and override the Target function defition by Source function defition
class Adapter: public AbstractTarget {
    public:
        AbstractSource *AS;
        
        //Constructor initializing the member Source Object
        Adapter(AbstractSource *S): AS(S) { }
        
        //RoundPin()of Adapter actually retuning FlatPin() of Source/Adaptee which is required by client
        void roundPin() {
            AS->FlatPin();
        }
        
        //Adapter returns Source version
        void PinCount() {
            AS->PinCount();
        }
};

// Client code
int main()
{
    cout << "Adapter Pattern Demo\n";
    Source *mySource = new Source; // Adaptee
    // Target = Adapter(Source)
    AbstractTarget *adapter = new Adapter(mySource);
    adapter->RoundPin();
    adapter->PinCount();

    return 0;
}