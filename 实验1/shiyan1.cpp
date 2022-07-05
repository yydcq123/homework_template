#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


long long int count=0;
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
    return (unsigned short)((randSeed >> 16) % n);
}

int* RandomList(int num ,RandomNumber rn)
{
    int* temp = new int[num];
    for(int a=0; a<num; a++){
        temp[a] = rn.randomInteger(10000);
    }
    return temp;
}


void BubbleSort (int* list,int num)
{
    int numberOfPairs = num;
    bool swappedElements = true;
    while (swappedElements)
    {
        numberOfPairs = numberOfPairs-1;
        swappedElements = false;
        for(int i = 0;i < num; i++)
        {
            count+=1;
            list[num+1]+=1;
            if(list[i]>list[i+1])
            {
                swap(list[i],list[i+1]);
                swappedElements = true;
            }
        }
    }
}

void MergeLists(int* list,int left,int mid, int right,int num)
{
    int tmp[right - left + 1];  //用来存储本轮已经排序好的数组
	int i = left, j = mid + 1;  // i是左端数组的起点，j是右端数组的起点
	int index = 0;

	while (i <= mid && j <= right) {
		if (list[i] < list[j]) {
			tmp[index++] = list[i++];
		}
		else {
			tmp[index++] = list[j++];
		}
		list[num]+=1;
	}

	// 可能左端数组还有剩下的数字
	while (i <= mid)
    {
        tmp[index++] = list[i++];
        list[num]+=1;
    }
	// 可能右端数组还有剩下的数字
	while (j <= right)
    {
        tmp[index++] = list[j++];
        list[num]+=1;
    }
	// tmp是排序好的数组，将tmp的内容拷贝到原始数组nums中
	index = 0;
	for (int k = left; k <= right; ++k) {
		list[k] = tmp[index++];
	}
}

void MergeSort(int* list,int left,int right,int num)
{

    if (left < right) {
		int mid = left + ((right - left) >> 1);
		MergeSort(list, left, mid,num);  // 拆分左端数组
		MergeSort(list, mid + 1, right,num); //拆分右端数组
		MergeLists(list, left, mid, right,num); // 将左右数组合并（在合并的过程排序）
	}

}

void QuickSort(int* list, int _left, int _right,int num) {
    int left = _left;
    int right = _right;
    int temp = 0;
    if (left < right) {   //待排序的元素至少有两个的情况
        list[num]+=1;
        temp = list[left];  //待排序的第一个元素作为基准元素
        while (left != right) {   //从左右两边交替扫描，直到left = right
            list[num]+=1;
            while (right > left&& list[right] >= temp)
                {
                    list[num]+=1;
                    right--;        //从右往左扫描，找到第一个比基准元素小的元素
                }
            list[left] = list[right];  //找到这种元素arr[right]后与arr[left]交换

            while (left < right && list[left] <= temp)
                {
                    list[num]+=1;
                    left++;         //从左往右扫描，找到第一个比基准元素大的元素
                }
            list[right] = list[left];  //找到这种元素arr[left]后，与arr[right]交换

        }
        list[right] = temp;    //基准元素归位
        QuickSort(list, _left, left - 1,num);  //对基准元素左边的元素进行递归排序
        QuickSort(list, right + 1, _right,num);  //对基准元素右边的进行递归排序
    }
}

int main()
{
    unsigned long rs = 4341; //随机数种子
    RandomNumber rn(rs);
    int * randm = NULL;
    int num=0;

    cout <<"请输入你想要获取的随机数的个数"<< endl;
    cin >> num;
    randm = RandomList(num ,rn);
    for(int a=0; a<num; a++){
        cout << randm[a] <<" ";
    }
    cout <<endl;

    int blist[num+1]={0};
    int mlist[num+1]={0};
    int qlist[num+1]={0};

    for(int a=0; a<num; a++){
        mlist[a]=randm[a];
        qlist[a]=randm[a];
        blist[a]=randm[a];
    }
    BubbleSort(blist,num-1);
    MergeSort(mlist,0,num-1,num);
    QuickSort(qlist,0,num-1,num);

    cout<<"冒泡排序结果如下："<<endl;
    /*for(int a=0; a<num; a++){
        cout<<blist[a]<<" ";
    }
    */
    cout<<endl<<"比较次数为："<<count<<endl;

    cout<<"归并排序结果如下："<<endl;
    /*for(int a=0; a<num; a++){
        cout<<mlist[a]<<" ";
    }
    */cout<<endl<<"比较次数为："<<mlist[num]<<endl;

    cout<<"快速排序结果如下："<<endl;
    /*for(int a=0; a<num; a++){
        cout<<qlist[a]<<" ";
    }
    */cout<<endl<<"比较次数为："<<qlist[num]<<endl;

    return 0;
}


