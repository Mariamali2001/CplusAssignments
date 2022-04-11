#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


const double PI=3.1415926;
const double G=9.81;

double radians (double angle);
double width (double speed, double angle);
double height (double speed, double angle);
double duration (double speed, double angle);

int main () {
    char jn = 'n';

    double v = 0;
    double alpha = 0;

    do {
        // output title
         cout << "\n Sschfer Litter";
         cout << "\n ============= \n" << endl;

         // Request parameters
         cout << "Throwing speed in m / s:";

         if (! (cin >> v)) {
            cerr << "Incorrect entry!" << endl;
            exit (1);
         }

         cout << "Throwing angle in degrees:";
         if (! (cin >> alpha)) {
            cerr << "Incorrect entry!" << endl;
            exit (1);
         }

         // Results output
         cout << "throwing distance:" << width (v, alpha);
         cout << "\n height:" << height (v, alpha);
         cout << "\n Duration:" << duration (v, alpha) << endl;

         // continue
         cout << "\n Continue?" << endl;
         if (! (cin >> jn)) {
            cerr << "Incorrect entry!" << endl;
            exit (1);
         }

    } while (jn == 'j');

    return 0;
}


double radians (double degrees) {
    return (2.0 * PI * degrees / 360.0);
}

double width (double speed, double angle) {
    return (pow (speed, 2) / G * sin (radians (2 * angle)));
}

double height (double speed, double angle) {
    return (pow (speed, 2.0) / (2.0 * G) * sin (radians (angle)) * sin (radians (angle)));
}

double duration (double speed, double angle) {
    return ((2 * speed) / G * sin (radians (angle)));
}



/*#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

double pi =3.1415;
double G = 9.81;
double toRadians (double degrees );

 double Distance (double v , double alpha );
int main()
{


cout << " please enter the initial speed ";
double v;
cin >> v;

cout << " please enter the initial angle  ";
double alpha;
cin >> alpha;

  /*for (int i =1 ; i < s.length (); i++)
    {

    if (s[i]==s[i-1]){
       res =' ';

    }

    else {
       res = s[i];
       cout << res ;
    }
  }

  cout << " throwing distance : "<< Distance (v,toRadians(alpha));

    return 0;


}


double toRadians (double degrees ){
double  rads = degrees*(pi/180);

  return rads ;



}

double Distance (double v , double alpha ){
 double W = (pow(v^2))/G * sin (2*alpha);

   return W;
}
*/
