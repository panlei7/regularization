#ifndef REG_DIFFERENCE_H_
#define REG_DIFFERENCE_H_

#include <armadillo>

arma::mat laplacian2d(const arma::mat& mat,
                      int ni1,
                      int ni2,
                      int nk1,
                      int nk2);


#endif
