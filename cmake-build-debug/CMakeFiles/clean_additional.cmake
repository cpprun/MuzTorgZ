# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/MuzTorgZ_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/MuzTorgZ_autogen.dir/ParseCache.txt"
  "MuzTorgZ_autogen"
  )
endif()
