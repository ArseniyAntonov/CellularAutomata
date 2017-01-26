import numpy as np
import matplotlib.pyplot as plt

plt.ion()


class Ant(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Game(object):
    def __init__(self, steps=100, x=25, y=25):
        self.colors = []
        self.rules = []
        self.ant = Ant(x, y)
        self.direction = 1  # 1- up 2 -left 3 - down 4 - right
        self.field = [[0 for _ in range(x * 2 + 1)] for _ in range(y * 2 + 1)]
        self.steps = steps

    def turn(self, direction):
        if direction == 'right':
            self.direction += 1
        if direction == 'left':
            self.direction -= 1
        if self.direction == 5:
            self.direction = 1
        if self.direction == 0:
            self.direction = 4

    def move_forward(self):
        if self.direction == 1:
            self.ant.y -= 1
        if self.direction == 2:
            self.ant.x -= 1
        if self.direction == 3:
            self.ant.y += 1
        if self.direction == 4:
            self.ant.x += 1

    def next_step(self):
        ax = self.ant.x
        ay = self.ant.y
        if self.field[ax][ay] == 1:
            self.turn('right')
            self.field[ax][ay] = 0
        elif self.field[ax][ay] == 0:
            self.turn('left')
            self.field[ax][ay] = 1
        self.move_forward()

    def start(self):
        step = 0
        while step < self.steps:
            self.next_step()
            step += 1
            plt.matshow(np.matrix(self.field), fignum=1, cmap=plt.cm.summer)
            plt.pause(0.0001)
            plt.clf()


Game(1000, 50, 50).start()
