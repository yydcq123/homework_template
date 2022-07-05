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
    return (unsigned short)((randSeed >> 16) % n)+1;
}

int* RandomList(int num ,RandomNumber rn)
{
    int* temp = new int[num];
    for(int a=0; a<num; a++){
        temp[a] = rn.randomInteger(100);
    }
    return temp;
}

void MergeLists(int* list,int* list1,int left,int mid, int right)
{
    int tmp[right - left + 1];  //用来存储本轮已经排序好的数组
    int tmp1[right - left + 1];
	int i = left, j = mid + 1;  // i是左端数组的起点，j是右端数组的起点
	int index = 0;

	while (i <= mid && j <= right) {
		if (((float)list[i]/(float)list1[i]) > ((float)list[j]/(float)list1[j])) {
			tmp[index] = list[i];
			tmp1[index++] = list1[i++];
		}
		else {
			tmp[index] = list[j];
			tmp1[index++] = list1[j++];
		}
	}

	// 可能左端数组还有剩下的数字
	while (i <= mid)
    {
        tmp[index] = list[i];
        tmp1[index++] = list1[i++];
    }
	// 可能右端数组还有剩下的数字
	while (j <= right)
    {
        tmp[index] = list[j];
        tmp1[index++] = list1[j++];
    }
	// tmp是排序好的数组，将tmp的内容拷贝到原始数组nums中
	index = 0;
	for (int k = left; k <= right; ++k) {
		list[k] = tmp[index];
		list1[k] = tmp1[index++];
	}
}

void MergeSort(int* list,int* list1,int left,int right)
{

    if (left < right) {
		int mid = left + ((right - left) >> 1);
		MergeSort(list,list1, left, mid);  // 拆分左端数组
		MergeSort(list,list1, mid + 1, right); //拆分右端数组
		MergeLists(list,list1, left, mid, right); // 将左右数组合并（在合并的过程排序）
	}
}

void KnapsackGreedy(int *w,int m,int *x,int n)
{
    for(int i=0;i<n;i++)
    {
        x[i]=0;
    }
    int cu = m;
    for(int i=0;i<n;i++)
    {
        if(w[i]>cu)
        {
            continue;
        }
        x[i]=1;
        cu=cu-w[i];
    }
}

int main()
{
    while(1){
        LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    unsigned long rs = 4312541; //随机数种子
    RandomNumber rn(rs);
    int * randm = NULL;
    int num=0;

    cout <<"请输入你想要获取的随机数的个数"<< endl;
    cin >> num;

    int w[num],v[num],C;
    C=200;

    randm = RandomList(num ,rn);
    for(int a=0; a<num; a++){
        w[a]=randm[a];
        cout << w[a] <<" ";
    }
    cout <<endl;


    int * randm1 = RandomList(num ,RandomNumber (12));
    for(int a=0; a<num; a++){
        v[a]=randm1[a];
        cout << v[a] <<" ";
    }
    QueryPerformanceCounter(&t1);

    MergeSort(v,w,0,num-1);
    KnapsackGreedy(w,C,v,num);

    QueryPerformanceCounter(&t2);
    cout << "Use Time:" << (double)((t2.QuadPart - t1.QuadPart) * 1000000.0 / tc.QuadPart) << "μs" << endl;
    for(int a=0; a<num; a++){
        cout << v[a] <<"--"<<w[a]<<"  ";
    }
    }

    return 0;
}
