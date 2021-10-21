import nltk 
from nltk.chat.util import Chat, reflections
reflections = {
    "i am" : "you are",
    "i was" : "you were",
    "i " : "you ",
    "i'm" : "you are",
    "i'd" : "you would",
    "i've" : "you have",
    "i'll" : "you will",
    "my" : "your",
    "you are" : "i am",
    "you were" : "i was",
    "you've" : "i have",
    "you'll" : "i will",
    "your" : "my",
    "yours" : "mine",
    "you" : "me",
    "me" : "you",
    "What's" : "What is",
    "What is" : "What's",
}
pairs = [
         [
          r"my name is (.*)",
          ["Hello %1, How are you today ?",]
         ],
         [
          r"hi|hey|hello",
          ["Hello","Hey there",]
         ],
         [
          r"What is your name?",
          ["I am a bot created by Aryan Sharma. You can call me Bixby",]
         ],
         [
          r"What's your name?",
          ["I am a bot created by Aryan Sharma. You can call me Bixby",]
         ],
         [
          r"Where are you from?",
          ["I am from artificially intelligence place",]
         ],
          [
          r"I am good what about you ?",
          ["I am good too just chillin for a while and talking to you!",]
         ],
          [
          r"How old are you ?",
          ["I am 2 yrs old",]
         ],
          [
          r"What you eat?",
          ["I eat memory and knowledge",]
         ],
          [
          r"Where do you live?",
          ["I am everywhere where do you live?",]
         ],
          [
          r"i live in (.*)",
          ["%1 , Great Place",]
         ],
]
def chat():
  print ("Hi! I am Bixby created by Aryan Sharma at your service")
  chat = Chat(pairs, reflections)
  chat.converse()
if __name__ == "__main__":
  chat()
  #this code is written by Aryansharma