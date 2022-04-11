#include <iostream>
#include <string>
using namespace std;

class medium {

private :

    string abbreviation ;
    string author ;
    string title ;
    int  yearofpub ;


public :

     string  getabbreviation  () const {
         return abbreviation ;
         }
    void   setabbreviation (string abbreviation) {
        this-> abbreviation= abbreviation ;
        }
    string  getauthor  () const {
         return author ;
         }
    void  setauthor (string author) {
         this->author= author  ;
        }

         string  gettitle () const {
         return title ;
         }
    void   settitle  (string title ) {

        this->title= title ;
        }

         int   getyearofpub   () const {
         return yearofpub ;
         }
     void    setyearofpub (int  yearofpub) {
        this-> yearofpub=yearofpub  ;
        }


    medium(){}

   medium (string abbreviation ,string author ,string title ,int  yearofpub ){
    this->abbreviation=abbreviation;
    this->author=author;
    this->title= title;
    this->yearofpub=yearofpub;


    }

    virtual ~medium(){}
    virtual string toString () const {

     return "["+ abbreviation + "]"+ author +":" + title ;

    }
   friend class Book ;
   friend class article;


};
 class Book : public medium

{
 private :
string publisher ;


 public :

 string  getpublisher  () const {
         return publisher ;
         }
    void   setpublisher (string publisher) {
        this-> publisher= publisher ;
        }


  Book (string abbreviation ,string author ,string title ,int  yearofpub , string publisher): medium (abbreviation , author, title ,yearofpub)
{
   this->publisher= publisher ;

}
virtual ~ Book (){}
  string toString ()const {


 return "["+ abbreviation + "]"+ author +":" + title + publisher +"," +to_string(yearofpub)  ;

}



};

class article :public medium {

    private :

    string namemagzine ;
    int  numbofmagzine ;
    int pagenumber ;

    public :
         article(string abbreviation ,string author ,string title ,int  yearofpub ,string namemagzine ,int  numbofmagzine ,int pagenumber )
    : medium (abbreviation , author , title , yearofpub) {
  this-> namemagzine = namemagzine;
  this-> numbofmagzine= numbofmagzine;
  this-> pagenumber= pagenumber;
   }

        string  getnamemagzine ()  {
         return namemagzine ;
         }
         void   setnamemagzine  (string namemagzine)  {
         this->namemagzine=namemagzine  ;
         }
         int   getnumbofmagzine  ()  {
           return numbofmagzine ;
         }
         void   setnumbofmagzine  (int numbofmagzine)  {
       this->numbofmagzine = numbofmagzine ;
         }
         int   getpagenumber   ()  {
         return pagenumber ;
         }
         void  setpagenumber  (int pagenumber)  {
         this->pagenumber=pagenumber ;
         }


virtual ~ article (){}
 string toString ()const {
  return "["+ abbreviation + "]"+ author + title + namemagzine + to_string(pagenumber)+ to_string (yearofpub)+ to_string (numbofmagzine);
 }

};



class CDs : public medium {

};

class Bibliography {
private :

    int sizeb ;
    int numofentries ;
    medium *myBibliography;

public :

Bibliography( int sizeb ){
 this->sizeb = sizeb;
 this->numofentries =0;
 myBibliography = new medium[sizeb];


}

Bibliography (const Bibliography& myBibliography){}

virtual ~ Bibliography(){}


int getsize (){

return sizeb ;

}
void setsize (int sizeb ){

this->sizeb=sizeb;

}

void insert ( medium* m ){
   if (numofentries==sizeb)
    cout << "it's is full ,you can't insert ";
   else
   myBibliography[numofentries]= *m;
    numofentries++;

}

 medium* operator [](string abbreviation  )
{
    for (int i=0; i< sizeb ;i++){
        if (abbreviation==myBibliography[i].getabbreviation() ){
             return &(this->myBibliography[i]);}
    }
    return nullptr;
}

  friend  ostream&  operator<< (ostream& os ,  Bibliography& b){
 for (int i =0 ;i < b.numofentries ;i++){
    os << ((&b.myBibliography[i])->toString())<<endl;
//&b.myBibliography[i].abbreviation << "]"<< b.myBibliography[i].author << ": "<<b.myBibliography[i].title
   }

   return os ;
 }


};


    void testBibliography()
{
 // create bibliography
 Bibliography myBibliography(10);
 Book* b1 = new Book("Ra01","Dietmar Ratz","Grundkurs Programmieren in Java",2001,"Hanser-Verlag");
 Book* b2 = new Book("Kr03","Guido Krueger","Handbuch der Java-Programmierung",2003,"Addison-Wesley");
 article* a1 = new article("Pa72","D. L. Parnas","On the Criteria To Be Used in Decomposing Systems intoModules",1972,"Communications of the ACM",15,1053);


 myBibliography.insert(b1);
 myBibliography.insert(b2);
 myBibliography.insert(a1);
cout << "Bibliography:" << endl << myBibliography; //display bibl.
 cout << endl << (*myBibliography["Pa72"]).toString() << endl;

}
int main()
{
 testBibliography();
 cin.sync();
 cin.get();
 return 0;

}
