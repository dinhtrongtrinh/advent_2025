import re

lines_for_answer = []
idk = []
lines_for_answer2 = [[],[],[],[]]


if __name__ == "__main__":
    with open('input.txt', 'r') as file:
        # for line in file:
        #     line_list = []
        #     each_number = re.findall(r'\d+', line)
        #     line_list.append(each_number)
        #     each_symbol = re.findall(r'\D+', line)
        #     line_list.append(each_symbol)
        #     print(line_list)
        lines = file.readlines()
        for i in range(len(lines)-1):
            lines[i] = lines[i].strip()
            each_number = re.findall(r'\d+', lines[i])
            lines_for_answer.append(each_number)


        each_symbol = re.findall("[*,+]", lines[-1])
        lines_for_answer.append(each_symbol)

    




    answer1 = 0
    answer2 = 0
    for line in lines:
        line_list = []
        for char in line:
            line_list.append(char)
        idk.append(line_list)
    
    the_numbers = []
    number = 0
    znamenko = ''
    for i in range(len(idk)):
        print(idk[i])

    for i in range(len(idk[0])-1,0,-1):
        new_col = True
        base = 10 
        for j in range(len(idk)-1):
            print(idk[j][i-1], i , j)
            if idk[j][i-1].isdigit():
                number = number * base + int(idk[j][i-1])
                base *= 10
                new_col = False
            else:
                znamenko = idk[j][i-1]

        if not new_col:
            the_numbers.append(number)
            number = 0
        else:
            if znamenko == '+':
                answer2 += sum(the_numbers)
            elif znamenko == '*':
                prod = 1
                for num in the_numbers:
                    prod *= num
                answer2 += prod
            the_numbers = []
            znamenko = ''


        
    

        
    #part 1
    for i in range(len(lines_for_answer[0])):
        if lines_for_answer[len(lines_for_answer)-1][i] == '+':
            sum = 0
            for j in range(0,len(lines_for_answer)-1):
                #print(lines_for_answer[j][i])
                sum += int(lines_for_answer[j][i])
            answer1 += sum
        else:
            sum = 1
            for j in range(0,len(lines_for_answer)-1):
                #print(lines_for_answer[j][i])
                sum *= int(lines_for_answer[j][i])
            answer1 += sum
    print(answer2)
    print(answer1)
    