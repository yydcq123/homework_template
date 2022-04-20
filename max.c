#include <stdio.h>


int main(int argc,char **args){
    int list[7]={5,1,2,3,7,14,6};
    int max=-1;
        //beacuse the result of sizeof is byte,a int is consisted by four byte 
        for(int i=0;i<sizeof(list)/4;i++){
            if(list[i]>max){
                max=list[i];
            }
        }
    printf("%d\n",max);
    return 0;
}
