!/usr/bin/env python3

import numpy as np
import yaml

class Model:

    def __init__(self, ni, nk, nplus):
        self.ni = ni
        self.nk = nk
        self.nplus = nplus
        self.nx = ni + nplus * 2
        self.nz = nk + nplus * 2
        self.data = np.zeros(self.nx, self.nz)

    def save(self, filenm):
        self.data.tofile(filenm)

class ReferenceModel(Model):
    pass


class UpdatedModel(Model):

    def square(self, center, width):
        cx, cz = [int(a) for a in center]
        if cx < 0 or cx > self.ni-1 or cz < 0 or cz > self.nk-1:
            raise ValueError("center is out of range")
        nw = int(width)
        if nw > ni or nw > nk:
            raise ValueError("width is too large")
        cx, cz = [a + self.plus for a in [cx, cz]]
        nw_half = nw / 2
        self.data[cx-nw_half:cx+nw_half, cz-nw_half, cz+nw_half] = 1.


if __name__ == '__main__':
    with open('config.yaml', 'r') as stream:
        config = yaml.load(stream)

    ni = config['ni']
    nk = config['nk']
    nplus = config['nplus']
    file_rmodel = config['file_rmodel']
    file_umodel = config['file_umodel']
    center = config['center']
    width = config['width']

    rmodel = ReferenceModel(ni, nk, nplus)
    rmodel.save(file_rmodel)

    umodel = UpdatedModel(ni, nk, nplus)
    umodel.square(center, width)
    umodel.save(file_umodel)
