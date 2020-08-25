/*递归乘法。 写一个递归函数，不使用 * 运算符， 实现两个正整数的相乘。可以使用加号、减号、位移，但要吝啬一些。
示例1:
 输入：A = 1, B = 10
 输出：10
示例2:
 输入：A = 3, B = 4
 输出：12
提示:
保证乘法范围不会溢出
来源：力扣（LeetCode）*/
/*解题思路
1、整体思路，将A分为两部分，最低1位和其他部分，分别进行判断和计算；
2、A右移1位取其他部分，判断是否为0，否则递归（入参A右移1位，B左移1位）；
3、通过移位运算取A的最低1位，判断是否为0，是返回递归返回值，否返回B值+递归返回值之和；*/
int multiply(int A, int B){
    int tmp = 0;

    if (A >> 1) {
        tmp = multiply(A >> 1, B << 1);
    }

    return (((unsigned int)A << 31) >> 31) ? (tmp + B) : tmp;
}

