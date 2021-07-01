#include"function.h"
Animal::Animal(Zoo* zoo,string name){
	belong=zoo;
	species=name;
	zoo->born(name);
}
Dog::Dog(Zoo* zoo) : Animal::Animal(zoo,"Dog") {

}
Dog::~Dog(){
	//do nothing
}
Cat::Cat(Zoo* zoo) : Animal::Animal(zoo,"Cat") {

}
Cat::~Cat(){
	//do nothing
}
Caog::Caog(Zoo* zoo) : Dog::Dog(zoo),Cat::Cat(zoo),Animal::Animal(zoo,"Caog") {

}
void Caog::barking(){
	cout<<"woof!woof!meow!\n";
}
void Caog::carton(){
	Cat::carton();
}
void Caog::throwBall(){
	Dog::throwBall();
}
Caog::~Caog(){
	//do nothing
}
