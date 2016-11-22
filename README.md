# Regularization

This is to test the Tikhonov regularization in finite-difference method.

## Requirement

### softwares and libraries

- [CMake](http://cmake.org/)
- [Armadillo(with hdf5 support)](http://arma.sourceforge.net/)
- [yaml-cpp](https://github.com/jbeder/yaml-cpp)

### Python packages

- yaml
- h5py
- numpy
- matplotlib

## How to run

First of all, install all dependencies.

1. build

	```
	> cd ${CODE_ROOT}
	> mkdir build
	> cd build
	> cmake ..
	> # check if armadillo and yaml library is OK
	> make
	```
2. configurations

	```
	> cd ../example
	> mkdir example1
	> cd example1
	> cp ../template/config.yaml ./
	> vi config.yaml
	> # then edit those parameters as you want
	```
3. run

	```
	> # generate the input data (rmodel.h5 and umodle.h5)
	> # you can modify ${CODE_ROOT}/scripts/make_models.py and create your favorite models.
	> ../../scripts/make_model.py
	> ../../bin/reg config.yaml
	```
4. plot

	```
	> ../../scripts/plot_results.py 0.1 0.05
	```

## Results

The details are in [my blog](http://panlei.today/2016/11/22/regularization/)
