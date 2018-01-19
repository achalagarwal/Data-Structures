struct Key{
    int val;
};

struct Element{
    int data;
    struct Element* next;
};

struct SeqList{
    struct Element* head;
};


void print();
struct SeqList newList();
struct SeqList insertInOrder(struct SeqList sl, struct Element e);
struct SeqList insertAtFront(struct SeqList sl, struct Element e);
struct SeqList insertAtEnd();
struct SeqList delete(struct SeqList sl, struct Element e);
struct SeqList deleteAtFront(struct SeqList sl);
