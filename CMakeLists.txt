# ------------------------------------------------------------------------------
#
# Copyright 2016 The Arken Platform Authors.
#
# All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.
#
# ------------------------------------------------------------------------------

include_directories(.)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/include)
include_directories(${PROJECT_SOURCE_DIR}/src/lua/json)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/clib/arken/net/HttpServer)

#add_executable(
#    miranda
#    main.cpp
#    mirandaserver.cpp
#    mirandatask.cpp
#    mirandaserver.h
#    mirandatask.h
#)

add_library(
  arken.net.HttpServer.miranda SHARED
  mirandaserver.cpp
  mirandatask.cpp
  mirandaserver.h
  mirandatask.h
  ${PROJECT_SOURCE_DIR}/src/arken/net/httpserver/httpserver.cpp
  httpserver.cpp
  run.cpp
)

set_target_properties(arken.net.HttpServer.miranda PROPERTIES PREFIX "" OUTPUT_NAME miranda)



find_package(Qt5Core)
find_package(Qt5Network)
find_package(Qt5Widgets)
find_package(Qt5Gui)

target_link_libraries( arken.net.HttpServer.miranda arken )
target_link_libraries( arken.net.HttpServer.miranda Qt5::Core Qt5::Network )
