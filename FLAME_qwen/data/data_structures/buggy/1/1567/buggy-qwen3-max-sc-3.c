#include <stdio.h>

void pai(int a[],int p,int q)
{
    int i;
    if(p==q)
    {
        printfa(a,q+1); // @@ [function 'printfa' is called but not declared before use; also, standard library function 'printf' is used without including <stdio.h> properly (though it is included), but the real issue is that 'printfa' is defined after its use and there's no forward declaration]
    }
    else
    {
        for(i=p;i<=q;i++)
        {
            change(a,p,i); // @@ [function 'change' is called but not declared before use; no forward declaration exists before this call]
            pai(a,p+1,q);
            change(a,p,i); // @@ [same as above: 'change' used without prior declaration]
        }
    }
    
    
}

void change(int a[],int p,int i)
{
    int temp;
    temp=a[p];
    a[p]=a[i];
    a[i]=temp;
}

void printfa(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int N;
    scanf("%d",&N);
    
    int i,a[10]; // @@ [if N is 10, then a[10] is size 10 with indices 0-9, which is sufficient, so this is not an error; however, in the reference program, size was 11 to be safe. But since N<=10, a[10] is acceptable. So no error here.]
    for(i=0;i<N;i++) a[i]=i+1;
    
    pai(a,0,N-1);
    
    return 0;
}