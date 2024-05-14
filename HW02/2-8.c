#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000
#define WORD_LEN 100
#define MAX_WORDS 100

typedef struct {
    char word[WORD_LEN];
    int count;
} WordFreq;

int compare(const void *a, const void *b) {
    WordFreq *wordA = (WordFreq *)a;
    WordFreq *wordB = (WordFreq *)b;
    if (wordA->count == wordB->count) return strcmp(wordA->word, wordB->word);
    return wordB->count - wordA->count;
}

void replaceWord(char *sentence, const char *find, const char *replace) {
    char buffer[MAX_LEN] = {0};
    char *insert_point = &buffer[0];
    const char *tmp = sentence;
    size_t find_len = strlen(find);
    size_t replace_len = strlen(replace);

    while (1) {
        const char *p = strstr(tmp, find);

        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        memcpy(insert_point, replace, replace_len);
        insert_point += replace_len;

        tmp = p + find_len;
    }

    strcpy(sentence, buffer);
}

void insertWordBefore(char *sentence, const char *find, const char *insert) {
    char buffer[MAX_LEN] = {0};
    char *insert_point = &buffer[0];
    const char *tmp = sentence;
    size_t find_len = strlen(find);
    size_t insert_len = strlen(insert);

    while (1) {
        const char *p = strstr(tmp, find);

        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        memcpy(insert_point, insert, insert_len);
        insert_point += insert_len;

        memcpy(insert_point, " ", 1);
        insert_point += 1;

        memcpy(insert_point, find, find_len);
        insert_point += find_len;

        tmp = p + find_len;
    }

    strcpy(sentence, buffer);
}

void deleteWord(char *sentence, const char *find) {
    replaceWord(sentence, find, "");
}

void countWords(char *sentence, WordFreq wordArray[], int *wordCount) {
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < *wordCount; i++) {
            if (strcmp(wordArray[i].word, token) == 0) {
                wordArray[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordArray[*wordCount].word, token);
            wordArray[(*wordCount)++].count = 1;
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char article[MAX_LEN], p[WORD_LEN], q[WORD_LEN];
    fgets(article, MAX_LEN, stdin);
    fgets(p, WORD_LEN, stdin);
    fgets(q, WORD_LEN, stdin);
    p[strcspn(p, "\n")] = 0;
    q[strcspn(q, "\n")] = 0;

    char tempArticle[MAX_LEN];
    strcpy(tempArticle, article);
    replaceWord(tempArticle, p, q);
    printf("%s\n", tempArticle);

    strcpy(tempArticle, article);
    insertWordBefore(tempArticle, p, q);
    printf("%s\n", tempArticle);

    strcpy(tempArticle, article);
    deleteWord(tempArticle, p);
    printf("%s\n", tempArticle);

    WordFreq wordArray[MAX_WORDS] = {0};
    int wordCount = 0;
    strcpy(tempArticle, article);
    countWords(tempArticle, wordArray, &wordCount);

    qsort(wordArray, wordCount, sizeof(WordFreq), compare);
    for (int i = 0; i < wordCount; i++) {
        printf("%s, %d\n", wordArray[i].word, wordArray[i].count);
    }

    return 0;
}
