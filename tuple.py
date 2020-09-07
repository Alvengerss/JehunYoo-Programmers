def solution(s):
    answer = []
    
    lsts = []
    sets = s[2:-2].split('},{')
    
    for st in sets:
        lsts.append(list(map(int, st.split(','))))
    
    lsts = sorted(lsts, key=lambda x: len(x))
    
    for lst in lsts:
        for item in lst:
            if not item in answer:
                answer.append(item)
    
    return answer