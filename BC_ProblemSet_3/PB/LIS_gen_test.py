f = open('lis_gen.in', 'w+')

def my_print(s):
	try:
		f.write(s + '\n')
	except:
		print s

import random

def get_random(L, R):
	return int(random.random() * (R - L + 1)) + L

def gen(n, m = None):
	if not m: m = n
	my_print(str(n))
	my_print(' '.join([str(get_random(1, m)) for cc in xrange(n)]))

# for c in xrange(30):
# 	gen(10)
# for c in xrange(20):
# 	gen(get_random(1, 1000))

# for c in xrange(5):
# 	gen(1000)

# for c in xrange(5):
# 	for cc in xrange(1, 9):
# 		gen(1000, 10 ** cc)

# for c in xrange(1, 7):
# 	for cc in xrange(1, 9):
# 		gen(3 ** c, 10 ** cc)

# my_print(str(1000))
# my_print(' '.join([str(1) for i in xrange(1000)]))

# my_print(str(1000))
# my_print(' '.join([str(i + 1) for i in xrange(1000)]))

# my_print(str(1000))
# my_print(' '.join([str(1000 - i) for i in xrange(1000)]))

my_print(str(1000))
my_print(' '.join([str(i % 22 + 1) for i in xrange(1000)]))

my_print(str(1000))
my_print(' '.join([str(22 - i % 22) for i in xrange(1000)]))

try:
	f.close()
except:
	pass
