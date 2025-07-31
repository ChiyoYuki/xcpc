#include<bits/stdc++.h>

using namespace std;

int main()
{
   	double x,y,z,w;
    cin>>x>>y>>z>>w;
    double a=-100.00;
    for(a;a<=99.999;a=a+0.001)
    {
        if(x*a*a*a+y*a*a+z*a+w==0)
        {
            printf("%.2lf ",a);
        }
        else if((x*a*a*a+y*a*a+z*a+w)*(x*(a+0.001)*(a+0.001)*(a+0.001)+y*(a+0.001)*(a+0.001)+z*(a+0.001)+w)<0)
        {
            printf("%.2lf ",a);
        }
	}
}