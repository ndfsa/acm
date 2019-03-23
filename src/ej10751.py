import sys
from math import sqrt

sqrt_two = sqrt(2)

def king_walk(n: float):
    if n > 2:
        return 4 * n - 4 + (n - 2) ** 2 * (sqrt_two) 
    elif n > 1:
        return n ** 2
    else:
        return 0


if __name__ == "__main__":
    lim = int(input())
    for i in range(lim):
        input()
        n = float(input())
        print('{0:.3f}\n'.format(king_walk(n)))
