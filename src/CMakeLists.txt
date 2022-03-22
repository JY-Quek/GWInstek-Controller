# --------------------------------------------------------------------------------
# Below is for making testing purposes
# To generate a library which is used for test scripts inside test/ folder
add_library(MultimeterController)

target_sources(MultimeterController
  PRIVATE
    MultimeterController.cpp
    HelperFunctions.cpp
  PUBLIC
    MultimeterController.h
    HelperFunctions.h
  )

target_link_libraries(MultimeterController
  PUBLIC
	SerialCommunication
)

# define the include path so that your package can find the .h file
target_include_directories(MultimeterController PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        "${PROJECT_BINARY_DIR}/src"
)

