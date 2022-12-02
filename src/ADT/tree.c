#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

AddressTree newTreeNode(TreeElType val) {
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya 
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL 
   Jika alokasi gagal, mengirimkan NULL */
    AddressTree p;

    p = (AddressTree) malloc(sizeof(TreeNode));
    if (p != NULL) {
        InfoRoot(p) = val;
        FirstC(p) = NULL;
        SecondC(p) = NULL;
        ThirdC(p) = NULL;
        Status(p) = false;
    }
    return p;
}

void deallocTreeNode (AddressTree p) {
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */
    free(p);
}

void CreateTree(TreeElType root, Tree first, Tree second, Tree third, Tree *p) {
/* Assign tree (p) dengan node baru dan memiliki list anak */
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon p */
/* Menghasilkan sebuah pohon ternary p, dari akar,*/
    *p = newTreeNode(root);
    if (*p != NULL) {
        FirstC(*p) = first;
        SecondC(*p) = second;
        ThirdC(*p) = third;
    }
}

boolean isTreeEmpty (Tree p) {
/* Mengirimkan true jika p adalah pohon biner yang kosong */
    return (p == NULL);
}

boolean isOneElmt (Tree p) {
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */
    return (!isTreeEmpty(p) && isTreeEmpty(FirstC(p)) && isTreeEmpty(SecondC(p)) && isTreeEmpty(ThirdC(p)));
}

void printTree(Tree p, int h, int startlevel) {
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
    int i;
    if (!isTreeEmpty(p)) {
        for (i=0; i<h*startlevel; i++) {
            printf(" ");
        }
        printf("%d\n", InfoRoot(p));
        printTree(FirstC(p), h, startlevel+1);
        printTree(SecondC(p), h, startlevel+1);
        printTree(ThirdC(p), h, startlevel+1);
    }
}

Tree GetParent(Tree currentNode, int val, Tree parent) {
    AddressTree a, b, c;

    if (isTreeEmpty(currentNode)) {
        return NULL;
    } 

    if (InfoRoot(currentNode) == val) {
        return parent;
    } else {
        a = GetParent(FirstC(currentNode), val, currentNode);
        b = GetParent(SecondC(currentNode), val, currentNode);
        c = GetParent(ThirdC(currentNode), val, currentNode);
        if (a != NULL) {
            return a;
        } else if (b != NULL) {
            return b;
        } else {
            return c;
        }
    }
}