# -*- coding: utf-8 -*-
#!/usr/bin/python3

import sys

N_MIN = 1
N_MAX = 1000
M_MIN = 1
M_MAX = 100

def main():
  line = input()
  assert len(line.split()) == 2, 'Too many or less arguments at line 1'
  N = int(line.split()[0])
  M = int(line.split()[1])
  assert N_MIN <= N <= N_MAX, 'N out of range: {}'.format(N)
  assert M_MIN <= M <= M_MAX, 'M out of range: {}'.format(N)

  A_MAX = N
  A_MIN = 1

  num_line = 0
  for line in sys.stdin:
    num_line += 1
    assert len(line.split()) == 2, 'Too many or less arguments at line {}'.format(num_line+1)
    a = int(line.split()[0])
    b = int(line.split()[1])
    assert  A_MIN <= a <= A_MAX , 'a out of range: {}'.format(a)
    assert  A_MIN <= b <= A_MAX , 'b out of range: {}'.format(b)

  assert num_line == M, '{} extra line(s) after end of data'.format(num_line - M)

if __name__ == '__main__':
  main()
