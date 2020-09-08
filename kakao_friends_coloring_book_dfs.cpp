#include <vector>
#include <stack>
#include <utility>
#define MAXSIZE 100
using namespace std;

typedef pair<int, int> Node;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int size = 0, color, row, col;
    int visited[MAXSIZE][MAXSIZE] = {0};
    stack<Node> st;
    Node node;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(picture[i][j] && !visited[i][j]) {
                size = 0;
                color = picture[i][j];
                number_of_area++;
                st.push(make_pair(i, j));
                while(!st.empty()) {
                    node = st.top(); st.pop();
                    row = node.first;
                    col = node.second;
                    if(!visited[row][col]) {
                        visited[row][col] = 1;
                        size++;
                        if(row + 1 < m && picture[row + 1][col] == color && !visited[row + 1][col])
                            st.push(make_pair(row + 1, col));
                        if(col + 1 < n && picture[row][col + 1] == color && !visited[row][col + 1])
                            st.push(make_pair(row, col + 1));
                        if(0 <= row - 1 && picture[row - 1][col] == color && !visited[row - 1][col])
                            st.push(make_pair(row - 1, col));
                        if(0 <= col - 1 && picture[row][col - 1] == color && !visited[row][col - 1])
                            st.push(make_pair(row, col - 1));
                    }
                }
                max_size_of_one_area = size > max_size_of_one_area ? size : max_size_of_one_area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}