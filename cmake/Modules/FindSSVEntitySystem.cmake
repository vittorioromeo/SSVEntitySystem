# -*- cmake -*-

# - Find SSVEntitySystem
# Find the SSVEntitySystem includes and library
# This module defines
# SSVENTITYSYSTEM_INCLUDE_DIR, where to find SSVEntitySystem headers.
# SSVENTITYSYSTEM_LIBRARIES, the libraries needed to use SSVEntitySystem.
# SSVENTITYSYSTEM_FOUND, If false, do not try to use SSVEntitySystem.
# also defined, but not for general use are
# SSVENTITYSYSTEM_LIBRARY, where to find the SSVEntitySystem library.

FIND_PATH(SSVENTITYSYSTEM_INCLUDE_DIR
  NAMES SSVEntitySystem/SSVEntitySystem.h
  PATH_SUFFIXES include/
  PATHS "${PROJECT_SOURCE_DIR}/../SSVEntitySystem/"
  "${PROJECT_SOURCE_DIR}/extlibs/SSVEntitySystem/"
  ${SSVENTITYSYSTEM_ROOT}
  $ENV{SSVENTITYSYSTEM_ROOT}
  /usr/local/
  /usr/
  /sw/         # Fink
  /opt/local/  # DarwinPorts
  /opt/csw/    # Blastwave
  /opt/
)

message("\nFound SSVEntitySystem include at: ${SSVENTITYSYSTEM_INCLUDE_DIR}.\n")

FIND_LIBRARY(SSVENTITYSYSTEM_LIBRARY
  NAMES SSVEntitySystem libSSVEntitySystem SSVEntitySystem-s libSSVEntitySystem-s ssventitysystem libssventitysystem ssventitysystem-s libssventitysystem-s
  PATH_SUFFIXES lib/ lib64/
  PATHS "${PROJECT_SOURCE_DIR}/../SSVEntitySystem/"
  "${PROJECT_SOURCE_DIR}/extlibs/SSVEntitySystem/"
  ${SSVENTITYSYSTEM_ROOT}
  $ENV{SSVENTITYSYSTEM_ROOT}
  /usr/local/
  /usr/
  /sw/         # Fink
  /opt/local/  # DarwinPorts
  /opt/csw/    # Blastwave
  /opt/
)

message("\nFound SSVEntitySystem library at: ${SSVENTITYSYSTEM_LIBRARY}.\n")

IF (SSVENTITYSYSTEM_LIBRARY AND SSVENTITYSYSTEM_INCLUDE_DIR)
    SET(SSVENTITYSYSTEM_LIBRARIES ${SSVENTITYSYSTEM_LIBRARY})
    SET(SSVENTITYSYSTEM_FOUND TRUE)
ELSE (SSVENTITYSYSTEM_LIBRARY AND SSVENTITYSYSTEM_INCLUDE_DIR)
    SET(SSVENTITYSYSTEM_FOUND FALSE)
ENDIF (SSVENTITYSYSTEM_LIBRARY AND SSVENTITYSYSTEM_INCLUDE_DIR)

IF (SSVENTITYSYSTEM_FOUND)
      MESSAGE(STATUS "Found SSVEntitySystem in ${SSVENTITYSYSTEM_INCLUDE_DIR}")
ELSE (SSVENTITYSYSTEM_FOUND)
   IF (SSVENTITYSYSTEM_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find SSVEntitySystem library")
   ENDIF (SSVENTITYSYSTEM_FIND_REQUIRED)
ENDIF (SSVENTITYSYSTEM_FOUND)

MARK_AS_ADVANCED(
  SSVENTITYSYSTEM_LIBRARY
  SSVENTITYSYSTEM_INCLUDE_DIR
)
