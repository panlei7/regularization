#include "laplacian.hpp"

#include <armadillo>

namespace {
  const double DIAG = 0.16666667;
  const double NEIG = 0.66666667;
  const double CENTER = -3.333333;
  const double C_1_1 = DIAG;
  const double C_100 = NEIG;
  const double C_101 = DIAG;
  const double C00_1 = NEIG;
  const double C0000 = CENTER;
  const double C0001 = NEIG;
  const double C01_1 = DIAG;
  const double C0100 = NEIG;
  const double C0101 = DIAG;
}

arma::mat CentralDifference(const arma::mat& data,
                           int ni1,
                           int ni2,
                           int nk1,
                           int nk2)
{
  arma::mat ret(arma::size(data), arma::fill::zeros);
  ret.submat(ni1, nk1, ni2, nk2) =
    C_1_1 * data.submat(ni1-1, nk1-1, ni2-1, nk2-1) +
    C_100 * data.submat(ni1-1, nk1,   ni2-1, nk2  ) +
    C_101 * data.submat(ni1-1, nk1+1, ni2-1, nk2+1) +
    C00_1 * data.submat(ni1,   nk1-1, ni2,   nk2-1) +
    C0000 * data.submat(ni1,   nk1,   ni2,   nk2  ) +
    C0001 * data.submat(ni1,   nk1+1, ni2,   nk2+1) +
    C01_1 * data.submat(ni1+1, nk1-1, ni2+1, nk2-1) +
    C0100 * data.submat(ni1+1, nk1,   ni2+1, nk2  ) +
    C0101 * data.submat(ni1+1, nk1+1, ni2+1, nk2+1);
  return ret;
}
