#include <iostream>

#include "engine.hpp"

int main([[maybe_unused]] int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Please provide a map path you dummy!" << std::endl;
    return -1;
  }
  eape::Engine battle_engine{};
  battle_engine.load(argv[1]);
  while (battle_engine.is_running()) {
    battle_engine.update();
  }
  return 0;
}
