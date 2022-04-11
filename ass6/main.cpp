#include <iostream>

using namespace std;
template <typename T>
class vector {
private :
    T *data ;
   int  capacity ;
    int numofelements;

public :
    vector ();
    vector (int size );
    vector (const T data []);
    ~vector ();
    int size ()const ;
    void resize(size_t s) ;
    void swap (T &v1 , T &v2);
    void add (const T &obj );
   void setValue(T* newValues);

       string toString();
       T& operator[](int i);
       T& operator = (const vector &v);
        friend std::ostream& operator <<(std::ostream& outs, const vector& v);
        void remove (vector<T>& vec , size_t x);
       void insertvar1 (vector <T>& v , int pos);
       void insertvar2 (const T& t , int pos);

       };


    template <typename T>
   vector  <T>:: vector (){
       data = new T[1];
        capacity = 1;
        numofelements = 0;
}
 template <typename T>

   vector<T> :: vector (const T d []){
       for (int i = 0; i < numofelements; i++)
             data[i] = d[i];
    }


    /* template <typename T>
     vector<T> :: vector (int size ){
       this ->capacity = size;
       this->numofelements = 0;
       this-> data = new T [this->capacity];

    }*/


    template <typename T>
   vector  <T>:: ~vector (){
      /* for (int  i =0 ; i< numofelements ;i++){
        delete this->data[i];
       }*/

   delete [] this ->data;
   }

    template <typename T>
   int vector  <T>:: size ()const {
       return this->numofelements;
    }

    template <typename T>
  void vector <T>:: resize(size_t s) {
     capacity=s;

  }

    template <typename T>
  void vector<T>:: swap (T &v1 , T &v2){
    int temp = v1;
    v1=v2;
    v2=temp;

    }
    template < typename T >
  string vector<T>:: toString (){
    for (int i = 0; i < numofelements; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

template < typename T >
void vector<T>::add (const T& obj ){
    if (this->numofelements < this->capacity)
        this->data [this->numofelements++]=obj;
    else
        throw std :: out_of_range("is full ");

}
template < typename T >
void vector<T>::setValue(T* newValues){
this->data = newValues;
}



 template <typename T>
   T&  vector<T> ::  operator[](int i) { return data[i]; }

template <typename T>

 T&  vector<T> ::  operator = (const vector &v){
 if (this!=&v)
    *data = *(v.data);
 }
 template <typename T>
std   ::ostream& operator<<(std::ostream& outs, const vector<T>& v){
    outs << v.data;
    return outs;
}
template <typename T>

void  vector<T> ::remove (vector<T>& vec , size_t x){

for (int i=x ;i<capacity ;i++){
    if (vec==data[i]){
        delete data[i];
    }

data[i] =i+1;
}
throw std :: out_of_range (" x is out of range");


}

template <typename T>
void vector<T> :: insertvar1 (vector <T>& v , int pos){
if (pos<capacity && pos >=0 )

    data[pos] =v;
    else
        throw std :: out_of_range("pos is out of range");
}



template <typename T>

void vector <T> ::    insertvar2 (const T& t, int pos){
for(int i=0 ;i<capacity ; i++){
    if (pos==i)
        data[pos]=t;

else
    throw std :: out_of_range("pos is out of range");
}

}

int main()
{
    vector < double > s;


    return 0;
}
