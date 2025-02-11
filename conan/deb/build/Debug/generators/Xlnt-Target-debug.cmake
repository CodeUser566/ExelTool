# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(xlnt_FRAMEWORKS_FOUND_DEBUG "") # Will be filled later
conan_find_apple_frameworks(xlnt_FRAMEWORKS_FOUND_DEBUG "${xlnt_FRAMEWORKS_DEBUG}" "${xlnt_FRAMEWORK_DIRS_DEBUG}")

set(xlnt_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET xlnt_DEPS_TARGET)
    add_library(xlnt_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET xlnt_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Debug>:${xlnt_FRAMEWORKS_FOUND_DEBUG}>
             $<$<CONFIG:Debug>:${xlnt_SYSTEM_LIBS_DEBUG}>
             $<$<CONFIG:Debug>:libstudxml::libstudxml;miniz::miniz>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### xlnt_DEPS_TARGET to all of them
conan_package_library_targets("${xlnt_LIBS_DEBUG}"    # libraries
                              "${xlnt_LIB_DIRS_DEBUG}" # package_libdir
                              "${xlnt_BIN_DIRS_DEBUG}" # package_bindir
                              "${xlnt_LIBRARY_TYPE_DEBUG}"
                              "${xlnt_IS_HOST_WINDOWS_DEBUG}"
                              xlnt_DEPS_TARGET
                              xlnt_LIBRARIES_TARGETS  # out_libraries_targets
                              "_DEBUG"
                              "xlnt"    # package_name
                              "${xlnt_NO_SONAME_MODE_DEBUG}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${xlnt_BUILD_DIRS_DEBUG} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Debug ########################################
    set_property(TARGET xlnt::xlnt
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Debug>:${xlnt_OBJECTS_DEBUG}>
                 $<$<CONFIG:Debug>:${xlnt_LIBRARIES_TARGETS}>
                 )

    if("${xlnt_LIBS_DEBUG}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET xlnt::xlnt
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     xlnt_DEPS_TARGET)
    endif()

    set_property(TARGET xlnt::xlnt
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Debug>:${xlnt_LINKER_FLAGS_DEBUG}>)
    set_property(TARGET xlnt::xlnt
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Debug>:${xlnt_INCLUDE_DIRS_DEBUG}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET xlnt::xlnt
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Debug>:${xlnt_LIB_DIRS_DEBUG}>)
    set_property(TARGET xlnt::xlnt
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Debug>:${xlnt_COMPILE_DEFINITIONS_DEBUG}>)
    set_property(TARGET xlnt::xlnt
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Debug>:${xlnt_COMPILE_OPTIONS_DEBUG}>)

########## For the modules (FindXXX)
set(xlnt_LIBRARIES_DEBUG xlnt::xlnt)
