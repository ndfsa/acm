import sys

if __name__ == "__main__":
    for line in sys.stdin:
        p = float(line)
        if p > 0:
            if p > 1:
                print('{0}%'.format(round(p * 100.0 / 4.0)))
            else:
                print('0%')
