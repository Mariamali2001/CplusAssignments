#include <iostream>

using namespace std;
template < class T >
class MyArrayContainer {

public :
explicit MyArrayContainer(int size=0):n(size),t(new T[size]){}
int search(const T& x) const;

private:
int n;
T* t;

};
template < class T >

int MyArrayContainer<T>::search(const T& x) const {
for (int i=0; i<n; ++i){
        if (t[i] == x){
return i;

}
return -1;
}

}
template<class C, class T>

void delete( C& c, const T& x){
typename C::iterator i = c.begin();
while ( i != c.end() && *i == x){
i = c.erase(i);
}
}

int main()
{
MyArrayContainer<int> mac_i(10);
int i = mac_i.search(25);
if (i != -1){
    cout << "found"<< endl;

}
 return 0;
}
