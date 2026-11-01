/* A-5 */
PART A – 5
   Binary Tree Creation and Traversals
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int x) {
    Node *p = (Node *)malloc(sizeof(Node));

    if (!p) {
        puts("Memory allocation failed.");
        exit(1);
    }

    p->data = x;
    p->left = p->right = NULL;

    return p;
}

Node *createTree(void) {
    int n, i, x;
    Node **q, *root;

    printf("Number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
        return NULL;

    q = (Node **)malloc((size_t)n * sizeof(Node *));

    if (!q) {
        puts("Memory allocation failed.");
        exit(1);
    }

    printf("Enter %d integer values in level order: ", n);

    scanf("%d", &x);
    root = newNode(x);
    q[0] = root;

    for (i = 1; i < n; ++i) {
        scanf("%d", &x);
        q[i] = newNode(x);

        if (i % 2 == 1)
            q[(i - 1) / 2]->left = q[i];
        else
            q[(i - 1) / 2]->right = q[i];
    }

    free(q);
    return root;
}

void preorder(Node *r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void inorder(Node *r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void postorder(Node *r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

void freeTree(Node *r) {
    if (r) {
        freeTree(r->left);
        freeTree(r->right);
        free(r);
    }
}

int main(void) {
    Node *root = NULL;
    int ch;

    do {
        puts("\n1.Create Binary Tree 2.Preorder 3.Inorder 4.Postorder 5.Exit");
        printf("Choice: ");

        if (scanf("%d", &ch) != 1)
            break;

        switch (ch) {
            case 1:
                freeTree(root);
                root = createTree();
                break;

            case 2:
                if (!root)
                    puts("Create tree first.");
                else {
                    preorder(root);
                    putchar('\n');
                }
                break;

            case 3:
                if (!root)
                    puts("Create tree first.");
                else {
                    inorder(root);
                    putchar('\n');
                }
                break;

            case 4:
                if (!root)
                    puts("Create tree first.");
                else {
                    postorder(root);
                    putchar('\n');
                }
                break;

            case 5:
                puts("Exiting.");
                break;

            default:
                puts("Invalid choice.");
        }

    } while (ch != 5);

    freeTree(root);
    return 0;
}


/* ============================================================
