#include "full.h"

int InterpolSearch(contract *arr,size_t length,int key)
{
    int mid, left=0,right=length-1;
    while (arr[left].amount<=key&&arr[right].amount>=key)
    {

        mid=left+((key-arr[left].amount)*(right-left))/(arr[right].amount-arr[left].amount);
        if (arr[mid].amount<key)
            left=mid+1;
            else if(arr[mid].amount>key)
            right=mid-1;
            else
            return mid;
    }
    if(arr[left].amount==key)
    return left;
    else return -1;
}

int binarySeacrh(contract *arr, size_t length, int key)
{
    bool flag = false;
    int left = 0, right = length - 1, mid;
    while ((left <= right) && (flag != true))
    {
        mid = (left + right) / 2;
        if (arr[mid].amount == key)
            flag = true;
        arr[mid].amount > key ? right = mid - 1 : left = mid + 1;
    }

    return (flag ? mid : -1);
}
