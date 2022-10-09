#include <iostream>

using namespace std;

class Vehicle {
  public:
    float fuelUsed;
    string fuelType;
    string invalidInput = "Please select either gasoline or diesel. \n";
    float co2Produced() {
      if (fuelType == "gasoline"){
        return fuelUsed * 2.3;
      }
      else if (fuelType == "diesel"){
        return fuelUsed * 2.7;
      }
    }
    void userInstructions(){
      if (co2Produced() >= 50){
        cout<<"Try to be more eco-friendly next time";
      }
      else {
        cout<<"You are doing great at being eco-friendly!";
      }
    }
};

int main(){
    Vehicle car;
    int valRead = 0;
    car.fuelUsed = 1;
    cout<<"How much fuel did your vehicle use during your trip (In Liters!): ";
    valRead = scanf("%f", &car.fuelUsed);
    while (valRead != 1){
        cout<<"Please enter a valid Number. "<<"\n";
        scanf("%*[^\n]");
        cout<<"How much fuel did your vehicle use during your trip (In Liters!): ";
        valRead = scanf("%f", &car.fuelUsed);
    }
    while(true) {
        cout<<"What type of fuel does your vehicle use (gasoline or diesel): ";
        cin>>car.fuelType;
        if(car.fuelType == "gasoline" || car.fuelType == "diesel"){
            break;
        }
        cout<<car.invalidInput;
    }
    cout<<"Your vehicle released "<<car.co2Produced()<<"kg of CO2"<<"\n";
    car.userInstructions();
}
