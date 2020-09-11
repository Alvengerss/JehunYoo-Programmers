from itertools import permutations

def solution(numbers):
    primes = set()
    numbers = list(numbers)
    
    for length in range(len(numbers)):
        primes |= set(map(int, map("".join, permutations(numbers, length + 1))))
    primes -= {0, 1}

    for i in range(2, int(max(primes) ** 0.5) + 1):
        primes -= set(range(i * 2, max(primes) + 1, i))
    
    answer = len(primes)
    
    return answer