# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(miniz_FRAMEWORKS_FOUND_DEBUG "") # Will be filled later
conan_find_apple_frameworks(miniz_FRAMEWORKS_FOUND_DEBUG "${miniz_FRAMEWORKS_DEBUG}" "${miniz_FRAMEWORK_DIRS_DEBUG}")

set(miniz_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET miniz_DEPS_TARGET)
    add_library(miniz_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET miniz_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Debug>:${miniz_FRAMEWORKS_FOUND_DEBUG}>
             $<$<CONFIG:Debug>:${miniz_SYSTEM_LIBS_DEBUG}>
             $<$<CONFIG:Debug>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### miniz_DEPS_TARGET to all of them
conan_package_library_targets("${miniz_LIBS_DEBUG}"    # libraries
                              "${miniz_LIB_DIRS_DEBUG}" # package_libdir
                              "${miniz_BIN_DIRS_DEBUG}" # package_bindir
                              "${miniz_LIBRARY_TYPE_DEBUG}"
                              "${miniz_IS_HOST_WINDOWS_DEBUG}"
                              miniz_DEPS_TARGET
                              miniz_LIBRARIES_TARGETS  # out_libraries_targets
                              "_DEBUG"
                              "miniz"    # package_name
                              "${miniz_NO_SONAME_MODE_DEBUG}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${miniz_BUILD_DIRS_DEBUG} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Debug ########################################
    set_property(TARGET miniz::miniz
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Debug>:${miniz_OBJECTS_DEBUG}>
                 $<$<CONFIG:Debug>:${miniz_LIBRARIES_TARGETS}>
                 )

    if("${miniz_LIBS_DEBUG}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET miniz::miniz
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     miniz_DEPS_TARGET)
    endif()

    set_property(TARGET miniz::miniz
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Debug>:${miniz_LINKER_FLAGS_DEBUG}>)
    set_property(TARGET miniz::miniz
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Debug>:${miniz_INCLUDE_DIRS_DEBUG}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET miniz::miniz
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Debug>:${miniz_LIB_DIRS_DEBUG}>)
    set_property(TARGET miniz::miniz
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Debug>:${miniz_COMPILE_DEFINITIONS_DEBUG}>)
    set_property(TARGET miniz::miniz
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Debug>:${miniz_COMPILE_OPTIONS_DEBUG}>)

########## For the modules (FindXXX)
set(miniz_LIBRARIES_DEBUG miniz::miniz)
