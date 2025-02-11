########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(Xlnt_FIND_QUIETLY)
    set(Xlnt_MESSAGE_MODE VERBOSE)
else()
    set(Xlnt_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/XlntTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${xlnt_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(Xlnt_VERSION_STRING "1.5.0")
set(Xlnt_INCLUDE_DIRS ${xlnt_INCLUDE_DIRS_DEBUG} )
set(Xlnt_INCLUDE_DIR ${xlnt_INCLUDE_DIRS_DEBUG} )
set(Xlnt_LIBRARIES ${xlnt_LIBRARIES_DEBUG} )
set(Xlnt_DEFINITIONS ${xlnt_DEFINITIONS_DEBUG} )


# Only the last installed configuration BUILD_MODULES are included to avoid the collision
foreach(_BUILD_MODULE ${xlnt_BUILD_MODULES_PATHS_DEBUG} )
    message(${Xlnt_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


