# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/FINALPROJECT_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/FINALPROJECT_autogen.dir/ParseCache.txt"
  "FINALPROJECT_autogen"
  )
endif()
