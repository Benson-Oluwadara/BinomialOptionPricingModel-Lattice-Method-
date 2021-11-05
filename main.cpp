#include <iostream>
#include"BinomialMethod.h"

#include"Lattice.h"
#include"Lattice.cpp"
#include"Data.h"
using namespace std;

int main() {
    /*   double st,k,r,t,v,deltaT;
       int b;
       char c,d;
       cout<<"Enter Stock Price:";
       cin>>st;
       cout<<"Enter Strike Price:";
       cin>>k;
       cout<<"Enter Risk Free Rate:";
       cin>>r;
       cout<<"Enter Number of Branches";
       cin>>b;
       cout<<"Enter Time in Months";
       cin>>t;
       deltaT=((t/12)/b);
       cout<<"Enter Option Type(p/c)";
       cin>>c;
       cout<<"Enter American/Europen(A/E)";
       cin>>d;
   */

    BinomialMethod bm;
    bm.Interface(50, 50, 0.10, 0.0833, 0.40, 5, 'p', 'E');
    cout << "FORWARD INDUCTION:" << endl;
    bm.ForwardInduction();
    bm.print();
    cout <<endl<<"BACKWARD INDUCTION:" << endl;
    bm.BackwardInduction();
    bm.print();
    cout << endl;
    

    //cout << endl;
    //bm.print();

    return 0;
}
