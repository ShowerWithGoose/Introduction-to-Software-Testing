#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define ll long long
#define pc putchar
#define gc getchar()
#define sc scanf
#define in(n) scanf("%d",&n)
#define pr printf
#define pn putchar('\n')
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define st struct
int a1[1000],pt1[1000];
int a2[1000],ptd[1000];
int a[1000],ptt[1000];
void swap(int* a,int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
void bubSort(int p[],int n){
	int i,j,jud;
	for(i=0;i<n-1;i++){
			jud=0;
		for(j=0;j<n-i-1;j++){
		if(p[j]<p[j+1]){
			swap(&p[j],&p[j+1]);
			swap(&a[j],&a[j+1]);
			jud=1; 
		}
		}
		if(jud==0) break;
		}
return ;
}
int main(){
    	int i,j,k,cnt=0,cnt2=0,ancnt=0,jud=0;
    	ll p=0,at,pt;
    	do{
    		sc("%d %d",&a1[cnt],&pt1[cnt]);
    		cnt++;
		}
		while(gc!='\n');
		do{
    		sc("%d %d",&a2[cnt2],&ptd[cnt2]);
    		cnt2++;
		}
		while(gc!='\n');
		fr(i,0,cnt){
			fr(j,0,cnt2){
				jud=0;
				p=pt1[i]+ptd[j];
				fr(k,0,ancnt){
					if(p==ptt[k]){
						jud=1;
						break;
					}
				}
				if(jud==0){
					ptt[ancnt]=p;
					a[ancnt]=a1[i]*a2[j];
					ancnt++;
				}else{
					a[k]+=a1[i]*a2[j];
				}
			}
		}
		bubSort(ptt,ancnt);
		fr(i,0,ancnt){
			pr("%d %d ",a[i],ptt[i]);
		}
return 0;
}

