cmake_minimum_required(VERSION 3.5)
project(foo)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(foo_msgs REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(foo_listener
  src/foo_listener.cpp
)
ament_target_dependencies(foo_listener
  "foo_msgs"
  "rclcpp"
)

install(TARGETS foo_listener
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
