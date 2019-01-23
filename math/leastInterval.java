import java.util.Arrays;
import java.util.Scanner;

/*
	problem: Task Scheduler
	给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

	然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

	你需要计算完成所有任务所需要的最短时间。

	示例 1：

	输入: tasks = ["A","A","A","B","B","B"], n = 2
	输出: 8
	执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
	注：

	任务的总个数为 [1, 10000]。
	n 的取值范围为 [0, 100]。

	idea:
	（1）因为每个任务的执行都需要一个单位时间，所以执行完全部任务，用时不会少于任务个数
	（2）其次，相同种类的任务之间有长度为n的冷却时间，所以要尽可能利用起来这些冷却时间，才能使总时间少
	（3）给定一个任务列表，规划任务执行顺序：
		a. 对每个任务的实例进行计数，同时初始化一个任务计时器time（初值为0）
		b. 按实例数排序（从小到大或者从大到小），首先要执行实例数最多的任务，计时器time递增
		c. 其次执行实例数次多的任务，计时器time递增，直到执行任务所用的时间达到冷却时长
		d. 重复b、c，直到实例数最多的任务个数为0，返回time


*/

public class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];

        for (char c: tasks)
            map[c - 'A']++;
        Arrays.sort(map);

        int time = 0;
        while (map[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (map[25] == 0)
                    break;
                if (i < 26 && map[25 - i] > 0)
                    map[25 - i]--;
                time++;
                i++;
            }
            Arrays.sort(map);
        }

        return time;
    }
}

Class LeastInterval{
	public static void main(String[] args) {
		char [] tasks = {'B', 'D', 'A', 'A', 'E', 'A', 'A', 'C', 'A'};

		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();

		Solution solu = new Solution();
		solu.leastInterval(tasks, n);
	}
}