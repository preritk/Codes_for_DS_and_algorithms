#include<bits/stdc++.h>
using namespace std;

long series[500] = {0};
int fibo(int N)
{
    if(series[N-1] == 0)
    {
        if(N<=2)
        {
            series[N-1] = 1;
        }
        else
        {
            series[N-1] = fibo(N-1)+fibo(N-2);
        }
    }
    return series[N-1];
}

int main(void)
{
    int N;
    cout<<"Enter element number to be printed: "<<endl;
    cin>>N;
    cout<<"\n\nThis number is: "<<fibo(N)<<endl;
    return 0;
}
