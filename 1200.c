#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char v;
    struct no *e, *d;
} No;

No* novo(char v){ No* n=malloc(sizeof(No)); n->v=v; n->e=n->d=NULL; return n; }

No* ins(No* r,char v){
    if(!r) return novo(v);
    if(v<r->v) r->e=ins(r->e,v);
    else if(v>r->v) r->d=ins(r->d,v);
    return r;
}

int busca(No* r,char v){
    if(!r) return 0;
    if(r->v==v) return 1;
    return v<r->v?busca(r->e,v):busca(r->d,v);
}

int p;
void esp(char c){ if(!p) printf(" "); printf("%c",c); p=0; }

void in(No* r){ if(r){ in(r->e); esp(r->v); in(r->d);} }
void pre(No* r){ if(r){ esp(r->v); pre(r->e); pre(r->d);} }
void pos(No* r){ if(r){ pos(r->e); pos(r->d); esp(r->v);} }

int main(){
    No* r=NULL; char cmd[10],x;
    while(scanf("%s",cmd)!=EOF){
        if(cmd[0]=='I' && strlen(cmd)==1){ scanf(" %c",&x); r=ins(r,x); }
        else if(!strcmp(cmd,"INFIXA")){ p=1; in(r); puts(""); }
        else if(!strcmp(cmd,"PREFIXA")){ p=1; pre(r); puts(""); }
        else if(!strcmp(cmd,"POSFIXA")){ p=1; pos(r); puts(""); }
        else if(cmd[0]=='P'){ scanf(" %c",&x); printf("%c %s\n",x,busca(r,x)?"existe":"nao existe"); }
    }
}
