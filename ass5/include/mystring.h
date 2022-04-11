#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std ;

 namespace  stringexercise {
    class mystring {
         private:
        size_t occupied; // number of characters
        size_t capacity; //	Amount of provisioned storage
        char *sequence;	 // Pointer to the beginning of the string
    public:
        // constructors
    	mystring();
        mystring(const char str[ ]);
        mystring( const std::string str );
        mystring(const mystring& source);
        virtual ~mystring( );

        // modifying member functions
        mystring& operator+=(const mystring& addend);
        mystring& operator+=(const char addend[ ]);
        mystring& operator+=(const char addend);

        mystring& operator=(const mystring& source);
        const char& operator[ ](size_t position) const;	 // Characters to Item
        char& operator[ ](size_t position);				 // Characters to Item


        // Constant member functions that do not change the state
        std::size_t length( ) const { return occupied; } // return number  of characters
        const char* c_str() const { return sequence; }	 // return as  C-string
        void swap(mystring&);							 // swap
        bool is_empty(){ return (occupied == 0); }		 // check whether empty

        // friend functions
        friend std::ostream& operator <<(std::ostream& outs, const mystring& source);

        friend bool operator==(const mystring& s1, const mystring& s2);
        friend bool operator!=(const mystring& s1, const mystring& s2);
        friend bool operator>=(const mystring& s1, const mystring& s2);
        friend bool operator<=(const mystring& s1, const mystring& s2);
        friend bool operator> (const mystring& s1, const mystring& s2);
        friend bool operator< (const mystring& s1, const mystring& s2);

    };

    // Prototype declarations for NON-MEMBER functions
    // for use in the context of the mystring class
    mystring operator+(const mystring& s1, const mystring& s2);
    mystring operator+(const mystring& s1, const char* s2 );
    mystring operator+(const char* s1, const mystring& s2);

    bool operator==(const mystring& s1, const mystring& s2);
    bool operator!=(const mystring& s1, const mystring& s2);
    bool operator>=(const mystring& s1, const mystring& s2);
    bool operator<=(const mystring& s1, const mystring& s2);
    bool operator> (const mystring& s1, const mystring& s2);
    bool operator< (const mystring& s1, const mystring& s2);

    std::ostream& operator<<(std::ostream& outs, const mystring& source);
    std::istream& operator>>(std::istream& ins, mystring& target);

} /* end namespace stringexercise */



#endif // MYSTRING_H
