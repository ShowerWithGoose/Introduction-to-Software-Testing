#include<stdio.h>
#include<string.h>
int a[200][5];//1x,1y,2x,2y
int myline[200][3];//前一个0，自己，后一个2

int main(void)
{
	int i,k,n,len,max,head,tail;
	int begin[2]={0,0};
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d %d %d %d",&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
	
	//try1：每条都组一遍
	len=max=0;
	for(i=1;i<=n;i++){
		head=tail=i;
		memset(myline,0,sizeof(myline));
		myline[i][1]=i; 
		len=1;
		for(k=1;k<=n;k++){
			if(myline[k][1]==k) continue;
			if(a[k][1]==a[tail][3]&&a[k][2]==a[tail][4]) {//新线段的头与已组成的尾
				myline[tail][2]=k;
				myline[k][0]=tail;
				tail=k;
				len++;
				myline[k][1]=k;k=0;
			}
			else if(a[k][3]==a[head][1]&&a[k][4]==a[head][2]){//新线段的尾与已组成的头
				myline[head][0]=k;
				myline[k][2]=head;
				head=k;
				len++;
				myline[k][1]=k;k=0;
			}
		}
		if(len>max){
			max=len;
			begin[0]=a[head][1];
			begin[1]=a[head][2];
		}
	}
	printf("%d %d %d",max,begin[0],begin[1]);
	return 0;
}


