#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct polynomial{
	int a;
	int pow;
	//struct polynomial *link;
};
struct polynomial S1[105];
struct polynomial S2[105];
struct polynomial S3[105];
int cmp(const void*p1,const void*p2){
	struct polynomial *a=(struct polynomial*)p1;
	struct polynomial *b=(struct polynomial*)p2;
	return b->pow-a->pow;
}
int main()
{
	int a,index;
	int i=0,j,k=0,cnt1,cnt2;
	char c='0';
	while(c!='\n'){
		scanf("%d%d%c",&a,&index,&c);
		S1[i].a=a;S1[i].pow=index;
		i++;
	}
	cnt1=i+1;
	i=0;c='0';
	while(c!='\n'){
		scanf("%d%d%c",&a,&index,&c);
		S2[i].a=a;S2[i].pow=index;
		i++;
	}
	cnt2=i+1;
    for(i=0;i<cnt1;i++){
    	for(j=0;j<cnt2;j++){
        	S3[k].a=S1[i].a*S2[j].a;
        	S3[k].pow=S1[i].pow+S2[j].pow;
        	k++;
    	}
	}
	qsort(S3,k,sizeof(struct polynomial),cmp);
	for(i=0;i<k;i++){
    	if(S3[i].pow==S3[i+1].pow&&S3[i].pow!=0){
            S3[i+1].a=S3[i+1].a+S3[i].a;
            S3[i].a=0;
        }
    }
	for(i=0;i<k;i++) if(S3[i].a!=0)printf("%d %d ",S3[i].a,S3[i].pow);
	return 0;
}

