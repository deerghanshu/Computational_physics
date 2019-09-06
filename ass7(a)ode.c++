#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

float dy(float x, float y);
float ye(float x);


int main(){
float y;
float h=0.5;

//-----Exact-----//
ofstream f1;
f1.open("exact");
float x=0.0;
do{
f1 << x<<" "<<ye(x) <<endl;
x=x+h;
}while(x<=4.0);
f1.close();

//-----Euler's Method-----//
ofstream f2;
f2.open("euler");
x=0.0,y=2.0;
do{
f2 << x<<" "<<y << endl;
y = y + dy(x,y)*h;
x=x+h;
}while(x<=4.0);
f2.close();

//-----Midpoint Method-----//
ofstream f3;
f3.open("midpt");
int c=0;
x=0.0,y=2.0;
do{
f3 <<x<<" "<< y <<endl;
float y1 = y + dy(x,y)*h/2.0;
y = y + dy(x+h/2.0,y1)*h;
x=x+h;
}while(x<=4.0);
f3.close();

//-----Heun's Method-----//
ofstream f4;
f4.open("heun");
x=0.0,y=2.0,h=0.5;
do{
f4 <<x<<" "<< y <<endl;
float y0=y,x0=x;
y = y0 + dy(x0,y0)*h;
x=x+h;
y = y0 + (dy(x0,y0)+dy(x,y))*h/2.0;
}while(x<=4.0);
return 0;
}

float dy(float x,float y){
return 4*exp(0.8*x) - 0.5*y;
}

float ye(float x){
return 4*(exp(0.8*x)-exp(-0.5*x))/1.3 + 2.0*exp(-0.5*x);
}



