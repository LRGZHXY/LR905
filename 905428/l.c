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
//1
void FGetStr(char *str,int size,FILE *file)
{
    int j=0;
    while(size)
    {
        if((str[j++]=fgetc(file))!=-1)
        {
            size--;
        }
        else
        {
            break;
        }
        if(str[j-1]=='\n')
        {
            break;
        }
    }
    if(str[j-1]=='\n')
    {
        str[j-1]='\0';
    }
    else if(size==0)
    {
        fseek(file,-1,1);
        str[j-1]='\0';
    }
    else
    {
        str[j-1]='\0';
    }
}
//2
void WriteArticle(FILE *f) {
    if (f == NULL) {
        return;
    }

    char ch;

    while ((ch = getchar()) != EOF) {
        fputc(ch, f);
    }
}
//3
void ReadArticle(FILE *f) {
    if (f == NULL) {
        return;
    }

    char ch;

    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }
}
//4
void BatchAdd(FILE *in, FILE *out) {
    if (in == NULL || out == NULL) {
        return;
    }

    double num1, num2;

    while (fscanf(in, "%lf %lf", &num1, &num2) == 2) {
        double sum = num1 + num2;
        fprintf(out, "%.2lf\n", sum);
    }
}
//5
// void fun(FILE *fin, FILE *fout) {
//     if (fin == NULL || fout == NULL) {
//         return;
//     }

//     ST student;

//     while (fscanf(fin, "%s %s %d %d %lf", student.name, student.id, &student.gender, &student.age, &student.scored) == 5) {
//         output(&student, fout);
//     }
// }

//209
int minSubArrayLen(int target, int* nums, int numsSize) {
    int minlength=100000;
    int sum=0;
    int left=0;
    int right=0;
    for(;right<numsSize;right++)
    {
        sum+=nums[right];
        while(sum>=target)
        {
            int MinLength=right-left+1;
            minlength=minlength<MinLength?minlength:MinLength;
            sum-=nums[left++];
        }
    }
    return minlength==100000?0:minlength;
}
//59
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    //初始化返回的结果数组的大小
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回结果数组ans
    int** ans = (int**)malloc(sizeof(int*) * n);
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    //设置每次循环的起始位置
    int startX = 0;
    int startY = 0;
    //设置二维数组的中间值，若n为奇数。需要最后在中间填入数字
    int mid = n / 2;
    //循环圈数
    int loop = n / 2;
    //偏移数
    int offset = 1;
    //当前要添加的元素
    int count = 1;

    while(loop) {
        int i = startX;
        int j = startY;
        //模拟上侧从左到右
        for(; j < startY + n - offset; j++) {
            ans[startX][j] = count++;
        }
        //模拟右侧从上到下
        for(; i < startX + n - offset; i++) {
            ans[i][j] = count++;
        }
        //模拟下侧从右到左
        for(; j > startY; j--) {
            ans[i][j] = count++;
        }
        //模拟左侧从下到上
        for(; i > startX; i--) {
            ans[i][j] = count++;
        }
        //偏移值每次加2
        offset+=2;
        //遍历起始位置每次+1
        startX++;
        startY++;
        loop--;
    }
    //若n为奇数需要单独给矩阵中间赋值
    if(n%2)
        ans[mid][mid] = count;

    return ans;
}

// strncpy(filename[i],dirname,strlen(dirname));
//         strcat(filename[i],"/");
//         strcat(filename[i],ptr->d_name);

//char**filename=(char**)malloc((count+1)*sizeof(char*));

// //按首字母A-Z排序
//     qsort(filename,count,sizeof(char*),lettersort);
    
//     //若按修改时间排序  ls-t
//     if(ls_[t])
//     {
//         struct stat info;
//         for(int i=0;i<count;i++)
//         {
//             if(lstat(filename[i],&info)==-1)
//             {
//                 perror("lstat error");
//             }
//             filename[i]=info.st_mtime;
//         }
//         for(int i=0;i<count;i++)
//         {
//             for(int j=i;j<count;j++)
//             {
//                 if(filename[i]<filename[j])
//                 {
//                     long int temp=filename[i];
//                     filename[i]=filename[j];
//                     filename[j]=temp;
//                 }
//             }
//         }
//     }

//     //若按Z-A排序  ls-r
//     if(ls_[r])
//     {
//         for(int i=0;i<count/2;i++)
//         {
//             char*temp;
//             temp=filename[i];
//             filename[i]=filename[count-i-1];
//             filename[count-i-1]=temp;
//         }
//     }
