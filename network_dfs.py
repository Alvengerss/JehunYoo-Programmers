def solution(n, computers):
    answer = 0
    visited = [0 for _ in range(n)]
    stack = []
    
    for i in range(n):
        for j in range(n):
            if computers[i][j] and not visited[i]:
                answer += 1
                stack.append(i)
                
                while len(stack):
                    node = stack.pop()
                    if not visited[node]:
                        visited[node] = 1
                        for k in range(n):
                            if computers[node][k] and not visited[k]:
                                stack.append(k)

    return answer