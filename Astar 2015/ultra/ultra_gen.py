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

# def gen_random(length):
#     my_print(''.join([chr(random.randint(97, 122)) for i in xrange(length)]))

# for i in xrange(10):
#     gen_random(100)

# for i in xrange(10):
#     gen_random(1000)

# for i in xrange(5):
#     gen_random(10000)

# for i in xrange(5):
#     gen_random(100000)

# for i in xrange(5):
#     gen_random(random.randint(1000, 100000))

# def gen_max(length):
#     length = (length // 26) * 26
#     sub_length = length // 26
#     l = [chr(97 + i / sub_length) for i in xrange(length)]
#     random.shuffle(l)
#     my_print(''.join(l))

# for i in xrange(10):
#     gen_max(100)

# for i in xrange(10):
#     gen_max(1000)

# for i in xrange(5):
#     gen_max(10000)

# for i in xrange(5):
#     gen_max(100000)

# for i in xrange(5):
#     gen_max(random.randint(1000, 100000))

def gen_max_x(length):
    l = [chr(97 + i % 26) for i in xrange(length)]
    my_print(''.join(l))

for i in xrange(1):
    gen_max_x(100000)

for i in xrange(4):
    gen_max_x(random.randint(100, 100000))

def gen_max_x2(length):
    l = [chr(97 + i % 26) for i in xrange(length)]
    random.shuffle(l)
    my_print(''.join(l))

for i in xrange(1):
    gen_max_x2(100000)

for i in xrange(4):
    gen_max_x2(random.randint(100, 100000))

try:
    f.close()
except:
    pass
