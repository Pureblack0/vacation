/*三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。
示例1:

 输入：n = 3 
 输出：4
 说明: 有四种走法
示例2:

 输入：n = 5
 输出：13*/
int waysToStep(int n){
    if (n < 4) {
        return n == 3 ? 4 : n;
    }

    int a = 1, b = 2, c = 4;
    for (int i = 4; i <= n; ++i) {
        int temp = (a + b) % 1000000007 + c;
        a = b;
        b = c;
        c = temp % 1000000007;
    }
    return c;
}
