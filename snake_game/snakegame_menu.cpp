#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

int gameover;
char move;
int score;
int y=28,x=28;
int yplayer=14,xplayer=14;
int ytail[100], xtail[100];
int ntail=1;
int yfood=8,xfood=8;
char player='^';
char tail='*';
char food='@';


//void foodspawn(){
//	start1:
//			yfood=rand()%27;
//			if(xfood==0||xfood==x-1||yfood==0||yfood==y-1){
//				goto start1;
//			}
//	start2:
//			xfood=rand()%27;
//			if(xfood==0||xfood==x-1||yfood==0||yfood==y-1){
//				goto start2;
//			}
//}

void generate_map(){
	system("cls");
	char map[y][x];
	
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
//			if(i==0 || j==0 || j==x-1 || i==y-1){
//				map[i][j]='*';
//			}else{
//				map[i][j]=' ';
//			}
			if(i==0 || i==y-1){
				map[i][j]='-';
			}else if(j==0 || j==x-1){
				map[i][j]='|';
			}else{
				map[i][j]=' ';
			}
		}
	}
	
	map[yplayer][xplayer]=player;
	map[yfood][xfood]=food;
	
	for(int i=0; i<=ntail; i++){
		map[ytail[i]][xtail[i]]=tail;
	}
	
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	
	printf("Press (w|a|s|d) to move ");
	printf("and press (p) to exit game");
	printf("\nScore: %d", score);
}

void movements(){
	move=getch();
	switch(move){
		case 'w':{
			ytail[0]=yplayer;
			xtail[0]=xplayer;
			player='^';
			yplayer--;
//			ytail--;
			break;
		}case 'a':{
			ytail[0]=yplayer;
			xtail[0]=xplayer;
			player='<';
			xplayer--;
//			xtail--;
			break;
		}case 's':{
			ytail[0]=yplayer;
			xtail[0]=xplayer;
			player='v';
			yplayer++;
//			ytail--;
			break;
		}case 'd':{
			ytail[0]=yplayer;
			xtail[0]=xplayer;
			player='>';
			xplayer++;
//			xtail--;
			break;
		}
	}
	for(int i=100; i>0; i--){
		ytail[i]=ytail[i-1];
		xtail[i]=xtail[i-1];
	}
//	for(int i=100; i>0; i--){
//		if(ytail[i]==yplayer||xtail[i]==xplayer){
//			move='p';
//		}
//	}

	if(xplayer==0||xplayer==x-1||yplayer==0||yplayer==y-1){
		move='p';
	}
}

//void gameplay(){
//	while(1){
//		generate_map();
//		movements();
//	}
//}

void menu(){
	int charname[100];
	char name[100];
	int choose;
	
	printf("Enter player's name: ");
	scanf("%[^\n]", &name);getchar();
	printf("Welcome to The Game \"%s\"\n\n", name);
	printf("Press enter to continue");
	getchar();
	
	while(choose!=3){
		//biar rapih
		system("cls");
		
		printf("1. Start The Game\n");
		printf("2. Game Info\n");
		printf("3. Exit\n");
		printf(">> ");
		scanf("%d", &choose);getchar();
		
		if(choose==1){
			system("cls");
			printf("Let's play %s...\nI wish you a fun journey!\n", name);
			printf("\nName your character:\n");
			scanf("%[^\n]", &charname);getchar();
			
			system("cls");
			printf("%s has named his/her character as \"%s\"", name, charname);
			printf("\n\nPress enter to continue");
			getchar();
			
			yplayer=14,xplayer=14;
			move=' ';
			player='^';
			ytail[0]=yplayer+1;
			xtail[0]=xplayer;
			yfood=8,xfood=8;
			score=0;
			ntail=1;
			while(move!='p'){
				if(yfood==yplayer&&xfood==xplayer){
					time_t t;
					srand((unsigned) time(&t));
					label1:
					yfood=(rand()%26)+1;
					if(yfood==y||yfood==0){
						goto label1;
					}
					label2:
					xfood=(rand()%26)+1;
					if(xfood==x||xfood==0){
						goto label2;
					}
					ntail++;
					score++;
				}
				
				generate_map();
				movements();
				
			}
		}
		if(choose==2){
			system("cls");
			
			printf("Movements Guide:\n");
			printf("w --> Go up\n");
			printf("a --> Go down\n");
			printf("s --> Go left\n");
			printf("d --> Go right\n");
			printf("\nAnother Guide:\n");
			printf("p --> Stop the game\n");
			printf("\nPress enter to go back");
			getchar();
		}
	}
}

int main(){
	menu();
	
	return 0;
}
