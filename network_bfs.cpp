#include <vector>
#include <queue>
#define MAX 200
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, node;
    int visited[MAX] = {0};
    queue<int> q;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(computers[i][j] && !visited[i]) {
                answer++;
                q.push(i);
                while(!q.empty()) {
                    node = q.front(); q.pop();
                    if(!visited[node]) {
                        visited[node] = 1;
                        for(int k=0; k<n; k++)
                            if(computers[node][k] && !visited[k])
                                q.push(k);
                    }
                }
            }
        }
    }
    
    return answer;
}