#include <iostream>


struct newperson{
    char name[20];
    int age;
};

int main(){
    newperson bucky = {
        "Bucky",
        21
    };

    newperson hoss = {
        "Hoss Jones",
        45
    };

    std::cout <<"name : " << bucky.name << " and age : " << bucky.age << std::endl; 
    std::cout <<"name : " << hoss.name << " and age : " << hoss.age << std::endl; 

    return 0;
}