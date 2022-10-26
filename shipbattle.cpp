#include <iostream>
#include <stdio.h>

using namespace  std;
const int size_map = 10;

class Ship{
public:

	Ship(int size, int dir);

	void getDamage();
	int operator - (int d){
		return this->size_ship-d;
	}


public:
	int size_ship;
	int ship_dir;
	bool alive;
	int data[size_map][size_map];	

};
Ship::Ship(int size, int dir){
	size_ship = size;
	ship_dir = dir;
	alive = true;

}
void Ship::getDamage(){
	this->size_ship -=1;
	if (this->size_ship==0){

	this->alive = false;
	}
}



void printArea(int size_map, int (*map)[10] );
bool setShip(Ship* ship, int (*map)[10], int size_map, int x, int y);
bool checkSetShip(int size_ship, int ship_dir, int x, int y);
int attackShip(Ship* ship_count[10] ,int (*map)[10], int x, int y);

int main(){
	int x,y,ship_s,ship_d;
	int wrecked_ships = 0; 
	int map[size_map][size_map] = {0};

	Ship* ship_count[10];
	for(int i=0; i<4;i++){
		printArea(size_map, map);
		cout<<"Одно-палобный корабль"<<endl;
		cout<<"Введи x "; cin >>x;
		cout<<"Введи y "; cin >>y;
		cout<<"Введи направление корабля от начало точки(0-вниз, 1-вправо, 2-вверх, 3-влево): "; cin >>ship_d;
		Ship* s1 = new Ship(1, ship_d);
		setShip(s1,map,size_map,x,y);
		ship_count[i] = s1;

	}
	for(int i=4; i<7;i++){
		printArea(size_map, map);
		cout<<"Двух-палобный корабль"<<endl;
		cout<<"Введи x "; cin >>x;
		cout<<"Введи y "; cin >>y;
		cout<<"Введи направление корабля от начало точки(0-вниз, 1-вправо, 2-вверх, 3-влево): "; cin >>ship_d;
		Ship* s1 = new Ship(2, ship_d);
		setShip(s1,map,size_map,x,y);
		ship_count[i] = s1;

	}
	for(int i=7; i<9;i++){
		printArea(size_map, map);
		cout<<"Трех-палобный корабль"<<endl;
		cout<<"Введи x "; cin >>x;
		cout<<"Введи y "; cin >>y;
		cout<<"Введи направление корабля от начало точки(0-вниз, 1-вправо, 2-вверх, 3-влево): "; cin >>ship_d;
		Ship* s1 = new Ship(3, ship_d);
		setShip(s1,map,size_map,x,y);
		ship_count[i] = s1;

	}
	for(int i=9; i<10;i++){
		printArea(size_map, map);
		cout<<"Четырех-палобный корабль"<<endl;
		cout<<"Введи x "; cin >>x;
		cout<<"Введи y "; cin >>y;
		cout<<"Введи направление корабля от начало точки(0-вниз, 1-вправо, 2-вверх, 3-влево): "; cin >>ship_d;
		Ship* s1 = new Ship(4, ship_d);
		setShip(s1,map,size_map,x,y);
		ship_count[i] = s1;

	}
	printArea(size_map, map);

	system("clear");
	while(true){
		printArea(size_map, map);
		cout<<"Введи x "; cin >>x;
		cout<<"Введи y "; cin >>y;
		int k = attackShip(ship_count,map,x,y);
		if(k!=-1){
			if (ship_count[k]->alive==false){
				wrecked_ships++;
				cout<<wrecked_ships<<endl;
				
			}
			}
		if(wrecked_ships==10){
			cout<<"You win";
			break;
		}
		}


}






void printArea(int size_map, int (*map)[10]){
	for (int i=0; i<size_map; i++){
		for(int j=0; j<size_map;j++){
			if(map[i][j]==1){
				cout<<1;
			}
			else if(map[i][j]==2){
				cout<<"X";
			}
			else{
				cout<<"-";
			}
		}
		cout<<endl;
	}
}

bool checkSetShip(int size_ship, int ship_dir, int x, int y){

	switch (ship_dir){
		case 0:
			if (size_ship==size_map-x || size_ship<=size_map-x) return true;
			else  return false;
			break;

		case 1:
			if (size_ship==size_map-y || size_ship<=size_map-y) return true;
			else  return false;
			break;

		case 2:
			if (size_ship-1==x || size_ship<=x) return true;
			else  return false;
			break;

		case 3:
			if (size_ship-1==y || size_ship<=y) return true;
			else  return false;
			break;
		default:
			return false;
			break;

	}
}

bool setShip(Ship* ship, int (*map)[10], int size_map, int x, int y){

	bool flag = checkSetShip(ship->size_ship, ship->ship_dir,x,y);

	if (map[x][y]==1 || x<0 || y<0 || x>=size_map || y>=size_map||flag==false){
		cout<<"Неправильные координаты"<<endl;
		return false;
	}
	else{
		for(int i=0; i < ship->size_ship; i++){	
			switch (ship->ship_dir){
				case 0:
					map[x][y] = 1;
					ship->data[x][y] = 1;
					x++;
					break;
				case 1:
					map[x][y] = 1;
  					ship->data[x][y] = 1;
					y++;
					break;
				case 2:
					map[x][y] = 1;
					ship->data[x][y] = 1;
					x--;
					break;
				case 3:
					map[x][y] = 1;
					ship->data[x][y] = 1;
					y--;
					break;
			}
		}

	}
	return true;
}

int attackShip(Ship* ship_count[10] ,int (*map)[10], int x, int y){
	for(int i=0; i<10; i++){
		if(ship_count[i]->data[x][y]==1){
			ship_count[i]->getDamage();
			map[x][y]=2;
			return i;
		}
		else{
			map[x][y] = 3;
		}
	}
	return -1;
}
