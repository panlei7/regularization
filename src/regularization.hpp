#ifndef REGULARIZATION_H_
#define REGULARIZATION_H_

#include <string>
#include <armadillo>

class Regularization
{
public:
  explicit Regularization(const std::string& filenm);
  virtual void cal_fitness() = 0;
  virtual void cal_gradient() = 0;
  void print_fitness(const std::string& method) const;

protected:
  void load();
  void save(std::string &filenm);

  int ni_;
  int nk_;
  int nx_;
  int nz_;
  int ni1_;
  int ni2_;
  int nk1_;
  int nk2_;
  int nplus_;
  std::string file_umodel_;
  std::string file_rmodel_;

  arma::mat umodel_; // updated model
  arma::mat rmodel_; // reference model

  arma::mat gradient_;
  double fitness_;
};

#endif
