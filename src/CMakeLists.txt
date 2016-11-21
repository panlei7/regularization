add_library(reg_lib
  regularization.cc
  )

target_link_libraries(reg_lib
  ${ARMADILLO_LIBRARIES}
  ${YAML_CPP_LIBRARIES}
  )
