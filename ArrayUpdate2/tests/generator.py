#!/usr/bin/env python3
# -*- encoding: utf-8 -*-
import random

NUMOFCASE = 15
N_MIN = 2;
N_MAX = 200000;
A_MIN = 1;
A_MAX = 5;
D_MIN = 1;
D_MAX = 5;
M_MIN = 1;
M_MAX = 200000;
X_MIN = 0;
X_MAX = 2;

seq = 0

def generate():

    filename = '50-random{:02d}.in'.format(seq)

    f = open(filename, 'w')
    N = random.randint(N_MIN, N_MAX)
    A = random.randint(A_MIN, A_MAX)
    D = random.randint(D_MIN, D_MAX)
    M = random.randint(M_MIN, M_MAX)
    f.write('{}\n{} {}\n{}\n'.format(N, A, D, M))

    for i in range(M):
        x = random.randint(X_MIN, X_MAX)
        y = random.randint(1, N-1)
        z = random.randint(y+1, N)
        f.write('{} {} {}\n'.format(x, y, z))

    
    K = random.randint(1    , N)
    f.write(str(K) + '\n')
    f.close()

def main():
    global seq
    for i in range(NUMOFCASE):
        generate()
        seq += 1

if __name__ == '__main__':
    main()
