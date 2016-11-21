#!/usr/bin/env python3

import numpy as np
import h5py
import matplotlib.pyplot as plt
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('alpha',
                    type=float,
                    help='cofficient for norm damping')
parser.add_argument('beta',
                    type=float,
                    help='cofficient for derivative damping')

args = parser.parse_args()
alpha = args.alpha
beta = args.beta

file_rmodel = "rmodel.h5"
file_umodel = "umodel.h5"
file_norm = "norm.h5"
file_deriv = "deriv.h5"

with h5py.File(file_rmodel, 'r') as hf:
    rmodel = np.array(hf.get('dataset'))
with h5py.File(file_umodel, 'r') as hf:
    umodel = np.array(hf.get('dataset'))
with h5py.File(file_norm, 'r') as hf:
    norm = np.array(hf.get('dataset'))
with h5py.File(file_deriv, 'r') as hf:
    deriv = np.array(hf.get('dataset'))

nz, nx = rmodel.shape

x = np.arange(nx)
z = np.arange(nz)

max_umodel = np.amax(np.abs(umodel))
max_norm = np.amax(np.abs(norm))
max_deriv = np.amax(np.abs(deriv))

plt.figure(figsize=(8, 10))
plt.subplot(321)
plt.pcolormesh(x, z, rmodel,
               vmin=-max_umodel, vmax=max_umodel,
               cmap=plt.cm.seismic)
plt.title(r"reference model $m_0$")
plt.axis([x.min(), x.max(), z.min(), z.max()])
plt.colorbar()

plt.subplot(322)
plt.pcolormesh(x, z, umodel,
               vmin=-max_umodel, vmax=max_umodel,
               cmap=plt.cm.seismic)
plt.title(r"updated model $m_1$")
plt.axis([x.min(), x.max(), z.min(), z.max()])
plt.colorbar()

plt.subplot(323)
plt.pcolormesh(x, z, norm,
               vmin=-max_norm, vmax=max_norm,
               cmap=plt.cm.seismic)
plt.title(r"norm-damping gradient $g_n$")
plt.axis([x.min(), x.max(), z.min(), z.max()])
plt.colorbar()

plt.subplot(324)
plt.pcolormesh(x, z, deriv,
               vmin=-max_deriv, vmax=max_deriv,
               cmap=plt.cm.seismic)
plt.title(r"derivative-damping gradient $g_d$")
plt.axis([x.min(), x.max(), z.min(), z.max()])
plt.colorbar()

plt.subplot(325)
plt.pcolormesh(x, z, umodel-alpha*norm,
               vmin=-max_umodel, vmax=max_umodel,
               cmap=plt.cm.seismic)
plt.title(r"$m_1 - {0:.2f} * g_n$".format(alpha))
plt.axis([x.min(), x.max(), z.min(), z.max()])
plt.colorbar()

plt.subplot(326)
plt.pcolormesh(x, z, umodel-beta*deriv,
               vmin=-max_umodel, vmax=max_umodel,
               cmap=plt.cm.seismic)
plt.title(r"$m_1 - {0:.2f} * g_d$".format(beta))
plt.axis([x.min(), x.max(), z.min(), z.max()])
plt.colorbar()

plt.show()
