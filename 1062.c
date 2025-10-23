#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            int v[n];
            scanf("%d", &v[0]);
            if (v[0] == 0) {
                printf("\n");
                break;
            }
            for (int i = 1; i < n; i++) scanf("%d", &v[i]);

            int pilha[n], topo = -1, prox = 1, i = 0;
            while (i < n) {
                if (prox <= n && (topo == -1 || pilha[topo] != v[i])) {
                    pilha[++topo] = prox++;
                } else if (pilha[topo] == v[i]) {
                    topo--;
                    i++;
                } else break;
            }

            if (i == n) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
