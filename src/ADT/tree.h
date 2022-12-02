#ifndef TREE_H
#define TREE_H

#include "boolean.h"
#define NilTree NULL

typedef int TreeElType;
typedef struct treeNode* AddressTree;
typedef struct treeNode { 
    TreeElType infoTree;
    AddressTree firstChild;
    AddressTree secondChild;
    AddressTree thirdChild;
    AddressTree parent;
    boolean visited;
} TreeNode;

/* SELEKTOR */
#define InfoRoot(p) (p)->infoTree
#define FirstC(p) (p)->firstChild
#define SecondC(p) (p)->secondChild
#define ThirdC(p) (p)->thirdChild
#define Status(p) (p)->visited

typedef AddressTree Tree;

AddressTree newTreeNode(TreeElType val);
/* Mengirimkan address hasi alokasi sebuah elemen bernilai x */
/* Jika alokasi berhasil, maka p↑.info= x, p↑.firstChild = Nil, p↑.secondChild = Nil, dan p↑.thirdChild = Nil */

Tree NewTree(TreeElType root, Tree first, Tree second, Tree third);
/* Menghasilkan pohon ternary dari root, dan memiliki anak first, second, dan third apabila alokasi node berhasil */

void CreateTree(TreeElType root, Tree first, Tree second, Tree third, Tree *p);
/* Assign tree (p) dengan node baru dan memiliki list anak */
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon p */
/* Menghasilkan sebuah pohon ternary p, dari akar,*/

void deallocTreeNode (AddressTree p);
/* I.S. p terdefinisi 
   F.S. p dikembalikan ke sistem 
   Melakukan dealokasi/pengembalian address p */

boolean isTreeEmpty(Tree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean isOneElmt(Tree p);
/* Mengirimkan true jika p tidak kosong dan hanya terdiri atas 1 elemen */

void printTree(Tree p, int h, int startlevel);
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

Tree GetParent(Tree currentNode, int val, Tree parent);
/* Mengembalikan parent dari suatu Node berisikan val */
/* Syarat: Tree tidak kosong */


#endif