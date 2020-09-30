#include <iostream>
#include <vector>
using namespace std;
struct Octal
{
	int arr[4][4]; 
	int parent; 
	int current; 
	int depth; 
};

int to_number(int [4][4]);
bool up(int [4][4]);
bool down(int [4][4]);
bool left(int [4][4]);
bool right(int [4][4]);

int main()
{
	int arr[4][4] = {0}; // 存储当前八数码
	vector<Octal> open; // open表
	vector<Octal> closed; // closed表
	int depth; // 深度
	Octal octal; // 八数码

	cout << "请输入八数码数据，按照从左到右，从上至下的顺序，空格用0代替：" << endl;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> arr[i][j];
			octal.arr[i][j] = arr[i][j];
		}
	}
	cout << "请输入深度：" << endl;
	cin >> depth;
	cout << "===开始运算===" << endl;

	octal.parent = 0;
	octal.current = to_number(arr);
	octal.depth = 0;
	open.push_back(octal);

	int goal = 123804765; // 最终的八数码值
	bool flag = false; // 成功解决为true，失败为false
	Octal temp;
	int count = 1;

	while (!open.empty())
	{
		temp.current = open[open.size()-1].current;
		temp.parent = open[open.size()-1].parent;
		temp.depth = open[open.size()-1].depth;
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				temp.arr[i][j] = open[open.size()-1].arr[i][j];
			
		open.pop_back();
		closed.push_back(temp);
		if (temp.current == goal)
		{
			flag = true;
			break;
		}
		if (temp.depth >= depth)
		{
			continue;
		}
		
		Octal produce[4]; // 四个可能生成的八数码数组
		for (int i = 0; i < 4; i++)
		{
			produce[i].parent = temp.current;
			for (int j = 1; j <= 3; j++)
				for (int k = 1; k <= 3; k++)
					produce[i].arr[j][k] = temp.arr[j][k];
			produce[i].depth = temp.depth + 1;
		}
		
		bool flagProduce[4][2]; // 四个八数码对应的标志，0为open中是否含有，1位closed中是否含有
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 2; j++)
				flagProduce[i][j] = true;

		
		if (up(produce[0].arr))
		{
			produce[0].current = to_number(produce[0].arr);
			for (int i = 0; i < open.size(); i++)
				if (open[i].current == produce[0].current)
				{
					flagProduce[0][0] = false;
					break;
				}
				
			if (flagProduce[0][0])
			{
				for (int i = 0; i < closed.size(); i++)
					if (closed[i].current == produce[0].current)
					{
						flagProduce[0][1] = false;
						break;
					}
				if (flagProduce[0][1])
					open.push_back(produce[0]);
			}
			
			/*
			if (flagProduce[0][0] && flagProduce[0][1])
			{
				cout << "up " << count++ << " " << produce[0].depth << endl;
				for (int i = 1; i <= 3; i++)
				{
					for (int j = 1; j <= 3; j++)
					{
						cout << produce[0].arr[i][j] << " ";
					}
					cout << endl;
				}
				cout << produce[0].current << endl;
				cout << "============" << endl;
			}
			*/
		}

		if (down(produce[1].arr))
		{
			produce[1].current = to_number(produce[1].arr);
			for (int i = 0; i < open.size(); i++)
				if (open[i].current == produce[1].current)
				{
					flagProduce[1][0] = false;
					break;
				}

			if (flagProduce[1][0])
			{
				for (int i = 0; i < closed.size(); i++)
					if (closed[i].current == produce[1].current)
					{
						flagProduce[1][1] = false;
						break;
					}
				if (flagProduce[1][1])
					open.push_back(produce[1]);
			}

			/*
			if (flagProduce[1][0] && flagProduce[1][1])
			{
				cout << "down " << count++ << " " << produce[1].depth << endl;
				for (int i = 1; i <= 3; i++)
				{
					for (int j = 1; j <= 3; j++)
					{
						cout << produce[1].arr[i][j] << " ";
					}
					cout << endl;
				}
				cout << produce[1].current << endl;
				cout << "============" << endl;
			}
			*/
		}
		
		if (left(produce[2].arr))
		{
			produce[2].current = to_number(produce[2].arr);
			for (int i = 0; i < open.size(); i++)
				if (open[i].current == produce[2].current)
				{
					flagProduce[2][0] = false;
					break;
				}

			if (flagProduce[2][0])
			{
				for (int i = 0; i < closed.size(); i++)
					if (closed[i].current == produce[2].current)
					{
						flagProduce[2][1] = false;
						break;
					}
				if (flagProduce[2][1])
					open.push_back(produce[2]);
			}

			/*
			if (flagProduce[2][0] && flagProduce[2][1])
			{
				cout << "left " << count++ << " " << produce[2].depth << endl;
				for (int i = 1; i <= 3; i++)
				{
					for (int j = 1; j <= 3; j++)
					{
						cout << produce[2].arr[i][j] << " ";
					}
					cout << endl;
				}
				cout << produce[2].current << endl;
				cout << "============" << endl;
			}
			*/
		}
		
		if (right(produce[3].arr))
		{
			produce[3].current = to_number(produce[3].arr);
			for (int i = 0; i < open.size(); i++)
				if (open[i].current == produce[3].current)
				{
					flagProduce[3][0] = false;
					break;
				}

			if (flagProduce[3][0])
			{
				for (int i = 0; i < closed.size(); i++)
					if (closed[i].current == produce[3].current)
					{
						flagProduce[3][1] = false;
						break;
					}
				if (flagProduce[3][1])
					open.push_back(produce[3]);
			}
			
			/*
			if (flagProduce[3][0] && flagProduce[3][1])
			{
				cout << "right " << count++ << " " << produce[3].depth << endl;
				for (int i = 1; i <= 3; i++)
				{
					for (int j = 1; j <= 3; j++)
					{
						cout << produce[3].arr[i][j] << " ";
					}
					cout << endl;
				}
				cout << produce[3].current << endl;
				cout << "============" << endl;
			}
			*/
 		}
	}

	if (flag)
	{
		vector<Octal> answer;
		cout << "找到一个解！" << endl;
		answer.push_back(temp);
		int parent = temp.parent;

		while(parent != 0)
		{
			for (int j = 0; j < closed.size(); j++)
			{
				if (closed[j].current == parent)
				{
  					temp.current = closed[j].current;
					temp.depth = closed[j].depth;
					temp.parent = closed[j].parent;
					for (int k = 1; k <= 3; k++)
					{
						for (int m = 1; m <= 3; m++)
						{
							temp.arr[k][m] = closed[j].arr[k][m];
						}
					}
					answer.push_back(temp);
					parent = closed[j].parent;
					break;
				}
			}
		}

		for (int i = answer.size()-1; i >= 0; i--)
		{
			cout << "第" << answer.size()-i-1 << "次：" << endl;
			for (int j = 1; j <= 3; j++)
			{
				for (int k = 1; k <= 3; k++)
				{
					cout << answer[i].arr[j][k] << " ";
				}
				cout << endl;
			}
		}
	}
	else
	{
		cout << "在深度限制内的所有结果搜索完毕，没有答案！" << endl;
	}

	return 0;
}

int to_number(int arr[4][4])
{
	// 将八数码矩阵中的数据转换为数字，方便存储和比较
	// 从左到右，从上至下，按照从1到9递增，1为亿位，……，9为个位
	int index = 100000000;
	long long result = 0;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			result += arr[i][j] * index;
			index /= 10;
		}
	}
	return result;
}

bool up(int arr[4][4])
{
	// 空格向上
	int i, j; // 空格的位置为(i, j)
	bool flag = false;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
			if (arr[i][j] == 0)
			{
				flag = true;
				break;
			}
		if (flag)
			break;
	}
	if (i == 1)
		return false; // 此时无法向上
	else
	{
		arr[i][j] = arr[i-1][j];
		arr[i-1][j] = 0;
	}
	return true;
}

bool down(int arr[4][4])
{
	// 空格向下
	int i, j; // 空格的位置为(i, j)
	bool flag = false;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
			if (arr[i][j] == 0)
			{
				flag = true;
				break;
			}
		if (flag)
			break;
	}
    if (i == 3)
		return false; // 此时无法向下
	else
	{
		arr[i][j] = arr[i+1][j];
		arr[i+1][j] = 0;
	}
	return true;
}

bool left(int arr[4][4])
{
	// 空格向左
	int i, j; // 空格的位置为(i, j)
	bool flag = false;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
			if (arr[i][j] == 0)
			{
				flag = true;
				break;
			}
		if (flag)
			break;
	}
	if (j == 1)
		return false; // 此时无法向左
	else
	{
		arr[i][j] = arr[i][j-1];
		arr[i][j-1] = 0;
	}
	return true;
}

bool right(int arr[4][4])
{
	// 空格向右
	int i, j; // 空格的位置为(i, j)
	bool flag = false;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 3; j++)
			if (arr[i][j] == 0)
			{
				flag = true;
				break;
			}
		if (flag)
			break;
	}
	if (j == 3)
		return false; // 此时无法向右
	else
	{
		arr[i][j] = arr[i][j+1];
		arr[i][j+1] = 0;
	}
	return true;
}
