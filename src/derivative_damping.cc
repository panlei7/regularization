#include "derivative_damping.hpp"
#include "laplacian.hpp"

#include <string>
#include <armadillo>
#include <yaml-cpp/yaml.h>

DerivativeDamping::DerivativeDamping(std::string &filenm):
  Regularization(filenm)
{
  YAML::Node config = YAML::LoadFile(filenm);
  output_file_ = config["file_deriv"].as<std::string>();

  laplacian_ = laplacian2d(umodel_-rmodel_, ni1_, ni2_, nk1_, nk2_);
}


void DerivativeDamping::save()
{
  Regularization::save(output_file_);
}


void DerivativeDamping::cal_fitness()
{
  fitness_ = arma::accu(arma::square(laplacian_));
}


void DerivativeDamping::cal_gradient()
{
  gradient_ = 2 * laplacian2d(laplacian_, ni1_, ni2_, nk1_, nk2_);

}
