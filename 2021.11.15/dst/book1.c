#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int a = 0, i = 0, j = 0;
     
    printf("������һ������\n");
    scanf("%d", &a);
    if (a <= 1)
    {
        printf("����Ҫ����1\n");
        return 0;
    }
     
    for (j = a; j > 1; j--)  /*ÿ�δӱ���ʼÿ�η��ֲ���������j--ȡ���������ֵ*/
    {
        for (i = 2; i < j; i++) /*�����Ƿ��г���1��������֮�������*/
        {
            /*ȷ��Ϊ������j--��ѡ�����һ��*/
            if (0 == j%i)
            {
                break;
            }
        }
        if (i == j)
        {
            printf("������%d�����������%d\n", a, j);
            break;
        }
    }
     
    return 0;
}
