#include <stdio.h>

typedef struct suanshi
{
	int xishu;
	int zhishu;
}suanshi; 

suanshi t1[100];
suanshi t2[100];
suanshi t[10000];

int main ()
{
	int i1 = 0, i2 = 0;
	char c;
	while(1)
	{
		scanf("%d", &t1[i1].xishu);
		scanf("%d", &t1[i1].zhishu);
		i1 ++;
		if((c = getchar()) == '\n'){
			break;
		}
	}
	while(1)
		{
			scanf("%d", &t2[i2].xishu);
			scanf("%d", &t2[i2].zhishu);
			i2 ++;
			if((c = getchar()) == '\n'){
				break;
			}
		}
	
	//test
	/*for(int i = 0 ; i < i1 ; i ++){
		printf("%d %d ", t1[i].xishu, t1[i].zhishu);
	}
	for(int i = 0 ; i < i2 ; i ++){
			printf("%d %d ", t2[i].xishu, t2[i].zhishu);
		}*/
	
	int len = 0;	
	for(int i = 0 ; i < i1 ; i ++){
		for(int j = 0 ; j < i2 ; j ++){
			t[len].xishu = t1[i].xishu * t2[j].xishu;
			t[len].zhishu = t1[i].zhishu + t2[j].zhishu;
			len ++;
		}
	}
	
	//test
	/*for(int i = 0 ; i < len ; i ++){
		printf("%d %d\n", t[i].xishu, t[i].zhishu);
	}*/
	
	for(int i = 0 ; i < len ; i ++){
		int flag = 1;
		for(int j = 0 ; j < len - i ; j ++)
		{
			if(t[j].zhishu < t[j + 1].zhishu){
				suanshi tem;
				tem = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tem;
				flag = 0;
			}
		}
		if(flag){
			break;
		}
	}
	
	//test
	/*for(int i = 0 ; i < len ; i ++){
		printf("%d %d\n", t[i].xishu, t[i].zhishu);
	}printf("\n");*/
	
	for(int i = 0 ; i < len ; i ++){
		int k = 1;
		while(t[i].zhishu == t[i + k].zhishu && i + k < len - 1){//question
			k ++;
		}
		for(int l = 1 ; l <= k - 1; l ++)
		{
			t[i].xishu += t[i + l].xishu;
		}
		for(int jk = i + 1 ; jk <= len - k ; jk ++)
		{
			t[jk] = t[jk + k - 1];
		}
		len -= k - 1;
		t[len].zhishu = -1;
		//test
		/*printf("%d\n", len);*/
	}
	
	for(int i = 0 ; i < len ; i ++){
		printf("%d %d ", t[i].xishu, t[i].zhishu);
	}
	return 0 ;
}

