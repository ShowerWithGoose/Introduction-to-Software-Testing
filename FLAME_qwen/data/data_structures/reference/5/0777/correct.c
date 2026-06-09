#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct multi{
	int a;
	int b;
}multi1[1000],multi2[1000],multi3[1000];
int comp(const void* p,const void* q) {
	struct multi *pp=(struct multi *)p;
	struct multi *qq=(struct multi *)q;
	return ((qq->b)-(pp->b));
}
int main(){
	int i;
	int cnt1=0,cnt2=0,cnt3=0;
	for(i=0;;i++){
	scanf("%d%d",&multi1[i].a,&multi1[i].b);
	cnt1++;
	if(getchar()=='\n')
	break;	
	}
	for(i=0;;i++){
	scanf("%d%d",&multi2[i].a,&multi2[i].b);
	cnt2++;
	if(getchar()=='\n')
	break;	
	}
	int j,k;
	for(j=0;j<cnt1;j++){
		for(k=0;k<cnt2;k++){
			multi3[cnt3].a=multi1[j].a*multi2[k].a;
			multi3[cnt3].b=multi1[j].b+multi2[k].b;
			cnt3++;
		}
	}
	int y;
	for(j=0;j<cnt3;j++){
		for(k=j+1;k<cnt3;k++){
			if(multi3[j].b==multi3[k].b){
			multi3[j].a=multi3[j].a+multi3[k].a;
			for(y=k;y<cnt3;y++){
				multi3[y].a=multi3[y+1].a;
				multi3[y].b=multi3[y+1].b;
			}
			cnt3--;
			}
		}
	}
	qsort(multi3,cnt3,sizeof(multi3[0]),comp);
	for(i=0;i<cnt3;i++){
		if(multi3[i].a!=0){
		   printf("%d %d ",multi3[i].a,multi3[i].b);
		}
	}
	return 0;
}



