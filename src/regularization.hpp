#ifndef REGULARIZATION_H_
#define REGULARIZATION_H_

#include <string>
#include <armadillo>

class Regularization
{
public:
  Regularization(std::string &filenm);

private:
  int ni_;
  int nk_;
  int nx_;
  int nz_;
  int nplus_;
};

#endif
