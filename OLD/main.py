import time
import pyautogui as pg

def forever(tabs, x, y):
    while True:
        operation(sleeptime, tabs, review_x, review_y, options_x, options_y, blank_x, blank_y)

def limited(repetitions, sleeptime, tabs, review_x, review_y, options_x, options_y, blank_x, blank_y):
    for i in range(repetitions):
        operation(sleeptime, tabs, review_x, review_y, options_x, options_y, blank_x, blank_y)
        return
    
def operation(sleeptime, tabs, review_x, review_y, options_x, options_y, blank_x, blank_y):
    pg.click(options_x, options_y)
        
    for i in range(tabs):
        pg.middleClick(review_x, review_y)
        time.sleep(sleeptime)

    pg.keyDown('ctrl')
    for i in range(tabs):
        pg.press('tab')
        time.sleep(0.1)
        pg.press('v')
        time.sleep(0.1)
        pg.press('enter')
    pg.keyUp('ctrl')

    for i in range(tabs):
        pg.keyDown('ctrl')
        pg.press('w')
        pg.keyUp('ctrl')
    pg.click(685, 330)

tabs = int(input("How many TABS do you want to open: "))
choice = int(input("Do you want to do this loop (1)forever or (2)limited?: "))

sleeptime = 0.3
options_x = int(input("Enter Options X Coordinates: "))
options_y = int(input("Enter Options Y Coordinates: "))
review_x = int(input("Enter Review X Coordinates: "))
review_y = int(input("Enter Review Y Coordinates: "))
blank_x = int(input("Enter Blank X Coordinates: "))
blank_y = int(input("Enter Blank Y Coordinates: "))

if choice == 1:
    forever(tabs)

elif choice == 2:
    repetitions = int(input("How many repetitions: "))
    limited(repetitions, sleeptime, tabs, review_x, review_y, options_x, options_y, blank_x, blank_y)

else:
    print("\nINVALID")

# while True:
#     pg.click(780, 392)
#     time.sleep(0.15)
    
#     # This is how many tabs the script will open
#     for i in range(15):
#         pg.middleClick(820, 430)
#     time.sleep(7)
    
#    # This is the ammount of times u control tab (must be the same value as pg.middleClick)

#     pg.keyDown('ctrl')
#     for i in range(15):
#         pg.press('tab')
#         time.sleep(0.1)
#         pg.press('v')
#         time.sleep(0.1)
#         pg.press('enter')
#     pg.keyUp('ctrl')

#     for i in range(15):
#         pg.keyDown('ctrl')
#         pg.press('w')
#         pg.keyUp('ctrl')
#     pg.click(685, 330)