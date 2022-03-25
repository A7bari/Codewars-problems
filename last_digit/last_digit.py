def last_digit(lst):
    if not lst:
        return 1
    else:
        var = 1
        for n in lst[len(lst):0:-1]:
            var = n**var
            if var > 2:
                var = (var - 2) % 4 + 2
    return lst[0]**var % 10

    pass
