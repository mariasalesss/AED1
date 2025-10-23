#include <stdio.h>
#include <stdlib.h>

int getchar_unlocked(void);
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

static void sift_down(int *a, int start, int end) {
    int root = start;
    while (1) {
        int left = 2 * root + 1;
        if (left >= end) break;
        int right = left + 1;
        int swap_idx = root;
        if (a[swap_idx] < a[left]) swap_idx = left;
        if (right < end && a[swap_idx] < a[right]) swap_idx = right;
        if (swap_idx == root) break;
        int tmp = a[root];
        a[root] = a[swap_idx];
        a[swap_idx] = tmp;
        root = swap_idx;
    }
}

static void build_max_heap(int *a, int N) {
    for (int i = (N - 2) / 2; i >= 0; --i) {
        sift_down(a, i, N);
        if (i == 0) break;
    }
}

static void heapsort(int *a, int N) {
    if (N <= 1) return;
    build_max_heap(a, N);
    for (int end = N - 1; end > 0; --end) {
        int tmp = a[0];
        a[0] = a[end];
        a[end] = tmp;
        sift_down(a, 0, end);
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

        heapsort(a, N);

        for (int i = 0; i < N; ++i) {
            char sep = (i + 1 == N) ? '\n' : ' ';
            write_int_sep(a[i], sep);
        }

        free(a);
    }

    return 0;
}
