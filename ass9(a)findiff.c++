#include <iostream>

using namespace std;

int main(){

double h = 0.01,T0=40,T10=200,Ta=20; 
double x0 = 0, l=10, dx= 2;
int np;
np = (l-x0)/dx+1;
cout << "No. of points " << np << endl;
int dim = np-2;
double A[dim][dim];

double b1,b2,b3;
b1 = h*(dx*dx)*Ta + T0;   
b2 = h*(dx*dx)*Ta;
b3 = h*(dx*dx)*Ta + T10;

double midwt = 2 + h*dx*dx;

//make A 
for(int i=0;i<dim;i++)
{
for(int j=0;j<dim;j++){
if(i==j) A[i][j] = midwt;
else if(i+1==j || j+1==i) A[i][j] = -1;
else A[i][j] = 0;
cout << A[i][j] << "      ";
}
cout << endl;
}

//Thomas Algorithm

//store
double e[dim],f[dim],g[dim],r[dim],x[dim];
for(int i=0;i<dim-1;i++)
e[i+1] = A[i+1][i];
for(int i=0;i<dim-1;i++)
g[i] = A[i][i+1];
for(int i=0;i<dim;i++)
f[i] = A[i][i];
for(int i=1;i<dim-1;i++)
r[i] = b2;
r[0] = b1;
r[dim-1] = b3;
//store

//****************************
cout << "Augmented " << endl;
for(int i=0;i<dim;i++){
for(int j=0;j<dim;j++){
cout << A[i][j] << "   ";
}
cout << r[i] << endl;
}
//*********************
//decomposition
for(int k=1;k<dim;k++)
{
e[k] = e[k]/f[k-1];
f[k] = f[k] - e[k]*g[k-1];
}

for(int k=1;k<dim;k++)
{
r[k] = r[k] - e[k]*r[k-1];
}

x[dim-1] = r[dim-1]/f[dim-1];
for(int k=dim-2;k>=0;k--)
x[k] = (r[k] - g[k]*x[k+1])/f[k];

for(int i=0;i<dim;i++)
cout << x[i] << endl;
return 0;
}
