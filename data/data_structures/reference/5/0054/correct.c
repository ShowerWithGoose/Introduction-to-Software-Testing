#include<stdio.h>
struct node{
	int x;
	int y;
}; 
int main(){
	char c;
	int sin[200];
	int i=0,j=0,k,l,h=0;
	struct node a[100];
	struct node b[100];
	struct node s[100];
	struct node temp;
	do{
		scanf("%d %d%c",&a[i].x,&a[i].y,&c);
		i++;
	}while(c!='\n');
	do{
		scanf("%d %d%c",&b[j].x,&b[j].y,&c);
		j++;
	}while(c!='\n');
	if(i>j){
		for(k=0;k<i;k++){
			for(l=0;l<j;l++){
				s[h].x=a[k].x*b[l].x;
				s[h].y=a[k].y+b[l].y;
				sin[h]=1;
				h++;
			}
		}}
		else{
			for(l=0;l<j;l++){
				for(k=0;k<i;k++){
				s[h].x=a[k].x*b[l].x;
				s[h].y=a[k].y+b[l].y;
				sin[h]=1;
				h++;
				
				}
			}
			
		}
		for(i=0;i<h;i++){
			for(j=i+1;j<h;j++){
				if(s[i].y<s[j].y){
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
		}
			for(i=0;i<h;i++){
			for(j=i+1;j<h;j++){
				if(s[i].y==s[j].y){
					s[i].x=s[i].x+s[j].x;
					sin[j]=-1;
				}
			}
		
		}
		for(i=0;i<h;i++){
		if(sin[i]==1)
			printf("%d %d ",s[i].x,s[i].y);
		}
}

