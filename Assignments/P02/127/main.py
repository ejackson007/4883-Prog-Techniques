deck = []
playing_field = []
stack = []
completed = False

# get first half of input
[deck.append([card]) for card in input().split()]

while deck[0][0] != '#':
    # get second half of input
    [deck.append([card]) for card in input().split()]
    # play each card in deck until its empty
    for card in deck:
        print(card)
    # set for next round
    deck.clear()
    playing_field.clear()
    stack.clear()
    # readin first line of new deck
    [deck.append([card]) for card in input().split()]
