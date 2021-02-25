class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ""
        for x in range(n):
            ans += 'a'
            
        k -= n
        index = n-1
        
        dt ={1:'a',2:'b',3:'c',4:'d',5:'e',6:'f',7:'g',8:'h',9:'i',10:'j',11:'k',12:'l',13:'m',14:'n',15:'o',16:'p',17:'q',18:'r',19:'s',20:'t',21:'u',22:'v',23:'w',24:'x',25:'y',26:'z'}        
        while k > 0:
            if k > 25:
                ans = ans[:index] + 'z' + ans[index+1:]
                k -= 25
            else:
                ans = ans[:index] + dt[k+1] + ans[index+1:]
                k = 0
            index -= 1
        
        return ans