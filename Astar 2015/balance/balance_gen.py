names = [
    'AntiMage',
    'Axe',
    'Bane',
    'Bloodseeker',
    'CrystalMaiden',
    'DrowRanger',
    'Earthshaker',
    'Juggernaut',
    'PoM',
    'ShadowFiend',
    'Morphling',
    'PhantomLancer',
    'Puck',
    'Pudge',
    'Razor',
    'SandKing',
    'StormSpirit',
    'Sven',
    'Tiny',
    'VengefulSpirit',
    'Windrunner',
    'Zeus',
    'Kunkka',
    'Lina',
    'Lich',
    'Lion',
    'Rhasta',
    'Slardar',
    'Tidehunter',
    'WitchDoctor',
    'Riki',
    'Enigma',
    'Tinker',
    'Sniper',
    'Necrolyte',
    'Warlock',
    'Beastmaster',
    'QoP',
    'Venomancer',
    'FacelessVoid',
    'SkeletonKing',
    'DeathProphet',
    'PhantomAssassin',
    'Pugna',
    'TemplarAssassin',
    'Viper',
    'Luna',
    'DragonKnight',
    'Dazzle',
    'Clockwerk'
]

# read = lambda: map(int, raw_input().strip().split())

# for i in xrange(input()):
#     n, m, k = read()
#     print n, m, k
#     for i in xrange(m):
#         a, b = read()
#         print names[a - 1], names[b - 1];

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

all_p = []
for i in xrange(50):
    for j in xrange(50):
        if i != j:
            all_p.append((i, j))

random.shuffle(all_p)
random.shuffle(all_p)
random.shuffle(all_p)
random.shuffle(all_p)
for i in xrange(2222):
    my_print(names[all_p[i][0]] + ' ' + names[all_p[i][1]])

try:
    f.close()
except:
    pass

