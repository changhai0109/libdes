cmake_minimum_required(VERSION 3.20)
project(libdes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindPkgConfig)

# numactl
pkg_check_modules(numactl REQUIRED IMPORTED_TARGET numa)

# zlib
pkg_check_modules(zlib REQUIRED IMPORTED_TARGET zlib)


add_library(
  des
  SHARED
  ${PROJECT_SOURCE_DIR}/src/des/Logger.cc
  ${PROJECT_SOURCE_DIR}/src/des/Component.cc
  ${PROJECT_SOURCE_DIR}/src/des/Observer.cc
  ${PROJECT_SOURCE_DIR}/src/des/Event.cc
  ${PROJECT_SOURCE_DIR}/src/des/Time.cc
  ${PROJECT_SOURCE_DIR}/src/des/ActiveComponent.cc
  ${PROJECT_SOURCE_DIR}/src/des/MpScQueue.cc
  ${PROJECT_SOURCE_DIR}/src/des/Simulator.cc
  ${PROJECT_SOURCE_DIR}/src/des/Mapper.cc
  ${PROJECT_SOURCE_DIR}/src/des/util/RoundRobinMapper.cc
  ${PROJECT_SOURCE_DIR}/src/des/util/BasicObserver.cc
  ${PROJECT_SOURCE_DIR}/src/des/util/Scheduler.cc
  ${PROJECT_SOURCE_DIR}/src/des/util/SpinLock.cc
  ${PROJECT_SOURCE_DIR}/src/des/util/RandomMapper.cc
  ${PROJECT_SOURCE_DIR}/src/des/Mapper.h
  ${PROJECT_SOURCE_DIR}/src/des/timeconf.h
  ${PROJECT_SOURCE_DIR}/src/des/Time.h
  ${PROJECT_SOURCE_DIR}/src/des/Logger.h
  ${PROJECT_SOURCE_DIR}/src/des/Component.h
  ${PROJECT_SOURCE_DIR}/src/des/Event.h
  ${PROJECT_SOURCE_DIR}/src/des/Simulator.h
  ${PROJECT_SOURCE_DIR}/src/des/ActiveComponent.h
  ${PROJECT_SOURCE_DIR}/src/des/Observer.h
  ${PROJECT_SOURCE_DIR}/src/des/des.h
  ${PROJECT_SOURCE_DIR}/src/des/MpScQueue.h
  ${PROJECT_SOURCE_DIR}/src/des/cacheline_util.h
  ${PROJECT_SOURCE_DIR}/src/des/util/SpinLock.h
  ${PROJECT_SOURCE_DIR}/src/des/util/RandomMapper.h
  ${PROJECT_SOURCE_DIR}/src/des/util/BasicObserver.h
  ${PROJECT_SOURCE_DIR}/src/des/util/Scheduler.h
  ${PROJECT_SOURCE_DIR}/src/des/util/RoundRobinMapper.h

  ${PROJECT_SOURCE_DIR}/src/rnd/Random.cc
  ${PROJECT_SOURCE_DIR}/src/rnd/Queue.h
  ${PROJECT_SOURCE_DIR}/src/rnd/Random.h
  ${PROJECT_SOURCE_DIR}/src/rnd/Queue.tcc
  ${PROJECT_SOURCE_DIR}/src/rnd/Random.tcc

  ${PROJECT_SOURCE_DIR}/src/prim/prim.h
  )

set_target_properties(
  des
  PROPERTIES
  LINKER_LANGUAGE
  CXX
  POSITION_INDEPENDENT_CODE
  ON
  )

target_include_directories(
  des
  PUBLIC
  ${PROJECT_SOURCE_DIR}/src
  ${NUMACTL_INCLUDE_DIR}
  ${ZLIB_INCLUDE_DIR}
  )

target_link_libraries(
  des
  PkgConfig::numactl
  PkgConfig::zlib
  )

include(GNUInstallDirs)

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/Mapper.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/timeconf.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/Time.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/Logger.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/Component.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/Event.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/Simulator.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/ActiveComponent.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/Observer.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/des.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/MpScQueue.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/cacheline_util.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/util/SpinLock.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/util/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/util/RandomMapper.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/util/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/util/BasicObserver.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/util/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/util/Scheduler.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/util/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/des/util/RoundRobinMapper.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/des/util/
  )

install(
  TARGETS
  des
  )

configure_file(
  ${PROJECT_SOURCE_DIR}/libdes.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/libdes.pc
  @ONLY
  )
install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/libdes.pc
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/pkgconfig/
  )
