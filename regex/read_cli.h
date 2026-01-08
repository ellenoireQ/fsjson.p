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

#pragma once
#include <algorithm>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct Context {
  bool reading = false;
  bool proc = false;
  std::string procFile;
  std::string outputPath;
  bool showHelp = false;
};

enum class ArgType { FLAG, VALUE, POSITIONAL };

struct cli {
  std::vector<std::string> names;
  ArgType type;
  std::string description;
  bool required = false;
  std::function<void(Context &, std::optional<std::string>)> handler;
};

class CommandLineInterface {
public:
  static bool parse(int argc, char *argv[], std::initializer_list<cli> args,
                    Context &ctx) {

    for (int i = 1; i < argc; ++i) {
      std::string token = argv[i];
      bool matched = false;

      for (const auto &arg : args) {

        auto it = std::find(arg.names.begin(), arg.names.end(), token);
        if (it == arg.names.end())
          continue;

        matched = true;
        std::optional<std::string> value = std::nullopt;

        if (arg.type == ArgType::VALUE) {
          if (i + 1 >= argc) {
            std::cerr << "Error: " << token << " requires a value\n";
            return false;
          }
          value = argv[++i];
        }

        if (arg.handler) {
          arg.handler(ctx, value);
        }
        break;
      }

      if (!matched) {
        std::cerr << "Error: unknown argument " << token << "\n";
        return false;
      }
    }
    return true;
  }

  static void printHelp(std::initializer_list<cli> args) {
    std::cout << "Usage: main [OPTIONS]\n\n";
    std::cout << "Options:\n";
    for (const auto &arg : args) {
      std::cout << "  ";
      for (size_t i = 0; i < arg.names.size(); ++i) {
        std::cout << arg.names[i];
        if (i < arg.names.size() - 1)
          std::cout << ", ";
      }
      if (arg.type == ArgType::VALUE) {
        std::cout << " <value>";
      }
      std::cout << "\n      " << arg.description;
      if (arg.required) {
        std::cout << " (required)";
      }
      std::cout << "\n";
    }
  }
};
