#include<bits/stdc++.h>
using namespace std;

class Car{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void stopEngine() = 0;
    
    virtual ~Car() {}
};

class SuperCar : public Car{
private :
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyre;

public:

    SuperCar(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        tyre = "MRF";
    }

    int getSpeed(){
        return currentSpeed;
    }

    void setTyre(string t){
        tyre = t;
    }

    string getTyre(){
        return tyre;
    }

    void startEngine(){
        isEngineOn = true;
        cout << brand << " " << model << " Engine Has Started." << endl;
    }

    void shiftGear(int gear){
        if(!isEngineOn){
            cout << "Engine is off, cannot shift any gear." << endl;
            return;
        }
        cout << "Gear shifted from " << currentGear << " to " << gear << endl;
        currentGear = gear;
    }

    void accelerate(){
        if(!isEngineOn){
            cout << "Engine is off, cannot accelerate";
            return;
        }
        currentSpeed += 20;
        cout << "Car speed accelerated to " << currentSpeed << endl;
    }
    
    void brake(){
        if(!isEngineOn){
            cout << "Engine is off, cannot brake";
            return;
        }
        currentSpeed -= 20;
        cout << "Car speed decreased to " << currentSpeed << endl;
    }

    void stopEngine(){
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " Engine turned off." << endl;
    }

    ~SuperCar() {}
};

int main(){
    Car* myCar = new SuperCar("Ford", "Mushtang");
    SuperCar* myCar = new SuperCar("Ford", "Mushtang");

    myCar->startEngine();
    // cout << myCar->getTyre() << endl;
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->shiftGear(2);
    myCar->accelerate();
    myCar->brake();
    // cout << "Current Speed is : " << myCar->getSpeed() << endl;
    // myCar->setTyre("Volks");
    

    delete myCar;
}