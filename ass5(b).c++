#include <iostream>
#include <iomanip>
#include <math.h>

#define TOL 10e-8

using namespace std; 

void inv(double A[][10],double A_inv[][10]){
int n=10;
for(int i=0;i<n;i++){
long double tmp=A[i][i];
for(int j=0;j<n;j++){
A_inv[i][j]=A_inv[i][j]/tmp;
A[i][j]=A[i][j]/tmp;
}
for(int k=0;k<n;k++){
if(k!=i){
tmp = A[k][i];
for(int j=0;j<n;j++){
A_inv[k][j] = A_inv[k][j] - tmp*A_inv[i][j];
A[k][j] = A[k][j] - tmp*A[i][j];
}
}
}
}
}

double Power(double A[][10]){
double x0[] = {1,1,1,1,1,1,1,1,1,1}; 
int n = 10;
double eval_new=1,eval_old=1,e;
double x_next[n];
do{

for(int i=0;i<n;i++){
x_next[i] = 0;
for(int j=0;j<n;++j){
x_next[i]+=A[i][j]*x0[j]; 
}
}

float  max = 0;
for(int i=0;i<n;i++)
max += pow(x_next[i],2.0);

max= sqrt(max);

for(int i=0;i<n;++i)
x0[i] = x_next[i]/max;

eval_old = eval_new;
eval_new = max;

//for(int i=0;i<n;++i)
//cout << x0[i] << endl;
//cout << endl << endl;


e = (eval_new-eval_old)/eval_old;
//cout << eval_new;
}while(abs(e)>TOL);
return eval_new;
}//POWER

int main(){
std::cout << setprecision(8); 

int n = 10;

double A[10][10];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
A[i][j] = double(int(4.0/pow(2,abs(i-j))));
}
}

cout << Power(A) << endl;

double A_inv[10][10];
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i!=j) A_inv[i][j] = 0 ;
else A_inv[i][j] = 1;
}
}

inv(A,A_inv);
/*for(int i=0;i<3;++i){
for(int j=0;j<3;++j){
cout << A_inv[i][j];
}
cout << endl;
}*/
cout << 1/Power(A_inv);

return 0;
}



