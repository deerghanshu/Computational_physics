#include<iostream>
#include<fstream>
#include<cmath>
#define TOL 1e-10
using namespace std;

int main(){
int n=2;
float a[n][n];
ifstream infile;
infile.open("6a");
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
infile>>a[i][j];
}
}
ofstream outfile;
outfile.open("out.dat");
do{
int p=0,q=1;
float max=a[0][1];
for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
if(abs(a[i][j])>abs(max)){
max=a[i][j];
p=i;
q=j;
}
}
}
if(a[p][q]<TOL) break;
float rho,t,c,s;
rho = (a[q][q] - a[p][p])/(2*a[p][q]);
t=rho/(abs(rho)*(abs(rho)+pow((pow(rho,2)+1.0),0.5)));
c=1/pow((1.0+t*t),0.5);
s=c*t;
float d[n][n];
d[p][q]=0;
d[q][p]=0;
d[p][p]=pow(c,2)*a[p][p] + pow(s,2)*a[q][q] - 2*c*s*a[p][q];
d[q][q]=pow(s,2)*a[p][p] + pow(c,2)*a[q][q] + 2*c*s*a[p][q];
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
outfile<<"--Iteration--"<<endl;
for(int i=0;i<n;i++){
outfile<<a[i][i]<<" ";
}
outfile<<endl<<endl;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i==j && (i==p || i==q)) outfile<<c<<" ";
else if(i==j) outfile<<"1 ";
else if(i==p && j==q) outfile<<s<<" ";
else if(i==q && j==p) outfile<<-s<<" ";
else outfile<<"0 ";
}
outfile<<endl;
}
outfile<<endl;
}while(1);


return 0;
}



