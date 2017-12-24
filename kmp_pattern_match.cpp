#include<bits/stdc++.h>

using namespace std;

void kmp_match(char text[], char pat[]);
void lps_array(char pat[], int lps[]);




void lps_array(char pat[], int lps[]){
	int M = strlen(pat),len =0;
	lps[0] = 0;
	for(int i=1; i < M;){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len != 0){
				len = lps[len-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void kmp_match(char text[], char pat[]){
    int M = strlen(pat);
    int N = strlen(text);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
 
    // Preprocess the pattern (calculate lps[] array)
    // printf("calculating lps");
    lps_array(pat, lps);
    
    for (int i=0, j=0; i < N;) {
        if (pat[j] == text[i]){
            i++;
            j++;
        }
        if(j == M){
            printf("pattern found at index %d\n", i-j);
            j = lps[j-1];
        }else if(i < N && pat[j] != text[i]){
            if (j != 0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    printf("text: %s\npattern: %s\n", txt, pat);
    kmp_match(txt, pat);
    return 0;
}