#include "regularization.hpp"

#include <string>
#include <armadillo>
#include "yaml-cpp/yaml.h"


Regularization::Regularization(std::string &filenm):
  fitness_(0.)
{
  YAML::Node config = YAML::LoadFile(filenm);

  ni_ = config["ni"].as<int>();
  nk_ = config["nk"].as<int>();
  nx_ = config["nx"].as<int>();
  nz_ = config["nz"].as<int>();
  nplus_ = config["nplus"].as<int>();
  data_.set_size(nx_, nz_);
  gradient_.set_size(nx_, nz_);
}


void Regularization::load(std::string &filenm)
{
  data_.load(filenm, arma::hdf5_binary);
}

void Regularization::save(std::string &filenm)
{
  gradient_.save(filenm, arma::hdf5_binary);
}
