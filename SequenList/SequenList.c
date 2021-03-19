// 顺序表

#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

#define boolean int
#define true 1
#define false 0

// 自定义结构体类型
typedef struct {
	// 数组定义，最长1024
	int data[MAX];
	// 该变量用于表示顺序表的长度或者表尾的下标
	int end;
} SqList;
// SqList为类型名

// 初始化顺序表，即输入数据到顺序表
// 指针函数
SqList *initial_SqList() {
	// 创建顺序表的指针
	SqList *pointer;
	int i = 0;
	int num;
	// 分配空间给顺序表
	pointer = (SqList *)malloc(sizeof(SqList));
	// 如果未成功分配空间，则end为-1
	if (pointer != NULL) {
		// 指针 -> 结构体内变量
		// “->”为指向运算符
		pointer -> end = -1;
	}
	printf("These numbers are used to initialize the Order Table.\n");
	printf("\033[33m[Warning] Max lenght is 1024.\033[37m\n");
	printf("Please Enter numbers(0 is end): ");
	scanf("%d", &num);
	while (num) {
		// 将num的值赋依次给data数组
		// data添加一次数据，则end就需要加1
		pointer -> data[i++] = num;
		pointer -> end++;
		scanf("%d", &num);
	}
	// 返回指针
	return pointer;
}

int cmp(const void*a, const void*b) {
	return *(int*)a - *(int*)b;
}

boolean containsDuplicate(SqList *pointer, int numsSize){
	int i, j = 0,len = numsSize;
	if (numsSize == -1) {
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return false;
	}
	int nums[MAX];
	for (int t = 0; t <= numsSize; t++) {
		nums[t] = pointer -> data[t];
	}
	boolean tf = true;
	if(numsSize == 0 || numsSize == 1) {
		return false;
	}
	if(numsSize == 2) {
		if(nums[0] == nums[1]) {
            		return true;
        	} else {
        		return false;
        	}
    	}
	qsort(nums, numsSize + 1, sizeof(int), cmp);
	for(i = 0; i <= numsSize; i++) {
        	if(nums[i] != nums[j]) {
			nums[++j] = nums[i];
        	}
    	}
    	if(len > j) {
        	tf = true;
    	} else {
        	tf = false;
    	}
    	return tf;
}

// 输出顺序表
void print_SqList(SqList *pointer) {
	printf("Order table: \n");
	for (int i = 0; i <= pointer -> end; i++) {
		printf("%5d", pointer -> data[i]);
	}
	printf("\n");
}

// 插入一个数
/**
 * pointer	指针
 * location	需要插入的物理位置
 * number	需要插入的数字
 * 状态码：
 * 	-1：表满
 * 	 1：超出范围
 * 	 0：成功插入
 */
int insert_SqList(SqList *pointer, int location, int number) {
	// 判断顺序表是否为满记录，即data数组是否满员
	if (pointer -> end >= MAX - 1) {
		printf("\033[31m[Error] This table is full!\n\033[37m");
		// 返回状态码
		return -1;
	}
	// 判断插入的位置是否在无效的位置
	if (location >= pointer -> end + 2 || location < 0) {
		printf("\033[31m[Error] Position out of range.\n\033[37m");
		// 返回状态码
		return 1;
	}
	// 从表尾开始向后方移动一位，一直到需要插入的位置
	for (int j = pointer -> end; j >= location; j--) {
		pointer -> data[j + 1] = pointer -> data[j];
	}
	// 将指定的位置存放需要插入的数据
	pointer -> data[location] = number;
	// 顺序表长度加1
	pointer -> end++;
	// 返回状态码
	return 0;
}

// 倒置顺序表
/**
 * pointer	指针
 */
void reverse_SqList(SqList *pointer) {
	// 判断表是否为空表
	if (pointer -> end == -1) {
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return;
	}
	// 临时变量，用于交换数据
	int temp;
	// 变量i表示表头开始的指针，变量j表示从表尾开始的指针
	// i和j同时向中间移动，移动一次，则交换一次数据
	// 直到i和j相等或者i大于j时
	for (int i = 0, j = pointer -> end; i < j; i++, j--) {
		temp = pointer -> data[i];
		pointer -> data[i] = pointer -> data[j];
		pointer -> data[j] = temp;
	}
	// 输出顺序表
	print_SqList(pointer);
}

// 查找指定数据
/**
 * 使用方法：二分法查找
 * 该方法在数据长度足够长的情况下
 * 比顺序查找方法速度快，内存消耗少
 * 返回值（状态码）：
 * 	-1：空表
 * 	i ：已找到
 * 	-2：未找到
 */
int query_SqList(SqList *pointer, int number) {
	// 判断表是否为空
	if (pointer -> end == -1) {
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return -1;
	}
	// 标志位：
	// 	0：未找到
	// 	1：已找到
	int flag = 0;
	// i和j分别表示表头指针和表尾指针
	int i, j;
	// 从表头到表尾同时向中间查找
	// 只要表中其中一个值与i或者j对应的值相等
	// 就将状态位置1，退出循环
	for (i = 0, j = pointer -> end; i <= j; i++, j--) {
		if (pointer -> data[i] == number) {
			flag = 1;
			printf("The physics location of this number: %d\n", i);
			printf("The logic location of this number: %d\n", i + 1);
			return i;
		}
		if (pointer -> data[j] == number) {
			flag = 1;
                        printf("The physics location of this number: %d\n", j);
                        printf("The logic location of this number: %d\n", j + 1);
			return j;
		}
	}
	// 如果标志位为0
	// 	输出“未找到”
	if (!flag) {
		printf("\033[31m[404]Not found this number!\n\033[37m");
		return -2;
	}
}

// 删除指定数据
void delete_SqList(SqList *pointer) {
	// 判断表是否为空
	if (pointer -> end == -1) {
		printf("\033[31m[Error] This table is empty!\n\033[37m");
		return;
	}
	// 定义并输入需要删除的数据
        printf("Please Enter a number that you want to delete: ");
	int number;
	scanf("%d", &number);
	// 定义标志位用于标志是否能查找到对应的数据
	int flag = query_SqList(pointer, number);
	/**
	 * 标志位：
	 * 	大于等于0：已找到，开始删除
	 * 			此时flag代表需要删除的数据的下标
	 * 			从需要删除的数据的下一位开始向前移动一位
	 * 			一直到表尾，结束循环
	 * 			将最后一位置0,并将表长度缩短1
	 * 	-2	：未找到
	 *	其他或-1：空表
	 */
	if (flag >= 0) {
		int i;
		for (i = flag; i < pointer -> end; i++) {
			pointer -> data[i] = pointer -> data[i + 1];
		}
		pointer -> data[i] = 0;
		pointer -> end--;
		printf("\033[32mDelete was successfully!\n\033[37m");
		print_SqList(pointer);
	} else if (flag == -2) {
		printf("\033[31m[Error] Delete failed!\n");
		printf("\033[31m[Error] This number was not found!\n\033[37m");
	} else {
		printf("\033[31m[Error] Delete failed!\n");
		printf("\033[31m[Error] This table is empty!\n\033[37m");
	}
}

int main() {
	SqList *pointer = initial_SqList();
	for (;;) {
		int select;
		printf("-------------------------------\n");
		printf("1. Print Sequen List\n");
		printf("2. Insert a Number\n");
		printf("3. Reverse Sequen List\n");
		printf("4. Reinitializes Order Table\n");
		printf("5. Query a Number\n");
		printf("6. Delete a Number\n");
		printf("7. Checking for duplicate elements\n");
		printf("8. Exit\n");
		printf("-------------------------------\n");
		printf("Enter 1 to 8:");
		scanf("%d", &select);
		switch (select) {
			case 1:
				print_SqList(pointer);
				break;
			case 2:
				printf("Enter location(Logic position):");
				int location;
				scanf("%d", &location);
				printf("Enter Number:");
				int num;
				scanf("%d", &num);
				int status = insert_SqList(pointer, location - 1, num);
				printf("Status Code : %d\n", status);
				print_SqList(pointer);
				printf("\n");
				break;
			case 3:
				reverse_SqList(pointer);
				printf("\n");
				break;
			case 4:
				pointer = initial_SqList();
				break;
			case 5:
				printf("Please Enter a number that you want to Query: ");
				int query_Num;
				scanf("%d", &query_Num);
				int clearStatusCode = query_SqList(pointer, query_Num);
				break;
			case 6:
				delete_SqList(pointer);
				break;
			case 7:
				if (!containsDuplicate(pointer, pointer -> end)) {
					printf("\033[32m[OK] No repeating elements.\n\033[37m");
				} else {
					printf("\033[33m[Warning] Contains repeating elements.\n\033[37m");
				}
				break;
			case 8:
				printf("The program has exited normally.(Status Code : 0)\n");
				exit(0);
			default:
				printf("\033[31m[Error] at selection number!\033[37m\n");
		}
	}
	return 0;
}
