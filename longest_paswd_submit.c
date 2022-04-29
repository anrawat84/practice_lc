int validate_token(char *str)
{
        // int len = 0;
        int lc =0, dc = 0;
        while (*str) {
                if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
                        lc++;
                } else if (*str >= '0' && *str <= '9') {
                        dc++;
                } else {
                        return 0;
                }
                str++;
        }
        if ((lc %2 == 0) && (dc %2 ==1)) {
                return (lc+dc);
        } else {
                return 0;
        }
}
int solution(char *str) {
    // write your code in C99 (gcc 6.2.0)
        char *token = strtok(str, " \n");
        int max_len = 0, len = 0;
        while (token) {
                len = validate_token(token);
                if (len > max_len) {
                        max_len = len;
                }

                token = strtok(NULL, " \n");
        }
	if (max_len == 0) {
		return -1;
	}
        return max_len;
}

