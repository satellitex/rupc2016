# -*- coding: utf-8 -*-
#!/usr/bin/python3

import random

W_MIN = 4
W_MAX = 100
H_MIN = 4
H_MAX = 100

seq = 0

def generate():
  global seq

  filename = '50-random{:02d}.in'.format(seq)

  f = open(filename, 'w')
  h = random.randint(H_MIN, H_MAX)
  w = random.randint(W_MIN, W_MAX)

  N_MIN = 0;
  N_MAX = (w*2 + h - 2) - 1

  n = random.randint(N_MIN, N_MAX)
  f.write("{} {}\n{}\n".format(w, h, n))

  for i in range(n):
    if i == 0:
      f.write("{}".format(random.randint(0, 1)))
    else:
      f.write(" {}".format(random.randint(0, 1)))
  f.write('\n')
  f.close()

def main():
  global seq

  for i in range(100):
    generate()
    seq += 1

if __name__ == '__main__':
  main()
