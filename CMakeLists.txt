# CMakeList.txt : CMake project for Raytrace, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Raytrace")

# Add source to this project's executable.
add_executable (Raytrace "Raytrace.cc" "Raytrace.h" "include/vec3.h" "include/color.h" "include/ray.h" "include/hittable.h" "include/sphere.h" "include/hittable_list.h" "include/rtweekend.h" "include/interval.h")


target_include_directories(Raytrace PRIVATE ${CMAKE_SOURCE_DIR}/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Raytrace PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
