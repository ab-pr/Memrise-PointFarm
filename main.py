

import time
import pyautogui
pyautogui.PAUSE = 0.05

sleep = time.sleep
pyClick = pyautogui.click
pyMove = pyautogui.moveTo
pyPress = pyautogui.press
kDown = pyautogui.keyDown
kUp = pyautogui.keyUp
pyPause = pyautogui.PAUSE

while True:
    pyClick(780, 392)
    sleep(0.15)

    for i in range(30):
        pyautogui.middleClick(820, 430)
    sleep(15)

    pyPause = 0.1
    for i in range(30):
        kDown('ctrl')
        pyPress('tab')
        sleep
        pyPress('v')
        pyPress('enter')
        kUp('ctrl')

    for i in range(30):
        kDown('ctrl')
        pyPress('w')
        kUp('ctrl')
    pyClick(685, 330)






