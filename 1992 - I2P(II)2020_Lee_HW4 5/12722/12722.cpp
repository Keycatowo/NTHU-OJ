#include "function.h"
#define MAX_INDEX 92    // 1,1�}�l���O���ƦC�̦h��93���٦bint64��
#include <cstdint>

using namespace std;
bool preprocessed = false;
int64_t series[MAX_INDEX];

void init(){
    if(preprocessed == false){
        preprocessed = true;
        series[0]=1;
        series[1]=1;
        for(int i=2;i<MAX_INDEX;i++){
            series[i] = series[i-1] + series[i-2];
        }

    }
}

void oj::Fib::setBase(const int x, const int y){
    a0 = x;
    a1 = y;
    init();
}


int64_t oj::Fib::operator[](int k){
    if (k==0){
        return a0;
    }
    else if (k==1){
        return a1;
    }
    else{
        if(k>(MAX_INDEX+1))
        // �]���D�ثO�Ҧbint64�̭����d��
        // �p�G�W�L93���٦��n�D����
        // �@�w�O0,0�}�l���ƦC
            return 0;
        return (series[k-2]*a0 + series[k-1]*a1);
    }
}



