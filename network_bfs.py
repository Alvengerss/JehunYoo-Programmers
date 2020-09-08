def solution(n, computers):
    answer = 0
    visited = [0 for _ in range(n)]
    queue = []
    
    for i in range(n):
        for j in range(n):
            if computers[i][j] and not visited[i]:
                answer += 1
                queue.append(i)
                
                while len(queue):
                    node = queue[0]; del queue[0]
                    if not visited[node]:
                        visited[node] = 1
                        for k in range(n):
                            if computers[node][k] and not visited[k]:
                                queue.append(k)

    return answer