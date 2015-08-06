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

def get_random(L, R):
    return int(random.random() * (R - L + 1)) + L

for i in xrange(100):
    my_print(i + 1)

for i in xrange(80):
    my_print(get_random(100, 1000000))

for i in xrange(10):
    my_print(get_random(100, 10000))

for i in xrange(10):
    my_print(1000000 - i)

try:
    f.close()
except:
    pass
