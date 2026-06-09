#include<stdio.h>
#include<string.h>
struct xianduan{
 int x1;
 int y1;
 int x2;
 int y2;
}s[110];
int cmp (const void *a,const void *b ) {
	int m= (*(struct xianduan *)a).x1;
	int n= (*(struct xianduan *)b).x1;
 if(m>=n) return 1;
 else  return -1;	
	
}
int num[105];
int main(){
int cishu;
scanf("%d",&cishu);

int i=0;
int p1,q1,p2,q2;
for(i=0;i<=cishu-1;i++){
  scanf(" %d",&p1);
  s[i].x1=p1;
  scanf(" %d",&q1);
   s[i].y1=q1; 
   scanf(" %d",&p2);
   s[i].x2=p2;  
    scanf(" %d",&q2);
   s[i].y2=q2;    
}
qsort(s,cishu,sizeof(s[0]),cmp);
int j=0;
int mx=0,my=0;
for(i=0;i<=cishu-2;i++)
{
mx=s[i].x2,my=s[i].y2;
  for(j=i+1;j<=cishu-1;j++){
 if(mx==s[j].x1&&my==s[j].y1) {
 	mx=s[j].x2,my=s[j].y2;
 	num[i]++;
 }	
  	
  }


}
int max=num[0];
int bj=0;
for(i=0;i<=cishu-1;i++) {
	if(max<num[i]) 
	max=num[i],
	bj=i;
}
printf("%d %d %d",max+1,s[bj].x1,s[bj].y1 );
return 0 ;
}


