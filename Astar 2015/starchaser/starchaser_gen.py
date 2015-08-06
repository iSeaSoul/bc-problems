import sys
import random

script_name = sys.argv[0].split("\\")[-1][:-3]

f = open('%s.in' % (script_name, ), 'w+')

def my_print(s):
    try:
        if not isinstance(s, str):
            s = str(s)
        f.write(s + '\n')
    except:
        # import traceback
        # traceback.print_exc()
        print s

def get_axis(x):
    return random.randint(-x, x)

def gen_random(n, x, t):
    my_print(n)
    for i in xrange(n):
        my_print(' '.join(map(str, [get_axis(x), get_axis(x), random.randint(0, t)])))

def gen_max(n, t=None):
    my_print(n)
    for i in xrange(n):
        my_print(' '.join(map(str, [i * 10000, i * 10000, i * 1000 if t == None else random.randint(0, t)])))

# gen_max(50000)
gen_max(50000, 10000000)
gen_max(50000, 100000000)
gen_random(50000, random.randint(100, 1000000), random.randint(10000, 10000000))
gen_random(50000, random.randint(100, 1000000), random.randint(10000, 10000000))
gen_random(50000, random.randint(100, 1000000), random.randint(10000, 10000000))

# for i in xrange(5):
#     gen_random(random.randint(1000, 10000), random.randint(10000, 1000000), random.randint(1000000, 10000000))

try:
    f.close()
except:
    pass
