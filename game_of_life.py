import random
import numpy as np
import matplotlib.pyplot as plt

plt.ion()


class Field():
    def __init__(self, x=10, y=10, borders=True):
        self.x = x
        self.y = y
        self.borders = borders
        self.field = [[random.getrandbits(1) for _ in range(self.x + 1)] for _ in range(self.y + 1)]

        self.tmp_field = ''
        self._clear_tmp_field()

    def _clear_tmp_field(self):
        self.tmp_field = [[0 for _ in range(self.x + 1)] for _ in range(self.y + 1)]

    def next_step(self):

        for x in range(1, self.x):
            for y in range(1, self.y):
                self._check_neighborhoods(x, y)

        self.field = self.tmp_field
        self._clear_tmp_field()

    def _check_neighborhoods(self, x, y):
        neighborhoods = 0
        for xp in range(-1, 2):
            for yp in range(-1, 2):
                if (xp != 0 or yp != 0) and self.field[x + xp][y + yp] == 1:
                    neighborhoods += 1
        if self.field[x][y] == 0 and neighborhoods == 3:
            self.tmp_field[x][y] = 1
        elif self.field[x][y] == 1 and (neighborhoods == 2 or neighborhoods == 3):
            self.tmp_field[x][y] = 1
        elif self.field[x][y] == 1:
            self.tmp_field[x][y] = 0


class Game():
    def __init__(self, steps=100):
        self.steps = steps

        self.field = Field(50, 50)

    def start(self):
        step = 0
        while step < self.steps:
            self.field.next_step()
            step += 1
            plt.matshow(np.matrix(self.field.field), fignum=1, cmap=plt.cm.summer)
            plt.pause(0.0001)
            plt.clf()


Game(100).start()
