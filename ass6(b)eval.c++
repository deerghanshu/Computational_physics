#include<iostream>
#include<fstream>
#include<cmath>
#define TOL 1e-10
using namespace std;
 
float sign(float b){
return (b>=0)?1.0 :-1.0;
}

int main(){
int n=4;
float a[n][n],a0[n][n];
ifstream infile;
infile.open("6b");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
infile>>a[i][j];
a0[i][j] = a[i][j];
}
}
float d[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
d[i][j] = a[i][j];
}
}
float r[n][n],id[n][n],r1[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
r[i][j]=(i==j)?1.0 :0.0;
id[i][j]=(i==j)?1.0 :0.0;
}
}
ofstream outfile;
outfile.open("out1.dat");
int e=0;

do{
int p,q;
float max=0.0;
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(abs(a[i][j])>abs(max)){
max=a[i][j];
p=i;
q=j;
}
}
}
if(abs(a[p][q])<TOL) break;
float rho,t,c,s;
rho = (a[q][q] - a[p][p])/(2.0*a[p][q]);
t=sign(rho)/(abs(rho)+pow((pow(rho,2.0)+1.0),0.5));
c=1.0/pow((1.0+t*t),0.5);
s=c*t;


for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
r1[i][j] = id[i][j];
}
}
r1[p][p] = c;
r1[q][q] = c;
r1[p][q] = s;
r1[q][p] = -s;


for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
float s1=0;
for(int k=0;k<n;k++){
s1 = s1+r[i][k]*r1[k][j];
}
r[i][j] = s1;
}
}


d[p][q]=0.0;
d[q][p]=0.0;
d[p][p]=pow(c,2.0)*a[p][p] + pow(s,2.0)*a[q][q] - 2.0*c*s*a[p][q];
d[q][q]=pow(s,2.0)*a[p][p] + pow(c,2.0)*a[q][q] + 2.0*c*s*a[p][q];
for(int j=0;j<n;j++){
if(j!=p && j!=q){
d[j][p] = c*a[j][p] - s*a[j][q];
d[p][j] = d[j][p];
d[j][q] = c*a[j][q] + s*a[j][p];
d[q][j] = d[j][q];
}
}
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
a[i][j] = d[i][j];
}
}
e=e+1;
outfile<<"--Iteration "<<e<<"--"<<endl;
for(int i=0;i<n;i++){
outfile<<a[i][i]<<" ";
}
outfile<<endl<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
outfile<<a[i][j]<<" ";
}
outfile<<endl;
}
outfile<<endl;
}while(1);

outfile<<"----Final Transformation Matrix----";
outfile<<endl<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
outfile<<r[i][j]<<" ";
}
outfile<<endl;
}
outfile<<endl<<endl;

/*
float rt[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
rt[i][j] = r[j][i];
}
}

float b[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
float s1=0;
for(int k=0;k<n;k++){
s1 = s1+a0[i][k]*r[k][j];
}
b[i][j] = s1;
}
}

cout<<"Final iteration transformed matrix"<<endl;
float ev[n][n];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
float s1=0;
for(int k=0;k<n;k++){
s1 = s1+rt[i][k]*b[k][j];
}
ev[i][j] = s1;
cout<<r1[i][j]<<" ";
}
cout<<endl;
}
*/
return 0;
}



