#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_invalid(long long n) {
    char buf[32];
    sprintf(buf, "%lld", n);
    int len = strlen(buf);

    if (len % 2 != 0)
        return false; 

    int half = len / 2;

    return strncmp(buf, buf + half, half) == 0;
}
bool is_invalid2(long long n){
    char buf[32];
    sprintf(buf, "%lld", n);
    int len = strlen(buf);

    if (len <= 1) return false;

    for (int p = 1; p <= len / 2; p++) {
        if (len % p != 0) continue;

        bool ok = true;
        for (int i = p; i < len; i += p) {
            if (strncmp(buf, buf + i, p) != 0) {
                ok = false;
                break;
            }
        }

        if (ok) return true;
    }

    return false;
}


int main(int argc, char *argv[]) {
    char *filename = "input.txt";
    if (argc == 2) {
        filename = argv[1];
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    long long answer = 0;
    long long answer2 = 0;
    long long first, second;

    while (fscanf(file, "%lld-%lld,", &first, &second) == 2) {
        for (long long n = first; n <= second; n++) {
            if (is_invalid(n)) {
                answer += n;
            }
            if(is_invalid2(n)){
                answer2 += n;
            }
        }
    }

    printf("Answer: %lld\n", answer);
    printf("Answer2: %lld\n", answer2);
    fclose(file);
    return 0;
}
