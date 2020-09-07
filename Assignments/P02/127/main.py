game = []

[game.append([card]) for card in input().split()]

while game[0][0] != '#':
    #read in line after # is not found
    [game.append([card]) for card in input().split()]
    print(game)

    #end of operation, ready for next 
    game.clear()
    print("Next pack")
    [game.append([card]) for card in input().split()]
