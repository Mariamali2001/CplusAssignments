#include <iostream>
#include "dlist.h"

using namespace std;
//Initializes dl as empty list
void initializeDList (DList & dl ){
dl.head=NULL;
dl.tail=NULL;


}
// insert a new element with value val at the beginning of the list.
void put (DList& dl, int val) {
   DListElem * newDList = new DListElem;
    newDList->info = val;
    newDList->previous=NULL;
    newDList->next = dl.head ;
  if (dl.head!=NULL ){
    dl.head->previous =newDList;
  }
  else {
    dl.tail = newDList;
  }

  dl.head=newDList;

  /*  if (head==NULL){
        head = newDList;
        return;
    }
 if (DList& dl == 0){
    newDList->next= head;
    head->last=newDList;
    head=newDList;
    return;
 }*/

}
bool get(DList& dl, int &val){
 if (dl.tail==NULL)
 return false ;

 else  {
    DListElem* temp =dl.tail->previous;
    val = dl.tail->info;

    if (temp == NULL)
    {
    dl.head=NULL;
    dl.tail=NULL;

    }
    else
    {

    DListElem* temp =dl.tail->previous;
    delete dl.tail;
    temp->next=NULL;
     dl.tail=temp;
    }
 }
     return true ;

 }



bool isEmpty(DList dl){

 if (dl.head==NULL & dl.tail==NULL)
 {
     return true;
 }
else {
    return false;
}


}
int dlistLength(DList dl){
    int count = 0;
 for ( ; dl.head != NULL; dl.head = dl.head->next)
 count++;
 return count;
}


int main(int argc, char* argv[])
{
  DList queue;

  initializeDList(queue);

  //insert 5 values
  for (int i = 1; i <= 5; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }
    cout<<"______________________________________________________________________________"<<endl;
  //remove 3 values and print them to console
  for (int j = 1; j <= 3; j++) {
    int value;
    if (get(queue, value))
       cout << "     get: " << value << endl;
  }
  cout<<""<<endl;
  cout << "Length: " << dlistLength(queue) << endl;
  cout<<"______________________________________________________________________________"<<endl;


  //insert 5 values
  for (int i = 6; i <= 10; i++) {
    cout << "put: " << 10 * i << endl;
    put(queue, 10 * i);
  }
  cout<<""<<endl;
  cout << "Length: " << dlistLength(queue) << endl;
  cout<<"______________________________________________________________________________"<<endl;


  //remove all values and print them
  while(!isEmpty(queue)) {
    int value;
    get(queue, value);
    cout << "     get: " << value << endl;
  }
cout<<"______________________________________________________________________________"<<endl;
  cin.sync(); cin.get();
  return 0;
}
