#include <iostream>

using namespace std;

int counter1=0;
int counter2=0;

int DAC_f(int n)
{
    if(n==1||n==2)
    {
        return 1;
    }else
    {
        counter1+=1;
        return DAC_f(n-1)+DAC_f(n-2);
    }
}

int DP_f(int n)
{
    int f[n+1];
    for(int i=1;i<=n;i++)
    {
        if(i==0||i==1)
        {
            f[i]=1;
        }else
        {
            counter2+=1;
            f[i]=f[i-1]+f[i-2];
        }
    }
}

int main()
{
    while(1)
    {
    counter1=0;
    counter2=0;
    int n=0;
    cout<<endl<<"请输入n的值：";
    cin>>n;
    DAC_f(n);
    DP_f(n);
    cout<<"使用分治算法的加法次数为："<<counter1<<endl<<"使用动态规划算法的加法次数为："<<counter2;

    }

    return 0;
}
