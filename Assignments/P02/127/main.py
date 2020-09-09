import time
start = time.perf_counter()
deck = []

[deck.append([card]) for card in input().split()]

while deck[0][0] != '#':
    [deck.append([card]) for card in input().split()]

    # stack with matching rank or suit.
    # must use while loop since for would not allow i to be decrimented
    i = 0
    while i < len(deck):
        # prioritize 3 move to left
        if(i > 2 and (deck[i][-1][0] == deck[i-3][-1][0] or deck[i][-1][1] == deck[i-3][-1][1])):
            deck[i-3].append(deck[i].pop())
            if(len(deck[i]) == 0):
                del deck[i]
            i = i - 4
        if(i > 0 and (deck[i][-1][0] == deck[i-1][-1][0] or deck[i][-1][1] == deck[i-1][-1][1])):
            deck[i-1].append(deck[i].pop())
            if(len(deck[i]) == 0):
                del deck[i]
            i = i - 2
        i = i + 1

    # print results
    if(len(deck) == 1):
        print("1 pile remaining: 52")
    else:
        print(f"{len(deck)} piles remaining: ", end='')
        for i in range(len(deck) - 1):
            print(len(deck[i]), end=' ')
        print(len(deck[-1]))

    # clear deck and cin first line of new deck
    deck.clear()
    [deck.append([card]) for card in input().split()]

end = time.perf_counter()
print(f'execution time: {end - start:0.4f}')
