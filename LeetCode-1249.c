char* minRemoveToMakeValid(char* s) {
    int length = strlen(s);
    int stack[100001];
    int top = -1;

    int i = 0;
    while (i < length) {
        if (s[i] == '(') {
            
            top = top + 1;
            stack[top] = i;
        } else if (s[i] == ')') {
            if (top == -1) {
              
                s[i] = '*';
            } else {
                
                top = top - 1;
            }
        }
        i = i + 1;
    }

 
    while (top != -1) {
        int unmatched_index = stack[top];
        s[unmatched_index] = '*';
        top = top - 1;
    }

   
    int result_length = 0;
    i = 0;
    while (i < length) {
        if (s[i] != '*') {
            s[result_length] = s[i];
            result_length = result_length + 1;
        }
        i = i + 1;
    }
    s[result_length] = '\0';

    return s;
}
