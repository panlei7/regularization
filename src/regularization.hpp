#ifndef REGULARIZATION_H_
#define REGULARIZATION_H_

#include <string>
#include <armadillo>

class Regularization
{
public:
  explicit Regularization(std::string &filenm);

protected:
  void load(std::string &filenm);
  void save(std::string &filenm);

private:
  int ni_;
  int nk_;
  int nx_;
  int nz_;
  int nplus_;
  arma::mat data_;
  arma::mat gradient_;
  double fitness_;
};

#endif
