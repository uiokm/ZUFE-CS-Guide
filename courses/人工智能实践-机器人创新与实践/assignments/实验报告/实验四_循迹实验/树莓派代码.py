from crypt import methods
from gpiozero import LED
from time import sleep
import numpy as np
from PIL import Image
import tflite_runtime.interpreter as tflite
#import picamera

import os
led_0 = LED(23)
led_1 = LED(24)
interpreter = tflite.Interpreter(model_path="model.tflite")
interpreter.allocate_tensors()
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()
'''with picamera.PiCamera() as camera:
camera.resolution = (640, 480)
camera.capture('input.png')'''
while 1:
photo=os.system("fswebcam --no-banner -r 640x480 input.png")
photo
img = Image.open('input.png').convert("L")
img=img.resize((28,28),Image.ANTIALIAS)
img_array = np.array(img)
img_array=img_array/255.0
img_array = img_array.astype('float32')
img_reshape=np.reshape(img_array,(1,28,28))
input_data = img_reshape
interpreter.set_tensor(input_details[0]['index'], input_data)
interpreter.invoke()
output_data = interpreter.get_tensor(output_details[0]['index'])
maxa=np.argmax(output_data[0])
print(maxa)
if maxa == 0:
led_0.on()
led_1.off()
print('left')
if maxa == 1:
led_0.off()
led_1.on()
print('right')
if maxa == 2:
led_0.on()
led_1.on()
print('straight')