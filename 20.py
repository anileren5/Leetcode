class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        flag = True
        for i in range(0,len(s)):
            current_parantheses = s[i]
            if current_parantheses in ['(','[','{']:
                stack.append(current_parantheses)
            elif current_parantheses in [')',']','}']:
                if (stack == []):
                    flag = False
                else:# The case stack is non empty
                    top = stack.pop()
                    if (current_parantheses == ')' and top != '(' ):
                        flag = False
                    elif (current_parantheses == ']' and top != '[' ):
                        flag = False
                    elif (current_parantheses == '}' and top != '{' ):
                        flag = False
        if (stack != []):
            flag = False
        return flag