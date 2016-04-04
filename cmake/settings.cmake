get_filename_component(settings_cmake_dir "${CMAKE_CURRENT_LIST_FILE}" PATH)

include("${settings_cmake_dir}/inc/msvc.cmake")
include("${settings_cmake_dir}/inc/posix.cmake")
if (USING_ASIO)
	include("${settings_cmake_dir}/inc/asio.cmake")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
