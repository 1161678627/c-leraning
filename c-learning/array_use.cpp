#include<iostream>
#include<cstring>
using namespace std;

int main12() {
	// 数组的定义，数组元素下标从0开始索引，此时数组中元素是有值的，值为int类型的最小取值范围
	// 一个数组名称只能初始化一次
	int arr1[10];
	// 根据给出的值，自动推测数组长度
	int arr2[] = { 1, 2, 3 };
	// 这种声明方式可以 赋值长度小于定义长度,当数组中下标没赋值时其实系统会给一个默认值 0
	int arr3[5] = { 1, 2, 3, 4,  5 };
	// c++ 数组 没有 长度属性，需要间接的通过 sizeof(arr3)/sizeof(arr3[0]) 这种 计算内存占用空间 的方式求
	for (int i = 0; i < sizeof(arr3)/sizeof(arr3[0]); i++)
	{
		cout << arr3[i] << endl;
	}

	// 使用数组名，可以查看数组在内存中的首地址,此时给出的arr1 是 16进制的， 可以使用 (int)arr1 强转 arr1 为int
	cout << "数组arr1在内存中的首地址为：" << (int)arr1 << endl;
	// 使用 &符号可以查看地址，arr1[0]表示arr的第0个元素，&arr1[0]表示取该元素的地址，第0个元素的地址就是数组在内存中的首地址，两者一致
	cout << "数组arr1中第0个元素在内存中的首地址为：" << (int)&arr1[0] << endl;
	// 数组在内存中是连续的存储空间，所以相邻元素地址之间的 大小差 一个元素sizeof大小
	cout << "数组arr1中第1个元素在内存中的首地址为：" << (int)&arr1[1] << endl;
	// 其他的变量、常量 也可以用 &取其地址
	int a = 1;
	cout << "整数变量a在内存中的地址为：" << (int)&a << endl;


	// 数组名是常量，不能被重新赋值
	// arr1 = 100;

	// 寻找数组中最大的数
	int arr4[] = { 300, 350, 200, 250, 400, 100 };
	int max_weight = 0;
	int max_index;
	for (int i = 0; i < 6; i++)
	{
		if (max_weight <= arr4[i])
		{
			max_weight = arr4[i];
			max_index = i;
		}
	}
	cout << "最重的小猪体重是第：" << max_index+1 << "只" << "它的体重是" << max_weight << endl;

	// 数组转置
	int arr5[] = { 100, 200, 300, 400, 500, 60, 70 };
	int length = sizeof(arr5) / sizeof(arr5[0]);
	int temp_num;
	for (int i = 0; i < length/2; i++)
	{
		temp_num = arr5[length - 1 - i];
		arr5[length - 1 - i] = arr5[i];
		arr5[i] = temp_num;
	}

	// 冒泡排序法
	int arr6[] = { 100, 200, 300, 400, 500, 60, 70 };
	for (int i = 7-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr6[j] > arr6[j+1])
			{
				temp_num = arr6[j + 1];
				arr6[j + 1] = arr6[j];
				arr6[j] = temp_num;
			}
		}
	}

	// 二维数组的定义方式
	/*二维数组定义的四种方式：
	1. `数据类型  数组名[ 行数 ][ 列数 ]; `
	2. `数据类型  数组名[ 行数 ][ 列数 ] = { {数据1，数据2 } ，{数据3，数据4 } };`
	3. `数据类型  数组名[ 行数 ][ 列数 ] = { 数据1，数据2，数据3，数据4};`
	4. `数据类型  数组名[  ][ 列数 ] = { 数据1，数据2，数据3，数据4};*/

	// 定义一个两行三列的二维数组
	int arr_2[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	// 查看数组占用内存大小 4*6=24字节,可以通过计算内存占用，推算出二维数组的行列数
	cout << "二维数组占用的内存空间的大小为：" << sizeof(arr_2) << endl;
	cout << "二维数组第一行占用的内存空间的大小为：" << sizeof(arr_2[0]) << endl;
	cout << "二维数组第一个元素占用的内存空间的大小为：" << sizeof(arr_2[0][0]) << endl;
	
	// 查看二维数组的首地址
	cout << "二维数组的首地址为：" << (int)arr_2 << endl;
	cout << "二维数组的第一行地址为：" << (int)arr_2[0] << endl;
	cout << "二维数组的第一行第一列数据地址为：" << (int)&arr_2[0][0] << endl;	// 这三个是一致的
	cout << "二维数组的第二行地址为：" << (int)arr_2[1] << endl;
	cout << "二维数组的第二行第一列数据地址为：" << (int)&arr_2[1][0] << endl;	// 和上面差了 3*4 = 12

	// 使用二维数组记录考试成绩
	int scores_arr[3][3] = {
		{100, 100, 100},
		{90, 50, 100},
		{60, 70, 80}
	};
	string names[3] = { "张三", "李四", "王五" };
	int scores_sum[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "现在统计第" << i + 1 << "名学生" << names[i] << "的成绩" << endl;
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += scores_arr[i][j];
		}
		scores_sum[i] = sum;
		cout << names[i] << "的成绩为" << sum << endl;
	}

	return 0;
}