int lengthOfLastWord(char* s) {
    int i = strlen(s)-1, wordLength = 0;
    while(i >= 0 && s[i] == ' '){
        i--;
    }
    while(i >= 0 && s[i] != ' '){
        i--;
        wordLength++;
    }

    return wordLength;
}