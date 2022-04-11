#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <time.h>

using namespace std;
int main(int argc, const char * argv[]) {
    srand((unsigned int ) time(0));
    cout << "warak kam 7aga tzakerha ybeh?";
    int n;
    cin >> n;
    cout << "etfaddal 2ool: "<< endl;
    string lliWaraya[n];
    for (int i = 0; i < n ; i++) {
        cin >> lliWaraya[i];
    }
    int result = rand() %n;
    cout << endl << "hnzaker: " << lliWaraya[result] << endl;

}






















/*#include<iostream>

using namespace std;

int main()
{
  int n ;
  cin >> n;


  int a[]=1000;


  int total=0 ;

   for (int k=0 k<n ;k++)
  {

      for (int m =0; m<n ;m++){
        if (a[k]< a[m]){
            swap(a[k],a[m]);
        }
      }
  }

  }
   cout << total<< endl;

}
*/
