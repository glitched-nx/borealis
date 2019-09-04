/*
    Borealis, a Nintendo Switch UI Library
    Copyright (C) 2019  natinusala
    Copyright (C) 2019  p-sam

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include <borealis/view.hpp>

namespace brls
{

enum class LabelStyle
{
    REGULAR = 0,
    MEDIUM,
    SMALL,
    DESCRIPTION,
    CRASH,
    BUTTON,
    LIST_ITEM
};

// A Label, multiline or with a ticker
class Label : public View
{
  private:
    std::string text;

    bool multiline;
    unsigned fontSize;
    LabelStyle labelStyle;

    NVGalign horizontalAlign = NVG_ALIGN_LEFT;
    NVGalign verticalAlign   = NVG_ALIGN_MIDDLE;

    NVGcolor customColor;
    bool useCustomColor = false;

  public:
    Label(LabelStyle labelStyle, std::string text, bool multiline = false);

    void draw(NVGcontext* vg, int x, int y, unsigned width, unsigned height, Style* style, FrameContext* ctx) override;
    void layout(NVGcontext* vg, Style* style, FontStash* stash) override;

    View* requestFocus(FocusDirection direction, View* oldFocus, bool fromUp = false) override
    {
        return nullptr;
    }

    void setVerticalAlign(NVGalign align);
    void setHorizontalAlign(NVGalign align);
    void setText(std::string text);

    /**
     * Sets the label color
     */
    void setColor(NVGcolor color);

    /**
     * Unsets the label color - it
     * will now use the default one
     * for the label style
     */
    void unsetColor();
};

} // namespace brls