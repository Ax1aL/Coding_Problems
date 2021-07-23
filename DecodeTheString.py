#Problem:---------------------------
#Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
#For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
#You can assume that the messages are decodable. For example, '001' is not allowed.

#Solution:--------------------------
#Using backtracking we take any possible solution composed of maximum 2 numbers and less than 27(z=26)
#And count the numbers of ways we found.It ends up having alot of special cases where 0 would be count as number or the begging of a number
#and we have to take that into consideration

count =0

def backtracking(str ,position=0):
    if position>= len(str)-1 :
        global count
        count+=1
        return

    if int(str[position])>=1 and int(str[position])<=9:
        if int(str[position+1]) != 0:
            backtracking(str,position+1)

    if position+1<=len(str)-1:
        if int(str[position:position+2]) >= 1 and int(str[position:position+2]) <= 26:
            if int(str[position])!=0:
                position += 1
                backtracking(str, position+1)

if __name__ == '__main__':
    backtracking("2191")
    print("The 2191 count is %d" %count)
    count=0
    backtracking("2101")
    print("The 2101 count is %d" %count)
    count = 0
    backtracking("001")
    print("The 001 count is %d" % count)
    count = 0
    backtracking("1111")
    print("The 1111 count is %d" % count)

