#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int pattern1[] = {1, 2, 3, 4, 5};
    int pattern2[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int pattern3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int count[] = {0, 0, 0};
    int len1, len2, len3, best;
    len1 = sizeof(pattern1) / sizeof(int);
    len2 = sizeof(pattern2) / sizeof(int);
    len3 = sizeof(pattern3) / sizeof(int);
    
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == pattern1[i % len1])
            count[0]++;
        if(answers[i] == pattern2[i % len2])
            count[1]++;
        if(answers[i] == pattern3[i % len3])
            count[2]++;
    }
    
    best = *max_element(count, count + 3);
    
    for(int i=0; i<3; i++)
        if(count[i] == best)
            answer.push_back(i+1);
    
    return answer;
}