#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
int max=200;
struct locate{
	int startx;
	int starty;
	int endx;
	int endy;
	int len;
}; 

struct locate turn;
void bubbleSort(struct locate a[], int n)
{
   int i,j,hold,flag;
     for (i=0;i<n-1;i++){
        flag=0;
            for (j=0;j<n-1-i;j++){
                if (a[j].startx>a[j+1].startx){
                    turn=a[j];
                    a[j]=a[j+1];
                    a[j+1]=turn;
                    flag=1;
                }
            }
            if (0==flag)  break;
			}
		}
int main(){
	struct locate add[max];
    int n,recordi,recordl;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&add[i].startx,&add[i].starty,&add[i].endx,&add[i].endy);
		add[i].len=1;
	}  
	bubbleSort(add,n);
	 for(int i=0;i<n;i++){
	 	if(add[i].len!=0) 
		 for(int j=i+1;j<n;j++){
	 		if(add[j].startx==add[i].endx&&add[j].starty==add[i].endy){
	 			add[i].endx=add[j].endx;
	 			add[i].endy=add[j].endy;
	 			add[j].len=0;
	 			add[i].len++;
			 }
		 }
	 }
	 
	 recordl=add[0].len;
	 for(int i=1;i<n;i++){
	 	if(add[i].len>recordl){
	 		recordl=add[i].len;
	 		recordi=i;
		 }
	 }
	 printf("%d %d %d",recordl,add[recordi].startx,add[recordi].starty); 
	 return 0;                        
}

