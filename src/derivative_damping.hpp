#ifndef REG_DERIVATIVEDAMPING_H_
#define REG_DERIVATIVEDAMPING_H_

#include "regularization.hpp"
#include <string>

class DerivativeDamping: public Regularization
{
public:
  explicit DerivativeDamping(std::string &filenm);

  void cal_fitness() override;
  void cal_gradient() override;

  void save();

private:
  std::string output_file_;
  arma::mat laplacian_;
};

#endif
