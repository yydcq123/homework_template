#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#pragma comment( lib,"winmm.lib" )
using namespace std;

const unsigned long maxshort = 65536L;
const unsigned long multiplier = 1194211693L;
const unsigned long adder = 12345L;
int counter=0;

class RandomNumber              //线性同余法随机数产生类
{
private:
    unsigned long randSeed;

public:
    RandomNumber(unsigned long s = 0);             //构造函数
    unsigned short randomInteger(unsigned long n); //产生0--n-1之间的随机整数
    double randomFloat(void);                      //产生[0,1)之间的随机实数
};

RandomNumber::RandomNumber(unsigned long s)
{
        //由用户定义随机数值
        randSeed = s;
}
/*
    产生0--n-1之间的随机整数，用线性同余计算的新种子高16位随机性好，将其右移16位
*/
unsigned short RandomNumber::randomInteger(unsigned long n)
{
    randSeed = multiplier * randSeed + adder;
    return (unsigned short)((randSeed >> 16) % n);
}

int* RandomList(int num ,RandomNumber rn)
{
    int* temp = new int[num];
    for(int a=0; a<num; a++){
        temp[a] = rn.randomInteger(100);
    }
    return temp;
}

int** KnapsackDP(int* w, int* v,int C,int n)
{
    int **m = 0;     //初始化一个二维数组
	m = new int*[n];   //建立包含row个指针的指针数组
	for (int i = 0; i < n; i++)
	{
		*(m + i) = new int[C];   //每个一维指针数组的长度都是col
	}
    for(int i=0;i < n;i++)
    {
        m[i][0]=0;
    }
    for(int i=0;i < C;i++)
    {
        m[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<C;j++)
        {
            m[i][j]=m[i-1][j];
            if(w[i]<j)
            {
                m[i][j]=max(m[i][j],m[i-1][j-w[i]]+v[i]);
            }
            /*if(i==n-1)
            {
                cout<<m[i][j]<<"-";
            }

        cout<<endl;*/
    }
    }
    return m;
}

int main()
{

    int Cs[]={200,400,800,2000};
    int ns[]={10,20,40,100,200,400,800,2000};
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    unsigned long rs = 42541; //随机数种子
    RandomNumber rn(rs);
    int * randm = NULL;
    int num=0;

    //cout <<"请输入你想要获取的随机数的个数"<< endl;
    //cin >> num;
    num=ns[j];
    int w[num],v[num],C;

    randm = RandomList(num ,rn);
    for(int a=0; a<num; a++){
        w[a]=randm[a];
        //cout << w[a] <<" ";
    }
    //cout <<endl;


    int * randm1 = RandomList(num ,RandomNumber (12));
    for(int a=0; a<num; a++){
        v[a]=randm1[a];
        //cout << v[a] <<" ";
    }


    int** m;
    //cout <<"请输入背包的容量：";
    //cin >> C;
    C=Cs[i];
    QueryPerformanceCounter(&t1);
    m=KnapsackDP(w,v,C,num);
    QueryPerformanceCounter(&t2);
    cout << "Use Time:" << (double)((t2.QuadPart - t1.QuadPart) * 1000000.0 / tc.QuadPart) << "μs" << endl;
        }
    }



    return 0;

}
