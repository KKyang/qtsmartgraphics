## qtsmartgraphics

A simple library that improves the user experience when displaying images by Qt's QLabel and QGraphicsView.

### Introduction

A simple library that improves the user experience when displaying images by Qt's QLabel and QGraphicsView. It also supports OpenCV Mat array type.

smartGraphicsView supports show image functions which supports QImage and Mat (in BGR format). It also supports mouse clicks, moves, wheel events, and region selection.

smartLabel supports show image functions which supports QImage and Mat (in BGR format). It also supports mouse clicks events.

### Usage

Functions below can be turned on or off individually.

#### OpenCV

If you wish to use OpenCV, add DEFINE += HAVE_OPENCV in your *.pro file.

#### OpenGL

If you wish to use OpenGL, you'll have to use OpenGL version (< QT 5.5) or add opengl module in the *.pro file (>= QT5.5). (QT += opengl)

#### QSideButtonBar

If you wish to turn off the SideButtonBar, add DEFINES += NO_SIDEMENU in your *.pro file.

#### QtSVG

If you wish to use icon for your QtSmartGraphicsView, add svg module in the *.pro file. (QT += svg)

~~qtsmartgraphics now uses OpenGL. Before Qt 5.5 you have to use OpenGL version. After Qt 5.5 you'll have to add opengl module in the *.pro file. (QT += opengl)~~

### Documentation

Available at: http://kkyang.github.io/qtsmartgraphics

### Author

Original by Shih-Jhong Yu, Revised by KKyang. If there is any bug found, feel free to open an issue at Github.

### License

This library is written by Qt 5.3 and is distributed via source codes. Due to Qt open source licensing, this library is protected under LPGLv3 license.
