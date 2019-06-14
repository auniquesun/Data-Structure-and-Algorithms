/*
problem:
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

idea:
reference: https://leetcode.com/articles/task-scheduler/
    solution one:   用排序的方法做，
                    1. 在小于冷却时间的cycle内，每次选次数最大task执行，计时
                    2. 超过冷却时间cycle，根据每个task剩余的次数，对task排序
                    3. 重复1，2，直到所有task剩余数目为0，其实相当于次数最多的task为0
Before we start off with the solution, we can note that the names of the tasks are irrelevant for obtaining the solution of the given problem. The time taken for the tasks to be finished is only dependent on the number of instances of each task and not on the names of tasks.

The first solution that comes to the mind is to consider the tasks to be executed in the descending order of their number of instances. For every task executed, we can keep a track of the time at which this task was executed in order to consider the impact of cooling time in the future. We can execute all the tasks in the descending order of their number of instances and can keep on updating the number of instances pending for each task as well. After one cycle of the task list is executed, we can again start with the first task(largest count of instances) and keep on continuing the process by inserting idle cycles wherever appropriate by considering the last execution time of the task and the cooling time as well.

But, there is a flaw in the above idea. Consider the case, where say the number of instances of tasks A, B, C, D, E are 6, 1, 1, 1, 1 respectively with n=2(cooling time). If we go by the above method, firstly we give 1 round to each A, B, C, D and E. Now, only 5 instances of A are pending, but each instance will take 3 time units to complete because of cooling time. But a better way to schedule the tasks will be this: A, B, C, A, D, E, ... . In this way, by giving turn to the task A as soon as its cooling time is over, we can save a good number of clock cycles.

From the above example, we are clear with one idea. It is that, the tasks with the currently maximum number of outstanding (pending)instances will contribute to a large number of idle cycles in the future, if not executed with appropriate interleavings with the other tasks. Thus, we need to re-execute such a task as soon as its cooling time is finished.

Thus, based on the above ideas, firstly, we obtain a count of the number of instances of each task in mapmap array. Then, we start executing the tasks in the order of descending number of their initial instances. As soon as we execute the first task, we start its cooling timer as well(ii). For every task executed, we update the pending number of instances of the current task. We update the current time, timetime, at every instant as well. Now, as soon as the timer, ii's value exceeds the cooling time, as discussed above, we again need to consider the task with the largest number of pending instances. Thus, we again sort the taskstasks array with updated counts of instances and again pick up the tasks in the descending order of their number of instances.

Now, the task picked up first after the sorting, will either be the first task picked up in the last iteration(which will now be picked after its cooling time has been finished) or the task picked will be the one which lies at (n+1)^{th}(n+1) 
th
  position in the previous descending taskstasks array. In either of the cases, the cooling time won't cause any conflicts(it has been considered implicitly). Further, the task most critical currently will always be picked up which was the main requirement.

We stop this process, when the pending instances of all the tasks have been reduced to 0. At this moment, timetime gives the required result.
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> task2num(26, 0);
        for (auto task: tasks)
            task2num[task - 'A']++;

        sort(task2num.begin(), task2num.end()); // 默认从小到大排，所以排序之后，task2num[25] 的值最大

        int time = 0;
        while (task2num[25] > 0) {  // 表明 task 还没执行完
            int i = 0;
            while (i <= n) {
                if (task2num[25] == 0)
                    break;
                if (i < 26 && task2num[25 - i] > 0)
                    task2num[25 - i]--;
                time++;
                i++;
            }
            sort(task2num.begin(), task2num.end());
        }
        vector<int> ().swap(task2num);  // 释放向量空间
        return time;
    }
};

/*
涉及到没次取最大值，就应该想到 “优先队列”
这个版本是 Java 的，已经 Accepted 了；C++ 出队，个数减1，不知道还是优先队列吗？总之C++这个版本没实现出来
public class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c: tasks)
            map[c - 'A']++;
        PriorityQueue < Integer > queue = new PriorityQueue < > (26, Collections.reverseOrder());
        for (int f: map) {
            if (f > 0)
                queue.add(f);
        }
        int time = 0;
        while (!queue.isEmpty()) {
            int i = 0;
            List < Integer > temp = new ArrayList < > ();
            while (i <= n) {
                if (!queue.isEmpty()) {
                    if (queue.peek() > 1)
                        temp.add(queue.poll() - 1);
                    else
                        queue.poll();
                }
                time++;
                if (queue.isEmpty() && temp.size() == 0)
                    break;
                i++;
            }
            for (int l: temp)
                queue.add(l);
        }
        return time;
    }
}

*/