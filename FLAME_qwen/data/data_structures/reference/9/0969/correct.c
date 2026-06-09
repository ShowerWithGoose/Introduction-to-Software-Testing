#include<stdio.h>
struct line {
	int x1;
	int y1;
	int x2;
	int y2;
};
struct line index[105];
int leftcheck(int i,int num)//检测是否为左端点 
{
	int flag=0;
	int j=0;
	for(j=0;j<num;j++)
	{
		if(j==i)
		    continue;
		if(index[i].x1==index[j].x2&&index[i].y1==index[j].y2)
		    flag=1;
	}
	return flag;
}
int stringlenth(int i,int num)//统计长度 
{
	int j=0;
	int flag=-1;
	for(j=0;j<num;j++)
	{
		if(j==i)
		    continue;
		if(index[i].x2==index[j].x1&&index[i].y2==index[j].y1)
		    flag=j;   
	}
	if(flag==-1)
	    return 0;
	else if(flag!=-1)
	    return 1+stringlenth(flag,num);
}
int start[105]; 
int main()
{
	int linenumber,input,first,check,longest,longstart=0;
	scanf("%d",&linenumber);
	for(input=0;input<linenumber;input++)//输入 
		scanf("%d%d%d%d",&index[input].x1,&index[input].y1,&index[input].x2,&index[input].y2);
	for(int m=0;m<105;m++)
	    start[m]=-1;
    for(input=0,first=0;input<linenumber;input++)
	    if(leftcheck(input,linenumber)==0)
		{
			start[first]=input;
			first++;
		}//此时start中是第一条线段的编号
	longest=0;
	for(check=0;start[check]!=-1;check++)
		if(stringlenth(start[check],linenumber)>longest)
		{
		    longest=stringlenth(start[check],linenumber);
		    longstart=start[check];
	    }
	    
	printf("%d %d %d",longest+1,index[longstart].x1,index[longstart].y1);
	return 0;
}

