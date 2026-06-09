#include <stdio.h>
#include <string.h>
int main() 
{char a[1000],b[10000];
int i,j,k=0;
gets(a);
for(i=0;i<strlen(a);i++)
{if(a[i]=='-')
{if(a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>=a[i-1])
for(j=0;j<=a[i+1]-a[i-1]-2;j++)
{b[k]=a[i-1]+j+1;
k++;
}
else if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>=a[i-1])
for(j=0;j<=a[i+1]-a[i-1]-2;j++)
{b[k]=a[i-1]+j+1;
k++;
}
else if(a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>=a[i-1])
for(j=0;j<=a[i+1]-a[i-1]-2;j++)
{b[k]=a[i-1]+j+1;
k++;
}
else {b[k]=a[i];
k++;
}
}
else
{b[k]=a[i];
k++;
}

}
printf("%s",b);
	return 0;
}

