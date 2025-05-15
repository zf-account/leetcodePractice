def count(s):
    n = len(s)
    start = 0
    windows = {}
    length = 0
    for end in range(n):
        if s[end] in windows:
            start = max(start, windows[s[end]] + 1)
        windows[s[end]] = end
        length = max(length, end - start)
    return length

s = "abcabcabc​"
print(f"result:{count(s)}")