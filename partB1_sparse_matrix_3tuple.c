/* B-1 */
PART B – 1
   Sparse Matrix Addition using 3-Tuple Representation
   ============================================================ */

#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, val;
} Term;

int readSparse(Term t[]) {
    int r, c, i, j, x, k = 1;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    t[0].row = r;
    t[0].col = c;
    t[0].val = 0;

    printf("Enter matrix elements row-wise:\n");

    for (i = 0; i < r; ++i)
        for (j = 0; j < c; ++j) {
            scanf("%d", &x);

            if (x != 0 && k < MAX) {
                t[k].row = i;
                t[k].col = j;
                t[k].val = x;
                k++;
            }
        }

    t[0].val = k - 1;

    return k;
}

void printTuple(Term t[]) {
    int i;

    puts("Row Col Value");

    for (i = 0; i <= t[0].val; ++i)
        printf("%3d %3d %5d\n",
               t[i].row, t[i].col, t[i].val);
}

void printNormal(Term t[]) {
    int i, j, k = 1;

    for (i = 0; i < t[0].row; ++i) {
        for (j = 0; j < t[0].col; ++j) {
            if (k <= t[0].val &&
                t[k].row == i &&
                t[k].col == j)
                printf("%d ", t[k++].val);
            else
                printf("0 ");
        }

        putchar('\n');
    }
}

int main(void) {
    Term a[MAX], b[MAX], c[MAX];
    int na, nb, i = 1, j = 1, k = 1;

    puts("Matrix A");
    na = readSparse(a);

    puts("Matrix B");
    nb = readSparse(b);

    if (a[0].row != b[0].row ||
        a[0].col != b[0].col) {
        puts("Matrices must have the same order.");
        return 1;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    while (i <= a[0].val && j <= b[0].val) {
        int posA = a[i].row * a[0].col + a[i].col;
        int posB = b[j].row * b[0].col + b[j].col;

        if (posA < posB)
            c[k++] = a[i++];

        else if (posB < posA)
            c[k++] = b[j++];

        else {
            int sum = a[i].val + b[j].val;

            if (sum) {
                c[k] = a[i];
                c[k++].val = sum;
            }

            i++;
            j++;
        }
    }

    while (i <= a[0].val)
        c[k++] = a[i++];

    while (j <= b[0].val)
        c[k++] = b[j++];

    c[0].val = k - 1;

    puts("Result in normal form:");
    printNormal(c);

    puts("Result in 3-tuple form:");
    printTuple(c);

    return 0;
}


/* ============================================================
