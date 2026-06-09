#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

typedef struct location{
	int x;
	int y;
	struct location *next;
}tab;

tab input[210],*temp;
int n,len,max,i,ans;

void scan();
void deal();

int main(){
	scanf("%d",&n);
	while(n--){
		scan();
		deal();
	}
	for(int j=0;j<i;j++){
		len = 0;
		for(temp = &input[j];temp->next!=NULL;temp=temp->next){
			len++;
		}
		if(len>max)	max = len,ans = j;
	} 
	printf("%d %d %d",max,input[ans].x,input[ans].y);
	return 0;
}

void scan(){
	scanf("%d%d%d%d",&input[i].x,&input[i].y,&input[i+1].x,&input[i+1].y);
	input[i].next = &input[i+1];
	input[i+1].next = NULL;
	i+=2;
}

void deal(){
	for(int j=0;j<=i-3;j++){
		if(input[i-2].x==input[j].x&&input[i-2].y==input[j].y) input[j].next=input[i-2].next;
		if(input[i-1].x==input[j].x&&input[i-1].y==input[j].y) input[i-2].next=&input[j],input[i-1].next=input[j].next;
	}
}

