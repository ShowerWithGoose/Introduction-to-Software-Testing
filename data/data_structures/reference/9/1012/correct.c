#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAXLINE 1024
int line[MAXLINE][1024];
int main()
{
	int n; 
	int num[101];//记录线段个数 
	memset(num,0,sizeof(num)); 
	scanf("%d",&n);
	int st1,st2,st3,st4;//store储存
	int rcd1=0,rcd2=0;//record1负责记录加了几个线段,record2负责记录store是否被加了 
	int i=0,t1=0,t2=0;//i计数line行数 t1负责扫描line t2负责记录store第一次被插在的数组 
	scanf("%d %d %d %d",&line[0][0],&line[0][1],&line[0][2],&line[0][3]);
	n--;
	while(scanf("%d %d %d %d",&st1,&st2,&st3,&st4)!=EOF)
	{
		rcd1=num[i+1];
		rcd2=0;
		for(t1=0;t1<=i;t1++)
		{
			if(st1==line[t1][0]&&st2==line[t1][1])
			{
				line[t1][0]=st3;
				line[t1][1]=st4; 
				rcd1++;
				num[t1]++;
				switch(rcd2){
					case 3:{
						line[t2][2]=line[t1][2];
						line[t2][3]=line[t1][3];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					case 4:{
						line[t2][0]=line[t1][2];
						line[t2][1]=line[t1][3];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					default:break;
				}
				rcd2=1;
				t2=t1;
			}//st前接line前
			else if(st1==line[t1][2]&&st2==line[t1][3])
			{
				line[t1][2]=st3;
				line[t1][3]=st4; 
				rcd1++;
				num[t1]++;
				switch(rcd2){
					case 3:{
						line[t2][2]=line[t1][0];
						line[t2][3]=line[t1][1];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					case 4:{
						line[t2][0]=line[t1][0];
						line[t2][1]=line[t1][1];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					default:break;
				}
				rcd2=2;
				t2=t1;
			}//st前接line后
			else if(st2==line[t1][2]&&st3==line[t1][3])
			{
				line[t1][2]=st1;
				line[t1][3]=st2; 
				rcd1++;
				num[t1]++;
				switch(rcd2){
					case 1:{
						line[t2][0]=line[t1][0];
						line[t2][1]=line[t1][1];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					case 2:{
						line[t2][3]=line[t1][0];
						line[t2][4]=line[t1][1];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					default:break;
				}
				rcd2=3;
				t2=t1;
			}//st后接line后
			else if(st3==line[t1][0]&&st4==line[t1][1])
			{
				line[t1][0]=st1;
				line[t1][1]=st2; 
				rcd1++;
				num[t1]++;
				switch(rcd2){
					case 1:{
						line[t2][0]=line[t1][2];
						line[t2][1]=line[t1][3];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					case 2:{
						line[t2][3]=line[t1][2];
						line[t2][4]=line[t1][3];
						num[t2]+=num[t1];
						memset(line[t1],0,sizeof(line[t1]));
						num[t1]=0;
						break;
					}
					default:break;
				}
				rcd2=4;
				t2=t1;
			}//st后接line前 
		} 
		if(num[i+1]==rcd1)
		{
			i++;
			line[i][0]=st1;
			line[i][1]=st2;
			line[i][2]=st3;
			line[i][3]=st4;
			rcd2=0;
		}
		n--;
	}
	num[i+1]--;
	t1=0;
	while(num[t1]!=-1)t1++;
	int i1,j1=0;
	for(i1=0;i1<t1;i1++){
		if(num[i1]>num[j1])
		j1=i1; 
	}
	if(line[j1][0]<line[j1][2])printf("%d %d %d",num[j1]+1,line[j1][0],line[j1][1]);
	else printf("%d %d %d",num[j1]+1,line[j1][2],line[j1][3]);
 	return 0;
 } 

