#include "../../src/ADT/tree.h"
#include "../../src/ADT/tree.c"

int main() {
    Tree p1, p2, p3, p4, p5, p6, p7, p8;

    printf("Driver Tree\n");
    p1 = newTreeNode(1);
    p2 = newTreeNode(2);
    p3 = newTreeNode(3);
    p4 = newTreeNode(4);
    p5 = newTreeNode(5);
    p6 = newTreeNode(6);
    p7 = newTreeNode(7);
    p8 = newTreeNode(8);

    CreateTree(5, p6, p7, p8, &p5);
    CreateTree(3, p4, p5, NULL, &p3);
    CreateTree(1, p2, p3, NULL, &p1);
    printTree(p1, 2, 0);

    Tree parent = GetParent(p3, 8, NULL);
    printf("Parent dari %d adalah %d.\n", InfoRoot(p5), InfoRoot(parent));
}