# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Q-Void_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Q-Void_autogen.dir/ParseCache.txt"
  "Q-Void_autogen"
  )
endif()
