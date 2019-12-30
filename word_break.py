

def word_break(s,dictionary):
    

    result = []
    index = 0
    word_break_helper(s,index,dictionary,result)


def word_break_helper(s,index,dictionary,result):
    for i in range(index + 1,len(s) + 1):
        prefix = s[index:i]
        if prefix in dictionary:

            if i == len(s):
                result.append(prefix)

                print(' '.join(result))
                result.pop()
            else:
                result.append(prefix)
                word_break_helper(s,i,dictionary,result)
                result.pop()





if __name__ == "__main__":
    
    dictionary = {"i","like","and","sam","sung","samsung","mobile","ice","cream","icecream","mango","man","go"}
    s = "ilikesamsungmobile" 
    s2 = "ilikeicecreamandmango"

    word_break(s2,dictionary)




