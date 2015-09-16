## qtsmartgraphics

A simple library that improves the user experience when displaying images by Qt's QLabel and QGraphicsView.

### Introduction

A simple library that improves the user experience when displaying images by Qt's QLabel and QGraphicsView. It also supports OpenCV Mat array type.

smartGraphicsView supports show image functions which supports QImage and Mat (in BGR format). It also supports mouse clicks, moves, and wheel events.

smartLabel supports show image functions which supports QImage and Mat (in BGR format). It also supports mouse clicks events.

### Usage

qtsmartgraphics now uses OpenGL. Before Qt 5.5 you have to use OpenGL version. After Qt 5.5 you'll have to add opengl module in the *.pro file. (QT += opengl)

### Author

Original by Shih-Jhong Yu, Revised by KKyang. If there is any bug found, feel free to open an issue at Github.

### License

This library is written by Qt 5.3 and is distributed via source codes. Due to Qt open source licensing, this library is protected under LPGLv3 license.
