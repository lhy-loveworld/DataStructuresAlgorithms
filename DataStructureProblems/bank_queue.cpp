//Arthor: lhy-loveworld
//Method: use of queue
//Complexity: Time: O(N) Space: O(N)

#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

int getrandom(int low, int high)
{
	return (low + rand() % (high - low +1));
}

int main()
{
	int i=0;
	int customNum = 10;
	int arrivalLow =0;
	int arrivalHigh=5;
	int serviceTimeLow=1;
	int serviceTimeHigh=4;
	int arrivalTime = 0;
	int serviceTime = 0;
	int totalWaitTime = 0;
	int currentTime = 0;
	queue <int> q;
	srand(time(NULL));


	for (i = 0; i < customNum; i++)
	{
		cout<<"arrivalTime "<<currentTime<<endl;
		serviceTime = getrandom(serviceTimeLow, serviceTimeHigh);
		cout<<"serviceTime "<<serviceTime<<endl;
		arrivalTime = getrandom(arrivalLow, arrivalHigh);
		if (q.empty()) q.push(currentTime+serviceTime);
		else
		{
			while ((!q.empty()) && (q.front() <= currentTime)) q.pop();
			if (q.empty()) q.push(currentTime+serviceTime);
			else
			{
				totalWaitTime += q.back() - currentTime;
				q.push(q.back()+serviceTime);
			}
		}
		cout<<"finishTime "<<q.back()<<endl;
		currentTime += arrivalTime; 
	}
	cout << totalWaitTime/customNum<<endl;
	return 0;
}