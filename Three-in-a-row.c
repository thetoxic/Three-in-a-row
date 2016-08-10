//Three in a row

/*
				Coded by ecomaikgolf
					iecomaikgolf@gmail.com
						@ecomaikgolf
																	*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void loop(char c[3][3]);
void Play_First (char c[3][3]);
void Play_Me(char c[3][3]);
void Play_IA (char[3][3]);
int winner(char c[3][3]);
int main(){

	char c [3][3];
	loop (c); //Call all elemental functions and refresh the screen

	system("pause");
	return 0;
}

void loop(char c[3][3]){
	int i,j;

	i = 0;

	Play_First(c);
	board(c);

	do{
		system("cls");
		board(c);

		if(i % 2 == 0){
			Play_Me(c);
		}else{
			Play_IA(c);
		}
		j = winner(c);
		i++;

	}while(i<=9 && j == 2);
	system("cls");
	board(c);

	if(j == 0){
		printf("Congrats!! You win!\n\n");
	}
	else{
	if (j == 1){
		printf("Oh no!You lose!!\n\n");
	}
	else{
		printf("Draw! Try again!!");
	}

}
}

void Play_First (char c[3][3]){//Give valors to matrix
	int i,j;
	char aux;

	aux = '1';

	for (i = 2 ; i>=0 ; i--){
		for(j = 0 ; j<3 ; j++){
			c[i][j] = aux++;
		}
	}
}

void Play_Me(char c[3][3]){
	int i,j,k;
	char aux;

	do{
		do{
			printf("Make a move: ");
			aux = _getche();
			printf("\n");
		}while(aux < '1' || aux > '9');
		k = 0;
		switch(aux){
			case '1': {
				i = 2;
				j = 0;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '2': {
				i = 2;
				j = 1;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '3': {
				i = 2;
				j = 2;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '4': {
				i = 1;
				j = 0;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '5': {
				i = 1;
				j = 1;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '6': {
				i = 1;
				j = 2;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '7': {
				i = 0;
				j = 0;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '8': {
				i = 0;
				j = 1;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
			case '9': {
				i = 0;
				j = 2;
				if(c[i][j] == '#' || c [i][j] == '*'){
					k = 1;
					printf("Occupied, try another number!!\n\n");
				}
				break;
			}
		}
	}while(k == 1);

	c[i][j] = '#';
}

void Play_IA (char c[3][3]){
	int i, j, k;
	char aux;

	srand(time(NULL));

	do{
		i = rand()%3;
		j = rand()%3;
		k = 0;

		if(c [i][j] == '#' || c[i][j] == '*'){
			k = 1;
		}
	}while(k == 1);

	c[i][j] = '*';



}

void board (char c[3][3]){
	int i,j;

	for(i = 0;i<3;i++){
		for(j = 0;j<3;j++){
			if( j <2){
				printf(" %c |",c[i][j]);
			}
			else{
				printf(" %c ",c[i][j]);
			}
		}
		if ( i < 2){
			printf("\n-----------\n");
		}

	}
	printf("\n\n");
}

int winner(char c[3][3]){
	if(c[0][0] == '#' || c[0][0] == '*'){
		if(c[0][0] == c[0][1] && c[0][0] == c[0][2]){
			if (c[0][0] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
		if (c[0][0] == c[1][0] && c[0][0] == c[2][0]){
			if(c[0][0] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
	}
	if(c[1][1] == '#' || c[1][1] == '*'){
		if(c[1][1] == c[0][0] && c[1][1] == c[2][2]){
			if (c[1][1] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
		if (c[1][1] == c[1][0] && c[1][1] == c[1][2]){
			if (c[1][1] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
		if (c[1][1] == c[2][0] && c[1][1] == c[0][2]){
			if (c[1][1] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
		if (c[1][1] == c[0][1] && c[1][1] == c[2][1]){
			if (c[1][1] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
	}
	if(c[2][2] == '#' || c[2][2] == '*'){
		if(c[2][2] == c[2][0] && c[2][2] == c[2][1]){
			if (c[2][2] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
		if(c[2][2] == c[0][2] && c[2][2] == c[1][2]){
			if (c[2][2] == '#'){
				return 0; //Win
			}
			else{
				return 1; //Lose
			}
		}
	}
	return 2; //Draw
}
