def solution(answers):
    answer = [0 for _ in range(3)]
    patterns = [
               [1, 2, 3, 4, 5],
               [2, 1, 2, 3, 2, 4, 2, 5],
               [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
               ]
    
    for prob, ans in enumerate(answers):
        for i in range(3):
            if ans == patterns[i][prob % len(patterns[i])]:
                answer[i] += 1
    answer = [i+1 for i in range(3) if answer[i] == max(answer)]
    
    return answer