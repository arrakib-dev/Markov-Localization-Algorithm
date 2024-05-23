# CMakeList.txt : CMake project for markov_localization_algorithm, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (markov_localization_algorithm "markov_localization_algorithm.cpp" "bayes_filter.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET markov_localization_algorithm PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
include_directories("include")