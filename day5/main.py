import re

ranges = []





if __name__ == "__main__":  
    ingredients = False
    answer1 = 0
    answer2 = 0
    with open('input.txt', 'r') as file:
        for line in file:
            line_strip = line.strip()
            if line_strip == '':
                ingredients = True
                continue
            else:
                if not ingredients:
                    line_split = line_strip.split('-')
                    ranges.append((int(line_split[0]), int(line_split[1])))
                    
                else:
                    for r in ranges:
                        if int(line_strip) >= r[0] and int(line_strip) <= r[1]:
                            answer1 += 1
                            break
                    pass
    print(answer1)
    # part 2
    ranges.sort()
    merged_ranges = []
    current_start, current_end = ranges[0]
    for r in ranges[1:]:
        if r[0] <= current_end + 1:
            current_end = max(current_end, r[1])
        else:
            merged_ranges.append((current_start, current_end))
            current_start, current_end = r
    merged_ranges.append((current_start, current_end))
    # now count all numbers in merged ranges
    for r in merged_ranges:
        answer2 += r[1] - r[0] + 1
    print(answer2)
    
