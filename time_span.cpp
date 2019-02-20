/*
问题 A: 日期差值
时间限制: 1 Sec  内存限制: 32 MB
提交: 4279  解决: 1028
[提交][状态][讨论版][命题人:外部导入]
题目描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。

输入
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD

输出
每组数据输出一行，即日期差值

样例输入
20130101
20130105
样例输出
5


思路：让小日期加日子到大日期


注意输入无大小之分，需要判断




*/
#include <cstdio>
  
int month[13][2] = {                    //存入月份； 
    {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},{31, 31}, {31, 31}, {30, 30}, {31, 31},{30, 30}, {31, 31}
};
  
bool leap (int year) {                  //判断是够为闰年； 
    return (year % 4 == 0 && year % 100 != 0 || (year % 400 == 0));  
} 
  
int main()
{
    int time1, y1, m1, d1;
    int time2, y2, m2, d2;
    while (scanf ("%d%d", &time1, &time2) != EOF) {
        if (time1 > time2) {
            int temp = time1;
            time1 = time2;
            time2 = temp;
        }
         
        y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;     
        y2 = time2 / 10000, m2 = time2 % 10000 / 100, d2 = time2 % 100;
        int count = 1;
        while (y1 < y2 - 1) {                //将年份缩短到差一年再进行日期的+1； 
            if (leap (y1) == 1)     count += 366; 
            else  count += 365;
            y1++;
        }
        while (y1 < y2 || m1 < m2 || d1 < d2) {
            d1++;
            if (d1 == month[m1][leap (y1)] + 1) {       //超过当月天数； 
                m1++;
                d1 = 1; 
            }
            if (m1 == 13) {                 //超过12个月； 
                y1++;
                m1 = 1;
            }
            count++;
        }
        printf ("%d\n", count);
    }
  
    return 0;
}
