#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random
import math

seq = 0
NUMOFCASE = 10

N_MIN = 2
N_MAX = 16
XY_MIN = -100
XY_MAX = 100
R_MIN = 1
R_MAX = 100

class Circle:
    x = None
    y = None
    r = None

def checkCommon(c, L):
    for i in range(L):
        for j in range(i+1, L):
            dist = (c[i].x - c[j].x)**2 + (c[i].y-c[j].y)**2
            r = (c[i].r + c[j].r)**2
            if dist <= r:
                return False
    return True

def checkCenter(circles):
    for i in range(len(circles)):
        for j in range(i+1, len(circles)):
            dist = (circles[i].x - circles[j].x) ** 2 + (circles[i].y - circles[j].y) ** 2
            if dist <= 4**2:
                return False
    return True

def generate():
    filename = '50-random{:02d}.in'.format(seq)

    f = open(filename, 'w')
    N = random.randint(N_MIN, N_MAX)
    f.write(str(N) + '\n')

    circles = []
    for i in range(N):
        c = Circle()
        c.x = random.randint(XY_MIN, XY_MAX)
        c.y = random.randint(XY_MIN, XY_MAX)
        circles.append(c)
        while not checkCenter(circles):
            print("D")
            c.x = random.randint(XY_MIN, XY_MAX)
            c.y = random.randint(XY_MIN, XY_MAX)
            circles[-1] = c


    for i in range(N):
        dist_min = 99999999999999
        for j in range(N):
            if i == j:
                continue
            dist = (circles[i].x - circles[j].x)**2 + (circles[i].y - circles[j].y)**2
            dist_min = min(dist_min, dist)

        print(dist_min)

        circles[i].r = random.randint(R_MIN, int(math.sqrt(dist_min)/2))
        while not checkCommon(circles, i):
            R_ORG = circles[i].r;
            circles[i].r = random.randint(R_MIN, R_ORG)

    print("B")

    for i in range(N):
        f.write('{} {} {}\n'.format(circles[i].x, circles[i].y, circles[i].r))
    f.close() 
    print("C")

def main():
    global seq
    for i in range(NUMOFCASE):
        generate()
        seq += 1
        print(i)

if __name__ == '__main__':
    main()
