// Copyright 2021 Chirkov Roman

#include <stdio.h>
#include <stdlib.h>

#include <string>

#include "include/application.h"

int main(int argc, char** argv) {
  Application app;
  std::string output = app.init(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
