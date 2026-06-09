#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{
	int x;
	int y;
}Begin;

typedef struct{
	int x;
	int y;
}End;

int main(){
	int n,i,j,r,k;
	int flag[105]={0},hold,max=0;
	Begin begins[105],line_begin[105];
	End ends[105],line_end[105];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&begins[i].x,&begins[i].y,&ends[i].x,&ends[i].y);
	}
	for(i=0;i<n;i++){
		line_begin[i]=begins[i];
		line_end[i]=ends[i];
		for(j=0;j<n;j++){
			if(((begins[j].x==line_end[i].x)&&(begins[j].y==line_end[i].y))||
			((ends[j].x==line_begin[i].x)&&(ends[j].y==line_begin[i].y))){
				if((begins[j].x==line_end[i].x)&&(begins[j].y==line_end[i].y)){
					line_end[i]=ends[j];
				}
				if((ends[j].x==line_begin[i].x)&&(ends[j].y==line_begin[i].y)){
					line_begin[i]=begins[j];
				}
				for(k=j;k<n;k++){
					begins[k]=begins[k+1];
					ends[k]=ends[k+1];
				}
				n--;
				j=0;
				flag[i]++;
				
			}
		}
		
	}
	for(r=0;r<n;r++){
		if(flag[r]>max) {
			max=flag[r];
			hold=r;
	    }
		
	}
	printf("%d %d %d",max+1,line_begin[hold].x,line_begin[hold].y);
	return 0;
	
} 

