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
    print("Please install the required modules.")
    sys.exit()


class ImageApp(QWidget):

    def __init__(self):
        QWidget.__init__(self)
        self.original_img = cv2.imread("../../assets/The_Chapter_House.jpg")
        if self.original_img is not None:
            self.original_img = cv2.cvtColor(self.original_img, cv2.COLOR_BGR2RGB)
        self.setup_ui()
        self.show_image(self.original_img)

    def setup_ui(self):
        """Setup the UI widgets."""
        self.image_label = QLabel()
        # Setup buttons
        self.original_btn = QPushButton("Original")
        self.original_btn.clicked.connect(self.show_original_image)
        self.blur_btn = QPushButton("Gaussian Blur")
        self.blur_btn.clicked.connect(self.do_gaussian_blur)
        self.canny_btn = QPushButton("Canny")
        self.canny_btn.clicked.connect(self.do_canny)
        self.quit_btn = QPushButton("Quit")
        self.quit_btn.clicked.connect(self.close)
        # Setup layout for buttons
        self.buttons_layout = QVBoxLayout()
        self.buttons_layout.addWidget(self.original_btn)
        self.buttons_layout.addWidget(self.blur_btn)
        self.buttons_layout.addWidget(self.canny_btn)
        self.buttons_layout.addStretch()
        self.buttons_layout.addWidget(self.quit_btn)
        # Setup main layout
        self.main_layout = QHBoxLayout()
        self.main_layout.addWidget(self.image_label)
        self.main_layout.addLayout(self.buttons_layout)
        self.setLayout(self.main_layout)
        self.setWindowTitle("Image Processing with Qt and OpenCV")

    def show_original_image(self):
        """Redraw original image."""
        self.show_image(self.original_img)

    def do_gaussian_blur(self):
        """Perform Canny edge detection on original image and display the result."""
        img = cv2.GaussianBlur(self.original_img, (15, 15), 0, 0)
        self.show_image(img)

    def do_canny(self):
        """Perform Gaussian blurring on original image and display the result."""
        img = cv2.cvtColor(self.original_img, cv2.COLOR_RGB2GRAY)
        img = cv2.Canny(img, 150, 150)
        img = cv2.cvtColor(img, cv2.COLOR_GRAY2RGB)
        self.show_image(img)

    def show_image(self, img):
        if img is not None:
            img_ = QImage(img.data, img.shape[1], img.shape[0], QImage.Format_RGB888)
            self.image_label.setPixmap(QPixmap.fromImage(img_))
        else:
            self.image_label.setText("Cannot load the input image!")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    image_app = ImageApp()
    image_app.show()
    app.exec_()
