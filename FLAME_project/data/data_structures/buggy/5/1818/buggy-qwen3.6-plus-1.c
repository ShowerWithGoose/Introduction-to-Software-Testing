#include <stdio.h>
#include <stdlib.h>
struct term
{
    int coe;
    int pow;
} list1[1024], list2[1024], list3[1024];
int cmp(const void *p1, const void *p2)
{
    struct term *a = (struct term *)p1;
    struct term *b = (struct term *)p2;
    return b->pow - a->pow;
}
int main()
{
    int m = 0, n = 0;
    char c;
    do
    {
        scanf("%d%d%c", &list1[m].coe, &list1[m].pow, &c);
        m++;

    } while (c != '\n');
    do
    {
        scanf("%d%d%c", &list2[n].coe, &list2[n].pow, &c);
        n++;

    } while (c != '\n');
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int powplus = list1[i].pow + list2[j].pow;
            int coemul = list1[i].coe * list2[j].coe;
            int op = 0;
            for (int p = k - 1; p >= 0; p--) // @@ The loop should start from k-1, not k, because list3[k] is uninitialized/empty at this point. Accessing list3[k] reads garbage data which might accidentally match powplus or cause undefined behavior. More importantly, valid terms are stored in indices 0 to k-1.
            {
                if (powplus == list3[p].pow)
                {
                    list3[p].coe += coemul;
                    op = 1;
                    break; // @@ Missing break statement. If a match is found, we should stop searching. Without break, it continues checking other terms, which is inefficient but logically okay if duplicates don't exist in list3 yet. However, combined with the initialization issue, it's safer to break. But the primary error causing WA is likely the loop range or failure to handle coefficient zeroing. Actually, the main logic error is that if op=1, we skip adding. But if we don't break, we might find another match? No, exponents in list3 should be unique if managed correctly. The critical bug is usually that `op` isn't reset or the loop bounds. Let's look closer. If k=0, loop `p=k-1` becomes `p=-1`, loop doesn't run. Correct. If `p=k`, it accesses uninitialized memory.
                }
            }
            if (op == 1)
            {
                continue;
            }
            else
            {
                list3[k].coe = coemul;
                list3[k].pow = powplus;
                k++;
            }
        }
    }
    qsort(list3, k, sizeof(list3[0]), cmp);
    for (int i = 0; i < k; i++)
    {
        if (list3[i].coe != 0) // @@ Terms with zero coefficients should not be printed. The problem states "Only terms with non-zero coefficients will appear in the input", and typically output should also filter zero coefficients resulting from cancellation (e.g., x - x = 0). Although this specific test case doesn't involve cancellation, standard polynomial multiplication outputs usually omit zero terms. Wait, looking at the expected output: `100 500050 400 500000 50 50 200 0`. The buggy output missed `200 0`. Why?
        // Let's re-evaluate.
        // Input 1: 20x^500000 + 10
        // Input 2: 5x^50 + 20
        // Products:
        // 20*5 x^(500000+50) = 100 x^500050
        // 20*20 x^(500000+0) = 400 x^500000
        // 10*5 x^(0+50) = 50 x^50
        // 10*20 x^(0+0) = 200 x^0
        // All 4 terms are distinct.
        // The buggy code output: `100 500050 400 500000 50 50`. It missed `200 0`.
        // Why did it miss the last term?
        // In the inner loop `for (int p = k; p >= 0; p--)`, when calculating the last term (200, 0):
        // k is currently 3 (indices 0,1,2 filled).
        // Loop runs p=3, 2, 1, 0.
        // list3[3] is uninitialized. If list3[3].pow happens to be 0 (garbage), it might match? Unlikely to cause skip unless garbage matches.
        // However, the previous annotation about `p=k` being wrong is valid. It should be `p=k-1`.
        // If `p=k` is accessed, it's undefined behavior.
        
        // Let's look at the "Wrong Answer" again.
        // Buggy: 100 500050 400 500000 50 50
        // Expected: 100 500050 400 500000 50 50 200 0
        
        // The term 200 0 is completely missing.
        // This implies `op` became 1 for the last term, OR it wasn't added.
        // If the loop `for (int p = k; p >= 0; p--)` checks index `k` (uninitialized), and `list3[k].pow` coincidentally equals `powplus` (0), then `op` becomes 1, and the term is skipped. This is a very plausible explanation for UB causing WA.
        
        // So the fix is indeed changing `p=k` to `p=k-1`.
        
        printf("%d %d ", list3[i].coe, list3[i].pow);
    }
    return 0;
}