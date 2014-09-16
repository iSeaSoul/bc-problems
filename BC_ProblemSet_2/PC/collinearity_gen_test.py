f = open('collinearity_gen.in', 'w+')

def my_print(s):
	try:
		f.write(s + '\n')
	except:
		print s

import random

def get_random(L, R):
	return int(random.random() * (R - L + 1)) + L

def gen_max(a, b):
	my_print(str(1000))
	for x in xrange(1000):
		my_print(str(x * a + b) + ' ' + str(x * a + b))

# gen_max(1, 0)
# gen_max(100000, -10000000)

def gen(x):
	my_print(str(1000))
	hash = {}
	for t in xrange(1000):
		a = get_random(-x, x)
		b = get_random(-x, x)
		while hash.has_key((a, b)):
			a = get_random(-x, x)
			b = get_random(-x, x)
		hash.setdefault((a, b), True)
		my_print(str(a) + ' ' + str(b))

gen(1000000)
# for x in xrange(2, 8):
# 	gen(x * 10)

def gen_square(x):
	my_print(str(1000))
	for a in xrange(x):
		for b in xrange(1000 / x):
			my_print(str(a * 10) + ' ' + str(b * 10))

# gen_square(20)
# gen_square(5)

try:
	f.close()
except:
	pass

