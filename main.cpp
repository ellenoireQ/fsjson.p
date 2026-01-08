#include "regex/read_cli.h"
#include <format>
#include <optional>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  Context ctx;
  CommandLineInterface commandline;

  auto args = {
      cli{.names = {"--read", "-r"},
          .type = ArgType::FLAG,
          .description = "Enable reading mode",
          .handler = [](Context &c, auto) { c.reading = true; }},

      cli{.names = {"--proc", "-p"},
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

  if (ctx.showHelp) {
    CommandLineInterface::printHelp(args);
    return 0;
  }

  cout << "Parsed context:\n";
  cout << "  reading: " << (ctx.reading ? "true" : "false") << "\n";
  cout << "  proc: " << (ctx.proc ? "true" : "false") << "\n";
  if (!ctx.procFile.empty()) {
    cout << "  procFile: " << ctx.procFile << "\n";
  }
  if (!ctx.outputPath.empty()) {
    cout << "  outputPath: " << ctx.outputPath << "\n";
  }

  // TODO: Next Implementation

  return 0;
}
