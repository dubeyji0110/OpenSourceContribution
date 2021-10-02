import pyautogui
from time import sleep
from PIL import ImageGrab,ImageOps

def takess():
    image = ImageGrab.grab().convert('L')
    # image.show()
    return image

def isCollide(data):
    #THE BELOW CODE IS FOR CACTUS
    for i in range(684,725):
        for j in range(526,568):
            if data[i, j] < 100 :
                pyautogui.keyDown('up')
                sleep(0.04)
                pyautogui.keyUp('up')
                return True
    
    #THE BELOW CODE FOR THE BIRDS
    for i in range(685,725):
        for j in range(490,523):
            if data[i, j] < 100 :
                pyautogui.keyDown('down')
                sleep(0.09)
                pyautogui.keyUp('down')
                return True
    return False

def hit(key):
    pyautogui.keyDown(key)

if __name__=="__main__":
    print("Game is starting in 5 seconds........ ")
    sleep(5)
    hit('up')
    while True:
        image = takess()
        data = image.load()
        isCollide(data)
            
        

    