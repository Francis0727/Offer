#include <iostream>
#include <initializer_list>
#include <iterator>
#include <list>

// 函数功能: 用于判断某个数是否为偶数
bool func(int num){
    return ((num & 1) == 0);
}

void ReorderOddEvent(int* pData,unsigned int length,bool(*func)(int)){
    if (pData == NULL || length == 0){
        return ;
    }
    
    int* pBegin = pData;
    int* pEnd = pData + length - 1;
    while (pBegin < pEnd){
        while (pBegin < pEnd && !func(*pBegin)){
            ++pBegin;
        }
        
        while (pBegin < pEnd && func(*pEnd)){
            --pEnd;
        }
        
        if (pBegin < pEnd){
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
        
    }
    
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,11,10};
    ReorderOddEvent(arr,sizeof(arr)/sizeof(arr[0]),func);
    for (int cnt = 0; cnt < sizeof(arr)/sizeof(arr[0]);++cnt){
        std::cout << arr[cnt] << " ";
    }std::cout << std::endl;
    
    return 0;
}