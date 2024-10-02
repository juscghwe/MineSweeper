/**
 * @file fieldarray.cpp
 * @author juscghwe <a href = "https://github.com/juscghwe">GitHub<\a>
 */

#include "gui/fieldarray.hpp"
#include "gui/onecell.hpp"
#include "guiconstants.hpp"

namespace GuiC = Constants::GuiConstants;

namespace Gui {

FieldArray::FieldArray(const std::unique_ptr<Utility::FieldVector>& kFieldVector, TextureManager& textureManager)
    : kWindowX_(GuiC::WINDOWBASED ? GuiC::WINDOWX : GuiC::BUTTONX * kFieldVector->columns()),
      kWindowY_(GuiC::WINDOWBASED ? GuiC::WINDOWY : GuiC::BUTTONY * kFieldVector->rows()),
      kButtonX_(GuiC::WINDOWBASED ? GuiC::WINDOWX / kFieldVector->columns() : GuiC::BUTTONX),
      kButtonY_(GuiC::WINDOWBASED ? GuiC::WINDOWY / kFieldVector->rows() : GuiC::BUTTONY),
      kFieldVector_(std::move(kFieldVector)),
      textureManager_(textureManager)
{}

void FieldArray::initializeGrid()
{
    int columnFactor = 0;  ///< Factor for X position
    int rowFactor = 0;     ///< Factor for Y position
    for (std::vector<Utility::CellStruct> row : kFieldVector_->getFieldGrid()) {
        for (Utility::CellStruct column : row) {
            const PixelStruct position = {columnFactor * kButtonX_, rowFactor * kButtonY_};
            Gui::OneCell(column, position, textureManager_);
            columnFactor++;
        }
        rowFactor++;
        columnFactor = 0;
    }
}

}  // namespace Gui