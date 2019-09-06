#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float dv(float x);
float dx(float v);
float xe(float t);


int main(){
float v,x;
float h=0.05;

//-----Exact-----//
ofstream f1;
f1.open("exact");
float t=0.0;
do{
f1 << t <<" "<<xe(t) <<endl;
t=t+h;
}while(t<=30.0);
f1.close();

//-----Euler's Method-----//
ofstream f2;
f2.open("euler");
x=1.0,v=0.0,t=0.0;
do{
f2 << t<<" "<<x << endl;
float v0=v,x0=x;
v = v0 + dv(x0)*h;
x = x0 + dx(v0)*h;
t=t+h;
}while(t<=30.0);
f2.close();

//-----Midpoint Method-----//
ofstream f3;
f3.open("midpt");
x=1.0,v=0.0,t=0.0;
do{
f3 <<t<<" "<< x <<endl;
float v0=v,x0=x,v1,x1;
v1 = v0 + dv(x0)*h/2;
x1 = x0 + dx(v0)*h/2;

v = v0 + dv(x1)*h;
x = x0 + dx(v1)*h;

t=t+h;
}while(t<=30.0);
f3.close();

//-----Heun's Method-----//
ofstream f4;
f4.open("heun");
x=1.0,v=0.0,t=0.0,h=0.05;
do{
f4 <<t<<" "<< x <<endl;
float t0=t,x0=x,v0=v;
float v1 = v0 + dv(x0)*h;
float x1 = x0 + dx(v0)*h;
t=t+h;
v = v0 + (dv(x0)+dv(x1))*h/2.0;
x = x0 + (dx(v0)+dx(v1))*h/2.0;
}while(t<=30.0);

return 0;
}

float dv(float x){
return -x;
}

float dx(float v){
return v;
}

float xe(float t){
return cos(t);
}



