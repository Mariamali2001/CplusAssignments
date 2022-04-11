#include <iostream>
#include<math.h>
using namespace std;
/*int main (){
    int m;
    int n;
    int a;
    int b;
    int c;
    cout << "please enter the value m "<<endl;
    cin>> m ;
    cout << "please enter the value n "<<endl;
    cin >> n;
    a=(m*m)-(n*n);
    b =2*m*n;
    c=sqrt(pow(a,2)+pow(b,2));
   // cout<<" a= "<<a<<" b= "<<b<<"  c= "<<c<<endl ;

    cout << " the Result a= " << a <<" " <<" the result b= "<< " "<<  b << " the result c= "<< c << endl;
    //a = power (m,2)- pow(n,2)


return 0;

}*/
int main(){
 int dollars ;
int quarters ;
int dimes ;
int nickles ;
int pennies ;
int input ;
int rem_pennies ;
cout << " Pl ea s e s p e c i f y the t o t a l amount o f p e n ni e s " << endl ;
cin >> input ;
rem_pennies = input ;
dollars = rem_pennies /100; // Remember d o l l a r s i s o f t y p e i n t
rem_pennies = rem_pennies %100;
quarters = rem_pennies /25;
rem_pennies = rem_pennies%25;
dimes = rem_pennies /10;
rem_pennies = rem_pennies%10;
nickles = rem_pennies / 5;
rem_pennies = rem_pennies%5;
pennies = rem_pennies ;
cout << dollars << " d o l l a r s "<< quarters << " q u a r t e r s "
<< dimes << " dimes " << nickles << " n i c k l e s "
<< pennies << " p e n ni e s " << endl ;


   return 0;





}

