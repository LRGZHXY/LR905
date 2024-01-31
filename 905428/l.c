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


// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) {
//         vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
//         int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
//         int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
//         int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
//         int count = 1; // 用来给矩阵中每一个空格赋值
//         int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
//         int i,j;
//         while (loop --) {
//             i = startx;
//             j = starty;

//             // 下面开始的四个for就是模拟转了一圈
//             // 模拟填充上行从左到右(左闭右开)
//             for (j = starty; j < n - offset; j++) {
//                 res[startx][j] = count++;
//             }
//             // 模拟填充右列从上到下(左闭右开)
//             for (i = startx; i < n - offset; i++) {
//                 res[i][j] = count++;
//             }
//             // 模拟填充下行从右到左(左闭右开)
//             for (; j > starty; j--) {
//                 res[i][j] = count++;
//             }
//             // 模拟填充左列从下到上(左闭右开)
//             for (; i > startx; i--) {
//                 res[i][j] = count++;
//             }

//             // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
//             startx++;
//             starty++;

//             // offset 控制每一圈里每一条边遍历的长度
//             offset += 1;
//         }

//         // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
//         if (n % 2) {
//             res[mid][mid] = count;
//         }
//         return res;
//     }
// };


// class Solution:
//     def generateMatrix(self, n: int) -> List[List[int]]:
//         nums = [[0] * n for _ in range(n)]
//         startx, starty = 0, 0               # 起始点
//         loop, mid = n // 2, n // 2          # 迭代次数、n为奇数时，矩阵的中心点
//         count = 1                           # 计数

//         for offset in range(1, loop + 1) :      # 每循环一层偏移量加1，偏移量从1开始
//             for i in range(starty, n - offset) :    # 从左至右，左闭右开
//                 nums[startx][i] = count
//                 count += 1
//             for i in range(startx, n - offset) :    # 从上至下
//                 nums[i][n - offset] = count
//                 count += 1
//             for i in range(n - offset, starty, -1) : # 从右至左
//                 nums[n - offset][i] = count
//                 count += 1
//             for i in range(n - offset, startx, -1) : # 从下至上
//                 nums[i][starty] = count
//                 count += 1                
//             startx += 1         # 更新起始点
//             starty += 1

//         if n % 2 != 0 :			# n为奇数时，填充中心点
//             nums[mid][mid] = count 
//         return nums


// var generateMatrix = function(n) {
//     let startX = startY = 0;   // 起始位置
//     let loop = Math.floor(n/2);   // 旋转圈数
//     let mid = Math.floor(n/2);    // 中间位置
//     let offset = 1;    // 控制每一层填充元素个数
//     let count = 1;     // 更新填充数字
//     let res = new Array(n).fill(0).map(() => new Array(n).fill(0));

//     while (loop--) {
//         let row = startX, col = startY;
//         // 上行从左到右（左闭右开）
//         for (; col < n - offset; col++) {
//             res[row][col] = count++;
//         }
//         // 右列从上到下（左闭右开）
//         for (; row < n - offset; row++) {
//             res[row][col] = count++;
//         }
//         // 下行从右到左（左闭右开）
//         for (; col > startY; col--) {
//             res[row][col] = count++;
//         }
//         // 左列做下到上（左闭右开）
//         for (; row > startX; row--) {
//             res[row][col] = count++;
//         }

//         // 更新起始位置
//         startX++;
//         startY++;

//         // 更新offset
//         offset += 1;
//     }
//     // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
//     if (n % 2 === 1) {
//         res[mid][mid] = count;
//     }
//     return res;
// };

// 单链表
// struct ListNode {
//     int val;  // 节点上存储的元素
//     ListNode *next;  // 指向下一个节点的指针
//     ListNode(int x) : val(x), next(NULL) {}  // 节点的构造函数
// };
// //
// ListNode* head = new ListNode(5);
// 使用默认构造函数初始化节点：

// ListNode* head = new ListNode();
// head->val = 5;
  
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode<T> {
//     pub val: T,
//     pub next: Option<Box<ListNode<T>>>,
// }

// impl<T> ListNode<T> {
//     #[inline]
//     fn new(val: T, node: Option<Box<ListNode<T>>>) -> Self {
//         ListNode { next: node, val }
//     }
// }

typedef struct ListNodeT {
    int val;
    struct ListNodeT next;
} ListNode;
