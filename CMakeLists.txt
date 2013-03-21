cmake_minimum_required(VERSION 2.8)
project(SSVEntitySystem)

set(SSVENTITYSYSTEM_BUILD_SHARED_LIB FALSE CACHE BOOL "Build shared libraries.")
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type." FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" CACHE STRING "" FORCE)

set(SPARSEHASH_INCLUDE_DIR "" CACHE STRING "google::sparsehash include directory")
set(SPARSEHASH_LIBRARY "" CACHE STRING "google::sparsehash library file")
set(SSVUTILS_INCLUDE_DIR "" CACHE STRING "SSVUtils include directory")
set(SSVUTILS_LIBRARY "" CACHE STRING "SSVUtils library file")

if(SSVENTITYSYSTEM_BUILD_SHARED_LIB)
	set(LIB_TYPE SHARED)
else()
	set(LIB_TYPE STATIC)
endif()

set(SRC_DIR "src")
set(INC_DIR "include")

set(
	SOURCES
	${INC_DIR}/${PROJECT_NAME}/Core/Component.h
	${INC_DIR}/${PROJECT_NAME}/Core/Entity.h
	${INC_DIR}/${PROJECT_NAME}/Core/Manager.h
	${INC_DIR}/${PROJECT_NAME}/Utils/Repository.h
	${INC_DIR}/${PROJECT_NAME}/Utils/Utils.h
	${SRC_DIR}/${PROJECT_NAME}/Core/Component.cpp
	${SRC_DIR}/${PROJECT_NAME}/Core/Entity.cpp
	${SRC_DIR}/${PROJECT_NAME}/Core/Manager.cpp
	${SRC_DIR}/${PROJECT_NAME}/Utils/Utils.cpp
)

include_directories(${SPARSEHASH_INCLUDE_DIR})
include_directories(${SSVUTILS_INCLUDE_DIR})
include_directories(${INC_DIR})

add_library(${PROJECT_NAME} ${LIB_TYPE} ${SOURCES})
target_link_libraries(SSVEntitySystem ${SPARSEHASH_LIBRARY})
target_link_libraries(SSVEntitySystem ${SSVUTILS_LIBRARY})

if(SSVENTITYSYSTEM_BUILD_SHARED_LIB)
	set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)
else()
	set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -s-d)
	set_target_properties(${PROJECT_NAME} PROPERTIES RELEASE_POSTFIX -s)
endif()

if(WIN32)
	install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)
else()
	install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION lib
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)
endif()

install(DIRECTORY ${INC_DIR}
	DESTINATION .)
