def solution(s):
    answer = []
    
    lists = []
    sets = s[2:-2].split('},{')
    
    for st in sets:
        lists.append(list(map(int, st.split(','))))
    
    lists = sorted(lists, key=lambda x: len(x))
    
    for lst in lists:
        for item in lst:
            if not item in answer:
                answer.append(item)
    
    return answer