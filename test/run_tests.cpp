#include <gtest/gtest.h>

extern int my_argc;
extern char** my_argv;
// eof
//---------------------------------------------

//---------------------------------------------
// main.cpp
int my_argc;
char** my_argv;

int main(int argc, char** argv)
{    
  ::testing::InitGoogleTest(&argc, argv);
  my_argc = argc;
  my_argv = argv;
  return RUN_ALL_TESTS();
}
// eof
//---------------------------------------------
