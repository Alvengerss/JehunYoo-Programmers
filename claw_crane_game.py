def solution(board, moves):
    answer = 0
    stack = []
    
    for move in moves:
        for row, _ in enumerate(board):
            if board[row][move - 1] != 0:
                item = board[row][move - 1]
                board[row][move - 1] = 0
                if len(stack) == 0 or stack[-1] != item:
                    stack.append(item)
                else:
                    stack.pop()
                    answer += 2
                break
    
    return answer