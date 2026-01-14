/*
 * Filesystem Json Parser
 *
 * Copyright (C) 2026 EllenoireQ
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef FSJSON_HELPER_H
#define FSJSON_HELPER_H

#include <fstream>
#include <string>
#include <unordered_map>

enum Proc { CMDLINE, STATUS, COMM, SCHED };

struct Pid {
  bool self;
  int pid = 0;
};

class Helper {
public:
  static int stringToEnum(std::string str) {
    if (str == "comm") {
      return Proc::COMM;
    } else if (str == "cmdline") {
      return Proc::CMDLINE;
    } else if (str == "status") {
      return Proc::STATUS;
    } else if (str == "sched") {
      return Proc::SCHED;
    }
    return 0;
  }
};

#endif // FSJSON_HELPER_H
