/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "toolbar.h"
#include "dsvgrenderer.h"
#include <QHBoxLayout>
#include <QLabel>

DWIDGET_USE_NAMESPACE

ToolBar::ToolBar(QWidget *parent)
    : QWidget(parent),
      m_edit(new QLineEdit)
{
    const qreal ratio = devicePixelRatioF();
    QPixmap iconPixmap = DSvgRenderer::render(":/images/redict.svg", QSize(22, 22) * ratio);
    QLabel *iconLabel = new QLabel;
    iconPixmap.setDevicePixelRatio(ratio);
    iconLabel->setPixmap(iconPixmap);

    m_edit->setFixedWidth(350);
    m_edit->setFixedHeight(30);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addSpacing(5);
    layout->addWidget(iconLabel);
    layout->addSpacing(20);
    layout->addWidget(m_edit);
    layout->addStretch();
    layout->setMargin(0);

    connect(m_edit, &QLineEdit::returnPressed, this, [=] { emit returnPressed(m_edit->text()); });
}

ToolBar::~ToolBar()
{
}
