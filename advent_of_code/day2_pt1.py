file_path = "day2_pt1.txt"

# Open the file in read mode
with open(file_path, 'r') as file:
    # Iterate over each line in the file
    ans = 0
    for line in file:
        id = ""
        i = 5
        while line[i].isdigit():
            id += line[i]
            i += 1
        id = int(id)
        rounds = line[line.find(':') + 1:].split(";")
        valid = True
        for around in rounds:
            nums = around.split(',')
            r = 0
            b = 0
            g = 0
            for num in nums:
                num = num.strip()
                i = 0
                count = ""
                while num[i].isdigit():
                    count += num[i]
                    i += 1
                count = int(count)
                if num[i + 1] == 'r':
                    r = count
                elif num[i + 1] == 'g':
                    g = count
                else:
                    b = count
            if r > 12 or g > 13 or b > 14:
                valid = False
                break
        if valid:
            ans += id

    print(ans)


        
