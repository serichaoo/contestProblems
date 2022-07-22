#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct task
{
	int duration;
	int deadline;
};

bool operator<(task a, task b)
{
	return a.duration < b.duration;
}

int main()
{
	int nTasks;
	cin >> nTasks;
	vector<task> tasks(nTasks);
	for (int i = 0; i < nTasks; i++)
		cin >> tasks[i].duration >> tasks[i].deadline;
	sort(tasks.begin(), tasks.end());

	long long reward = 0;
	long long time = 0;
	for (int i = 0; i < nTasks; i++)
	{
		time += tasks[i].duration;
		reward += (tasks[i].deadline - time);
	}
	cout << reward;
	return 0;
}
