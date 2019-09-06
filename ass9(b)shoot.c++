#include <iostream>
#include <fstream>

using namespace std;

double fT(double z){return z;}
double fz(double T){return 0.01*(T-20.0);}

double rk4(double z0,double T0,int flag){
ofstream f0;
ofstream f1;
ofstream f2;
if(flag==0){
f0.open("shoot0");}
if(flag==1){
f1.open("shoot1");}
if(flag==2){
f2.open("shoot2");}
double h = 0.5,x=0.0,T=T0,z=z0;
double k1T,k2T,k3T,k4T;
double k1z,k2z,k3z,k4z;
while(x<=10.0){
k1T = fT(z);
k1z = fz(T);
k2T = fT(z+0.5*k1z*h);
k1z = fz(T+0.5*k1T*h);
k3T = fT(z+0.5*k2z*h);
k3z = fz(T+0.5*k2T*h);
k4T = fT(z+k3z*h);
k4z = fz(T+k3T*h);

T = T + (1.0/6.0)*(k1T+2*k2T+2*k3T+k4T)*h;
z = z + (1.0/6.0)*(k1z+2*k2z+2*k3z+k4z)*h;
x = x + h;
if(flag==1){
f1<< x << " "<< z << "  "<<  T << endl;}
else if(flag==0){
f0<< x << " "<< z << "  "<<  T << endl;}
else{
f2<< x << " "<< z << "  "<<  T << endl;}

}
return T;
}

int main(){

double z1,z2,z0,T0=40.0;

z1 = 10.0;
z2 = 20.0;
double T1 =  rk4(z1,T0,0);
double T2 =  rk4(z2,T0,2);

z0 = z1 + (z2-z1)*(200.0-T1)/(T2-T1);

cout << "Initial conditions : " << "T0 = 40.0  z0 = " << z0<<"\n";  

cout << rk4(z0,T0,1)<<"\n";

return 0;

}
