/**
 * @file onecell.hpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#ifndef ONE_CELL_H
#define ONE_CELL_H

#include "gui/texturemanager.hpp"
#include "utility/cellstruct.hpp"
#include <SFML/Graphics.hpp>

namespace Gui {

struct PixelStruct {
    int X;
    int Y;
};

class OneCell
{
  public:
    OneCell(Utility::CellStruct cellStruct, const PixelStruct kPosition, TextureManager& kTextureManager);

    void gotClicked();

    void gotFlagged();

  private:
    sf::Sprite sprite_;
    Utility::CellStruct cellStruct_;
    const PixelStruct kPosition_;
    TextureManager& kTextureManager_;

    const std::pair<GuiC::CellState, int> getStateFromStruct(const Utility::CellStruct& kCellStruct);

    void redraw(TextureManager& kTextureManager);
};

};  // namespace Gui

#endif  // ONE_CELL_H