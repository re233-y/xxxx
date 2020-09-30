#include <stdio.h>
enum  direction{start,up,down,left,right};
int matrix[3][3];
int print_matrix(int);
int all_in_place();
int  iterative_deepening(int k,int d,int i,int j,enum direction dir);
int main()
{
    const int MAX_DEPTH=10;  
    int i,j,d;
    for(i=0;i<9;i++)    
        scanf("%d",matrix[0]+i);

    for(i=0; i<9&&matrix[0][i]; i++)    
        ;
    j = i%3;
    i /= 3;
    //���������DFSäĿ�����㷨����ȱ߽��1��MAX_DEPTH
    for(d=1;d<MAX_DEPTH && iterative_deepening(1,d,i, j,start);d++)
        ;
    return 0;
}

/*
*  k    : ��ǰ���
*  d    : ��ȱ߽�
*  i,j   : �ո�λ��
*  dir  : ��һ���ƶ�����
*/
int  iterative_deepening(int k,int d,int i,int j,enum direction dir)
{
    int ret=1;

    if(k>d)
        return ret;

    if(all_in_place())    //    ����Ŀ��״̬
        return print_matrix(k);
    else
    {
        if(dir!=up&&i<2 )    //��������
        {
            matrix[i][j] =     matrix[i+1][j];
            matrix[i+1][j] = 0;
            ret = iterative_deepening(k+1,d,i+1,j,down);
            matrix[i+1][j] = matrix[i][j];
            matrix[i][j] = 0;
            if(!ret)
                return print_matrix(k);
        }

        if(dir!=down&&i>0 )    //��������
        {
            matrix[i][j] =     matrix[i-1][j];
            matrix[i-1][j] = 0;
            ret = iterative_deepening(k+1,d,i-1,j,up);
            matrix[i-1][j] = matrix[i][j];
            matrix[i][j] = 0;
            if(!ret)
                return print_matrix(k);
        }

        if(dir!=left&&j<2 )    //��������
        {
            matrix[i][j] =     matrix[i][j+1];
            matrix[i][j+1] = 0;
            ret = iterative_deepening(k+1,d,i,j+1,left);
            matrix[i][j+1] = matrix[i][j];
            matrix[i][j] = 0;
            if(!ret)
                return print_matrix(k);
        }

        if(dir!=right&&j>0 )    //��������
        {
            matrix[i][j] =     matrix[i][j-1];
            matrix[i][j-1] = 0;
            ret = iterative_deepening(k+1,d,i,j-1,left);
            matrix[i][j-1] = matrix[i][j];
            matrix[i][j] = 0;
            if(!ret)
                return print_matrix(k);
        }
    }
    return ret;
}

int all_in_place()
{
    const int object[3][3]={{1,2,3},{8,0,4},{7,6,5}};
    int i;
    for(i=0;i<9;i++)
        if(matrix[0][i] != object[0][i])
            return 0;
    return 1;
}

int print_matrix( int count)
{
    int i,j;
    printf("\n\nsetp %d\n",count);
    for(i=0;i<3;i++,putchar('\n'))
        for(j=0;j<3;j++)
            printf("%d\t",matrix[i][j]);

    return 0;
}
