# This was done by reading the whole deck in first. It needs to be done by reading one card at a time


game = []
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
    while not completed:
        for stacks in game:
            # priority to left most movement
            if(game.index(stacks) >= 3):
                if(stacks[-1][0] == get_left_rank(stacks, 3) or
                   stacks[-1][1] == get_left_suit(stacks, 3)):
                    stack_cards(stacks, 3)
            elif(game.index(stacks) >= 1):
                if(stacks[-1][0] == get_left_rank(stacks, 1) or
                   stacks[-1][1] == get_left_suit(stacks, 1)):
                    stack_cards(stacks, 1)
        # check if the size of the game field changed
        if(len(game) == prev_size):
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
