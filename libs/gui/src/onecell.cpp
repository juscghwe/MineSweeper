/**
 * @file onecell.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#include "gui/onecell.hpp"

namespace GuiC = Constants::GuiConstants;

namespace Gui {

OneCell::OneCell(Utility::CellStruct cellStruct, const Utility::PositionStruct kPosition,
                 TextureManager& kTextureManager)
    : cellStruct_(cellStruct), kPosition_(kPosition), kTextureManager_(kTextureManager)
{
    sf::Sprite sprite_;
    sprite_.setPosition(kPosition_.column, kPosition_.row);
    redraw(kTextureManager_);
}

void OneCell::gotClicked()
{
    cellStruct_.isCovered = false;
    redraw(kTextureManager_);
}

void OneCell::gotFlagged()
{
    if (cellStruct_.isCovered) {
        cellStruct_.isFlagged = true;
    }
}

// @private
const std::pair<GuiC::CellState, int> OneCell::getStateFromStruct(const Utility::CellStruct& kCellStruct)
{

    if (kCellStruct.isCovered) {
        return {GuiC::CellState::Unknown, 0};
    } else if (kCellStruct.isFlagged) {
        return {GuiC::CellState::Flagged, 0};
    } else {
        if (kCellStruct.adjacentMines == 0) {
            return {GuiC::CellState::Empty, 0};
        }
        return {GuiC::CellState::Adjacent, kCellStruct.adjacentMines};
    }
}

//@private
void OneCell::redraw(TextureManager& kTextureManager)
{
    auto [state, adjacent] = getStateFromStruct(cellStruct_);
    const sf::Texture& texture = kTextureManager.getTexture(state, adjacent);
    sprite_.setTexture(texture);
    // TODO: Call for redraw
}

};  // namespace Gui