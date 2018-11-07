#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cmath>

char* reverseString(char* s) {
    //344.字符串反转
    int length=strlen(s);
    for(int i=0;i<length/2;i++) {
        s[i] ^= s[length-1-i];
        s[length-1-i] ^= s[i];
        s[i] ^= s[length-1-i];
    }
    return s;
}

int* twoSum(int* nums, int numsSize, int target) {
    //1.两数和
    int flag=0;
    int* answer;
    for(int i=0;i<numsSize-1;i++) {
        if(!flag) {
            for(int j=i+1;j<numsSize;j++) {
                if(nums[i]+nums[j]==target) {
                    flag=1;
                    answer=(int*)malloc(2*sizeof(int));
                    answer[0]=i;
                    answer[1]=j;
                    break;
                }
            }
        }
    }
    return answer;
}

int reverse(int x) {
    //7.整数反转
    int number;
    int sum=0;
    while(x!=0) {
        number = x % 10;
        x /= 10;
        //判断越界
        if (sum > INT_MAX/10 || (sum == INT_MAX / 10 && number > 7)) return 0;
        if (sum < INT_MIN/10 || (sum == INT_MIN / 10 && number < -8)) return 0;
        sum = sum*10 + number;
    }
    return sum;
}

double myPow(double x, long long n) {
    //乘方
    double s = x;
    x=1.;
    int i=0;
    if(s==1.) return 1.;
    else if(s==-1.) {
        if(n%2==0) return 1.;
        else return -1.;
    }
    else if(n>=0) {
        while(i<n && x!=0) {
            x *= s;
            i++;
        }
    }
    else {
        n=(-n);
        s = (double)1/s;
        while(i<n && x!=0) {
            x *= s;
            i++;
        }
    }
    return x;
}

int main() {

    return 0;
}