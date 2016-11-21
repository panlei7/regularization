#include "regularization.hpp"

#include <string>
#include <armadillo>
#include "yaml-cpp/yaml.h"
#include <iostream>


Regularization::Regularization(const std::string &filenm):
  fitness_(0.)
{
  YAML::Node config = YAML::LoadFile(filenm);

  ni_ = config["ni"].as<int>();
  nk_ = config["nk"].as<int>();
  nplus_ = config["nplus"].as<int>();
  nx_ = ni_ + nplus_*2;
  nz_ = nk_ + nplus_*2;

  ni1_ = nplus_;
  ni2_ = ni1_ + ni_ - 1;
  nk1_ = nplus_;
  nk2_ = nk1_ + nk_ - 1;

  file_umodel_ = config["file_umodel"].as<std::string>();
  file_rmodel_ = config["file_rmodel"].as<std::string>();

  umodel_.set_size(nx_, nz_);
  rmodel_.set_size(nx_, nz_);
  gradient_.set_size(nx_, nz_);
}


namespace
{
  void load_hdf5(arma::mat& data, std::string& filenm)
  {
    data.load(filenm);
  }
}


void Regularization::load()
{
  load_hdf5(umodel_, file_umodel_);
  load_hdf5(rmodel_, file_rmodel_);
}


void Regularization::save(std::string& filenm)
{
  gradient_.save(filenm, arma::hdf5_binary);
}


void Regularization::print_fitness(const std::string& s) const
{
  std::cout << "The fitness of the "
            << s
            << " is "
            << fitness_
            << std::endl;
}
