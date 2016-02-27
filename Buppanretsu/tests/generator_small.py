#!/usr/bin/python3
# -*- coding: utf-8 -*-

import random
import sys

NUMOFCASE = 10
W_MIN = 4
W_MAX = 100
H_MIN = 4
H_MAX = 100

seq = 0

def generate():
  global seq
  assert len(sys.argv) == 1 or len(sys.argv) == 3, "Usage: python3 {} [W_size] [H_size]\nlen(sys.argv) = {}".format(sys.argv[0], len(sys.argv))
  h = random.randint(H_MIN, H_MAX)
  w = random.randint(W_MIN, W_MAX)
  if len(sys.argv) == 3:
    h = int(sys.argv[1])
    w = int(sys.argv[2])

  N_MIN = 0;
  N_MAX = min(100, (w*2 + h - 2) - 1)

  left_max = w*2+h-2-1
  right_max = w*2+h-2-1-4
  n =  left_max+ right_max
  print("{} {}\n{}".format(w, h, n))

  query = ['0' for i in range(left_max)]
  for i in range(right_max):
    index = random.randint(0, len(query))
    query.insert(index, '1')
  print (" ".join(query))

def main():
  generate()

if __name__ == '__main__':
  main()
