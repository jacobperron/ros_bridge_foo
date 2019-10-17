cmake_minimum_required(VERSION 2.8.3)
project(foo)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  foo_msgs
)

catkin_package(
 CATKIN_DEPENDS roscpp foo_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(foo_talker src/foo_talker.cpp)

target_link_libraries(foo_talker
  ${catkin_LIBRARIES}
)

install(TARGETS foo_talker
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
