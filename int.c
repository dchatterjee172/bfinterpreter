#include "stdio.h"
#include "stdlib.h"
#include "string.h"
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
}
			
int main(){
	init();
	while(1){
		com=(char *)malloc(500);
		printf(">>> ");
		fgets(com,500,stdin);
		com[strlen(com)-1]='\0';
		if(com[0]=='e'){
			exit(0);
		}
		eval(0);
		free(com);
	}
	return 0;
}
