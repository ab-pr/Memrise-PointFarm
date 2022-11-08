import time as sleep
import pyautogui as pagui
pagui.PAUSE = 0.02 # ←Change this to change the ammount of delay in the script (u can use this so ur system can catch up with the script)


while True:
    pagui.click(780, 392)
    sleep.sleep(0.15)
    
    # This is how many tabs the script will open
    for i in range(15):
        pagui.middleClick(820, 430)
    sleep.sleep(7)
    
   # This is the ammount of times u control tab (must be the same value as pagui.middleClick)

    pagui.keyDown('ctrl')
    for i in range(15):
        pagui.press('tab')
        sleep.sleep(0.1)
        pagui.press('v')
        sleep.sleep(0.1)
        pagui.press('enter')
    pagui.keyUp('ctrl')

    for i in range(15):
        pagui.keyDown('ctrl')
        pagui.press('w')
        pagui.keyUp('ctrl')
    pagui.click(685, 330)