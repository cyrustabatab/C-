from collections import OrderedDict

class TrieXOR:

    def __init__(self,k):
        self.root = {}
        self.k = k


    def add(self,num):

        current = self.root
        for i in range(self.k):
            bit = (num >>i ) & 1

            if bit not in current:
                current[bit] = {}

            current = current[bit]


    def max(self,num):

        current = self.root
        
        xor = 0
        for i in range(self.k):
            bit = (num >>i)  & 1

            if (1 - bit) in current:
                xor |= (1 << bit)
                current = current[1 - bit]
            else:
                current = current[bit]

    
        return xor


def max_xor(nums):


    k = max(x).bit_length()

    trie = Trie(k)

    for num in nums:
        trie.add(num)


    max_xor = 0

    for num in nums:
        max_xor = max(max_xor,trie.max(num))

class Trie:
    END_SYMBOL = "*"
    def __init__(self):
        self.root = {}


    def add(self,word):
        current = self.root
        for c in word:
            if c not in current:
                current[c] = {}
            current = current[c]


        current[Trie.END_SYMBOL] = True


    def __contains__(self,word):

        current = self.root
        for c in word:
            if c not in current:
                return False

            current = current[c]

        return Trie.END_SYMBOL in current



    def delete(self,word):
        current = self.root

        for c in word:
            if c not in current:
                return

            current = current[c]


        if Trie.END_SYMBOL not in current:
            return

        del current[Trie.END_SYMBOL]

        
        if len(current) >= 1:
            return

        self._removeLastNodeWithMultipleChildren(word)
    

    def _removeLastNodeWithMultipleChildren(self,word):
        current = self.root
        lastNodeWithMultipleChildren = None
        childToBreak = None


        for i,c in enumerate(word[:-1]):
            if c not in current:
                return

            current = current[c]


            hasMultipleChildren = False
            count = 0

            for child in current:
                if child == Trie.END_SYMBOL:
                    hasMultipleChildren = True
                    break
                count += 1
                if count == 2:
                    hasMultipleChildren = True
                    break
            

            if hasMultipleChildren:
                lastNodeWithMultipleChildren = current
                childToBreak = word[i + 1]
    

        
        if lastNodeWithMultipleChildren:
            del lastNodeWithMultipleChildren[childToBreak]
        else:
            del self.root[word[0]]






def normalize(word,n):

    diff = n - len(word)


    return ['#'] * diff + word



def get_letters(words):
    

    letters = OrderedDict()

    for i in reversed(range(len(words[-1]))):
        for word in words:
            c = word[i]
            if c not in letters:
                letters[c] = None


    return letters

def is_valid(letters,words):

    w1,w2,w3 = words
    n = len(words[-1])
    carry = 0
    for i in reversed(range(n)):
        if any(letters[word[i]] is None for word in words):
            return True
        elif letters[w1[i]] + letters[w2[i]] + carry == letters[w3[i]]:
            carry = 0
        elif letters[w1[i]] + letters[w2[i]] + carry == 10 + letters[w3[i]]:
            carry = 1
        else:
            return False


    return True




def solve_crypta(words,letters,unassigned,index,numbers):
    if index == len(unassigned):
        print(letters)
        return True


    letter = unassigned[index]
    
    solution = False
    for number in numbers:
        letters[letter] = number
        numbers.remove(number)

        if is_valid(letters,words):
            solution = solve_crypta(words,letters,unassigned,index + 1,numbers) or solution

        numbers.add(number)
        letters[letter] = None
    
    return solution


def cryptarithemetic(words):


    words = list(map(list,words))
    n = len(words[-1])
    words[0] = normalize(words[0],n)
    words[1] = normalize(words[1],n)


    letters= get_letters(words)
    letters['#'] = 0 
    unassigned = [letter for letter in letters if letter !=  '#']

    numbers = set(range(0,10))

    solve_crypta(words,letters,unassigned,0,numbers)




