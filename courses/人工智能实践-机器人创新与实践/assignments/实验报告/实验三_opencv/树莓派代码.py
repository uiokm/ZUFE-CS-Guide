from gpiozero import LED
from time import sleep
import cv2

led1 = LED(27)
led2 = LED(17)
led3 = LED(22)
# set up camera object
cap = cv2.VideoCapture(0)
# QR code detection object
detector = cv2.QRCodeDetector()
while True:
    # get the image
    _, img = cap.read()
    # get bounding box coords and data
    data, bbox, _ = detector.detectAndDecode(img)

    # if there is a bounding box, draw one, along with the data
    if bbox is not None:
        for i in range(len(bbox)):
            cv2.line(img, tuple(bbox[i][0]), tuple(bbox[(i+1) % len(bbox)][0]), color=(255, 0, 255), thickness=2)
        cv2.putText(img, data, (int(bbox[0][0][0]), int(bbox[0][0][1]) - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
        if data=='1':
            print("data found: ", data)
            led1.off()
            led2.off()
            led3.off()
        if data=='2':
            print("data found: ", data)
            led1.on()
            led2.off()
            led3.off()
        if data=='3':
            print("data found: ", data)
            led1.off()
            led2.on()
            led3.off()
        if data=='4':
            print("data found: ", data)
            led2.on()
            led1.on()
            led3.off()
        if data=='5':
            print("data found: ", data)
            led2.off()
            led1.off()
            led3.on()
        if data=='6':
            print("data found: ", data)
            led2.on()
            led1.on()
            led3.on()

    # display the image preview
    cv2.imshow("code detector", img)
    if(cv2.waitKey(1) == ord("q")):
        break
# free camera object and exit
cap.release()
cv2.destroyAllWindows() 