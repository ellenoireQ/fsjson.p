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
