#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <editline/readline.h>
#include <editline/history.h>
int *arr;
char *com;
void init(){
	int i;
	arr=(int *)malloc(30000*4);
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
		eval();
		free(com);
	}
	return 0;
}
