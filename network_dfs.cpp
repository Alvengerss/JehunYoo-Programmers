#include <vector>
#include <stack>
#define MAX 200
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0, node;
    int visited[MAX] = {0};
    stack<int> st;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(computers[i][j] && !visited[i]) {
                answer++;
                st.push(i);
                while(!st.empty()) {
                    node = st.top(); st.pop();
                    if(!visited[node]) {
                        visited[node] = 1;
                        for(int k=0; k<n; k++)
                            if(computers[node][k] && !visited[k])
                                st.push(k);
                    }
                }
            }
        }
    }
    
    return answer;
}