f = open('gcd_gen.in', 'w+')

def my_print(s):
	try:
		f.write(s + '\n')
	except:
		print s

import random

def get_random(L, R):
	return int(random.random() * (R - L + 1)) + L

def gcd(x, y):
	return x if y == 0 else gcd(y, x % y)

import math

def get_fac_num(x):
	ret = 0
	for cx in xrange(1, (int)(math.sqrt(x) + 10)):
		if x % cx == 0:
			ret += 1
			if cx * cx != x:
				ret += 1
		if cx * cx >= x:
			break
	return ret

def gen():
	x = get_random(1, 100000)
	a = get_random(1, 100000 / x) * x
	b = get_random(1, 100000 / x) * x
	num = get_fac_num(x)
	k = get_random(1, num + 1)
	my_print(str(b) + ' ' + str(a) + ' ' + str(k))

for x in xrange(1, 21):
	gen()

try:
	f.close()
except:
	pass

