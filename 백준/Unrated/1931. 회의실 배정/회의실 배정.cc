#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare(pair<int, int> v1, pair<int, int> v2) {
	if(v1.second == v2.second) // 같으면 시작시간 빠른 것 부터 나열 
		return v1.first < v2.first;
	return v1.second < v2.second;
}

int main(){
	int N, start, end;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		v.push_back({start, end});
    }
	sort(v.begin(), v.end(), compare);
	int skip = v[0].second;
	int count = 1;
	for(int i = 1; i < N; i++) {
		if(skip <= v[i].first) {
			count++;
			skip = v[i].second;
		}
	}
	cout << count;
}