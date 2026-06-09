#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int num;
	int index;
}a[1000],b[1000],node[10000];
int main(){
	int l1,l2;
	for(int i=0;;i++){
		l1=i+1;
		scanf("%d%d",&a[i].num,&a[i].index);
		if(getchar()=='\n')
			break;
	}
	for(int i=0;;i++){
		l2=i+1;
		scanf("%d%d",&b[i].num,&b[i].index);
		if(getchar()=='\n')
			break;
	}
	int k=0;
	for(int i=0;i<l1;i++){
		for(int j=0;j<l2;j++,k++){
			node[k].num=a[i].num*b[j].num;
			node[k].index=a[i].index+b[j].index;
		}
	}
	int l3=k,temp;
	for(int k=0;k<l3;k++){
        for(int j=k+1;j<l3;j++){
            if(node[k].index<node[j].index){
                temp=node[k].num;
                node[k].num=node[j].num;
                node[j].num=temp;
                temp=node[k].index;
                node[k].index=node[j].index;
                node[j].index=temp;
            }
            else if(node[k].index==node[j].index){
                node[k].num+=node[j].num;
                node[j].num=0;
                node[j].index=0;
            }
        }
    }
    for(int k=0;node[k].num!=0;k++){
        printf("%d %d ",node[k].num,node[k].index);
    }
	return 0;
}

