#include <iostream>
using namespace std;
char apassword [26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y', 'Z'};
char atext [26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y', 'z'};
void encryption (string text , string password);

void decryption (string encrypt , string password);


 void encryption (string text , string password)

    {

    for(int i=0 ;i<text.length();i++){
        int index=0;
        if (text[i]==32){
            cout << ' ';
            continue;
        }
        for (int j=0;j<26;j++){
        if (text[i]==atext[j]){
            index+=j;
            break;
        }
        }
        for (int k=0;k<26;k++){
        if (password[i]==apassword[k]){
            index+=k;
            if(index>25)
                index-=26;
            cout << apassword[index];
            break;
        }
    }
}
    }


       void decryption (string encrypt , string password) {

   for (int i =0 ;i<encrypt.length();i++){
    int index=0;
    if (encrypt[i]==32){
         cout << ' ';
            continue;
        }

       for (int j=0;j<26;j++){
        if (password[i]==apassword[j]){
            index+=j;
            break;
        }
        }
        for (int k=0;k<26;k++){
        if (encrypt[i]==encrypt[k]){
            index-=k;
            if(index<0)
                index+=26;
            cout << atext[index];
            break;
        }
    }
}
    }



int main(){

    string text;
    string  decryption=" ";
     string encrypt=" ";
    cout<< "please enter your text "<< endl;
    getline(cin,text);

    string password;
    cout<< "please enter your password "<< endl;
    getline(cin,password );

    encryption(text,password);

    //decryption(encrypt ,password);


/*char x;

    if (toupper(x))
        decryption();
    else
        encryption() ;
*/


 /*if (text==text.toUpperCase()){
        decryption(encrypt,password);

    }
else {
    encryption(text,password);
}*/

    return 0;
}



