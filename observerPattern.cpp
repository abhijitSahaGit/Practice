#include <stdio.h>
#include<iostream>
#include<list>
#include<string>
using namespace std;

//Forward declaration
class Stock;//Stock is Observable Base-class, contains list of Observers

class ObserverInterface {
    public:
        virtual void updateObserver(Stock *stock)=0;//Stock is Observable Base-class
};

class Stock{
    private:
        double _price;
        list<ObserverInterface *> _investors;
        Stock();//Default constructor private
    public:
        Stock(double price) : _price(price) { }
        void attach(ObserverInterface *investor) {
            _investors.push_back(investor);
        }
        void detach(ObserverInterface *investor) {
            _investors.remove(investor);
        }
        
        void Notify() {
            list<ObserverInterface *>::iterator itr=_investors.begin();
            for(;itr!= _investors.end(); ++itr ) {
                (*itr)->updateObserver(this);
            }
        }
        
        double getPrice() {
            return _price;
        }
        
        void setPrice(double price) { //changeState, so Notify all Observers
            _price = price;
            Notify();
        }
};

// The 'ConcreteObservable' class
class Company : public Stock { // Stock is 'Observable' Base-class
private:
  string _name;
public:
  Company(string name, double price) : _name(name), Stock(price) {}
  string getName(void) { return _name; }
};

// The 'ConcreteObserver' class
class Investor : public ObserverInterface {
private:
  string _name;
  Investor(){}

public:
  Investor(string name) : _name(name){}
  void updateObserver(Stock* stock) // Stock is 'Observable' Base-class
  {
    cout<<"Notified Investor :"<<_name<<" about "<<(static_cast<Company*>(stock))->getName() << stock->getPrice()<<endl;
    //Company* 'ConcreteObservable' class; stock is not polymorphic, this is why dynamic_cast is not used
  }
};


int main()
{
  printf("Observer Pattern Demo");
  Company* c1 = new Company("Google", 123.0);   // 'ConcreteObservable' class
  cout<<"Created company Google with Stock Price 123.0\n"<<endl;

  Investor* i1 = new Investor("Billy"); // Investor is 'ConcreteObserver' class
  c1->attach(i1);
  cout<<"Created investor Billy following Google\n"<<endl;

     //change Observable State
  c1->setPrice(125.0); //will call notify() which inturn call updateObserver

  Investor* i2 = new Investor("Timmy");
  c1->attach(i2);
  Investor* i3 = new Investor("Lenny");
  c1->attach(i3);
  cout<<"\nCreated investor Timmy and Lenny following Google\n"<<endl;

  //change Observable State
  c1->setPrice(145.0);

  c1->detach(i1);
  c1->detach(i3);
  cout<<"\nInvestor Billy and Lenny not interested in Google anymore\n"<<endl;

  //change Observable State
  c1->setPrice(165.0);
  delete i1;
  delete i2;
  delete i3;
  delete c1;

    return 0;
}
