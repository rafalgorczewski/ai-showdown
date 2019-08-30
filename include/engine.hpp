#ifndef EAPE_ENGINE_HPP
#define EAPE_ENGINE_HPP

#include <string>

namespace eape {

  class Engine {
   public:
    void load();
    bool is_running() const;
    void update();

   private:
  };

}  // namespace eape

#endif  // EAPE_ENGINE_HPP
