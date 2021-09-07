import serial
import subprocess

ser = serial.Serial('COM3',9600)

f = open('dataFile.txt','w')

while 1 :
    f.write(ser.readline())
    ser.flushInput()
    ser.flushOutput()
    f.close()
    subprocess.call(['java', '-jar', 'FileUploader.jar'])
    f = open('dataFile.txt','w')