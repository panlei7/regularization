#include "norm_damping.hpp"
#include "derivative_damping.hpp"


int main(int argc, char *argv[])
{
  std::string filenm;

  if (argc > 1)
    filenm = argv[1];
  else {
    std::cout << "you need to assign the config yaml file." << std::endl;
    return -1;
  }
  NormDamping nd(filenm);
  nd.cal_fitness();
  nd.cal_gradient();
  nd.print_fitness("norm damping");
  nd.save();

  DerivativeDamping dd(filenm);
  dd.cal_fitness();
  dd.cal_gradient();
  dd.print_fitness("derivative damping");
  dd.save();

  return 0;
}
