f = open('ST_gen.in', 'w+')

def my_print(s):
	try:
		f.write(s + '\n')
	except:
		print s

import random

def get_random(L, R):
	return int(random.random() * (R - L + 1)) + L

def gen(n):
	my_print(str(n))
	my_print(' '.join([str(get_random(1, n)) for cc in xrange(n)]))

gen(100)
gen(447)

try:
	f.close()
except:
	pass
