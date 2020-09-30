#include<iostream>
using namespace std;
#define UP 0
#define DOWN 1
#define LEFT  2
#define RIGHT 3 //0 1 2 3分别对应移动方向：上 下 左 右
struct Node
{
    int xy[3][3];  
    int mov;  //上一步到这一步移动方向 
};
Node step[102],end; //可移动步数 
int count = 1;   
void  init()
{ 
    int i,j;
    cout<<"请输入初始值"<<endl;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
        cin>>step[0].xy[i][j];
    step[0].mov=-1;
    cout<<"请输入目标值"<<endl;
    for(i=0;i<3;i++)
      for(j=0;j<3;j++)
        cin>>step[102].xy[i][j];
    step[102].mov=-1;
}


int location(int num)
{
	//找到空格位置
    int i;
    for(i=0;i<9;i++)
      if(step[num].xy[i/3][i%3] == 0) return i;

    cout<<"未能找到空格位置"<<endl;
    return -1;
}


long long sign(int num){
	//唯一性标记
    long long sum = 0;
    int p = 1,i,j;
    for(i=2;i>=0;i--)
      for(j=2;j>=0;j--)
      {
          sum += step[num].xy[i][j]*p;
          p=p*10;
	  }
    return sum;
}


void move(int num)
{
	//对空格进行移动
    int loc;
    loc = location(num);
    int stand = step[num].mov;
    if(loc / 3 != 0 && stand != UP)
    {
        step[count] = step[num];
        step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 - 1][loc % 3];
        step[count].xy[loc / 3 - 1][loc % 3] = 0;
        step[count].mov = DOWN;
        count++;
    }
    if(loc / 3 != 2 && stand != DOWN)
    {
        step[count] = step[num];
        step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 + 1][loc % 3];
        step[count].xy[loc / 3 + 1][loc % 3] = 0;
        step[count].mov = UP;
        count++;
    }
    if(loc % 3 != 0 && stand != LEFT)
    {
        step[count] = step[num];
        step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 ][loc % 3 - 1];
        step[count].xy[loc / 3 ][loc % 3 - 1] = 0;
        step[count].mov = RIGHT;
        count++;
    }
    if(loc % 3 != 2 && stand != RIGHT)
    {
      step[count] = step[num];
      step[count].xy[loc / 3][loc % 3] = step[count].xy[loc / 3 ][loc % 3 + 1];
      step[count].xy[loc / 3 ][loc % 3 + 1] = 0;
      step[count].mov = LEFT;
      count++;
    }
}

void display(int num)
{
  int i,j;
  for(i = 0;i < 3;i++)
  {
    for(j = 0;j < 3;j++)
      cout<<step[num].xy[i][j];
    cout<<endl;
  }
}

int search()
{
  int i = 0;
  while(1)
  {
    display(i);
    if(i == 101)
    {
      cout<<"移动步数超出了上限"<<endl;
      return 0;
    }
    if(sign(i) == sign(101))
    {
      cout<<"在第"<<i<<"次找到了";
      display(i);
      return i;
    }
    move(i);
    i++;
  }
}

int main()
{
  init();
  search();
  return 0;
}





