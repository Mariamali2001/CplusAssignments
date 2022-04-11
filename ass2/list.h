#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED


struct DListElem {
int     info;
DListElem * next ;
DListElem * previous ;
    DListElem (){
   next =NULL;
   previous = NULL;

}
};
struct DList {
DListElem * head ;
DListElem * tail ;
int Length =0;

};


typedef DListElem * dlist ;
const dlist emptylist =0;

void initializeDList(DList & dl);
void put(DList& dl, int val);
bool get(DList& dl, int &val);
bool isEmpty(DList dl);
int dlistLength(DListElem dl);




#endif // LIST_H_INCLUDED
