deck = []
pf = []  # playing field

# function to clean up the if statements.
# returns the suit of the card on the top of the stack left amount of places


def get_left_suit(stack, left):
    return pf[pf.index(stack) - left][-1][1]


def get_left_rank(stack, left):
    return pf[pf.index(stack) - left][-1][0]


def stack_cards(stack, left):
    pf[pf.index(stack) - left].append(stack[-1])
    # get rid of pile if the move makes it empty
    if(len(stack) == 1):
        pf.remove(stack)
    else:
        pf[pf.index(stack)].pop()


# get first half of input
[deck.append([card]) for card in input().split()]

while deck[0][0] != '#':
    # get second half of input
    [deck.append([card]) for card in input().split()]
    # play each card in deck until its empty
    for card in deck:
        pf.append(card)
        changed = True  # change made to pf
        # keep making changes until you cannot anymore
        while changed:
            changed = False  # set that it hasnt been changed
            for stack in pf:
                if(pf.index(stack) > 2):
                    if(stack[-1][0] == get_left_rank(pf[pf.index(stack)], 3) or
                       stack[-1][1] == get_left_suit(pf[pf.index(stack)], 3)):
                        stack_cards(pf[pf.index(stack)], 3)
                        changed = True
                if(not changed and pf.index(stack) > 0):
                    if(stack[-1][0] == get_left_rank(pf[pf.index(stack)], 1) or
                       stack[-1][1] == get_left_suit(pf[pf.index(stack)], 1)):
                        stack_cards(pf[pf.index(stack)], 1)
                        changed = True
    if(len(pf) == 1):
        print("1 pile remaining: 52")
    else:
        print(f"{len(pf)} piles remaining: {[len(stack) for stack in pf]}")
    # prepare game for next run
    deck.clear()
    pf.clear()
    [deck.append([card]) for card in input().split()]
