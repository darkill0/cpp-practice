#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>

using namespace  std;
const int size_map = 5;
class Ship{
public:

	Ship(int size, int dir);
	void getDamage();
public:
	int size_ship;
	int ship_dir;
	bool alive;	

};
Ship::Ship(int size, int dir){
	size_ship = size;
	ship_dir = dir;
	alive = true;
}

void printArea(int size_map, int (*map)[5] );
bool setShip(Ship ship, int (*map)[5], int size_map, int x, int y);
bool checkSetShip(int size_ship, int ship_dir, int x, int y);

int main(){
	int x,y,ship_s,ship_d;
	int map[size_map][size_map] = {0};
	Ship s1(2, 2);
	Ship ship_count[5] = {s1,s1,s1,s1,s1};
	// setShip(s1, map, size_map);
	// printArea(size_map, map);
	// while(true){
	// 	cout<<"Введи x"; cin>>x;
	// 	cout<<"Введи y"; cin>>y;
	// 	setShip(s1,map,size_map,x,y);
	// 	printArea(size_map, map);
	// }
	for (int i=0; i<5;i++){
		printArea(size_map, map);
		cout<<"Введи количество палуб: "; cin >>ship_s;
		cout<<"Введи x "; cin >>x;
		cout<<"Введи y "; cin >>y;
		cout<<"Введи направление корабля от начало точки(0-вниз, 1-вверх, 2-вверх, 3-влево): "; cin >>ship_d;
		ship_count[i] = Ship(ship_s, ship_d);

		setShip(ship_count[i],map,size_map,x,y);


	}
	for (int i=0; i<5;i++){
		cout<<ship_count[i].size_ship<<endl;
	}

}

void printArea(int size_map, int (*map)[5]){
	for (int i=0; i<size_map; i++){
		for(int j=0; j<size_map;j++){
			if(map[i][j]==1){
				cout<<1;
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
			else  return true;
			break;

		case 1:
			if (size_ship==size_map-y || size_ship<=size_map-y) return false;
			else  return true;
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

bool setShip(Ship ship, int (*map)[5], int size_map, int x, int y){

	bool flag = checkSetShip(ship.size_ship, ship.ship_dir,x,y);

	if (map[x][y]==1 || x<0 || y<0 || x>=size_map || y>=size_map||flag==false){
		cout<<"Неправильные координаты"<<endl;
		return false;
	}
	else{
		for(int i=0; i < ship.size_ship; i++){	
			switch (ship.ship_dir){
				case 0:
					map[x][y] = 1;
					x++;
					break;
				case 1:
					map[x][y] = 1;
					y++;
					break;
				case 2:
					map[x][y] = 1;
					x--;
					break;
				case 3:
					map[x][y] = 1;
					y--;
					break;
			}
		}

	}
	return true;
}
