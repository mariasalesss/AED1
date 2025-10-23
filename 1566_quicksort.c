#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

enum { INSERTION_CUTOFF = 16 };

static inline void swap_int(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static void insertion_sort(int *a, int l, int r) {
    for (int i = l + 1; i < r; ++i) {
        int key = a[i];
        int j = i - 1;
        while (j >= l && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

static int median_of_three(int *a, int l, int r) {
    int m = l + ((r - l) >> 1);
    if (a[l] > a[m]) swap_int(&a[l], &a[m]);
    if (a[m] > a[r - 1]) swap_int(&a[m], &a[r - 1]);
    if (a[l] > a[m]) swap_int(&a[l], &a[m]);
    return a[m];
}

static int hoare_partition(int *a, int l, int r, int pivot) {
    int i = l - 1;
    int j = r;
    while (1) {
        do { ++i; } while (a[i] < pivot);
        do { --j; } while (a[j] > pivot);
        if (i >= j) return j;
        swap_int(&a[i], &a[j]);
    }
}

static void quick_sort_rec(int *a, int l, int r) {
    while (r - l > INSERTION_CUTOFF) {
        int pivot = median_of_three(a, l, r);
        int p = hoare_partition(a, l, r, pivot);
        if (p - l < r - (p + 1)) {
            quick_sort_rec(a, l, p + 1);
            l = p + 1;
        } else {
            quick_sort_rec(a, p + 1, r);
            r = p + 1;
        }
    }
    if (r - l > 1) insertion_sort(a, l, r);
}

static void quick_sort(int *a, int N) {
    if (N <= 1) return;
    quick_sort_rec(a, 0, N);
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
        if (!a) { fprintf(stderr, "malloc failed\n"); return 1; }

        for (int i = 0; i < N; ++i) {
            int v = read_int();
            if (v < 0) v = 0;
            a[i] = v;
        }

        quick_sort(a, N);

        for (int i = 0; i < N; ++i) {
            char sep = (i + 1 == N) ? '\n' : ' ';
            write_int_sep(a[i], sep);
        }

        free(a);
    }

    return 0;
}
