f = open('iSea_gen.in', 'w+')

def my_print(s):
	try:
		f.write(s + '\n')
	except:
		print s

import random

def get_random(L, R):
	return int(random.random() * (R - L + 1)) + L

def gen():
	n = get_random(10, 20)
	k = get_random(1, n)
	c = []
	p = get_random(99, 100)
	for i in xrange(n):
		if i < 47: c.append(p)
		else: c.append(1)
		if get_random(0, 30) < 25:
			p = max(1, p - get_random(0, 20))
	my_print(str(n) + ' ' + str(k))
	my_print(' '.join([str(cc) for cc in c]))

for c in xrange(20):
	gen()

try:
	f.close()
except:
	pass

