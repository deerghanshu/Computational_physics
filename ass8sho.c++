#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;


int main(){

ofstream f1;
f1.open("sho1"); 

double T = 2*acos(-1.0);

//-----RK4-----// 
double x = 1.0 , t = 0.0 , p = 0.0 , h = 0.02*T , x0 = 1.0 ,p0 = 0.0;
double x1,x2,x3,x4,p1,p2,p3,p4;
while(t <= 20){
double e = 0.5*(pow(p,2.0) + pow(x,2.0));
f1 << t/T << " " << x << " " << p << " " << e << "\n";
x1 = p;
p1 = -x;
x2 = p + (p1*h/2.0);
p2 = -(x+(x1*h/2.0));
x3 = p + (p2*h/2.0);
p3 = -(x+(x2*h/2.0));
x4 = p + (h*p3);		
p4 = -(x+(h*x3));
x = x0 + (h*((x1+(2.0*x2)+(2.0*x3)+x4)/6.0));
p = p0 + (h*((p1+(2.0*p2)+(2.0*p3)+p4)/6.0));
t = t + h; 
x0 = x;
p0 = p;
}


//-----Euler's Method-----//
ofstream f2;
f2.open("sho2");

x=1.0,p=0.0,t=0.0;
while(t <= 20){
f2 << t/T <<" "<< x << " "<< p <<" "<< 0.5*(pow(p,2.0) + pow(x,2.0)) << endl;
double p0 = p , x0 = x;
p = p0 - x0 * h;
x = x0 + p0 * h;
t = t + h;
}

return 0;
}
