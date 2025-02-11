########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(xlnt_COMPONENT_NAMES "")
if(DEFINED xlnt_FIND_DEPENDENCY_NAMES)
  list(APPEND xlnt_FIND_DEPENDENCY_NAMES libstudxml miniz)
  list(REMOVE_DUPLICATES xlnt_FIND_DEPENDENCY_NAMES)
else()
  set(xlnt_FIND_DEPENDENCY_NAMES libstudxml miniz)
endif()
set(libstudxml_FIND_MODE "NO_MODULE")
set(miniz_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(xlnt_PACKAGE_FOLDER_DEBUG "/home/gorillabacteria/.conan2/p/b/xlnt848e33c103741/p")
set(xlnt_BUILD_MODULES_PATHS_DEBUG )


set(xlnt_INCLUDE_DIRS_DEBUG "${xlnt_PACKAGE_FOLDER_DEBUG}/include")
set(xlnt_RES_DIRS_DEBUG )
set(xlnt_DEFINITIONS_DEBUG "-DXLNT_STATIC")
set(xlnt_SHARED_LINK_FLAGS_DEBUG )
set(xlnt_EXE_LINK_FLAGS_DEBUG )
set(xlnt_OBJECTS_DEBUG )
set(xlnt_COMPILE_DEFINITIONS_DEBUG "XLNT_STATIC")
set(xlnt_COMPILE_OPTIONS_C_DEBUG )
set(xlnt_COMPILE_OPTIONS_CXX_DEBUG )
set(xlnt_LIB_DIRS_DEBUG "${xlnt_PACKAGE_FOLDER_DEBUG}/lib")
set(xlnt_BIN_DIRS_DEBUG )
set(xlnt_LIBRARY_TYPE_DEBUG STATIC)
set(xlnt_IS_HOST_WINDOWS_DEBUG 0)
set(xlnt_LIBS_DEBUG xlntd)
set(xlnt_SYSTEM_LIBS_DEBUG )
set(xlnt_FRAMEWORK_DIRS_DEBUG )
set(xlnt_FRAMEWORKS_DEBUG )
set(xlnt_BUILD_DIRS_DEBUG )
set(xlnt_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(xlnt_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${xlnt_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${xlnt_COMPILE_OPTIONS_C_DEBUG}>")
set(xlnt_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${xlnt_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${xlnt_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${xlnt_EXE_LINK_FLAGS_DEBUG}>")


set(xlnt_COMPONENTS_DEBUG )