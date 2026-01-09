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

#ifndef FSJSON_FILESYSTEM_H
#define FSJSON_FILESYSTEM_H

#include "helper.h"
#include <format>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

namespace ns {
struct comm {
  std::string comm;
};
struct cmdline {
  std::string cmdline;
};
} // namespace ns

using namespace nlohmann;

class FileSystem {
public:
  inline static json j;
  static void read_proc(Proc proc, bool jsonMode = false, Pid pid = {}) {

    switch (proc) {
    case Proc::CMDLINE: {
      auto format = std::format("/proc/{}/cmdline", "self");
      auto saved_pid = "";
      if (pid.self)
        saved_pid = "self";

      if (!pid.self)
        format = std::format("/proc/{}/cmdline", pid.pid);

      std::ifstream inputFile(format);
      std::string line;

      if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
          if (jsonMode) {
            ns::cmdline p = {line};
            j["cmdline"] = p.cmdline;
          } else {
            std::cout << line << std::endl;
          }
        }
        inputFile.close();
      } else {
        std::cerr << "Unable to open file for reading." << std::endl;
      }

      if (jsonMode)
        std::cout << j.dump(4) << std::endl;
      break;
    }
    case Proc::STATE:
      break;
    case Proc::COMM:
      auto format = std::format("/proc/{}/comm", "self");
      auto saved_pid = "";
      if (pid.self)
        saved_pid = "self";

      if (!pid.self)
        format = std::format("/proc/{}/comm", pid.pid);

      std::ifstream inputFile(format);
      std::string line;

      if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
          if (jsonMode) {
            ns::comm p = {line};
            j["comm"] = p.comm;
          } else {
            std::cout << line << std::endl;
          }
        }
        inputFile.close();
      } else {
        std::cerr << "Unable to open file for reading." << std::endl;
      }

      if (jsonMode)
        std::cout << j.dump(4) << std::endl;
      break;
    }
  }
};

#endif // FSJSON_FILESYSTEM_H
