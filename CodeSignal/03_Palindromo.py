def solution(inputString):
    reversed_string = inputString[::-1]
    
    if reversed_string == inputString:
        return True
    else:
        return False

result = solution("aabaa")
print(result)
