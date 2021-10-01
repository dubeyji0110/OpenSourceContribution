board = [[' ', ' ', ' '], 
         [' ', ' ', ' '],
         [' ', ' ', ' ']]

# comp -> maximizer(player) | human -> minimizer(opponent)
minimizer = 'O'
maximizer = 'X'

def display(board):
    for i in range(3):
        print(board[i][0]+" | "+board[i][1]+" | "+board[i][2])

def isWinner(player):
    for i in range(3):
        if board[i][0]==board[i][1] and board[i][1]==board[i][2] and board[i][0]!=' ':
            if board[i][0]==player:
                return 1
            else:
                return 0
    for i in range(3):
        if board[0][i]==board[1][i] and board[1][i]==board[2][i] and board[0][i]!=' ':
            if board[0][i]==player:
                return 1
            else:
                return 0
    if board[0][0]==board[1][1] and board[1][1]==board[2][2] and board[1][1]!=' ':
        if board[0][0]==player:
            return 1
        else:
            return 0
    if board[0][2]==board[1][1] and board[1][1]==board[2][0] and board[1][1]!=' ':
        if board[0][2]==player:
            return 1
        else:
            return 0
    return 0

def isMoveLeft(board):
    for i in range(3):
        for j in range(3):
            if board[i][j]==' ':
                return 1
    return 0

def evaluate(board):
    for i in range(3):
        if board[i][0]==board[i][1] and board[i][1]==board[i][2]:
            if board[i][0]==maximizer:
                return 10
            elif board[i][0]==minimizer:
                return -10
    for i in range(3):
        if board[0][i]==board[1][i] and board[1][i]==board[2][i]:
            if board[0][i]==maximizer:
                return 10
            elif board[0][i]==minimizer:
                return -10
    if board[0][0]==board[1][1] and board[1][1]==board[2][2]:
        if board[0][0]==maximizer:
            return 10
        elif board[1][1]==minimizer:
            return -10
    if board[0][2]==board[1][1] and board[1][1]==board[2][0]:
        if board[0][2]==maximizer:
            return 10
        elif board[1][1]==minimizer:
            return -10
    return 0

def minimax(board, depth, isMax):
    score = evaluate(board)
    if score==10 or score==-10:
        return score-depth
    if isMoveLeft(board)==0:
        return 0-depth
    if isMax:
        best=-1000
        for i in range(3):
            for j in range(3):
                if board[i][j]==' ':
                    board[i][j]=maximizer
                    best=max(best,minimax(board,depth+1,not isMax))
                    board[i][j]=' '
        return best
    else:
        best=1000
        for i in range(3):
            for j in range(3):
                if board[i][j]==' ':
                    board[i][j]=minimizer
                    best=min(best,minimax(board,depth+1,not isMax))
                    board[i][j]=' '
        return best

def findBestMove(board):
    bestVal=-1000
    r=-1
    c=-1
    for i in range(3):
        for j in range(3):
            if board[i][j]==' ':
                board[i][j]=maximizer
                moveVal=minimax(board,0,False)
                board[i][j]=' '
                if moveVal>bestVal:
                    bestVal=moveVal
                    r=i
                    c=j
    return [r,c]

def compMove():
    bestMove = findBestMove(board)
    board[bestMove[0]][bestMove[1]]='X'

def playerMove():
    while True:
        moveRow = int(input("Enter Row"))
        moveCol = int(input("Enter Column"))
        if moveRow<3 and moveCol<3 and board[moveRow][moveCol]==' ':
            board[moveRow][moveCol]='O'
            break
        else:
            print("Enter right values")

def main():
    display(board)
    while isMoveLeft(board):
        playerMove()
        compMove()
        display(board)
        if isWinner('X'):
            print("AI is winner")
            return
        elif isWinner('O'):
            print("You are winner")
            return
    print("Tie!!!")

main()