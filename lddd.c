/*公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。
示例：
输入：[[10,20],[30,200],[400,50],[30,20]]
输出：110
解释：
第一个人去 A 市，费用为 10。
第二个人去 A 市，费用为 30。
第三个人去 B 市，费用为 50。
第四个人去 B 市，费用为 20。
最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
来源：力扣（LeetCode）*/
/*我们这样来看这个问题，公司首先将这 2N2N 个人全都安排飞往 BB 市，再选出 NN 个人改变它们的行程，让他们飞往 AA 市。
如果选择改变一个人的行程，那么公司将会额外付出 price_A - price_B 的费用，这个费用可正可负。
因此最优的方案是，选出 price_A - price_B 最小的 N 个人，让他们飞往 A 市，其余人飞往 B 市。
算法
按照 price_A - price_B 从小到大排序；
将前 N 个人飞往 A 市，其余人飞往 B 市，并计算出总费用。*/
int cmp(const void *a, const void *b)
{
     return(*(int *)a-*(int *)b);
}
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int sum =0;
    int b[costsSize+1];
    for(int i=0;i<costsSize;i++){
        sum+=costs[i][1];
        b[i] = costs[i][0] - costs[i][1];       
    }
    qsort(b,costsSize,sizeof(int),cmp);             
    for(int i=0;i<costsSize/2;i++){
        sum+=b[i];                    
    }       
    return sum;
}
