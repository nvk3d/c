//
//  main.c
//  comb #85
//
//  Created by Nikita Bondar on 11.03.17.
//  Copyright © 2017 nvk3d. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void
print(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int
check(int *pr, int pos, int elem)
{
    for (int i = 0; i < pos; i++) {
        if (pr[i] == elem)
            return 0;
    }
    return 1;
}

void
comb(int *pr, int pos, int n)
{
    /**
     * Тут все наборы заданной длины от 1 до n
     */
    if (pos == n)
        return print(pr, n);
    for (int i = 0; i < n; i++) {
        pr[pos] = i + 1;
        comb(pr, pos + 1, n);
    }
}

void
combNeed(int *pr, int pos, int n)
{
    /**
     * Тут наборы перестановок от 1 до n
     */
    if (pos == n)
        return print(pr, n);
    for (int i = 0; i < n; i++) {
        pr[pos] = i + 1;
        if (pos == 0 || check(pr, pos, pr[pos])) {
            combNeed(pr, pos + 1, n);
        }
    }
}

int
main(void)
{
    int n, *pr;
    scanf("%d", &n);
    pr = calloc(n, sizeof(*pr));
    combNeed(pr, 0, n);
    free(pr);
    return 0;
}
