def solution(year):
    if year % 100 == 0:
        return year // 100
    else:
        return (year // 100) + 1
result = solution(1905)
print(result)
