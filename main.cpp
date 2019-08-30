#include "engine.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
  eape::Engine battle_engine;
  battle_engine.load_map();
  while (battle_engine.is_running()) {
    
  }

  return 0;
}
