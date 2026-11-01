/* B-5 */
PART B – 5
   Binary Search Tree Operations and Traversals
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

Node *insert(Node *r, int x) {
    if (!r)
        return newNode(x);

    if (x < r->data)
        r->left = insert(r->left, x);
    else if (x > r->data)
        r->right = insert(r->right, x);

    return r;
}

void inorder(Node *r) {
    if (r) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(Node *r) {
    if (r) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(Node *r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

Node *search(Node *r, int key) {
    while (r && r->data != key)
        r = key < r->data ? r->left : r->right;

    return r;
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
    int ch, n, i, x;

    do {
        puts("\n1.Create BST 2.Inorder 3.Preorder 4.Postorder 5.Search 6.Exit");
        printf("Choice: ");

        if (scanf("%d", &ch) != 1)
            break;

        switch (ch) {
            case 1:
                freeTree(root);
                root = NULL;

                printf("Number of integers: ");
                scanf("%d", &n);

                printf("Enter integers: ");

                for (i = 0; i < n; ++i) {
                    scanf("%d", &x);
                    root = insert(root, x);
                }

                break;

            case 2:
                inorder(root);
                putchar('\n');
                break;

            case 3:
                preorder(root);
                putchar('\n');
                break;

            case 4:
                postorder(root);
                putchar('\n');
                break;

            case 5:
                printf("Key: ");
                scanf("%d", &x);

                puts(search(root, x) ? "Key found." : "Key not found.");
                break;

            case 6:
                puts("Exiting.");
                break;

            default:
                puts("Invalid choice.");
        }

    } while (ch != 6);

    freeTree(root);

    return 0;
}


/* ============================================================
