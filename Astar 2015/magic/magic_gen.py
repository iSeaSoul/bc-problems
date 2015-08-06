from sets import Set

s = Set()
for i in xrange(90000010, 100000000):
    y = str(i)
    j = int(y[-1] + y[1:-1] + y[0])

    if j * 1000000 % i == 0 and j != i:
        # print i, 1.0 * j / i
        s.add(1.0 * j / i)

for x in sorted(s):
    print x

# import sys
# import random

# script_name = sys.argv[0].split("\\")[-1][:-3]

# f = open('%s.in' % (script_name, ), 'w+')

# def my_print(s):
#     try:
#         if not isinstance(s, str):
#             s = str(s)
#         f.write(s + '\n')
#     except:
#         # import traceback
#         # traceback.print_exc()
#         print s

# def get_random(L, R):
#     return int(random.random() * (R - L + 1)) + L

# def gen_random():
#     my_print("%d.%d" % (get_random(0, 9), get_random(1, 999999)))

# for i in xrange(19):
#     gen_random()
