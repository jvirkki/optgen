/*
 *  Copyright 2015-2018 Jyri J. Virkki <jyri@virkki.com>
 *
 *  This file is part of optgen.
 *
 *  optgen is free software: you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  optgen is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with optgen.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#include "optgen.h"

static char level_line[1024];

int add_level(char * arg, int command)
{
  if (arg == NULL) {
    printf("error: arg is null into callback\n");
    exit(1);
  }
  sprintf(level_line, "%s;%s", level_line, arg);
  return OPTGEN_CALLBACK_OK;
}

int main(int argc, char * argv[])
{
  char * options[COUNT_OPTIONS];
  int command;

  int rv = optgen_parse(argc, argv, &command, options);

  if (rv == OPTGEN_NONE) {
    printf("no args\n");
    exit(0);
  }

  if (rv != OPTGEN_OK) {
    printf("return not ok\n");
    exit(1);
  }

  if (command == OPTGEN_NO_COMMAND) {
    if (options[OPT_experimental]) {
      printf("no command:experimental\n");
    } else {
      printf("no command\n");
    }
    exit(0);
  }

  if (command == COMMAND_info) {
    if (options[OPT_info]) {
      printf("info:info\n");
      exit(0);
    } else {
      printf("info\n");
      exit(0);
    }
  }

  if (command == COMMAND_help) {
    if (options[OPT_help] == NULL) {
      printf("help:no value\n");
      exit(0);
    }
    printf("help:%s\n", options[OPT_help]);
    exit(0);
  }

  if (command == COMMAND_two) {
    if (options[OPT_two]) {
      printf("two:two:%s\n", options[OPT_two]);
      exit(0);
    }
    if (options[OPT_level]) {
      printf("two:level:%s\n", level_line);
      exit(0);
    }
    if (options[OPT_letter]) {
      printf("two:letter:%s\n", options[OPT_letter]);
      exit(0);
    }
    if (options[OPT_path]) {
      printf("two:path:%s\n", options[OPT_path]);
      exit(0);
    }

  }

  if (command == COMMAND_testing) {
    printf("testing\n");
    exit(0);
  }

  printf("no known test\n");
  printf("command: %d\n", command);
  opt_show_help();
  exit(1);
}
