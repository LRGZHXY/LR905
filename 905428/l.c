#include <stdio.h>
double fun(int num)
{
	if (num == 0 || num == 1)
	{
		return 1.0;
	}
	else
	{
		return num * fun(num - 1);
	}
}
int main()
{
	double sum = 1.0;
	int n, i;
	scanf_s("%d", &n);
	for (i = 1;i <= n;i++)
	{
		sum += 1.0 / fun(i);
	}
	printf("%.8lf", sum);
}



//二分查找
int search(int* nums, int numsSize, int target) {
    int left=0;
    int right=numsSize-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(target==mid)
        {
            return nums[mid];
        }
        if(target>nums[mid])
        {
            left=mid+1;
        }
        if(target<nums[mid])
        {
            right=mid-1;
        }
    }
    return -1;
}



int removeElement(int* nums, int numsSize, int val) {
    int slow=0;
    for(int fast=0;fast<numsSize;fast++)
    {
        if(nums[fast]!=val)
        {
            nums[slow]=nums[fast];
            slow++;
        }
    }
    return slow;
}




int removeDuplicates(int* nums, int numsSize) {
    int slow=0;
    int fast=1;
    while(fast<numsSize)
    {
        if(nums[fast]!=nums[slow])
        {
            slow++;
            nums[slow]=nums[fast];
        }
        fast++;
    }
    return slow+1;
}




void moveZeroes(int* nums, int numsSize) {
    int slow=0;
    for(int fast=0;fast<numsSize;fast++)
    {
        if(nums[fast]!=0)
        {
            nums[slow]=nums[fast];
            slow++;
        }
    }
    for(int i=slow;i<numsSize;i++)
    {
        nums[i]=0;
    }
}