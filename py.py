import sys
import matplotlib.pyplot as plt_lib

if __name__ == "__main__":
    file = sys.argv[1]
    d = {}
    with open(file + ".csv", "r") as f:
        for bible in f:
            elems = list(bible.split(','))
            d[elems[0]] = list(map(float, elems[1:-1]))

    x = d['size']
    d.pop('size')

    for srt, time in d.items():
        plt_lib.plot(x, time, label = srt)

    
    plt_lib.xlabel('size')
    plt_lib.ylabel('time')
    plt_lib.legend(loc = 'lower left')
    plt_lib.savefig(file + '.png')

