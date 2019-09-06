#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int main(){
int n=10;
float a;
float x[n],y[n];
for(int i=0;i<n;i++){
x[i] = 1.0;
}

long double ym=0.0,ev;
do{
for(int i=0;i<n;i++){
y[i]=0.0;
for(int j=i-2;j<i+3;j++){
if(j<0 || j>=n) continue;
a=4./pow(2.,abs(i-j));
y[i] = y[i]+a*x[j];
}
}
ev=ym;
for(int i=1;i<n;i++){
ym=ym+y[i]*y[i];
}
ym=sqrt(ym);
for(int i=0;i<n;i++){
x[i]=y[i]/ym;
}
cout<<ym<<" :: (";
for(int i=0;i<n;i++){
cout<<x[i]<<" ,";
}
cout<<")"<<endl;
}while(abs(1-ev/ym)>10e-8);
cout<<"Largest Eigenvalue = "<<ym<<endl;


return 0;
}

