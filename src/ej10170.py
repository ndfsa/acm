from math import sqrt, ceil
import sys

def get_result(S, D):
    b = 2.0 * S + 1.0
    k = (-b + sqrt(b ** 2.0 + 8.0 * (D - S))) / 2.0
    return int(S) + ceil(k)


if __name__ == "__main__":
    for line in sys.stdin:
        lst = line.split(" ")
        if lst[0] != "\n":
            print(int(get_result(float(lst[0]), float(lst[1]))))
        else:
            break

