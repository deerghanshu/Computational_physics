#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double f(double x, double y){return 2.0*x*y + 2.0*x - pow(x,2) - 2.0*pow(y,2) + 72.0;} 
double a=0.0, b=8.0;

double if1(double y){
return (b-a)*(f(b,y)+f(a,y))/2.0;
}

double if2(double y){
return (b-a)*(f(b,y)+4*f((a+b)/2.0,y)+f(a,y))/6.0;
}

double if3(double y){
return (b-a)*(f(b,y)+3*f((2*b+a)/3.0,y)+3*f((2*b+a)/3.0,y)+f(a,y))/8.0;
}

int main(){

std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
std::cout.precision(6);

double i1,i2,i3;
double c=0.0, d=6.0;
//Trapezoidal Rule
i1 = (d-c)*(if1(d)+if1(c))/2.0;
cout << "Trapezoidal Rule: " << i1/((b-a)*(d-c)) << "\n";

//Simpson 1/3 Rule
i2 = (d-c)*(if2(d)+4*if2((c+d)/2.0)+if2(c))/6.0;
cout << "Simpson 1/3 Rule: " << i2/((b-a)*(d-c)) << "\n";

//Simpson 3/8 Rule
i3 = (d-c)*(if3(d)+3*if3((2*c+d)/3.0)+3*if3((c+2*d)/3.0)+if3(c))/8.0;
cout << "Simpson 3/8 Rule: " << i3/((b-a)*(d-c)) << "\n";

return 0;
}
