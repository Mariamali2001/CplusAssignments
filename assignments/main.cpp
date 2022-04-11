#include <iostream>
#include <string>


using namespace std ;


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

    public :
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


};
class Book : public medium
{
string publisher ;

 string  getpublisher  () const {
         return publisher ;
         }
    void   setpublisher (string publisher) {
        this-> publisher= publisher ;
        }

 Book (string abbreviation ,string author ,string title ,int  yearofpub , string publisher) : medium(abbreviation , author, title ,yearofpub) , Book(publisher)
{
   this->publisher= publisher ;

}
virtual ~ Book (){}
 string toString ()const {

 return "["+ abbreviation "]"+ author +":" + title + publisher + to_string(yearofpub);

}



};

class article :public medium {

    private :

    string namemagzine ;
    int  numbofmagzine ;
    int pagenumber ;

    public :
        string  getnamemagzine () const {
         return namemagzine ;
         }
         void   setnamemagzine  () const {
         this->namemagzine=namemagzine  ;
         }
         string  getnumbofmagzine  () const {
         return numbofmagzine ;
         }
         void   setnumbofmagzine  () const {
       this->numbofmagzine = numbofmagzine ;
         }
         string  getpagenumber   () const {
         return pagenumber ;
         }
         void  setpagenumber  () const {
         this->pagenumber=pagenumber ;
         }

   article(string abbreviation ,string author ,string title ,int  yearofpub ,
     string namemagzine ,int  numbofmagzine ,int pagenumber ) : medium (abbreviation , author , title , yearofpub) , article ( namemagzine ,  numbofmagzine , pagenumber){
 this-> namemagzine = namemagzine;
 this-> numbofmagzine= numbofmagzine;
 this-> pagenumber= pagenumber;
   }
virtual ~ article (){}
string toString ()const {
 return " ["+ abbreviation + "]"+ author + title + namemagzine + to_string(pagenumber)+ to_string (yearofpub)+ to_string (numbofmagzine);
}
};



class CDs : public medium {

};

class Bibligraphy {
private :
    struct Entry {
     string name ;
     long number ;

    };
    Entry * Bibligraphy ;
    int size ;
    int numofEntries ;

public :

Bibligraphy( int size ){
 this->size = size;
}

Bibligraphy (const Bibligraphy& myBibliography){}

virtual ~ Bibliography (){}


int getsize (){

return size ;

}
void setsize (int size ){

this->size=size;

}

void insert (){
   medium newmedium ;


}

friend long& operator [](string name )
{
   if (abbreviation == NULL)
        return nullptr ;
    else

   return *myBibliography ;

   return myBibliography +"["+ abbreviation +"]" ;


}

friend ostream& operator  << (ostream& os , const Bibliography& myBibliography){
   for (int i =0 ;i < myBibliography.numofEntries ;++i){
    os <<myBibliography.name << "[ " << myBibliography.abbreviation << "]"<< endl;

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
 Article* a1 = new Article("Pa72","D. L. Parnas","On the Criteria To Be Used in Decomposing Systems intoModules”,1972,"Communications of the ACM",15,1053);
 try {

 myBibliography.insert(b1);
 myBibliography.insert(b2);
 myBibliography.insert(a1);
 cout << "Bibliography:" << endl << myBibliography; //display bibl.
 cout << endl << (*myBibliography["Pa72"]).toString() << endl;
 }
 catch (Error f){
 cout << endl << f.getMessage() << endl;
 }
}
int main(int argc, char *argv[])
{
 testBibliography();
 cin.sync();
 cin.get();
 return 0;
}

