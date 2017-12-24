#include<bits/stdc++.h>
using namespace std;

void z_match(string text, string pat);
void calc_z_array(string text, int z[]);

void print_array(int z[], int l){
    for (int i=0;i<l;i++)
        printf("%d ", z[i]);
    printf("\n");
}

void z_match(string text, string pat){
    string full_string = pat + '$' + text;
    int n = full_string.length();
    int z[n];
    z[0]=0;
    calc_z_array(full_string, z);

    for(int i=0; i < n; i++) {
        if (z[i] == pat.length())
            cout << "pattern found at index " << i-pat.length()-1 << "\n";
    }

}

void calc_z_array(string text, int z[]){
    int n = text.length();
    int l, r, k;
    l = r = 0;

    for (int i=0; i < n ; i++){
        if(i > r){
            l = r = i;
            while (r < n && text[r-l] == text[r])
                r++;
            z[i] = r-l;
            r--;
        }else{
            k = i-l;

            if (z[k] < r-i+1){
                z[i] = z[k];
            }else{
                l = i;
                while (r < n && text[r-l] == text[r])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    z_match("geeks for geeks for geek", "geeks");
    return 0;
}