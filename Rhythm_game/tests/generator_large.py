#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random

NUMOFCASE = 10
N_MIN = 1
N_MAX = 1000
M_MIN = 0
M_MAX = 100

seq = 0

def generate():
  global seq

  n = N_MAX
  m = M_MAX
  print("{} {}".format(n, m))
  for i in range(m):
    a = random.randint(N_MIN, n)
    b = random.randint(N_MIN, n)
    while a == b:
      b = random.randint(N_MIN, n)
    print("{} {}".format(a, b))

def main():
  global seq

  generate()

if __name__ == '__main__':
  main()
