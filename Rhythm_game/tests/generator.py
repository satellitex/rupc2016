#!/usr/bin/python3
# -*- coding: utf-8 -*-

import random

N_MIN = 1
N_MAX = 1000
M_MIN = 1
M_MAX = 100

seq = 0

def generate():
  global seq

  filename = '50-random{:02d}.in'.format(seq)

  f = open(filename, 'w')
  n = random.randint(N_MIN, N_MAX)
  m = random.randint(M_MIN, M_MAX)
  f.write("{} {}\n".format(n, m))
  for i in range(m):
    a = random.randint(N_MIN, n)
    b = random.randint(N_MIN, n)
    f.write("{} {}\n".format(a, b))
  f.close()

def main():
  global seq

  for i in range(100):
    generate()
    seq += 1

if __name__ == '__main__':
  main()
