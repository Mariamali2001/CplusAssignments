#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std ;

int  reorderpoint (int consumption, int orderDuration );

int  orderproposal ( int a, int actualStock );

class Article {
    public  :
int numberOfArticle;
string description;
double  costPrice ;
int orderDuration ;



};

class Stock {
public  :
  int articleNumber;
  int actualStock;
  int maximumStock;
  int consumption ;

 int  reorderpoint (int consumption, int orderDuration ) {
 double leadTime = consumption*orderDuration;
double safetyStock =consumption*2;

return   leadTime + safetyStock;
 }


int  orderproposal  ( int a , int actualStock ){

if (actualStock <= a){
   return   a- actualStock;

}
else {
    return 0;
}
}

};


int main (){
    Stock out;

ifstream obj("input.csv");
if (!obj.is_open() ) std :: cout <<"ERROR : file open "<< '\n';
string numberofArticle ;
string description;
string actualStock;
string maximumStock;
string   costPrice ;
string  consumption ;
string  orderDuration ;
double totalStock =0;
int i=0 ;
ofstream output;
output.open("output.csv");

while (obj.good() &&i<5 )
    {
    getline(obj,numberofArticle,',');
    getline (obj,description,',');
    getline (obj,actualStock,',') ;
    getline (obj,maximumStock,',') ;
    getline (obj,costPrice,',') ;
    getline (obj,consumption,',');
    getline (obj,orderDuration,'\n');


   stringstream actual (actualStock);
   double x=0;
   actual >> x;
   stringstream cost (costPrice);
   double y =0;
   cost >> y;
   totalStock += x*y;


output <<numberofArticle<<',';
output<<description<<',';
output<<actualStock<<',' ;
output<<maximumStock<<',' ;
output<<costPrice<<',' ;
output<<consumption<<',';
output<<orderDuration<<',';
output << out.reorderpoint (stoi(consumption),stoi(orderDuration))<< ',';
int a=out.reorderpoint (stoi(consumption),stoi(orderDuration));
output<<out.orderproposal(a, stoi(actualStock))<< '\n';





std ::cout << "numberofArticle :"<< numberofArticle <<'\n';
std ::cout << "description :"<< description <<'\n';
std ::cout << "actualStock :"<< actualStock <<'\n';
std ::cout << "maximumStock :"<< maximumStock <<'\n';
std ::cout << "costPrice :"<< costPrice <<'\n';
std ::cout << "consumption :"<< consumption <<'\n';
std ::cout << "orderDuration :"<< orderDuration <<'\n';
std :: cout << "-------------"<< '\n';

i++;

}
output <<"the total stock  = " <<totalStock << endl;
obj.close() ;
}
