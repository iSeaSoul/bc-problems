f = open('knn2_gen.in', 'w+')

def my_print(s):
	try:
		f.write(s + '\n')
	except:
		print s

import random

def get_random(L, R):
	return int(random.random() * (R - L + 1)) + L

def gen():
	n, m = 100000, 100000
	my_print(str(n) + ' ' + str(m))
	hash = {}
	get_random(1, 100)
	for i in xrange(n):
		xi = get_random(1, 1000000000)
		while hash.has_key(xi):
			xi = get_random(1, 1000000000)
		hash.setdefault(xi, True)
		# xi = i + 1
		vi = get_random(1, 1000)
		my_print(str(xi) + ' ' + str(vi))
	for i in xrange(m):
		xi = get_random(1, n)
		ki = get_random(1, n - 1)
		my_print(str(xi) + ' ' + str(ki))

gen()

try:
	f.close()
except:
	pass

