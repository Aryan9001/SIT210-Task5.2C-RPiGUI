from tkinter import*
import tkinter.font
from gpiozero import LED
import RPi.GPIO
RPi.GPIO.setwarnings(False)
RPi.GPIO.setmode(RPi.GPIO.BCM)


red_Led = LED(21)
blue_Led = LED(25)
green_Led = LED(22)

win = Tk()
win.title("LED Control")
myFont = tkinter.font.Font(family = 'Helveticq', size = 12, weight = 'bold')

def RedLED():
    if red_Led.is_lit:
       red_Led.off()
       RedledButton["text"] = "Turn on red led"
    else:
        red_Led.on()
        RedledButton["text"] = "Turn off red led"
        blue_Led.off()
        BlueledButton["text"] = "Turn on blue led"
        green_Led.off()
        GreenledButton["text"] = "Turn on green led"

def BlueLED():
    if blue_Led.is_lit:
        blue_Led.off()
        BlueledButton["text"] = "Turn on blue led"
    else:
        blue_Led.on()
        BlueledButton["text"] = "Turn off blue led"
        RedledButton["text"] = "Turn on red led"
        green_Led.off()
        GreenledButton["text"] = "Turn on green led"

def GreenLED():
    if green_Led.is_lit:
       green_Led.off()
       GreenledButton["text"] = "Turn on green led"
    else:
        green_Led.on()
        GreenledButton["text"] = "Turn off green led"
        blue_Led.off()
        BlueledButton["text"] = "Turn on blue led"
        red_Led.off()
        RedledButton["text"] = "Turn on red led"


def close():

    RPi.GPIO.cleanup()
    win.destroy()



RedledButton = Button(win, text='Turn led on red led', font=myFont, command=RedLED, bg='bisque2', height=1, width=24)
RedledButton.grid(row=0, column=1)
BlueledButton = Button(win, text='Turn led on blue led', font=myFont, command=BlueLED, bg='bisque2', height=1, width=24)
BlueledButton.grid(row=1, column=1)
GreenledButton = Button(win, text='Turn led on green led', font=myFont, command=GreenLED, bg='bisque2', height=1, width=24)
GreenledButton.grid(row=2, column=1)
ExistledButton = Button(win, text='EXIST', font=myFont, command=close, bg='red', height=1, width=6)
ExistledButton.grid(row=3, column=1)
win.mainloop()