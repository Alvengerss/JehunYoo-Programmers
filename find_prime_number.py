def solution(numbers):
    answer = 0
    primes = []
    length = len(numbers)
    numbers = [number for number in numbers] # list of char
    originals = numbers[:]
    
    for number in numbers:
        if len(number) < length:
            for num in number:
                originals.remove(num)
            for original in originals:
                numbers.append(number + original)
            for num in number:
                originals.append(num)

    for number in set(numbers):
        if isPrime(int(number)):
            primes.append(int(number))
            
    answer = len(set(primes))
    
    return answer

def isPrime(number):
    if number < 2: return False
    elif number == 2: return True
    elif number % 2 == 0: return False
    for i in range(3, number, 2):
        if number % i == 0:
            return False
    else:
        return True