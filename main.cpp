#include <iostream>

#include "engine.hpp"

int main([[maybe_unused]] int argc, char** argv) {
  if (argc < 4) {
    std::cerr << "Please provide paths you dummy!" << std::endl;
    return -1;
  }
  eape::Engine battle_engine(argv[2], argv[3]);
  battle_engine.load(argv[1]);
  while (battle_engine.is_running()) {
    battle_engine.update();
  }
  return 0;
}
