#include "../include/catch.hpp"


#include <armadillo>

TEST_CASE("read binary file", "[armadillo]")
{
  arma::mat x;
  x.load("rmodel.h5");
  REQUIRE(arma::size(x) == arma::size(24, 24));
}
