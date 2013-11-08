//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

#ifndef HUGGLEWEB_H
#define HUGGLEWEB_H

#include <QFrame>
#include <QWebHistory>
#include "wikipage.hpp"
#include "wikiedit.hpp"
#include "exception.hpp"
#include "core.hpp"

namespace Ui
{
    class HuggleWeb;
}

namespace Huggle
{
    class WikiEdit;

    //! Web browser
    class HuggleWeb : public QFrame
    {
            Q_OBJECT

        public:
            explicit HuggleWeb(QWidget *parent = 0);
            ~HuggleWeb();
            QString CurrentPageName();
            /*!
             * \brief Retrieve a page in render mode on currently selected project
             * \param page
             */
            void DisplayPreFormattedPage(WikiPage *page);
            /*!
             * \brief Open a page but append action=render to it
             * \param url
             */
            void DisplayPreFormattedPage(QString url);
            void DisplayPage(QString url);
            /// \todo DOCUMENT ME
            void RenderHtml(QString html);
            /// \todo DOCUMENT ME
            void DisplayDiff(WikiEdit *edit);
            static QString Encode(const QString &string);

        private:
            Ui::HuggleWeb *ui;
            QString CurrentPage;
    };
}

#endif // HUGGLEWEB_H