#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct xiangs {
	int xishu;
	int mici;
};

int cmp_mici(const void *p1, const void *p2) {
	int ans;
	struct xiangs* pdata01=(struct xiangs *) p1;
	struct xiangs* pdata02=(struct xiangs *) p2;
	ans = -(pdata01->mici-pdata02->mici);
	return ans;
}

int main() {
	int i=0,j=0;
	struct xiangs xiang1[20];
	struct xiangs xiang2[20];
	struct xiangs ans0[40];

	char a,b;
	int c=10;
	//printf("%d\n",c);
	for(i=0; i<20; i++) {
		xiang1[i].xishu=0;
		xiang1[i].mici=0;
		xiang2[i].xishu=0;
		xiang2[i].mici=0;
	}
	for(i=0; i<40; i++) {
		ans0[i].xishu=0;
		ans0[i].mici=0;
	}
	i=0;j=0;
	do {
		scanf("%d%c%d%c",&xiang1[i].xishu,&a,&xiang1[i].mici,&b);
		//printf("%d %d\n",xiang1[i].xishu,xiang1[i].mici);
		i++;
	} while(b!=c);


	while(scanf("%d %d ",&xiang2[j].xishu,&xiang2[j].mici)!=EOF) {
		//printf("\n");
		//printf("%d %d\n",xiang2[j].xishu,xiang2[j].mici);
		j++;
	}

	int num1=i,num2=j,k=0;
	/*for(i=0; i<num1; i++) {
		printf("\n");
		printf("%d: %d %d\n",i,xiang1[i].xishu,xiang1[i].mici);
	}
	for(j=0; j<num2; j++) {
		printf("%d: %d %d\n",j,xiang2[j].xishu,xiang2[j].mici);
	}*/
	for(i=0; i<num1; i++) {
		for(j=0; j<num2; j++) {
			ans0[k].xishu=xiang2[j].xishu*xiang1[i].xishu;
			ans0[k].mici=xiang2[j].mici+xiang1[i].mici;
			//printf("ans0[%d]=%d %d \n",k,ans0[k].xishu,ans0[k].mici);
			k++;
		}
	}
	//printf("\n");
	for(i=0; i<k; i++) {
		for(j=0; j<k; j++) {
			if((ans0[i].mici==ans0[j].mici)&&i!=j) {

				ans0[i].xishu+=ans0[j].xishu;
				ans0[j].mici=-1;
			}
		}
	}
	qsort(ans0,k,sizeof(struct xiangs),cmp_mici);
	for(i=0; i<k; i++) {
		if(ans0[i].mici!=-1&&ans0[i].xishu!=0)
			printf("%d %d ",ans0[i].xishu,ans0[i].mici);
	}
	return 0;
}

