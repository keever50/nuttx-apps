/****************************************************************************
 * apps/graphics/nxwidgets/src/cstickybutton.cxx
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************
 *
 * Portions of this package derive from Woopsi (http://woopsi.org/) and
 * portions are original efforts.  It is difficult to determine at this
 * point what parts are original efforts and which parts derive from Woopsi.
 * However, in any event, the work of  Antony Dzeryn will be acknowledged
 * in most NxWidget files.  Thanks Antony!
 *
 *   Copyright (c) 2007-2011, Antony Dzeryn
 *   All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the names "Woopsi", "Simian Zombie" nor the
 *   names of its contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Antony Dzeryn ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Antony Dzeryn BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <sys/types.h>
#include <stdint.h>
#include <stdbool.h>

#include <nuttx/nx/nxglib.h>

#include "graphics/nxwidgets/cstickybutton.hxx"
#include "graphics/nxwidgets/cgraphicsport.hxx"

/****************************************************************************
 * Pre-Processor Definitions
 ****************************************************************************/

/****************************************************************************
 * CButton Method Implementations
 ****************************************************************************/

using namespace NXWidgets;

/**
 * Constructor for buttons that display a string.
 *
 * @param pWidgetControl The controlling widget for the display.
 * @param x The x coordinate of the button, relative to its parent.
 * @param y The y coordinate of the button, relative to its parent.
 * @param width The width of the button.
 * @param height The height of the button.
 * @param text The text for the button to display.
 * @param style The style that the button should use.  If this is not
 *        specified, the button will use the global default widget
 *        style.
 */

CStickyButton::CStickyButton(CWidgetControl *pWidgetControl,
                             nxgl_coord_t x, nxgl_coord_t y,
                             nxgl_coord_t width, nxgl_coord_t height,
                             const CNxString &text,
                             CWidgetStyle *style)
: CButton(pWidgetControl, x, y, width, height, text, style)
{
  m_isStuckDown = false;
}

/**
 * Sets the key's stuck down state.  If this is true, the key has a
 * inwards-bevelled border when drawn.  If it is false, the key has
 * an outwards-bevelled border.
 *
 * @param stuckDown The new stuck down state.
 */

void CStickyButton::setStuckDown(bool stuckDown)
  {
    m_isStuckDown = stuckDown;
    redraw();
  }

/**
 * Draws the outline of the button.
 *
 * @param port Graphics port to draw to.
 */

void CStickyButton::drawOutline(CGraphicsPort *port)
{
  CButton::drawOutline(port, m_isStuckDown);
}

/**
 * Draw the area of this widget that falls within the clipping region.
 * Called by the redraw() function to draw all visible regions.
 *
 * @param port The CGraphicsPort to draw to.
 * @see redraw()
 */

void CStickyButton::drawContents(CGraphicsPort *port)
{
  CButton::drawContents(port, m_isStuckDown);
}

/**
 * Draw the area of this widget that falls within the clipping region.
 * Called by the redraw() function to draw all visible regions.
 *
 * @param port The CGraphicsPort to draw to.
 * @see redraw()
 */

void CStickyButton::drawBorder(CGraphicsPort *port)
{
  CButton::drawBorder(port, m_isStuckDown);
}
