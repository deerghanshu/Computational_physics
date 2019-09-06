#include<iostream>
#include<cmath>
#include<fstream>
#define pi acos(-1.0)
using namespace std;

int main(){
int n = 100000;
int x[n],w[n], m = 1048579, c = 4, a = 1023;
x[0] = 51555, w[0] = 51100;
for(int i=1;i<n;i++){
x[i] = (a*x[i-1]+c)%m;
w[i] = (a*w[i-1]+c)%m;
}

float y[n],z[n],v[n],u[n];
for(int i=0;i<n;i++){
y[i] = float(x[i])/(m-1);
v[i] = float(w[i])/(m-1);
z[i] = float(rand())/RAND_MAX;
u[i] = float(rand())/RAND_MAX;
}

ofstream f;
f.open("rand");
for(int i=0;i<n-1;i++)
f<<y[i]<<"\t"<<v[i]<<"\n";

ofstream g;
g.open("pi");
float d=0,e=0;
for(int i=0;i<n-1;i++){
if(pow(y[i],2)+pow(v[i],2)<=1.0) d=d+1;
if(pow(z[i],2)+pow(u[i],2)<=1.0) e=e+1;
g<<i<<" "<<d*4.0/(i+1)<<" "<<e*4.0/(i+1)<<" "<<" "<<pi<<"\n";
}

return 0;
}

