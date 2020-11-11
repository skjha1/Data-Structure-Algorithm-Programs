/*
Your task is to implement a new data structure called a team queue.

In a team queue, each element is a part of a team. If a new element wants to enter the queue, it first scans the queue to find his teammates and joins in the queue behind them. If the element has no teammates already waiting in the queue then he joins at the end of the queue (Bad Luck Element). Dequeing operation in a team queue is the same as that in a normal queue.

Input Format

The input file will contain one or more test cases. Each test case begins with the number of teams t (1 ≤ t ≤ 1000).
Then t team descriptions follow, each one consisting of the number of elements belonging to the team and the elements themselves. Elements are integers in the range 0..999999. A team may consist of up to 1000 elements.

Finally, a list of commands follows.

There are three different kinds of commands:
• ENQUEUE x — enter element x into the team queue
• DEQUEUE — process the first element and remove it from the queue
• STOP — end of test case
The input will be terminated by a value of 0 for t.

Warning:
A test case may contain up to 200000 (two hundred thousand) commands, so the implementation of the team queue should be efficient: both enqueing and dequeuing of an element should only take constant time.

Output Format

For each test case, first print a line saying ‘Scenario #k’, where k is the number of the test case.
Then, for each ‘DEQUEUE’ command, print the element which is dequeued on a single line.
Print a blank line after each test case, even after the last one

Sample Input 0

2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
0
Sample Output 0

Scenario #1
101
102
103
201
202
203

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int teamBelongTo[1000001];
queue<int> teamQueue[1001];
int main()
{
    int T = 1;
    int numTeams;
    while (cin >> numTeams, numTeams)
    {
        for (int t = 0; t < numTeams; ++t)
        {
            while (!teamQueue[t].empty())
                teamQueue[t].pop();
            int numElem;
            cin >> numElem;
            while (numElem--)
            {
                int elem;
                cin >> elem;
                teamBelongTo[elem] = t;
            }
        }
        
        queue<int> combinedQueue;
        
        cout << "Scenario #" << T++ << '\n';
        string command;
        while (cin >> command, command[0] != 'S')
        {
            if (command[0] == 'E')
            {
                int num;
                cin >> num;
                int team = teamBelongTo[num];
                if (teamQueue[team].empty())
                {
                    combinedQueue.push(team);
                }
                
                teamQueue[team].push(num);
            }
            else
            {
                int team = combinedQueue.front();
                cout << teamQueue[team].front() << '\n';
                teamQueue[team].pop();
                if (teamQueue[team].empty())
                    combinedQueue.pop();
            }
        }
        cout << '\n';
    }
}