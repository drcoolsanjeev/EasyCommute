#!/usr/bin/env python

import sys
import os
#!/enter the json file name bycommand line
filename = sys.argv[1]

with open(filename) as f:
    lines = f.readlines()

length = len(lines)
failed = []
for i in range(2, length-2):
    dep = lines[i].split('"')
    install = dep[1]+"=="+dep[3]
    value = os.system('pip install '+install)
    if value != 0:
        failed.append(dep[1])

if len(failed) == 0:
    print("Successfully installed everything")
else :
    for i in failed:
        print("Couldn't Install {}".format(i))