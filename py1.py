import sys
import matplotlib.pyplot as plt_lib

if __name__ == "__main__":
    file = sys.argv[1]
    d = {}
    with open(file + "2.csv", "r") as f:
        for line in f:
            elems = list(line.split(','))
            d[elems[0]] = list(map(float, elems[1:-1]))

    x = d['size']
    d.pop('size')

    for srt, time in d.items():
        plt_lib.plot(x, time, label = srt)

    
    plt_lib.xlabel('size')
    plt_lib.ylabel('time')
    plt_lib.legend(loc = 'lower left')
    plt_lib.savefig(file + '2.png')

