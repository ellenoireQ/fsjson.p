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
#include <format>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

enum Proc {
  CMDLINE,
  STATE,
  COMM,
};

namespace ns {
struct comm {
  std::string comm;
};
} // namespace ns

using namespace nlohmann;

class FileSystem {
public:
  inline static json j;
  static void read_proc(Proc proc, int pid = 0) {
    switch (proc) {
    case Proc::CMDLINE:
      break;
    case Proc::STATE:
      break;
    case Proc::COMM:
      auto format = std::format("/proc/{}/comm", pid);
      std::ifstream inputFile(format);
      std::string line;

      if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
          std::cout << line << std::endl;
          ns::comm p = {line};
          j["comm"] = p.comm;
        }
        inputFile.close();
      } else {
        std::cerr << "Unable to open file for reading." << std::endl;
      }

      std::cout << j.dump(4) << std::endl;
      break;
    }
  }
};
