cmake_minimum_required(VERSION 3.3)
project(webpthumb)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# ECM setup
find_package(ECM 0.0.11 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(FeatureSummary)

find_package(KF5KIO)

find_library(FOUND_WEBP webp REQUIRED)

set(webpthumb_SRCS WebPThumb.cpp)
add_library(webpthumb MODULE ${webpthumb_SRCS})
target_link_libraries(webpthumb PRIVATE KF5::KIOWidgets webp)

install(TARGETS webpthumb DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES webpthumb.desktop DESTINATION ${SERVICES_INSTALL_DIR})

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
