import cv2
import numpy as np

cap = cv2.VideoCapture(0)

# Create old frame
ret, frame = cap.read()
oldGray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

# Lucas-Kanade Params
lkParams = dict(winSize=(20, 20),
                maxLevel=4,
                criteria=(cv2.TermCriteria_EPS | cv2.TERM_CRITERIA_COUNT, 10, 0.03))


# Select Point Function
def select(event, x, y, flags, params):
    global point, objSelected, oldPoints
    if event == cv2.EVENT_LBUTTONDOWN:
        point = (x, y)
        objSelected = True
        oldPoints = np.array([[x, y]], dtype=np.float32)


# Detect Direction
def Direction(old, new):
    if new[0][0] + 1 < old[0][0]:
        dir = 'Left Direction'
    elif new[0][0] - 1 > old[0][0]:
        dir = 'Right Direction'
    else:
        dir = 'No motion'
    return dir


# Calling Select Object Function
cv2.namedWindow("Frame")
cv2.setMouseCallback("Frame", select)

objSelected = False
point = ()
oldPoints = np.array([[]])

# While Loop
while True:

    ret, frame = cap.read()
    grayFrame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # If object selected, use Optical Flow Algorithm
    if objSelected is True:
        newPoints, status, error = cv2.calcOpticalFlowPyrLK(oldGray, grayFrame, oldPoints, None, **lkParams)
        oldGray = grayFrame.copy()
        dir = Direction(oldPoints, newPoints)
        oldPoints = newPoints
        x, y = newPoints.ravel()
        cv2.circle(frame, (x, y), 10, (0, 0, 0), -1)
        cv2.putText(frame, dir, (100, 450), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 255, 0), 2)

      #ask user to select point
    else:
        cv2.putText(frame, 'select point', (200, 100), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 0), 2)

    # Show Frame
    cv2.imshow("Frame", frame)


    #Wait Key
    key = cv2.waitKey(1)
    if key == 32:
        break

cap.release()
cv2.destroyAllWindows()