#!/usr/bin/env python3

import numpy as np
import yaml
import h5py


class Model:

    def __init__(self, ni, nk, nplus):
        self.ni = ni
        self.nk = nk
        self.nplus = nplus
        self.nx = ni + nplus * 2
        self.nz = nk + nplus * 2
        self.data = np.zeros([self.nx, self.nz])

    def save(self, filenm):
        h5f = h5py.File(filenm, 'w')
        h5f.create_dataset('dataset_1', data=self.data)
        h5f.close()


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
        cx, cz = [a + self.nplus for a in [cx, cz]]
        nw_half = nw // 2
        self.data[cx-nw_half:cx+nw_half, cz-nw_half:cz+nw_half] = 1.


if __name__ == '__main__':
    with open('config.yaml', 'r') as stream:
        config = yaml.load(stream)

    ni = config['ni']
    nk = config['nk']
    nplus = config['nplus']
    file_rmodel = config['file_rmodel']
    file_umodel = config['file_umodel']
    center_square = config['center_square']
    width_square = config['width_square']

    rmodel = ReferenceModel(ni, nk, nplus)
    rmodel.save(file_rmodel)

    umodel = UpdatedModel(ni, nk, nplus)
    umodel.square(center_square, width_square)
    umodel.save(file_umodel)
