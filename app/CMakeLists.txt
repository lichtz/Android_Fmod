
cmake_minimum_required(VERSION 3.4.1)
add_library( # Sets the name of the library.
            w-voice

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).

               src/main/cpp/effect_fix.cpp
             )
add_library( # Sets the name of the library.
             fmod

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             IMPORTED )
set_target_properties(fmod
  PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libfmod.so)
add_library( # Sets the name of the library.
             fmodL

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             IMPORTED )
set_target_properties(fmodL
  PROPERTIES IMPORTED_LOCATION
  ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libfmodL.so)
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( # Specifies the target library.
                       w-voice
                        fmod
                        fmodL
                       ${log-lib} )