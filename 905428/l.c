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



//704.二分查找
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
//27.移除元素
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
//26.删除有序数组中的重复项
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
//283.移动零
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
//字符串连接
char* strcat(char *a, const char *b) {
    char *temp = a;

    while (*temp) {
        temp++;
    }

    while (*b) {
        *temp = *b;
        temp++;
        b++;
    }

    *temp = '\0';

    return a;
}
//结构体定义
typedef struct ListNodeT{
    int val;
    struct ListNodeT next;
}ListNode;
//34
int searchleftBorder(int* nums,int numsSize,int target)
{
    int left=0;
    int right=numsSize-1;
    int leftBorder=-1;
    while(left<=right)
    {
        int middle=left+(right-left)/2;
        if(nums[middle]==target)
        {
            leftBorder=middle;
            right=middle-1;
        }
        else if(nums[middle]>target)
        {
            right=middle-1;
        }
        else if(nums[middle]<target)
        {
            left=middle+1;
        }
    }
    return leftBorder;
}
int searchrightBorder(int* nums,int numsSize,int target)
{
    int left=0;
    int right=numsSize-1;
    int rightBorder=-1;
    while(left<=right)
    {
        int middle=left+(right-left)/2;
        if(nums[middle]==target)
        {
            rightBorder=middle;
            left=middle+1;
        }
        else if(nums[middle]>target)
        {
            right=middle-1;
        }
        else if(nums[middle]<target)
        {
            left=middle+1;
        }
    }
    return rightBorder;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int rightBorder=searchrightBorder(nums,numsSize,target);
    int leftBorder=searchleftBorder(nums,numsSize,target);
    *returnSize=2;
    int* arr=(int*)malloc(sizeof(int)*2);
    arr[0]=leftBorder;
    arr[1]=rightBorder;
    return arr;
}
//844
#include <stdbool.h>
bool backspaceCompare(char* s, char* t) {
    int i=strlen(s)-1,j=strlen(t)-1;
    int skipS=0,skipT=0;
    while(i>=0||j>=0)
    {
        while(i>=0)
        {
            if(s[i]=='#')
            {
                skipS++;
                i--;
            }
            else if(skipS>0)
            {
                skipS--;
                i--;
            }
            else
            {
                break;
            }
        }
        while(j>=0)
        {
            if(t[j]=='#')
            {
                skipT++;
                j--;
            }
            else if(skipT>0)
            {
                skipT--;
                j--;
            }
            else
            {
                break;
            }
        }
        if(i>=0&&j>=0)
        {
            if(s[i]!=t[j])
            {
                return false;
            }
        }
        else
        {
            if(i>=0||j>=0)
            {
                return false;    
            }
        }
        i--,j--;
    }
    return true;
}
//977
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int*arr=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++)
    {
        arr[i]=nums[i]*nums[i];
    }
    for(int j=0;j<numsSize;j++)
    {
        for(int k=j+1;k<numsSize;k++)
        {
            if(arr[k]<arr[j])
            {
                int tmp=arr[k];
                arr[k]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    *returnSize = numsSize; 
    return arr;
}