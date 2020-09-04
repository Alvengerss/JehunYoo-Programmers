#include <vector>
#include <stack>
using namespace std;

stack<int> st;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, move, item;
    int boardSize = board[0].size();
    
    for(int i=0; i<moves.size(); i++) {
        move = moves[i] - 1;
        for(int row=0; row<boardSize; row++) {
            if(board[row][move] != 0) {
                item = board[row][move];
                board[row][move] = 0;
                if(st.empty() || item != st.top())
                    st.push(item);
                else if(item == st.top()) {
                    st.pop();
                    answer += 2;
                }
                break;
            }
        }
    }
    
    return answer;
}