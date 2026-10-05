int scoreOfParentheses(char* s) {
    int stack[51];
    int top = 0;
    stack[top] = 0;

    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '(') {
            top = top + 1;
            stack[top] = 0;
        } else {
            int inside_score = stack[top];
            top = top - 1;

            int current_score;
            if (inside_score == 0) {
                current_score = 1;
            } else {
                current_score = 2 * inside_score;
            }

            stack[top] = stack[top] + current_score;
        }
        i = i + 1;
    }

    return stack[0];
}
