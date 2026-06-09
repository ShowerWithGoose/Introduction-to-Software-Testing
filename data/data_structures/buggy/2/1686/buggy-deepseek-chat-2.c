#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[99999999];int a[99999],n[99999];char b[99999],m[99999];
int main()
{int i,j,t,l,sum=0,temp,f=0;

gets(s);
for(i=0,j=0;s[i]!='\0';i++) 
if(s[i]!=' ')s[j++]=s[i];
s[j]='\0';//去空格 

/*for(i=0;i<=j;i++)
{printf("%c",s[i]);
}*/

j=0;
for(i=0;i<=strlen(s)-1;i++)
{if(s[i]<'0'||s[i]>'9') 
{b[j++]=s[i];}
else 
{while(s[i]>='0'&&s[i]<='9')
{a[j]=a[j]*10+s[i]-'0';i++;}
i--;
}
}l=j-1;

/*for(i=0;i<=l;i++)
printf("%d%c",a[i],b[i]);
printf("\n");//提数字与字符 */

j=0;t=0;
for(i=0;i<=l;i++)
{if (b[i]=='*'||b[i]=='/') 
   {n[j]=a[i];
      while(b[i]=='*'||b[i]=='/') 
     {if(b[i]=='*') n[j]=n[j]*a[i+1];
      else  n[j]=n[j]/a[i+1];
      i++;
     }
            i--;j++;
    }
    else  {m[t++]=b[i];n[j++]=a[i];} // @@ [Error: When encountering '+' or '-', the code stores the operator in m[t] and the number in n[j], but the index j is incremented after storing a[i], while the operator index t is incremented before storing b[i]. This causes a mismatch between operators and numbers in later calculations, as the number array n may have extra or misaligned entries. Additionally, the loop variable i is used to iterate over operators (b[i]), but the number array a is indexed by the same i, which may not correspond correctly because the number of operators and numbers differ by one.]

}


/*for(i=0;i<=t-1;i++)
{printf("%d%c",n[i],m[i]);
 }printf("\n"); //进行乘除*/

sum=n[0];
for(i=0;i<t-1;i++)
{
if(m[i]=='+') sum=sum+n[i+1];
else sum=sum-n[i+1];
 } 
 printf("%d",sum);//计算和
  
return 0;
}