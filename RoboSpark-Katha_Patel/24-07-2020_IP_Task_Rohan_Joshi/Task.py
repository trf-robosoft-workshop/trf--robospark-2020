

import cv2
import numpy as np

original = cv2.imread(r"D:\Codes\Python\IP_Images\yellow_flower.jpg")
res = cv2.resize(original, (640, 400))

bgrl = np.array([15, 0, 120], np.uint8)
bgrh = np.array([215, 255, 255], np.uint8)

mask = cv2.inRange(res, bgrl, bgrh)
cv2.resize(mask, (640, 400))
kernel = np.array(([3, 2, 6], [5, 7, 8], [2, 4, 8]), np.uint8)

blurred_avg = cv2.blur(mask, (5, 5))
gaus_blur = cv2.GaussianBlur(mask, (5, 5), 8)
bil = cv2.bilateralFilter(mask, 5, 5, 4)
blurred = cv2.filter2D(mask, -1, kernel)
text = cv2.putText(res, 'this is text', (30, 45), cv2.FONT_HERSHEY_COMPLEX_SMALL, 2, (255, 25, 55), 4)

cv2.imshow('original', res)
cv2.imshow('masked', mask)
cv2.imshow('blurred avg', blurred_avg)
cv2.imshow('blurred', blurred)
cv2.imshow('gaus_blur', gaus_blur)
cv2.imshow('img_with_text', text)

cv2.imwrite('original.jpg', res)
cv2.imwrite('masked.jpg', text)
cv2.imwrite('blurred_avg.jpg', blurred_avg)
cv2.imwrite('blurred.jpg', blurred)
cv2.imwrite('gaus_blur.jpg', gaus_blur)
cv2.imwrite('img_with_text.jpg', text)


cv2.waitKey(0)
cv2.destroyAllWindows()
