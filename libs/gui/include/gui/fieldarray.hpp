/**
 * @file fieldarray.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#ifndef FIELD_ARRAY_H
#define FIELD_ARRAY_H

#include "gui/texturemanager.hpp"
#include "utility/fieldvector.hpp"
#include <memory>

namespace Gui {

class FieldArray
{
  public:
    FieldArray(const std::unique_ptr<Utility::FieldVector>& kFieldVector, TextureManager& textureManager);

    const std::pair<int, int> getWindowSize() const { return std::pair<int, int>{kWindowX_, kWindowY_}; };

  private:
    const int kWindowX_;
    const int kWindowY_;
    const int kButtonX_;
    const int kButtonY_;
    const std::unique_ptr<Utility::FieldVector>& kFieldVector_;
    TextureManager& textureManager_;

    void initializeGrid();
};

};  // namespace Gui

#endif