import random

words = ["fight", "water", "program", "flutter", "ballon","fest","computer","melon","supernatural"]

word = random.choice(words)

turns = 5

gusses = word[0] + word[len(word) - 1] + ""

while turns > 0:
    failed = 0

    
    for char in word:
        if char in gusses:
                print(char)
        else:
            print("_")
            failed += 1

    if failed == 0:
        print("win :)\n")
        print("\nword was: ", word)
        break

    guess = input("Enter your guess here: ")

    gusses += guess

    if guess not in word:
        turns -= 1
        print("Wrong Guess :(")
        print(turns, "lives left")

    if turns == 0:
        print("\nGame Over!!")
        print("\nWord was: ", word)