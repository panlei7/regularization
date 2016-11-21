add_library(reg_lib
  regularization.cc
  laplacian.cc
  derivative_damping.cc
  norm_damping.cc
  )

target_link_libraries(reg_lib
  ${ARMADILLO_LIBRARIES}
  ${YAML_CPP_LIBRARIES}
  )

add_executable(reg reg.cc)
target_link_libraries(reg reg_lib)
