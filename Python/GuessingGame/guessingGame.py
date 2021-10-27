import random

randNo = random.randint(1, 100)

guess = 0
while (True):
    num = int(input("Enter your guess: "))
    if(num>randNo):
        print("You guessed it wrong ! Enter a smaller number")
        guess+=1
        continue
    elif(num < randNo):
        print("You guessed it wrong ! Enter a larger number")
        guess+=1
        continue
    elif(num==randNo):
        guess+=1
        print("You won!")
        print(f"You took {guess} guesses")
        break

with open("hiscore.txt") as f:
    hiscore = int(f.read())

if(guess<hiscore):
    print("You just broke the high score !")
    with open("hiscore.txt", 'w') as f:
        f.write(str(guess))
