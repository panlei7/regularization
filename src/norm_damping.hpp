#ifndef REG_NORMDAMPING_H_
#define REG_NORMDAMPING_H_

#include "regularization.hpp"
#include <string>

class NormDamping: public Regularization
{
public:
  explicit NormDamping(std::string &filenm);

  void cal_fitness() override;
  void cal_gradient() override;

  void save();

private:
  std::string output_file_;
};

#endif
