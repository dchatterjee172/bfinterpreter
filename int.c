#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <editline/readline.h>
#include <editline/history.h>

int *arr,loopstack[100],sp;
char *com;

void init(){
	int i;
	arr=(int *)malloc(30000*4);
	for(i=0;i<30000;i++)
		arr[i]=0;
	sp=-1;
}

void push(int insp,int *loopstack){
	
	if(sp>99)
		printf("loop stack overflow");
	else{
		sp++;
		loopstack[sp]=insp;
		//printf("\npush"); debug purpose
	}
}

int pop(int *loopstack){
	int insp;
	if(sp<0){
		printf("loop stack underflow");
		printf("%d",sp);
	}
	else{
		insp=loopstack[sp];
		sp--;
		//printf("\npop"); debug purpose
		return insp;
	}
}

int next(int insp){
	int i,c=0;
	for(i=insp+1;;i++){
		if(com[i]==']'){
			if(c==0){
				return i;
			}
			else{
				c--;
			}
		}
		else if(com[i]=='['){
			c++;
		}
	}	
}

void eval(){
	int insp;
	//char *arr1;
	//arr1=(char *)malloc(3);
	for(insp=0;insp<strlen(com);insp++){
		if(com[insp]=='>')
			arr=arr+1;
		else if(com[insp]=='<')
			arr=arr-1;
		else if(com[insp]=='+')
			*arr=*arr+1;
		else if(com[insp]=='-')
			*arr=*arr-1;
		else if(com[insp]=='.')
			putchar(*arr);
		else if(com[insp]==','){
			//fgets(arr1,3,stdin);
			//arr1[strlen(arr1)-1]='\n';
			//*arr=arr1[0];
			*arr=getchar();
		}
		else if(com[insp]=='['){
			if(*arr){
				push(insp,loopstack);
			}
			else{
				insp=next(insp);
			}
			
		}
		else if(com[insp]==']'){
			insp=pop(loopstack)-1;   
		}
	}
}
			
int main(){
	
	printf("Happy brain fucking!!! press h for help\nbegin\n\n");
	while(1){
		com=(char*)malloc(10000);
		com=readline("\n>>> ");
		add_history(com);
		if(com[0]=='e'){
			exit(0);
		}
		else if(com[0]=='r'){
			main();
		}
		else if(com[0]=='h'){
			printf("\n > Increment the pointer. \n < Decrement the pointer. \n + Increment the byte at the pointer. \n - Decrement the byte at the pointer. \n , Input a byte and store it in the byte at the pointer. \n . Output the byte at the pointer. \n [ Jump forward past the matching ] if the byte at the pointer is zero. \n ] Jump backward to the matching [ unless the byte at the pointer is zero. \n r to reset every thing and restart the interpreter \n e to exit");
		}
		init();
		eval();
		free(com);
	}
	return 0;
}
