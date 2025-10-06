def tour(petrolpumps):
    start = 0
    deficit = 0
    balance = 0
    for i in range(len(petrolpumps)):
        balance += petrolpumps[i][0] - petrolpumps[i][1]
        if balance < 0:
            start = i + 1
            deficit += balance
            balance = 0
    return start if balance + deficit >= 0 else -1
