#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

class simulator {
	int N_C;
	int N_A;
	int arrivalLow;
	int arrivalHigh;
	int serviceTimeLow;
	int serviceTimeHigh;
 private:
	int getserviceTime() {return (serviceTimeLow + rand() % (serviceTimeHigh - serviceTimeLow +1));};
	int getarrivalTime() {return (arrivalLow + rand() % (arrivalHigh - arrivalLow +1));};
 public:
	simulator(int nc = 0, int na = 0, int al = 0, int ah = 0, int sl = 0, int sh = 0) { N_C = nc; N_A = na; arrivalLow = al; arrivalHigh = ah; serviceTimeLow = sl; serviceTimeHigh = sh;};
	int result();
};

int simulator::result() {
	int currentTime = 0;
	int arrivalTime = 0;
	int finishTime = 0;
	int totalWaitTime = 0;
	priority_queue <int> p_q;
	queue <int> q;
	for (int i = 0; i < N_C; i++) {
		q.push(arrivalTime);
		arrivalTime += getarrivalTime();
	}
	while (!q.empty()) {
		while ((p_q.size() < N_A) && (!q.empty())) {
			finishTime = q.front() + getserviceTime();
			q.pop();
			p_q.push(-finishTime);
		}
		if (!q.empty()) {
			if (p_q.top()+q.front() >= 0) {
				finishTime = q.front() + getserviceTime();
				p_q.pop();
				q.pop();
				p_q.push(-finishTime);
			} else {
				finishTime = getserviceTime() - p_q.top();
				totalWaitTime += -p_q.top() - q.front();
				p_q.pop();
				q.pop();
				p_q.push(-finishTime);
			}
		}
	}
	return totalWaitTime/N_C;
}

int main() {
	srand(time(NULL));
	simulator s1(1000, 4, 0, 2, 2, 7);
	cout<<s1.result()<<endl;
	return 0;
}