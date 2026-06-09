#include <stdio.h>  
int a[1000000]; 
int b[1000000]; 
int N; 
 
void print()
    { 
        int i; 
        for(i = 0; i < N-1; i++){
        printf("%d ", b[i]); 
    }
        printf("%d", b[i]);
        printf("\n"); 
    } 
void f(int c)
    { 
        int i; 
        if(c == N) 
        print(); 
        else
            { 
                for(i = 0; i < N; i++)
                    { 
                        if(!a[i])
                            { 
                                a[i] = 1; 
                                b[c] = i + 1; 
                                f(c + 1); 
                                a[i] = 0; 
                            } 
                    } 
            } 
} 
 
int main()
    { 
        scanf("%d", &N); 
        f(0); 
    } 



