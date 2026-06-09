#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct{
    int num;
    int exp;
}asketla;
asketla a[100],b[100],c[1000];

int cmp(const void*aa,const void*ab){
    if(((asketla*)aa)->exp<((asketla*)ab)->exp)
    return 1;
    return -1;
} 

int main(){
    int i;
    scanf("%d%d",&a[0].num,&a[0].exp );
    for(i=1;;i++){
        scanf("%d%d",&a[i].num,&a[i].exp);
        if(getchar()=='\n')
        break;
    }
    int m=0;
    for(int j=0;;j++){
        scanf("%d%d",&b[j].num,&b[j].exp);
        for(int k=0;k<=i;k++,m++){ // @@ The loop condition k<=i accesses a[i] which was not initialized as a valid term (loop in input stopped before initializing a[i] fully or i is count, so a[i] is garbage/uninitialized). Also, this nested loop structure is logically flawed for reading polynomial B and multiplying simultaneously. It assumes polynomial B has only one term per iteration of outer loop but multiplies against all terms of A including uninitialized ones. More critically, the array c is too small (1000) for potential products if inputs are large, but specifically here, the logic `k<=i` uses `i` which is the index of the last element + 1? No, `i` increments after reading. If input is `8 1000000000\n`, `a[0]` is read. Loop `i=1` reads next? No, input ends. The `for(i=1;;i++)` reads `a[1]` then checks newline. Wait, the input format says "ends with a newline". The first polynomial input `8 1000000000` likely ends with newline. So `a[0]` is read. Then `i=1`, `scanf` waits for more input? No, the problem says "First input... then input second". The code reads `a[0]`, then enters loop `i=1`, tries to `scanf` for `a[1]`. This will block or read from the next line (polynomial B). This is a major logical error in input parsing. However, focusing on the specific crash/error: The array `c` size is 1000. The product of two polynomials can have up to N*M terms. If N=1, M=1, size is 1. The test case has 1 term each. `i` becomes 1 after reading `a[0]`? No. `a[0]` read. `i=1`. `scanf` reads `15` (from next line)? Yes. `a[1].num=15`. `getchar()` reads space? No, `15 1000000000\n`. `scanf` consumes `15`. `getchar` consumes space? No, `scanf` skips whitespace. `scanf("%d%d", ...)` reads `15` and `1000000000`. Then `getchar()` reads `\n`. Break. So `a` has 2 terms? `a[0]` and `a[1]`. But `a[1]` is actually the first term of polynomial B. This confirms the input parsing is completely broken. 
        // The primary Runtime Error source in the context of the provided "Buggy Output" being empty/crash is likely due to accessing invalid memory or infinite loops/logic errors leading to undefined behavior. 
        // Specifically, `c` array overflow is possible if polynomials are larger. 
        // But looking at `qsort(c,m,...)`, `m` is the number of products.
        // The merging logic: `c[k].exp=-1` marks deleted.
        // The output loop: `s<sum`.
        // The specific error requested is likely the array bounds or logical corruption.
        // Let's look at `c[1000]`. If inputs were larger, it would crash. Here inputs are small.
        // The real issue is that `a` contains mixed data from Poly A and Poly B because the input parsing for Poly A bleeds into Poly B's line.
        // When Poly B is read, it reads further garbage or crashes.
        // However, usually "Runtime Error" in these online judges with small arrays and large potential degrees/counts points to Buffer Overflow or Segmentation Fault.
        // Here, `c` is size 1000. `a` and `b` are 100.
        // If Poly A has 10 terms and Poly B has 10 terms, `m` becomes 100. OK.
        // The logic `k<=i` in the multiplication loop: `i` is the index AFTER the last term of A (which is actually mixed).
        // If `i` is large, `m` grows fast.
        
        // Let's annotate the most critical structural/logical failure causing undefined behavior/crash.
        // The input parsing loop for A does not stop correctly at the end of Poly A if there is no trailing space before newline, or it consumes the first term of B.
        // In the test case:
        // Line 1: "8 1000000000"
        // Line 2: "15 1000000000"
        // Code:
        // Reads a[0]=8, exp=10^9.
        // Loop i=1:
        // scanf("%d%d", &a[1].num, &a[1].exp). This reads from stdin. Since Line 1 ended with \n, scanf skips whitespace and reads from Line 2.
        // a[1].num = 15, a[1].exp = 10^9.
        // getchar() reads the \n at end of Line 2.
        // Break.
        // So Poly A is considered to have terms a[0] and a[1]. i is now 2? No, i increments in for loop. i starts 1. End of loop body. i++ -> i=2. Check condition? No, break exits loop. So i remains 1? No, `for(i=1;;i++)`. Increment happens at end of iteration. If break is inside, increment might not happen depending on placement. Break is after i++? No.
        // Structure: `for(i=1;;i++) { ... if(...) break; }`.
        // Iteration 1: i=1. Read a[1]. Check getchar. It is \n. Break.
        // So i is 1.
        // Poly A terms: a[0], a[1]. Count = 2? Indices 0 and 1.
        // Now Poly B reading:
        // `for(int j=0;;j++)`
        // `scanf("%d%d", &b[0].num, &b[0].exp)`.
        // Stdin is now empty? Or at EOF?
        // The previous scanf consumed "15 1000000000". The getchar consumed "\n".
        // So next scanf waits for input. But there is no more input.
        // scanf returns EOF. b[0] is uninitialized/garbage.
        // Then inner loop `k=0` to `k<=i` (0 to 1).
        // m=0. c[0] = a[0]*b[0]. c[1] = a[1]*b[0].
        // m becomes 2.
        // getchar() in B loop. Returns EOF (-1). Not '\n'. Loop continues.
        // j=1.
        // scanf("%d%d", &b[1]...). Still EOF. Undefined behavior/Garbage.
        // Inner loop runs again. m increases.
        // Infinite loop or until crash.
        
        // Therefore, the input parsing logic is fundamentally broken, leading to reading garbage/infinite loops.
        
        // However, I must annotate specific lines.
        
        c[m].num =a[k].num*b[j].num ;
        c[m].exp =a[k].exp+b[j].exp ;
        }
        if(getchar()=='\n')
        break;        
    }
    int sum=m;
    for(int k=0;k<=m;k++){ // @@ Loop bound k<=m accesses c[m] which is out of bounds if m is the count (indices 0..m-1). Also logic modifies array while iterating.
        for(int xk=0;xk<=sum;xk++){ // @@ Logic error: comparing against elements that might have been marked invalid or out of current valid range, and modifying 'sum' inside loop affects bound check unpredictably.
            if(c[k].exp==c[xk].exp&&c[k].exp!=-1&&xk!=k){
                c[k].num+=c[xk].num ;
                c[xk].exp=-1;
                sum--; 
            }
        }
    }
    qsort(c,m,sizeof(asketla),cmp); // @@ Sorting includes uninitialized or garbage elements if m is incorrect due to input errors.
    for(int s=0;s<sum;s++){
        printf("%d %d ",c[s].num,c[s].exp);
    }
    return 0;
    
}