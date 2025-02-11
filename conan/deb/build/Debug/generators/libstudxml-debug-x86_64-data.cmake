########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(libstudxml_COMPONENT_NAMES "")
if(DEFINED libstudxml_FIND_DEPENDENCY_NAMES)
  list(APPEND libstudxml_FIND_DEPENDENCY_NAMES expat)
  list(REMOVE_DUPLICATES libstudxml_FIND_DEPENDENCY_NAMES)
else()
  set(libstudxml_FIND_DEPENDENCY_NAMES expat)
endif()
set(expat_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(libstudxml_PACKAGE_FOLDER_DEBUG "/home/gorillabacteria/.conan2/p/b/libst0e54a965cc7b9/p")
set(libstudxml_BUILD_MODULES_PATHS_DEBUG )


set(libstudxml_INCLUDE_DIRS_DEBUG )
set(libstudxml_RES_DIRS_DEBUG )
set(libstudxml_DEFINITIONS_DEBUG "-DLIBSTUDXML_STATIC")
set(libstudxml_SHARED_LINK_FLAGS_DEBUG )
set(libstudxml_EXE_LINK_FLAGS_DEBUG )
set(libstudxml_OBJECTS_DEBUG )
set(libstudxml_COMPILE_DEFINITIONS_DEBUG "LIBSTUDXML_STATIC")
set(libstudxml_COMPILE_OPTIONS_C_DEBUG )
set(libstudxml_COMPILE_OPTIONS_CXX_DEBUG )
set(libstudxml_LIB_DIRS_DEBUG "${libstudxml_PACKAGE_FOLDER_DEBUG}/lib")
set(libstudxml_BIN_DIRS_DEBUG )
set(libstudxml_LIBRARY_TYPE_DEBUG STATIC)
set(libstudxml_IS_HOST_WINDOWS_DEBUG 0)
set(libstudxml_LIBS_DEBUG studxml)
set(libstudxml_SYSTEM_LIBS_DEBUG )
set(libstudxml_FRAMEWORK_DIRS_DEBUG )
set(libstudxml_FRAMEWORKS_DEBUG )
set(libstudxml_BUILD_DIRS_DEBUG )
set(libstudxml_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(libstudxml_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${libstudxml_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${libstudxml_COMPILE_OPTIONS_C_DEBUG}>")
set(libstudxml_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${libstudxml_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${libstudxml_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${libstudxml_EXE_LINK_FLAGS_DEBUG}>")


set(libstudxml_COMPONENTS_DEBUG )