#include<stdio.h>
#include<stdlib.h>
struct line{
	int x1,y1,x2,y2;
	int id;
};
struct line arr[105];
struct len{
	int num;
	int cnt;
};
struct len lenth[105];
int comp_1(const void*p1,const void*p2){
	struct line*a = (struct line*) p1;
	struct line*b = (struct line*) p2;
	if(a->x1<=b->x1){
		return -1;
	}
	else{
		return 1;
	}
}
int comp_2(const void*p1,const void*p2){
	struct len*aa = (struct len*)p1;
	struct len*bb = (struct len*)p2;
	if(aa->cnt<=bb->cnt){
		return -1;
	}
	else{ 
		return 1;
	}
}
int main()
{
	int n;
	int i,j,k;
	int flag;
	int str_len = 0;
	scanf("%d",&n);
	for(i=0;i<105;i++){
		lenth[i].cnt = 1;
	}
	for(i = 0;i < n;i++){
		scanf("%d%d%d%d",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
		arr[i].id = i;
	}
	qsort(arr,n,sizeof(arr[0]),comp_1);
	for(i=0;i<n;i++){
		k = i;
		if(flag==1){
			str_len++;
		}
		flag=0;
		for(j=i+1;j<n;j++){
			if((arr[j].x1==arr[k].x2&&arr[j].y1==arr[k].y2)||(arr[j].x1==arr[k].x1&&arr[j].y1==arr[k].y1)||(arr[j].x2==arr[k].x2&&arr[j].y2==arr[k].y2)){
				lenth[str_len].cnt++;
				lenth[str_len].num = i;
				k = j;
				flag = 1;
			}
		}
	}
	qsort(lenth,str_len,sizeof(lenth[0]),comp_2);
	printf("%d %d %d",lenth[str_len-1].cnt,arr[lenth[str_len-1].num].x1,arr[lenth[str_len-1].num].y1);
	return 0;
}

