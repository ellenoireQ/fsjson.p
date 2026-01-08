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

#include "regex/helper.h"
#include "regex/read_cli.h"
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  Context ctx;
  CommandLineInterface commandline;

  auto args = {
      cli{.names = {"read", "r"},
          .type = ArgType::FLAG,
          .description = "Enable reading mode",
          .handler = [](Context &c, auto) { c.reading = true; }},

      cli{.names = {"proc", "p"},
          .type = ArgType::VALUE,
          .description = "Specify proc file (cmdline, comm, state)",
          .handler =
              [](Context &c, auto value) {
                c.proc = true;
                c.procFile = *value;
              }},

      cli{.names = {"--output", "-o"},
          .type = ArgType::VALUE,
          .description = "Output file path",
          .handler = [](Context &c, auto value) { c.outputPath = *value; }},

      cli{.names = {"--pid", "-p"},
          .type = ArgType::VALUE,
          .description = "Specify PID for reading /proc",
          .handler = [](Context &c, auto value) { c.pid = *value; }},

      cli{.names = {"--json", "-j"},
          .type = ArgType::FLAG,
          .description = "Display/Print to json",
          .handler = [](Context &c, auto) { c.json = true; }},

      cli{.names = {"--version", "-v"},
          .type = ArgType::FLAG,
          .description = "Show version",
          .handler = [](Context &c, auto) { c.showVersion = true; }},

      cli{.names = {"--help", "-h"},
          .type = ArgType::FLAG,
          .description = "Show this help message",
          .handler = [](Context &c, auto) { c.showHelp = true; }},
  };

  if (argc == 1) {
    cout << "Error: missing argument\nTry 'main --help' for more information."
         << endl;
    return 1;
  }

  if (!CommandLineInterface::parse(argc, argv, args, ctx)) {
    return 1;
  }

  if (ctx.showVersion) {
    CommandLineInterface::printVersion();
    return 1;
  }
  if (ctx.showHelp) {
    CommandLineInterface::printHelp(args);
    return 0;
  }

  FileSystem fs;
  Helper help;

  if (ctx.json) {
    switch (help.stringToEnum(ctx.procFile)) {
    case Proc::COMM:
      fs.read_proc(Proc::COMM, std::stoi(ctx.pid));
      break;
    case Proc::CMDLINE:
      break;
    case Proc::STATE:
      break;
    default:
      break;
    }
  }

  // TODO: Next Implementation

  return 0;
}
