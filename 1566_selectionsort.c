#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getchar_unlocked();
int putchar_unlocked(int c);

static inline int fast_getchar(void) {
#if defined(_MSC_VER)
    return getchar();
#else
    return getchar_unlocked();
#endif
}

static int read_int(void) {
    int c = fast_getchar();
    while (c != EOF && (c < '0' || c > '9')) c = fast_getchar();
    if (c == EOF) return -1;
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = fast_getchar();
    }
    return x;
}

static inline void fast_putchar(int c) {
#if defined(_MSC_VER)
    putchar(c);
#else
    putchar_unlocked(c);
#endif
}

static void write_int_sep(int x, char sep) {
    char buf[16];
    int i = 0;
    if (x == 0) buf[i++] = '0';
    else {
        int tmp = x;
        char rev[16];
        int j = 0;
        while (tmp > 0) {
            rev[j++] = '0' + (tmp % 10);
            tmp /= 10;
        }
        while (j--) buf[i++] = rev[j];
    }
    for (int k = 0; k < i; ++k) fast_putchar(buf[k]);
    fast_putchar(sep);
}

enum { THRESHOLD_SELECTION = 5000 };

static void selection_sort(int *a, int N) {
    for (int i = 0; i < N - 1; ++i) {
        int min_idx = i;
        int min_val = a[i];
        for (int j = i + 1; j < N; ++j) {
            if (a[j] < min_val) {
                min_val = a[j];
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = tmp;
        }
    }
}

static void counting_sort_and_write(const int *vals, int N) {
    int counts[231];
    memset(counts, 0, sizeof(counts));
    for (int i = 0; i < N; ++i) {
        int v = vals[i];
        if (v < 20) v = 20;
        if (v > 230) v = 230;
        counts[v]++;
    }
    int printed = 0;
    for (int h = 20; h <= 230; ++h) {
        while (counts[h] > 0) {
            printed++;
            char sep = (printed == N) ? '\n' : ' ';
            write_int_sep(h, sep);
            counts[h]--;
        }
    }
}

int main(void) {
    int NC = read_int();
    if (NC < 0) return 0;

    for (int case_i = 0; case_i < NC; ++case_i) {
        int N = read_int();
        if (N <= 0) {
            fast_putchar('\n');
            continue;
        }

        int *a = (int*) malloc((size_t)N * sizeof(int));
        if (!a) {
            fprintf(stderr, "malloc failed\n");
            return 1;
        }

        for (int i = 0; i < N; ++i) {
            int v = read_int();
            if (v < 0) v = 0;
            a[i] = v;
        }

        if (N <= THRESHOLD_SELECTION) {
            selection_sort(a, N);
            for (int i = 0; i < N; ++i) {
                char sep = (i + 1 == N) ? '\n' : ' ';
                write_int_sep(a[i], sep);
            }
        } else {
            counting_sort_and_write(a, N);
        }

        free(a);
    }

    return 0;
}
