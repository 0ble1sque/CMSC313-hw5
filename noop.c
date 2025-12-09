//NOOP - Not Object-Oriented Programming
#include <stdio.h>
#include <stdlib.h>

void accelerate(void* vehicle);
void brake(void* vehicle);
void startEngine();

struct Vehicle{
    void (*accelerate)(void* vehicle);  //pointer for func displaying acceleration
    void (*brake)(void* vehicle);       //pointer for func displaying decceleration
};

struct Car{
    struct Vehicle frame;   //Car struct holds a Vehicle struct, mimicking polymorphism
};

//func displaying acceleration
void gas(void* vehicle){
    printf("Car: Pressing gas pedal...\n");
}

//func displaying decceleration
void deccelerate(void* vehicle){
    printf("Car: Applying brakes...\n");
}

//func displaying start of engine
//not included in a struct
void startEngine(){
    printf("Engine started!\n");
}

int main(){
    //allocates memory for Car struct
    struct Car* myCar = (struct Car*)malloc(sizeof(struct Car));

    //accelerate points to gas func
    myCar->frame.accelerate = gas;
    //brake points to deccelerate func
    myCar->frame.brake = deccelerate;

    //displays engine start
    startEngine();
    //displays acceleration
    myCar->frame.accelerate(myCar);
    //displays decceleration
    myCar->frame.brake(myCar);

    //frees memory from Car struct
    free(myCar);

    return 0;
}