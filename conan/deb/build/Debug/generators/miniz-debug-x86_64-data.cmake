########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(miniz_COMPONENT_NAMES "")
if(DEFINED miniz_FIND_DEPENDENCY_NAMES)
  list(APPEND miniz_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES miniz_FIND_DEPENDENCY_NAMES)
else()
  set(miniz_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(miniz_PACKAGE_FOLDER_DEBUG "/home/gorillabacteria/.conan2/p/b/miniz91fdd4e088207/p")
set(miniz_BUILD_MODULES_PATHS_DEBUG )


set(miniz_INCLUDE_DIRS_DEBUG )
set(miniz_RES_DIRS_DEBUG )
set(miniz_DEFINITIONS_DEBUG )
set(miniz_SHARED_LINK_FLAGS_DEBUG )
set(miniz_EXE_LINK_FLAGS_DEBUG )
set(miniz_OBJECTS_DEBUG )
set(miniz_COMPILE_DEFINITIONS_DEBUG )
set(miniz_COMPILE_OPTIONS_C_DEBUG )
set(miniz_COMPILE_OPTIONS_CXX_DEBUG )
set(miniz_LIB_DIRS_DEBUG "${miniz_PACKAGE_FOLDER_DEBUG}/lib")
set(miniz_BIN_DIRS_DEBUG )
set(miniz_LIBRARY_TYPE_DEBUG STATIC)
set(miniz_IS_HOST_WINDOWS_DEBUG 0)
set(miniz_LIBS_DEBUG miniz)
set(miniz_SYSTEM_LIBS_DEBUG )
set(miniz_FRAMEWORK_DIRS_DEBUG )
set(miniz_FRAMEWORKS_DEBUG )
set(miniz_BUILD_DIRS_DEBUG )
set(miniz_NO_SONAME_MODE_DEBUG FALSE)


# COMPOUND VARIABLES
set(miniz_COMPILE_OPTIONS_DEBUG
    "$<$<COMPILE_LANGUAGE:CXX>:${miniz_COMPILE_OPTIONS_CXX_DEBUG}>"
    "$<$<COMPILE_LANGUAGE:C>:${miniz_COMPILE_OPTIONS_C_DEBUG}>")
set(miniz_LINKER_FLAGS_DEBUG
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${miniz_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${miniz_SHARED_LINK_FLAGS_DEBUG}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${miniz_EXE_LINK_FLAGS_DEBUG}>")


set(miniz_COMPONENTS_DEBUG )