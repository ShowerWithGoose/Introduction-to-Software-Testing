//我学到的 1.返回数组的函数类型为字符指针 2.返回数组的函数内应该定义静态变量(静态局部变量仍然是局部变量)3.不能随意改变影响循环终止条件的量 4.printf测试 

#include <stdio.h>
#include <string.h>
char s1[100],s2[100];
char *create(char left,char right)
{
    //static char s1[100];
    int i=0;
    int temp=left;
    for(i=0;i<=right-left-2;i++)
    {
        s1[i]=temp+1;
        temp++;
    }
    return s1;
}
char *insert(char a[],char b[],int position)//position为斜杠数组下标
{
    //static char s2[100];
    int i=0;
    for(i=0;i<position;i++)
        s2[i]=b[i];
    
    int j=0;
    for(i=position;i<position+strlen(a);i++)
    {
        s2[i]=a[j];
        j++;
    }

    j=position+1;
    for(i=position+strlen(a);b[j]!='\0';i++)
    {
        s2[i]=b[j];
        j++;
    }

    return s2;
}
int main()
{
    char s[100];
    fgets(s,99,stdin);
    int i=0,j=1;
    int link[100]={0},link_num=0;//link[]下标从1开始
    int flag=0;
    for(i=1;s[i]!='\0';i++)
    {
        if(s[i]=='-' && s[i-1]<s[i+1])
        {
            if('a'<=s[i-1] && s[i-1]<='z' && 'a'<=s[i+1] && s[i+1]<='z')
                flag++;
            else if('A'<=s[i-1] && s[i-1]<='Z' && 'A'<=s[i+1] && s[i+1]<='Z')
                flag++;
            else if('0'<=s[i-1] && s[i-1]<='9' && '0'<=s[i+1] && s[i+1]<='9')
                flag++;
        }
        if(flag==1)
        {
            link_num++;
            link[j]=i;
            j++;
        }
        flag=0;
    }

    char string[100];
    strcpy(string,s);
    int temp=0;
    for(i=1;i<=link_num;i++)
    {
    	if(i==1)
			temp=0;
		else
		{
			temp+=strlen(create(s[link[i-1]-1],s[link[i-1]+1]))-1;
			memset(s1,0,sizeof(s1));
		}
			//temp=max(strlen(create(s[link[i-1]-1],s[link[i-1]+1]))-1,0);
			//a-fG-Pm-t
        
		//printf("第%d次\n",i); 
        //printf("temp是%d\n",temp);
        //printf("斜杠下标是%d\n",link[i]) ;
        //printf("创建字符串为：");
		//puts(create(s[link[i]-1],s[link[i]+1]));
		//memset(s1,0,sizeof(s1));
        //printf("插入后字符串：");puts(insert(create(s[link[i]-1],s[link[i]+1]),string,link[i]+temp)) ;
        //printf("string为 ");puts(string) ;
		
		
		strcpy(string,insert(create(s[link[i]-1],s[link[i]+1]),string,link[i]+temp));
		memset(s1,0,sizeof(s1));
    }
    puts(string);
    return 0;
}

