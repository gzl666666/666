#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <windef.h>
#include <math.h>
#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;


double arrays[100];
char strings[100];
int n, Max, flag, q = 1;
int Is_float,         ///是否输入小数
Is_parenthesis,        ///是否输入括号
file_into,              ///是否写入文件
pos = 0,         ///pos为 + - * /的位置
pos1 = -1,        ///pos1,pos2为括号位置
pos2 = -1;
ofstream ofile;

void randomNumber()                                   /***********arrays保存四则运算中将出现的数字*************************/
{
    flag = rand() % 3 + 2;
    for (int i = 0; i < flag; i++)
    {
        if (Is_float)
        {
            arrays[i] = (rand() % Max) + (rand() % 100 * 0.01);
        }
        else
        {
            arrays[i] = (rand() % Max) + 1;
        }
    }
}

void randomIs_parenthesis()                               /**********随机括号的位置****************************************/
{
    pos1 = -1;
    pos2 = -1;
    if (Is_parenthesis)
    {
        while (1)
        {
            pos1 = rand() % flag;
            pos2 = rand() % flag;
            if (abs(pos1 - pos2))
            {
                pos1 = min(pos1, pos2);
                pos2 = max(pos1, pos2);
                break;
            }
        }
        if (flag == 2)
        {
            pos1 = -1;
            pos2 = -1;
        }
    }
}

void priduction()                                  /************输出算式***********************************/
{
    for (int i = 0; i < flag; i++)
    {
        int k = rand() % pos;                  ///strings[i]为随机的符号
        if (i == pos1 && pos1 != pos2)
        {
            cout << "(" << " ";
            file_into&& ofile << "(" << " ";
        }
        cout << arrays[i] << " ";
        file_into&& ofile << arrays[i] << " ";
        if (i == pos2 && pos1 != pos2)
        {
            cout << ")" << " ";
            file_into&& ofile << ")" << " ";
        }
        if (i != flag - 1)
        {
            cout << strings[k] << " ";
            file_into&& ofile << strings[k] << " ";
        }
    }

}



void main() {
    ofile.open("F:\math.txt");
    cout << "请输入题目数量以及题目中出现的最大数:" << endl;
    cin >> n >> Max;
    cout << "请输入想要的运算符（+-*/）" << endl;
    getchar();
    gets_s(strings);
    cout << "是否需要小数？（1/0）";
    cin >> Is_float;
    cout << "是否需要括号？（1/0）";
    cin >> Is_parenthesis;
    cout << "是否写入文件？（1/0）";
    cin >> file_into;

    for (int i = 0; i < strlen(strings); i++)
    {
        if (strings[i] == '+' || strings[i] == '-' || strings[i] == '*' || strings[i] == '/')
        {
            strings[pos++] = strings[i];                       ///strings 存四则运算中将出现的符号
        }
    }

    while (n--)
    {
        randomNumber();
        randomIs_parenthesis();
        file_into&& ofile << "(" << q << ")" << "  ";
        cout << "(" << q++ << ")" << "  ";
        priduction();
        cout << "=";
        cout << endl;
        file_into&& ofile << endl;

    }
    ofile.close();
}