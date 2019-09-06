#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;


float dfa0(float x, float a1){
return 1.0-exp(-a1*x);}

float dfa1(float x, float a0, float a1){
return a0*x*exp(-a1*x);}

float f(float x, float a0, float a1){
return a0*(1.0-exp(-a1*x));}

int main(){

float z[5][2],d[5],da[2];
float x[5] = {0.25, 0.75, 1.25, 1.75, 2.25};
float y[5] = {0.28, 0.57, 0.68, 0.74, 0.79};

float a0,a1;
a0 = 1.0;
a1 = 1.0;

do{

for(int i=0;i<5;i++){
z[i][0] = dfa0(x[i],a1);
z[i][1] = dfa1(x[i],a0,a1);
d[i] = y[i] - f(x[i],a0,a1);
}
float zt[2][5];
for(int i=0;i<5;i++){
zt[0][i] = z[i][0];
zt[1][i] = z[i][1];
}
float ztz[2][2];
for(int i=0;i<2;i++){
float s=0,t=0;
for(int j=0;j<5;j++){
s = s + zt[i][j]*z[j][0];
t = t + zt[i][j]*z[j][1];
}
ztz[i][0] = s;
ztz[i][1] = t;
}
//for(int i=0;i<2;i++)
//cout<<ztz[i][0]<<" "<<ztz[i][1]<<endl;

float ztzi[2][2];
float det = ztz[0][0]*ztz[1][1] - ztz[0][1]*ztz[1][0];
ztzi[0][0] = ztz[1][1]/det;
ztzi[0][1] = -ztz[1][0]/det;
ztzi[1][0] = -ztz[0][1]/det;
ztzi[1][1] = ztz[0][0]/det;

//cout<<det<<endl;
//for(int i=0;i<2;i++)
//cout<<ztzi[i][0]<<" "<<ztzi[i][1]<<endl;

float ztd[2]={0,0};
for(int i=0;i<5;i++){
ztd[0] = ztd[0] + zt[0][i]*d[i];
ztd[1] = ztd[1] + zt[1][i]*d[i];
}
//cout<<ztd[0]<<" "<<ztd[1]<<endl;
da[0] = da[1] = 0.0;
for(int i=0;i<2;i++){
da[0] = da[0] + ztzi[0][i]*ztd[i];
da[1] = da[1] + ztzi[1][i]*ztd[i];
}
//cout<<da[0]<<" "<<da[1]<<endl;

a0 = a0 + da[0];
a1 = a1 + da[1];

cout<<"( "<<a0<<" , "<<a1<<" )"<<"\n";
}while(abs(da[0]/a0)>0.00001);

ofstream f1;
f1.open("fit");
for(float k=0.0;k<=2.5;k+=0.01)
f1<<k<<"\t"<<f(k,a0,a1)<<"\n";


return 0;
}

