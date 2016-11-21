#ifndef REGULARIZATION_H_
#define REGULARIZATION_H_

#include <string>
#include <armadillo>

class Regularization
{
public:
  explicit Regularization(std::string& filenm);
  void load();
  virtual void cal_fitness();
  virtual void cal_gradient();
  void print_fitness(std::string& method);

protected:
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
