# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(libstudxml_FRAMEWORKS_FOUND_DEBUG "") # Will be filled later
conan_find_apple_frameworks(libstudxml_FRAMEWORKS_FOUND_DEBUG "${libstudxml_FRAMEWORKS_DEBUG}" "${libstudxml_FRAMEWORK_DIRS_DEBUG}")

set(libstudxml_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET libstudxml_DEPS_TARGET)
    add_library(libstudxml_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET libstudxml_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Debug>:${libstudxml_FRAMEWORKS_FOUND_DEBUG}>
             $<$<CONFIG:Debug>:${libstudxml_SYSTEM_LIBS_DEBUG}>
             $<$<CONFIG:Debug>:expat::expat>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### libstudxml_DEPS_TARGET to all of them
conan_package_library_targets("${libstudxml_LIBS_DEBUG}"    # libraries
                              "${libstudxml_LIB_DIRS_DEBUG}" # package_libdir
                              "${libstudxml_BIN_DIRS_DEBUG}" # package_bindir
                              "${libstudxml_LIBRARY_TYPE_DEBUG}"
                              "${libstudxml_IS_HOST_WINDOWS_DEBUG}"
                              libstudxml_DEPS_TARGET
                              libstudxml_LIBRARIES_TARGETS  # out_libraries_targets
                              "_DEBUG"
                              "libstudxml"    # package_name
                              "${libstudxml_NO_SONAME_MODE_DEBUG}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${libstudxml_BUILD_DIRS_DEBUG} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Debug ########################################
    set_property(TARGET libstudxml::libstudxml
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Debug>:${libstudxml_OBJECTS_DEBUG}>
                 $<$<CONFIG:Debug>:${libstudxml_LIBRARIES_TARGETS}>
                 )

    if("${libstudxml_LIBS_DEBUG}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET libstudxml::libstudxml
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     libstudxml_DEPS_TARGET)
    endif()

    set_property(TARGET libstudxml::libstudxml
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Debug>:${libstudxml_LINKER_FLAGS_DEBUG}>)
    set_property(TARGET libstudxml::libstudxml
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Debug>:${libstudxml_INCLUDE_DIRS_DEBUG}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET libstudxml::libstudxml
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Debug>:${libstudxml_LIB_DIRS_DEBUG}>)
    set_property(TARGET libstudxml::libstudxml
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Debug>:${libstudxml_COMPILE_DEFINITIONS_DEBUG}>)
    set_property(TARGET libstudxml::libstudxml
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Debug>:${libstudxml_COMPILE_OPTIONS_DEBUG}>)

########## For the modules (FindXXX)
set(libstudxml_LIBRARIES_DEBUG libstudxml::libstudxml)
