#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
using namespace std;

int main(){
ifstream infile;
infile.open("5a");
int n=3;
long double a[n][n],b[n][n],x[n],y[n],x1[n],y1[n];
for(int i=0;i<n;i++){
x[i]=1.0;
x1[i]=1.0;
for(int j=0;j<n;j++){
infile>>a[i][j];
b[i][j]=a[i][j];
}
}
long double ai[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
ai[i][j]=0.0;
if(i==j) ai[i][j]=1.0;
}
}
//INVERSE
for(int i=0;i<n;i++){
long double tmp=b[i][i];
for(int j=0;j<n;j++){
ai[i][j]=ai[i][j]/tmp;
b[i][j]=b[i][j]/tmp;
}
for(int k=0;k<n;k++){
if(k!=i){
tmp = b[k][i];
for(int j=0;j<n;j++){
ai[k][j] = ai[k][j] - tmp*ai[i][j];
b[k][j] = b[k][j] - tmp*b[i][j];
}
}
}
}
/*for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<ai[i][j]<<" ";
}
cout<<endl;
}*/


ofstream outfile;
outfile.open("res.dat");
outfile<<setprecision(10);
//Largest Eigenvalue
long double xmax=0.0,ev;
do{
for(int i=0;i<n;i++){
y[i]=0;
for(int j=0;j<n;j++){
y[i]=y[i]+a[i][j]*x[j];
}
}
for(int i=0;i<n;i++){
x[i]=y[i];
}
ev=xmax;
xmax=x[0];
for(int i=1;i<n;i++){
if(abs(x[i])>abs(xmax)) xmax=x[i];
}
outfile<<xmax<<" :: (";
for(int i=0;i<n;i++){
x[i]=x[i]/xmax;
outfile<<x[i]<<" ,";
}
outfile<<")"<<endl;
}while(abs(1-ev/xmax)>10e-8);
outfile<<endl<<"Largest Eigenvalue = "<<xmax<<endl;
outfile<<endl;

//Smallest Eigenvalue
long double xmax1=0.0,ev1;
do{
for(int i=0;i<n;i++){
y1[i]=0;
for(int j=0;j<n;j++){
y1[i]=y1[i]+ai[i][j]*x1[j];
}
}
for(int i=0;i<n;i++){
x1[i]=y1[i];
}
ev1=xmax1;
xmax1=x1[0];
for(int i=1;i<n;i++){
if(abs(x1[i])>abs(xmax1)) xmax1=x1[i];
}
outfile<<xmax1<<" :: (";
for(int i=0;i<n;i++){
x1[i]=x1[i]/xmax1;
outfile<<x1[i]<<" ,";
}
outfile<<")"<<endl;
}while(abs(1-ev1/xmax1)>10e-8);
outfile<<endl<<"Smallest Eigenvalue = "<<1.0/xmax1<<endl;
return 0;
}
