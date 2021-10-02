
from datetime import datetime
import pyttsx3
import pytz

def speak(s):
    text = str(s)
    engine = pyttsx3.init()
    engine.setProperty("rate",150)
    engine.say(text)
    engine.runAndWait()

def get_time():
    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    print("Current Time =", current_time)

def get_date():
    now = datetime.now()
    today = now.strftime("%d/%m/%Y")
    print(today)

get_date()
get_time()
speak("time to take paracetamol")
