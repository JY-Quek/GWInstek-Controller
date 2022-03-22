# --------------------------------------------------------------------------------
# Below is for making Application Purposes
# link to source files
file(GLOB src_files
     "*.h"
     "*.cpp"
)
add_executable(SampleApplication ${src_files})

target_link_libraries(SampleApplication
  PRIVATE
	MultimeterController
)





