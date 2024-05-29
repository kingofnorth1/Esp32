# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "I:/software/ESP32-IDF/Espressif/frameworks/esp-idf-v5.1.2/components/bootloader/subproject"
  "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader"
  "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader-prefix"
  "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader-prefix/tmp"
  "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader-prefix/src/bootloader-stamp"
  "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader-prefix/src"
  "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "I:/document/Esp32/Esp32-C3-Idf-GPIOTurn/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
