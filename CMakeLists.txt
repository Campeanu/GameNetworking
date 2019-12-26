cmake_minimum_required(VERSION 3.8)
set(This Networking)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

get_directory_property(ParentDirectory PARENT_DIRECTORY)
if(ParentDirectory STREQUAL "")
    # Define option for linking with the runtime statically.
    if(MSVC)
        option(RUNTIME_STATIC_LINKAGE "Link with runtime library statically" OFF)
    endif(MSVC)

    # If the runtime static linkage option is turned on, replace compiler flag that selects runtime library variant.
    if(MSVC AND RUNTIME_STATIC_LINKAGE)
        foreach(flag
            CMAKE_C_FLAGS
            CMAKE_CXX_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_MINSIZEREL
            CMAKE_C_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
        )
            if(${flag} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag} "${${flag}}")
            endif(${flag} MATCHES "/MD")
        endforeach(flag)
    endif(MSVC AND RUNTIME_STATIC_LINKAGE)

    # Organize applications, libraries, etc. in folders in the IDE.
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Ensure proper loading of side-loaded shared libraries on all targets.
    set(CMAKE_SKIP_BUILD_RPATH FALSE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    if(APPLE)
        set(CMAKE_INSTALL_RPATH "@loader_path")
    elseif(UNIX)
        set(CMAKE_INSTALL_RPATH "\$ORIGIN")
    endif()

    # Don't add the goofy "d" postfix for debug builds of libraries.
    set(CMAKE_DEBUG_POSTFIX "")

    # Suppress Microsoft warnings about functions being unsafe.
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)

    # Specify where to find external libraries.
    # example set(VARIABLE_NAME "${CMAKE_CURRENT_SOURCE_DIR}/path_to_include_folder")

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        # 64 bits architecture
        set(SFML "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SFML/SFML_x64")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        # 32 bits architecture
        set(SFML "${CMAKE_CURRENT_SOURCE_DIR}/vendor/SFML/SFML_x86")
    endif()

    # All other libraries can be pulled in without further configuration.

endif(ParentDirectory STREQUAL "")

# Add subdirectories directly in this repository.

add_subdirectory(networking)
