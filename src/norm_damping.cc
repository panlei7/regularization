#include "norm_damping.hpp"

#include <string>
#include <armadillo>
#include <yaml-cpp/yaml.h>

NormDamping::NormDamping(const std::string &filenm):
  Regularization(filenm)
{
  YAML::Node config = YAML::LoadFile(filenm);
  output_file_ = config["file_norm"].as<std::string>();

  this->load();
}


void NormDamping::save()
{
  Regularization::save(output_file_);
}


void NormDamping::cal_fitness()
{
  fitness_ = arma::accu(arma::square(umodel_-rmodel_));
}


void NormDamping::cal_gradient()
{
  gradient_ = 2*(umodel_ - rmodel_);
}
