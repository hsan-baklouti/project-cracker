# (guess,green,blue)
input = [("234", 1, 1), ("567", 0, 0), ("564", 1, 0), ("401", 0, 2), ("124", 1, 1)]


def check_feedback(code, guess):
    green = 0

    for i in range(3):
        if code[i] == guess[i]:
            green += 1

    code_count = {}
    guess_count = {}

    for digit in code:
        if digit in code_count:
            code_count[digit] += 1
        else:
            code_count[digit] = 1

    for digit in guess:
        if digit in guess_count:
            guess_count[digit] += 1
        else:
            guess_count[digit] = 1

    total_matches = 0
    for digit in guess_count:
        if digit in code_count:
            if guess_count[digit] < code_count[digit]:
                total_matches += guess_count[digit]
            else:
                total_matches += code_count[digit]

    blue = total_matches - green

    return green, blue


found_codes = []
for a in range(10):
    for b in range(10):
        for c in range(10):
            possible = str(a) + str(b) + str(c)
            matches_all = True

            for guess, want_green, want_blue in input:
                got_green, got_blue = check_feedback(possible, guess)
                if got_green != want_green or got_blue != want_blue:
                    matches_all = False
                    break

            if matches_all:
                found_codes.append(possible)

print("code:", found_codes)
