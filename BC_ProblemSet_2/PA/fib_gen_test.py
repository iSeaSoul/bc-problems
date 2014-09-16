f = open('fib_gen.in', 'w+')

def my_print(s):
	try:
		f.write(s + '\n')
	except e:
		print s

import random

def get_random(L, R):
	return int(random.random() * (R - L + 1)) + L

def gen():
	a, b = get_random(1, 100), get_random(1, 100)
	ta, tb = a, b
	while b < 1000000:
		a, b = b, a + b
	my_print( str(ta) + ' ' + str(tb) + ' ' + str(a + get_random(0, 1)) )

for x in xrange(1, 21):
	gen()

try:
	f.close()
except:
	pass

