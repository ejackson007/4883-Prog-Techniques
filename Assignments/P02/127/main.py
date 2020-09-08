# Changed to have current playing field. In a endless loop

game = []
playing_field = []
completed = False
prev_size = 52


# function to clean up the if statements.
# returns the suit of the card on the top of the stack left amount of places
def get_left_suit(stack, left):
    return game[game.index(stack) - left][-1][1]


def get_left_rank(stack, left):
    return game[game.index(stack) - left][-1][0]


def stack_cards(stack, left):
    game[game.index(stack) - left].append(stack[-1])
    # get rid of pile if the move makes it empty
    if(len(stack) == 1):
        game.remove(stack)


[game.append([card]) for card in input().split()]

while game[0][0] != '#':
    # read in line after # is not found
    [game.append([card]) for card in input().split()]
    # print(game)
    for stacks in game:
        playing_field.append(stacks)
        while not completed:
            # priority to left most movement
            if(len(playing_field) >= 4):
                if(playing_field[-1][-1][0] == get_left_rank(playing_field[-1], 3) or
                   playing_field[-1][-1][1] == get_left_suit(playing_field[-1], 3)):
                    stack_cards(playing_field[-1], 3)
            elif(len(playing_field) >= 2):
                if(playing_field[-1][-1][0] == get_left_rank(playing_field[-1], 1) or
                   playing_field[-1][-1][1] == get_left_suit(playing_field[-1], 1)):
                    stack_cards(playing_field[-1], 1)
            # check if the size of the game field changed
            if(len(playing_field) == prev_size):
                completed = True
            else:
                prev_size = len(game)  # set current length
    # print results
    if(len(game) == 1):
        print("1 pile remaining: 52")
    else:
        print(f"{len(game)} piles remaining: {[len(stack) for stack in game]}")
    # start new game
    game.clear()
    completed = False
    prev_size = 52
    [game.append([card]) for card in input().split()]
