# Install script for directory: /home/lzmuda/DCL/ImageAcquisition/src/Types

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/lzmuda/DCL/ImageAcquisition/dist")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "sdk")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Types" TYPE FILE FILES
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/CameraInfo.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/Drawable.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/DrawableContainer.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/Ellipse.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/Features.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/ImagePosition.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/Line.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/MatrixTranslator.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/Rectangle.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/stream_OpenCV.hpp"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "sdk")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "sdk")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Types/Objects3D" TYPE FILE FILES
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/Objects3D/Chessboard.hpp"
    "/home/lzmuda/DCL/ImageAcquisition/src/Types/Objects3D/Object3D.hpp"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "sdk")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/lzmuda/DCL/ImageAcquisition/build/src/Types/Circles/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

