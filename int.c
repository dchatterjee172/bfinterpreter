#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <editline/readline.h>
#include <editline/history.h>
int *arr;
char *com;
void init(){
	int i;
	arr=(int *)malloc(2000);
	for(i=0;i<500;i++)
		arr[i]=0;
}

int loop1(int i){
	int k;
	for(;com[i]!=']';i++){
		if(com[i]=='>')
			arr=arr+1;
		else if(com[i]=='<')
			arr=arr-1;
		else if(com[i]=='+')
			*arr=*arr+1;
		else if(com[i]=='-')
			*arr=*arr-1;
		else if(com[i]=='.'){
			putchar(*arr);
			}
		else if(com[i]==','){
			*arr=getchar();
		}
		else if(com[i]=='['){
			while(*arr){
				k=loop1(i+1);
			}
			i=k;		
			
		}	
	}
	return i;
}
	
void eval(){
	int i,k;
	char *arr1;
	arr1=(char *)malloc(50);
	for(i=0;i<strlen(com);i++){
		if(com[i]=='>')
			arr=arr+1;
		else if(com[i]=='<')
			arr=arr-1;
		else if(com[i]=='+')
			*arr=*arr+1;
		else if(com[i]=='-')
			*arr=*arr-1;
		else if(com[i]=='.'){
			putchar(*arr);
			printf("\n");
		}
		else if(com[i]==','){
			fgets(arr1,50,stdin);
			arr1[strlen(arr1)-1]='\n';
			*arr=arr1[0];
		}
		else if(com[i]=='['){
			while(*arr){
				k=loop1(i+1);
			}
			i=k;		
			
		}		
	}
}
			
int main(){
	init();
	printf("begin\n\n");
	while(1){
		com=(char*)malloc(500);
		com=readline(">>> ");
		add_history(com);
		if(com[0]=='e'){
			exit(0);
		}
		else if(com[0]=='r'){
			main();
		}
		else if(com[0]=='h'){
			printf("\n > to increase the address \n < to decrease the address \n + to increase the value of the address \n - to decrease the value of the address \n , to input \n . to output \n [ to start a loop \n ] to end the scope of a loop");
		}
		eval();
		free(com);
	}
	return 0;
}
