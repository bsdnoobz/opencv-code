#!/usr/bin/env python
# encoding: utf-8

import os
import sys

try:
    from PyQt5.QtCore import *
    from PyQt5.QtGui import *
    from PyQt5.QtWidgets import *
    import cv2
except ImportError:
    print("Please install the required packages.")
    sys.exit()

class ImageViewer(QWidget):

    def __init__(self):
        QWidget.__init__(self)
        self.filename = "../../assets/flughahn.jpg"
        self.setup_ui()

    def setup_ui(self):
        img = cv2.imread(self.filename)
        self.image_label = QLabel()
        if img is None:
            self.image_label.setText("Cannot load the input image.")
        else:
            img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            img_ = QImage(img.data, img.shape[1], img.shape[0], QImage.Format_RGB888)
            self.image_label.setPixmap(QPixmap.fromImage(img_))
        self.quit_button = QPushButton("Quit")
        self.quit_button.clicked.connect(self.close)
        self.main_layout = QVBoxLayout()
        self.main_layout.addWidget(self.image_label)
        self.main_layout.addWidget(self.quit_button)
        self.setLayout(self.main_layout)
        self.setWindowTitle("OpenCV - Qt Integration")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    viewer = ImageViewer()
    viewer.show()
    app.exec_()
