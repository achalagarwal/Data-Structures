#define POLY_H
struct pnode;
typedef struct pnode* PNode;

struct pnode{
    int exp;
    int val;
    PNode next;
};

struct polynomial;
typedef struct polynomial* Poly;

struct polynomial{
  PNode root;
};

Poly addX(Poly p, int exp, int val);
Poly createP();
Poly addPoly(Poly a, Poly b);
void printP(Poly a);
Poly addPolyFast(Poly a, Poly b);
