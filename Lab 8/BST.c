#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"BST.h"
Bst create(Element e){
	Bst b = (Bst)malloc(sizeof(struct bst));
	assert(b!=NULL);
	b -> e = e;
	b -> left = NULL;
	b -> right = NULL;
	b -> balance = 0;
	return b;
}

Bst addB(Bst b, Element e){
	Bst c = b;
	while(c!=NULL){
		if(c->e->value < e->value){
			c -> balance++;
			if(c->right==NULL){
				//c->balance++;
				c->right = create(e);
				return b;
			}
			else{
				//c -> balance++;
				c = c->right;
			}
		}
		else if(c ->e -> value >= e -> value) {
			c->balance--;
			if(c->left == NULL){
				c->left = create(e);
				return b;
			}
			else{
				c = c->left;
			}
		}
	//	else
	//		return b;
	}
}

/*Bst find(Bst b, Element e){
//	if
}*/

Bst extractPredecessor(Bst b){
	Bst p = b;
	if(b == NULL)
		return NULL;
	b = b->left;
	while(b->right!=NULL){
		p = b;
		b = b->right;
	}
	if(b->left == NULL)
		return b;
	else{
		if(p->left == b){
			p->left = b->left;
		}
		else if(p->right == b){
			p->right = b->left;
		}
		return b;
	}
}

void deleteB(Bst b, Element e){
	Bst c = b;
	Bst p = b;
	int flag = 0;

	//check record also and not just key

	if(p->e->value > e->value){
		c = p->left;
	}
	else if(p->e->value < e->value){
		c = p->right;
	}
	else{// c==value
	    Bst i = extractPredecessor(p);
	    i -> left = c -> left;
	    i -> right = c-> right;
	    return ;
	}

	while(c!=NULL){
		if(c->e->value == e->value){
	//		Bst e = extractPredecessor(e);
		//cases
		//one of the sub trees is null
		//both the  sub trees are null
			if(c->left == NULL){
				if(c->right!=NULL){
				//check which child of parent
					if(p->left == c){
						//p->left = extractPredecessor(C);
						p->left = c->right;
					}
				//else p->right ==c
					else{
						//p->right = extractPredecessor(c);
						p->right = c->right;
					}
					//found and deleted
					return;
				}
				else{
					if(p->left == c){
						p->left = NULL;
					}
					else{ //p->right == c
						p->right = NULL;
					}
					//found at leaf and deleted
					return;
				}
			}
			else if( c->right == NULL){
				if(p->left == c){
					p->left = c->left;
				}
				else{ //p->right == c	
					p->right = c->right;
				}
				//found and deleted
				return;
			}
			else{ //neither == NULL
				Bst i = extractPredecessor(c);
				//attach i to parent of c
				if(p->left == c)
					p->left = i;
				else
					p->right = i;
				i -> left = c->left;
				i -> right = c -> right;
				//found and deleted
				return;
			}
		}
		// unite all return calls and free c if deleted
		//prepare for next level, update parent
		p = c;
		if(c->e->value < e->value){
			//p = c;
			c = c->right;
		}
		else // c is > element
			c = c->left;
	}
	//not found hence not deleted
	return ;
}

int getHeight(Bst b){
	int c = 0;
	while(b!=NULL){
		c++;
		if(b->balance>=0)
			b=b->right;
		else
			b=b->left;
	}
	return c;
}
