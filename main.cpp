#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main() {
	LIST L;
	L=MAKENULL(L);
	INSERT('d', FIRST(L), L);
	INSERT('a', FIRST(L), L);
	INSERT('c', END(L)->prev, L);
	INSERT('e', END(L), L);
	INSERT('b', FIRST(L)->next, L);
	DELETE(LOCATE('x', L), L);
	PRINTLIST(L);
	system("pause");
    return 0;
}

void PRINTLIST(LIST L){
	position tmp=L;
	while(tmp->next!=NULL){
		printf("%c, ", tmp->next->element);
		tmp=tmp->next;
		if(tmp->next==0)
			printf("\n");
	}	
}

LIST MAKENULL(LIST L) {
    L=newnode();
	L->next=NULL;
	L->prev=NULL;
	return L;
} 

position END(LIST L) {         
    position q=L;
    while(q->next!=NULL)
    	q=q->next;
    return q;
}

position FIRST(LIST L) { 
    return L;
}

LIST INSERT (elementtype x, position p, LIST L) {                 
	position inserted_cell;
	inserted_cell=newnode();
	inserted_cell->element=x;
	inserted_cell->next=p->next;
	p->next=inserted_cell;
	inserted_cell->prev=p;
	if(inserted_cell->next!=NULL)
        inserted_cell->next->prev=inserted_cell;  
    return L;     
}

LIST DELETE (position p, LIST L) {         
    if(p->prev!=NULL)
    	p->prev->next=p->next;
    if (p->next!=NULL)
        p->next->prev=p->prev;
    return L;     
}

position LOCATE (elementtype x, LIST L) {
    position p=L;
    while(p->next!=NULL){
    	if (p->next->element==x)
    		return p->next;
    	else p = p->next;
	}
    return END(L); 
}

elementtype RETRIEVE(position p, LIST L) {
    return p->element;  
}

position NEXT (position p, LIST L) {
	if(p->next!=NULL)
    	return p->next;
    return NONE;
}

position PREV (position p, LIST L) {
    if(p->prev!=NULL)
		return p->prev;
	return NONE;
}
