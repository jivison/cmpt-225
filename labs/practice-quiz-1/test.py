#!/usr/bin/env python
import subprocess
import sys, os


def itsover():
    rt = subprocess.call("make clean",shell=True);
    sys.exit(1)



passed = 0

# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w')
# sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)  -> Python 2


# Compile
rt = subprocess.call("cp Stack.cpp testdir",shell=True);
os.chdir("testdir")
rt = subprocess.call("make",shell=True);
if rt != 0:
    sys.stdout.write("compilation failed\n");
    itsover()


# Run test
sys.stdout.write("Running test ... ");
rt = subprocess.call("timeout 2s ./x > 1.out",shell=True)
if rt:
    sys.stdout.write("ran too long\n");
else:
    rt = subprocess.call("diff -b 1.out 1.er &>/dev/null",shell=True);
    if rt == 0:
        sys.stdout.write("passed\n");
    else:
        sys.stdout.write("failed\n");


rt = subprocess.call("make -s clean",shell=True);
sys.exit(0)
