/**
 * @file onecell.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#include "gui/onecell.hpp"

namespace GuiC = Constants::GuiConstants;

namespace Gui {

OneCell::OneCell(Utility::CellStruct cellStruct, const PixelStruct kPosition, TextureManager& textureManager)
    : cellStruct_(cellStruct), kPosition_(kPosition), textureManager_(textureManager)
{
    sf::Sprite sprite_;
    sprite_.setPosition(kPosition_.X, kPosition_.Y);
    redraw();
}

void OneCell::gotClicked()
{
    cellStruct_.isCovered = false;
    redraw();
}

void OneCell::gotFlagged()
{
    if (cellStruct_.isCovered) {
        cellStruct_.isFlagged = true;
        redraw();
    }
}

// @private
const std::pair<GuiC::CellState, int> OneCell::getStateFromStruct()
{

    if (cellStruct_.isCovered) {
        return {GuiC::CellState::Unknown, 0};
    } else if (cellStruct_.isFlagged) {
        return {GuiC::CellState::Flagged, 0};
    } else {
        if (cellStruct_.adjacentMines == 0) {
            return {GuiC::CellState::Empty, 0};
        }
        return {GuiC::CellState::Adjacent, cellStruct_.adjacentMines};
    }
}

//@private
void OneCell::redraw()
{
    const auto [state, adjacent] = getStateFromStruct();
    const sf::Texture& texture = textureManager_.getTexture(state, adjacent);
    sprite_.setTexture(texture);

    float cellWidth = kScale_.X;
    float cellHeight = kScale_.Y;

    sf::Vector2u textureSize = texture.getSize();  // Get the original size of the texture

    sprite_.setScale(
        cellWidth / textureSize.x,
        cellHeight / textureSize.y);  // Set the scale based on the ratio between desired size and texture size
}

};  // namespace Gui