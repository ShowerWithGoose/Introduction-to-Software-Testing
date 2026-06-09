#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct Z{
int A;
int B;	
struct Z* next;	
}W;

int main()
{
int V[3][100]={0};	
int op,g,h,d,i=0,max=0;
struct Z* r;
struct Z* j;
struct Z* k;
struct Z* P1;
struct Z* P2;
struct Z* P3;
struct Z* Q; 	
char c;
k=(struct Z*)malloc(sizeof(W));
r=(struct Z*)malloc(sizeof(W));
j=(struct Z*)malloc(sizeof(W));
P1=(struct Z*)malloc(sizeof(W));
P2=(struct Z*)malloc(sizeof(W));
P3=(struct Z*)malloc(sizeof(W));
scanf("%d %d",&(r->A),&(r->B));
c=getchar();
P1=r;
while(c!='\n')
 {
 Q=(struct Z*)malloc(sizeof(W));	
 scanf("%d %d",&(Q->A),&(Q->B));
 c=getchar();	
 Q->next=NULL;
 r->next=Q;	
 r=Q;	
 }
r=(struct Z*)malloc(sizeof(W));
P2=(struct Z*)malloc(sizeof(W));
scanf("%d %d",&(r->A),&(r->B));
c=getchar();
P2=r;
while(c!='\n')
 {
 Q=(struct Z*)malloc(sizeof(W));	
 scanf("%d %d",&(Q->A),&(Q->B));
 c=getchar();	
 Q->next=NULL;
 r->next=Q;	
 r=Q;	
 }
r=P1;
k=P2;
j->A=(r->A)*(k->A);   
j->B=(r->B)+(k->B);
P3->next=j;
for(r=P1;r!=NULL;r=r->next) 
 {
 k=P2;	
 for(k=P2;k!=NULL;k=k->next) 	
  {
  Q=(struct Z*)malloc(sizeof(W));	
  Q->A=(r->A)*(k->A);   
  Q->B=(r->B)+(k->B);
  Q->next=NULL;
  j->next=Q;	
  j=Q;    	
  }		
 }
i=1;
j=P3->next->next;
for(j=j;j!=NULL;j=j->next)
 {
 V[1][i]=j->A;
 V[2][i]=j->B;
 i++;	
 }

i=1; 
for(i=1;V[1][i+1]!=0;i++) 
 {
 if(V[1][i]==-1)
 continue;	
 d=i+1;
 max=V[2][i];	
 for(d=d;V[1][d]!=0;d++)
  {
  if(V[1][d]==-1)
  continue;    	
  if(V[2][d]==max)
   {
   V[1][i]+=V[1][d];
   V[1][d]=-1;   	
   } 	
  }
 }

i=1; 
for(i=1;V[1][i]!=0;i++) 
 {
 if(V[1][i]==-1)
 continue;	
 op=i;
 d=i;
 max=V[2][i];	
 for(d=d;V[1][d]!=0;d++)
  {
  if(V[1][i]==-1)
  continue;    	
  if(V[2][d]>max)
   {
   max=V[2][d]; 
   op=d;  	
   }
  }
  g=V[1][i];
  h=V[2][i];
  V[1][i]=V[1][op];
  V[2][i]=V[2][op];
  V[1][op]=g;
  V[2][op]=h; 
 }

i=1;
printf("%d %d ",V[1][1],V[2][1]);
i=2; 
for(i=2;V[1][i]!=0;i++) 
 {
 if(V[1][i]==-1)
 continue;	
 printf("%d %d ",V[1][i],V[2][i]); 
 }
return 0; 
}




