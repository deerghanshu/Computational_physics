#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double f(double x, double y){return 2.0*x*y + 2.0*x - pow(x,2) - 2.0*pow(y,2) + 72.0;} 
double a=0.0, b=8.0;
/*
double if1(double y){
return (b-a)*(f(b,y)+2*f((a+b)/2.0,y)+f(a,y))/4.0;
}

double if2(double y){
return (b-a)*(f(b,y)+4*f((a+b)/2.0,y)+f(a,y))/6.0;
}

double if3(double y){
return (b-a)*(f(b,y)+3*f((2*b+a)/3.0,y)+3*f((2*b+a)/3.0,y)+f(a,y))/8.0;
}*/

double if1(double y,int n){
double s1 = 0;
double h = (b-a)/n; 
for(int i=1; i <= n-1; i++){
s1 = s1 + f(a+i*h,y); 
}
return (h/2)*(f(a,y)+ f(b,y) + (2*s1));
}

double if2(double y,int n){
double s1 = 0,s2 = 0;
double h = (b-a)/n; 
for(int i=1; i <= n-1; i++){
if(i%2 == 0)
s1 = s1 + f(a+i*h,y); 
else
s2 = s2 + f(a+i*h,y);
}
return (h/3)*(f(a,y)+ f(b,y) + (2*s1) + (4*s2));
}

double if3(double y,int n){
double s1 = 0,s2 = 0;
double h = (b-a)/n; 
for(int i=1; i <= n-1; i++){
if(i%3 == 0)
s1 = s1 + f(a+i*h,y); 
else
s2 = s2 + f(a+i*h,y);
}
return (3*h/8)*(f(a,y)+ f(b,y) + (2*s1) + (3*s2));
}


int main(){

std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
std::cout.precision(6);

int n;
double i1,i2,i3;
double c=0.0, d=6.0;
double h,s1,s2; 
//Trapezoidal Rule
//i1 = (d-c)*(if1(d)+2*if1((c+d)/2.0)+if1(c))/4.0;
cout << "Trapezoidal Rule\n";
cout<<"Input n: ";
cin>>n;
s1 = 0,h = (d-c)/n;
for(int i=1; i <= n-1; i++){
s1 = s1 + if1(c+i*h,n); 
}
i1 = (h/2)*(if1(c,n)+ if1(d,n) + (2*s1));
cout<< i1/((b-a)*(d-c)) << "\n";

//Simpson 1/3 Rule
//i2 = (d-c)*(if2(d)+4*if2((c+d)/2.0)+if2(c))/6.0;
cout << "\nSimpson 1/3 Rule\n";
cout<<"Input n(even): ";
cin>>n;
s1 = 0,s2 = 0,h = (d-c)/n;
for(int i=1; i <= n-1; i++){
if(i%2 == 0)
s1 = s1 + if2(c+i*h,n); 
else
s2 = s2 + if2(c+i*h,n);
}
i2 = (h/3)*(if2(c,n)+ if2(d,n) + (2*s1) + (4*s2));
cout<< i2/((b-a)*(d-c)) << "\n";

//Simpson 3/8 Rule
//i3 = (d-c)*(if3(d)+3*if3((2*c+d)/3.0)+3*if3((c+2*d)/3.0)+if3(c))/8.0;
cout << "\nSimpson 3/8 Rule\n";
cout<<"Input n(multiple of 3): ";
cin>>n;
s1 = 0,s2 = 0,h = (d-c)/n;
for(int i=1; i <= n-1; i++){
if(i%3 == 0)
s1 = s1 + if3(c+i*h,n); 
else
s2 = s2 + if3(c+i*h,n);
}
i3 = (3*h/8)*(if3(c,n)+ if3(d,n) + (2*s1) + (3*s2));
cout<< i3/((b-a)*(d-c)) << "\n";

return 0;
}
