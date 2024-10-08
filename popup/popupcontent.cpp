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

#include "popupcontent.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QLabel>
#include "dimagebutton.h"

PopupContent::PopupContent(QWidget *parent)
    : DAbstractDialog(parent),
      m_queryLabel(new QLabel),
      m_transLabel(new QLabel)
{
    DBlurEffectWidget *bgWidget = new DBlurEffectWidget(this);
    bgWidget->setBlendMode(DBlurEffectWidget::BehindWindowBlend);
    bgWidget->setMaskColor(DBlurEffectWidget::LightColor);

    QScrollArea *contentFrame = new QScrollArea;
    contentFrame->setWidgetResizable(true);
    contentFrame->setStyleSheet(contentFrame->styleSheet()
                                + "QScrollArea { background: transparent; }" 
                                + "QScrollArea > QWidget > QWidget { background: transparent; }");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(contentFrame);
    layout->setMargin(0);

    /*DImageButton *querySpeakBtn = new DImageButton();
    querySpeakBtn->setNormalPic(":/images/audio-dark-normal.svg");
    querySpeakBtn->setHoverPic(":/images/audio-dark-hover.svg");
    querySpeakBtn->setPressPic(":/images/audio-dark-press.svg");
    //layout->addWidget(querySpeakBtn);
    connect(querySpeakBtn, &DImageButton::clicked, this, [this](){
        Speaker(m_queryLabel->text());
    });

    DImageButton *transSpeakBtn = new DImageButton();
    transSpeakBtn->setNormalPic(":/images/audio-dark-normal.svg");
    transSpeakBtn->setHoverPic(":/images/audio-dark-hover.svg");
    transSpeakBtn->setPressPic(":/images/audio-dark-press.svg");
    //layout->addWidget(querySpeakBtn);
    connect(transSpeakBtn, &DImageButton::clicked, this, [this](){
        Speaker(m_transLabel->text());
    });*/


    QWidget *mainWidget = new QWidget;
    QGridLayout *mainLayout = new QGridLayout(mainWidget);
    contentFrame->setWidget(mainWidget);

    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->addWidget(m_queryLabel, 0, 0);
    //mainLayout->addWidget(querySpeakBtn, 0, 1);
    mainLayout->addWidget(m_transLabel, 1, 0);
    //mainLayout->addWidget(transSpeakBtn, 1, 1);
    //mainLayout->addStretch();

    m_queryLabel->setWordWrap(true);
    m_transLabel->setWordWrap(true);

    setFixedSize(300, 200);
    bgWidget->resize(size());
}

PopupContent::~PopupContent()
{
}

void PopupContent::mouseMoveEvent(QMouseEvent *e)
{
    // disable move window.
    e->ignore();
}

void PopupContent::updateContent(std::tuple<QString, QString, QString, QString, QString> data)
{
    m_queryLabel->setText(std::get<0>(data));
    m_transLabel->setText(std::get<3>(data));
}
