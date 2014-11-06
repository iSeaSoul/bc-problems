f = open('nim2_gen.in', 'w+')

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

# for c in xrange(1, 5):
# 	gen(3**c)

# for c in xrange(5):
# 	gen(1000, 10**c)

# for c in xrange(5):
# 	gen(100, 10**12)

for c in xrange(20):
	gen(1000, get_random(10**2, 10**12))

my_print(str(40))
my_print(' '.join([str(2 ** cc) for cc in xrange(40)]))

my_print(str(40))
my_print(' '.join([str(2 ** cc + 2 ** 3 + 2 ** 16) for cc in xrange(40)]))

try:
	f.close()
except:
	pass
