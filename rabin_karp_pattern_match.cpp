#include<bits/stdc++.h>
#define d 256

void rabin_karp_match(char *text, char *pat, int q);
void rabin_karp_match(char *text, char *pat, int q){
    int N = strlen(text);
    int M = strlen(pat);
    int p = 0, t = 0;
    int h = 1;

    for (int i=0;i<M-1;i++)
        h = (h*d)%q;

    // calculating hash for pattern and text

    for (int i=0;i<M;i++){
        p = (d*p + pat[i])%q;
        t = (d*t + text[i])%q;
    }
    
    for (int i=0; i<N-M; i++){
        printf("%d %d\n", p, t);
        if (p == t){
            int j=0;
            for(j=0; j<M;j++){
                if(text[i+j] != pat[j]){
                    break;
                }
            }
            if(j == M)
                printf("pattern found at index %d\n",i);
        }
        if (i < N-M){
            t = (d*(t-text[i]*h) + text[i+M])%q;
            if(t<0)
                t += q;
        }
    }
}
int main(){
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101; // A prime number
    rabin_karp_match(txt, pat, q);
    return 0;
}