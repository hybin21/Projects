# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/LAB18_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/LAB18_autogen.dir/ParseCache.txt"
  "LAB18_autogen"
  )
endif()
