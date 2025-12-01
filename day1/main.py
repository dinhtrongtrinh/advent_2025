import re

if __name__ == "__main__":

    num_list = [i for i in range(1,100)]
    zero = None
    count = 0
    current = 50

    with open('input.txt', 'r') as f:
        for l in f:
            zero = None
            line = l[:-1]
            if int(l[1:]) >= 100:
                total_times = int(l[1:]) // 100
                count += total_times
            move_num = int(l[1:]) % 100
            if line[0] == 'L':
                if current < move_num:
                    move = current - move_num
                    if current != 0:
                        count += 1
                elif current > move_num:
                    move = (current - move_num) - 1
                else:
                    zero = True

            if line[0] == 'R':
                if (current + move_num) == 100:
                    zero = True
                elif (current + move_num) < 100:
                    move = (current + move_num) -1
                elif (current + move_num) > 100:
                    move = (current + move_num) - 101
                    count += 1

            if not zero:
                current = num_list[move]
            elif zero:
                count += 1
                current = 0

    print(f"Final count = {count}")
