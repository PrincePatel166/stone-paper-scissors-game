#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int genraterandomenumber(int n){
	srand(time(NULL));
	return rand()%n;
}
int greater(char char1,char char2){
	if(char1==char2){
		return -1;
	}
	else if(char1=='r'&& char2=='s'){
		return 1;
	}
	else if(char2=='r'&& char1=='s'){
		return 0;
	}
	else if(char1=='r'&& char2=='p'){
		return 0;
	}
	else if(char2=='r'&& char1=='p'){
		return 1;
	}
	else if(char1=='p'&& char2=='s'){
		return 0;
	}
	else if(char2=='p'&& char1=='s'){
		return 1;
	}
}
int main(){
	int playerscore=0,i,compscore=0,temp;
	char playerchar ,compchar;
	char dict[]={'r','p','s'};
	printf("welcome to the game rock paper scissors\n");
	for(i=0;i<3;i++){
		//taking player input
		printf("players turn\n");
		printf("choose\n 1. for rock\n 2. for paper\n 3. for scissors\n");
		scanf("%d",&temp);
		playerchar=dict[temp-1];
		printf("player select char %c\n",playerchar);
		
		//taking computer input
		printf("computers turn\n");
		printf("choose 1 for rock\n 2 for paper\n 3 for scissors\n");
		temp=genraterandomenumber(3)+1;
		compchar=dict[temp-1];
		printf("computer select char %c\n",compchar);
		
       //		compare the score
		if(greater(compchar,playerchar)==1){
			compscore+=1;
			printf("computer got it!\n");
		}
		else if(greater(compchar,playerchar)==-1){
			compscore+=0;
			playerscore+=0;
			printf("its draw!\n");
			
		}
		else{
			playerscore+=1;
			printf("player got it!\n");
		}
		printf("player:%d\n computer:%d\n ",playerscore,compscore);
	}
	if(compscore>playerscore){
		printf("computer win the game\n");
	}
	else if(compscore<playerscore){
		printf("player win the game\n");
	}

	else {
		printf("the game is draw\n");
	}	
   return 0;
}
