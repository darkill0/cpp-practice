#include <iostream>
#define SPACE ' '
using namespace std;

void printArea(char area[3][3]){
	for (int i=0; i<3; i++){
		cout<<area[i][0]<<"|"<<area[i][1]<<"|"<<area[i][2]<<endl;
	}
}

void moveFirstGamer(char area[3][3]){
	int x,y;
	cout<<"Ход крестиков"<<endl;
	cout<<"Номер строки с нуля до 2: "; cin>>x;
	cout<<"Номер столбца с нуля до 2: "; cin>>y;
	if (x<0 || y<0 || x>2 || y>2 || area[x][y]!=SPACE){
		cout<<"Неправильный номер строки или столбца"<<endl;
		moveFirstGamer(area);
	}
	else{
		area[x][y] = 'X';
	}
}

void moveTwelweGamer(char area[3][3]){
	int x,y;
	cout<<"Ход ноликов"<<endl;
	cout<<"Номер строки с нуля до 2: "; cin>>x;
	cout<<"\nНомер столбца с нуля до 2: "; cin>>y;
	if (x<0 || y<0 || x>2 || y>2 || area[x][y]!=SPACE){
		cout<<"Неправильный номер строки или столбца"<<endl;
		moveTwelweGamer(area);
	}
	else{
		area[x][y] = 'O';
	}
}

char cheackGame(char area[3][3]){
	char p;
	int col = 0;
	for (int t=0; t<3; t++){
		p = area[t][0];
		if (p==area[t][1] && area[t][1]==area[t][2] && area[t][1]!=SPACE){
			return area[t][1];
		}

	}
	for (int t=0; t<3; t++){
		
		if (area[0][t]==area[1][t] && area[1][t]==area[2][t] && area[1][t]!=SPACE ){
			return area[1][t];
		}
	}
	for (int i=0; i<3;i++){
		for(int j=0;j<3;j++){
			if (area[i][j]!=SPACE) col++;
		}
	}
	if (col==9) return 'p';

	if (area[0][0]==area[1][1] && area[1][1]==area[2][2]) return area[1][1];
	if (area[0][2]==area[1][1] && area[1][1]==area[2][0]) return area[1][1];
	return SPACE;


}


int state(char area[3][3]){
	char done = cheackGame(area);
	if (done != SPACE){
		if(done=='X') cout<<"Выйграл первый игрок"<<endl;
		else if (done=='O')cout<<"Выйграл второй игрок"<<endl;
		else cout<<"Ничья"<<endl;
		return 1;
	}
	return 0;
}


int main(){
	int done;
	char area[3][3] = {SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE};
	while(true)
	{
		printArea(area);
		moveFirstGamer(area);
		printArea(area);
		if (state(area)==1){
			break;
		}


		moveTwelweGamer(area);
		printArea(area); 
		if (state(area)==1){
			break;
		}
		system("clear");

	}
}
