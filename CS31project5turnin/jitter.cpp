#include <iostream>
#include <cassert>
#include <cctype>
#include <cstring>
using namespace std;
const int MAX_WORD_LENGTH = 20;

void DeleteNonalpha (char input[]);
int editStandards(int distance[],
                  char word1[][MAX_WORD_LENGTH+1],
                  char word2[][MAX_WORD_LENGTH+1],
                  int nStandards);

int determineMatchLevel(const int distance[],
                        const char word1[][MAX_WORD_LENGTH+1],
                        const char word2[][MAX_WORD_LENGTH+1],
                        int nStandards,
                        const char jeet[]);

int main() {
//    const int TEST1_NSTANDARDS = 4;
//    int test1dist[TEST1_NSTANDARDS] = { 2, 4, 1, 13 };
//    char test1w1[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "electric", "space", "electric", "were" };
//    char test1w2[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "billionaire", "capsule", "car", "eccentric" };
//    assert(editStandards(test1dist, test1w1, test1w2, TEST1_NSTANDARDS) == 4);
//    int test2dist[TEST1_NSTANDARDS] = { -2, 4, 1, 13 };
//    char test2w1[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "electric", "space", "", "were" };
//    char test2w2[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "billionai4re", "capsule", "car", "eccentric" };
//    cout << editStandards(test2dist, test2w1, test2w2, TEST1_NSTANDARDS) << endl;
//    int n = editStandards(test2dist, test2w1, test2w2, TEST1_NSTANDARDS);
//       for (int i = 0; i < n; i++) {
//           cout << test2dist[i] << ", " << test2w1[i] << ", " << test2w2[i] << endl;
//       }
//    assert(editStandards(test2dist, test2w1, test2w2, TEST1_NSTANDARDS) == 2);
//    int test3dist[TEST1_NSTANDARDS] = { 2, 4, 1, -13 };
//    char test3w1[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "electric", "", "electric", "were" };
//    char test3w2[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "billionaire", "ca4psule", "car", "eccentric" };
//    assert(editStandards(test3dist, test3w1, test3w2, TEST1_NSTANDARDS) == 2);
//    int test4dist[TEST1_NSTANDARDS] = { -2, -4, -1, -13 };
//    char test4w1[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "electric", "space", "electric", "were" };
//    char test4w2[TEST1_NSTANDARDS][MAX_WORD_LENGTH + 1] = { "b4illionaire", "capsule", "car", "eccentric" };
//    assert(editStandards(test4dist, test4w1, test4w2, TEST1_NSTANDARDS) == 0);

                        const int TEST1_NSTANDARDS = 4;
                    int test1dist[TEST1_NSTANDARDS] = {
                        2,             4,         1,         13
                    };
                    char test1w1[TEST1_NSTANDARDS][MAX_WORD_LENGTH+1] = {
                        "eccentric",   "space",  "electric", "were"
                    };
                    char test1w2[TEST1_NSTANDARDS][MAX_WORD_LENGTH+1] = {
                        "billionaire", "capsule", "car",     "eccentric"
                    };

                    assert(determineMatchLevel(test1dist, test1w1, test1w2, TEST1_NSTANDARDS,
                        "The eccentric outspoken billionaire launched a space station cargo capsule.") == 2);
                    assert(determineMatchLevel(test1dist, test1w1, test1w2, TEST1_NSTANDARDS,
                        "The eccentric outspoken billionaire launched    a space capsule.") == 2);
                    assert(determineMatchLevel(test1dist, test1w1, test1w2, TEST1_NSTANDARDS,
                        "**** 2022 ****") == 0);

                    assert(determineMatchLevel(test1dist, test1w1, test1w2, TEST1_NSTANDARDS,
                        "  It's an ELECTRIC car!") == 1);
                    assert(determineMatchLevel(test1dist, test1w1, test1w2, TEST1_NSTANDARDS,
                        "space space capsule space capsule capsule") == 1);

                    assert(determineMatchLevel(test1dist, test1w1, test1w2, TEST1_NSTANDARDS,
                        "Two eccentric billionaires were space-capsule riders.") == 0);
                    cout << "All tests succeeded" << endl;
             }



void DeleteNonalpha (char input[]){
    int num = 0;
    for(int j=0;input[j] != '\0';j++)
    {
        if(isalpha(input[j]) || isspace(input[j]))
        { input[num] = input[j];
            num++;}
       }
    input[num] ='\0';
}

int editStandards(int distance[],
                  char word1[][MAX_WORD_LENGTH+1],
                  char word2[][MAX_WORD_LENGTH+1],
                  int nStandards){
    if(nStandards <= 0)
        return 0;
    // Firstly remove modules with negative numbers in the array.
    
    int num = 0;
    for (int i = 0; i<nStandards; i++){
        if (distance[i] > 0) {
            distance[num] = distance[i];
            strcpy(word1[num],word1[i]);
            strcpy(word2[num],word2[i]);
            num++; }
    }
            nStandards = num;
            distance[num] = '\0';
    
    // Remove the Standards with word1 or word2 containing '' within module.
    for (int i=0; i < nStandards; i++)
    {
        if ((word1[i][0] == '\0') || (word2[i][0] == '\0')) {
            int pos = i;
            char w1copy[MAX_WORD_LENGTH+1]; char w2copy[MAX_WORD_LENGTH+1]; int copy;
            strcpy(w1copy,word1[pos]); strcpy(w2copy,word2[pos]); copy = distance[pos];
            for (int k=pos; k<nStandards-1; k++){
                distance[k] = distance[k+1];
                strcpy(word1[k],word1[k+1]);
                strcpy(word2[k],word2[k+1]);
            }
            distance[nStandards-1] = copy;
            strcpy(word1[nStandards-1],w1copy); strcpy(word2[nStandards-1],w2copy);
            nStandards--;
            i--;
        }
    }
    
    
    
    //  Remove standards that contain non-alpha character for two arrays.
    for (int i=0; i<nStandards; i++) {
        for (int j=0; j< strlen(word1[i]); j++) {
            if (!isalpha(word1[i][j])){
                int pos = i;
                char w1copy[MAX_WORD_LENGTH+1]; char w2copy[MAX_WORD_LENGTH+1]; int copy;
                strcpy(w1copy,word1[pos]); strcpy(w2copy,word2[pos]); copy = distance[pos];
                for (int k=pos; k<nStandards-1; k++){
                    distance[k] = distance[k+1];
                    strcpy(word1[k],word1[k+1]);
                    strcpy(word2[k],word2[k+1]);
                }
                distance[nStandards-1] = copy;
                strcpy(word1[nStandards-1],w1copy); strcpy(word2[nStandards-1],w2copy);
                nStandards--;
                i--;
            }
        }
    }
    for (int i=0; i<nStandards; i++) {
        for (int j=0; j< strlen(word2[i]); j++) {
            if (!isalpha(word2[i][j])){
                int pos = i;
                char w1copy[MAX_WORD_LENGTH+1]; char w2copy[MAX_WORD_LENGTH+1]; int copy;
                strcpy(w1copy,word1[pos]); strcpy(w2copy,word2[pos]); copy = distance[pos];
                for (int k=pos; k<nStandards-1; k++){
                    distance[k] = distance[k+1];
                    strcpy(word1[k],word1[k+1]);
                    strcpy(word2[k],word2[k+1]);
                }
                distance[nStandards-1] = copy;
                strcpy(word1[nStandards-1],w1copy); strcpy(word2[nStandards-1],w2copy);
                nStandards--;
                i--;
            }
        }
    }
    
    //Convert all the characters into lowercase in word1 and word2 .
    for (int i=0; i<nStandards; i++){
        for (int j=0; j < strlen(word1[i]); j++){
            word1[i][j] = tolower(word1[i][j]);
        }
        
    }
    for (int i=0; i<nStandards; i++) {
        for (int j=0; j < strlen(word2[i]); j++){
            word2[i][j] = tolower(word2[i][j]);
        }
    }
    
    //Finally, remove all the duplicates and leave one with the biggest corresponding int.
    for (int i = 0; i < nStandards; i++){
        int max = distance[i];
        for (int j = i+1; j < nStandards; j++){
            if(strcmp(word1[i],word1[j]) == 0 && strcmp(word2[i],word2[j]) == 0){
                if (distance[j] > max){
                    max = distance[j];
                    int pos = i;
                    char w1copy[MAX_WORD_LENGTH+1]; char w2copy[MAX_WORD_LENGTH+1];
                    strcpy(w1copy,word1[pos]); strcpy(w2copy,word2[pos]);
                    for (int k=pos; k<nStandards-1; k++){
                        distance[k] = distance[k+1];
                        strcpy(word1[k],word1[k+1]);
                        strcpy(word2[k],word2[k+1]);
                    }
                    strcpy(word1[nStandards-1],w1copy); strcpy(word2[nStandards-1],w2copy);
                    nStandards--;
                    j = i;
                }
                
                else        //when the former distance is bigger or equal to the latter: Remove the latter.
                {int pos = j;
                    char w1copy[MAX_WORD_LENGTH+1]; char w2copy[MAX_WORD_LENGTH+1];
                    strcpy(w1copy,word1[pos]); strcpy(w2copy,word2[pos]);
                    for (int k=pos; k<nStandards-1; k++){
                        distance[k] = distance[k+1];
                        strcpy(word1[k],word1[k+1]);
                        strcpy(word2[k],word2[k+1]);
                    }
                    strcpy(word1[nStandards-1],w1copy); strcpy(word2[nStandards-1],w2copy);
                    nStandards--; j--;
                }
            }
        }
    }
    return nStandards;
}
    
    
int determineMatchLevel(const int distance[],
                        const char word1[][MAX_WORD_LENGTH+1],
                        const char word2[][MAX_WORD_LENGTH+1],
                        int nStandards,
                        const char jeet[]){
    int Bound = 280;
    char copyOfJeet[Bound+1];
    strcpy(copyOfJeet, jeet);
    DeleteNonalpha (copyOfJeet);
    
    
    
// Let's further modify it to make each word seperated only by one space: there can be as many spaces as it can before the first word, since we don't care about them anyway.
    int newnum = 0;
    for(int i=0; i< strlen(copyOfJeet) ; ++i)
    {
        if (isalpha(copyOfJeet[i])) {
            copyOfJeet[newnum] = copyOfJeet[i];
            newnum++;
        }
        if (isspace(copyOfJeet[i])) {
            copyOfJeet[newnum] = copyOfJeet[i];
            while (isspace(copyOfJeet[i+1])) { i++; }
            newnum++;
        }
    }
    copyOfJeet[newnum] = ' ';
    copyOfJeet[newnum+1] = '\0';
    
//    for(int i=0; i< strlen(copyOfJeet) ; ++i)
//    {
//        cout << copyOfJeet[i];
//    }
//    cout << endl;
//
    for(int i=0; i< strlen(copyOfJeet) ; ++i)
    {
        copyOfJeet[i] = tolower(copyOfJeet[i]);
    }
 // Now, the final step is to determine the match level of standard modules provided.
 // Make a loop that loop through elements 0 to nStandards-1 in distance, word1, word2 which check the position of occurence of ith element of word1 in copyOfJeet, ith element if word2 in copyOfJeet, and see if the spaces between them are <= distance[i].
    
    int count = 0;
    for (int i = 0; i < nStandards; i++) {
        int numSpace = 0;
        if (strstr(copyOfJeet, word1[i]) == NULL || strstr(copyOfJeet, word2[i]) == NULL) { ;}
        else if (strstr(copyOfJeet, word2[i]) - strstr(copyOfJeet, word1[i]) < 0) { ;}
        else {
            char* first = strstr(copyOfJeet, word1[i]);
            char* dp;
            char* second = strstr(copyOfJeet, word2[i]);
            for (dp = first; dp < second; dp++) {
                
                if ( *dp == ' ') {numSpace++; }
            }
            
            if (*(first + strlen(word1[i])) != ' ') {; }
            else if ((*(second + strlen(word2[i])) != ' ')) {;}
            else if (numSpace <= distance[i]) {  count++;}
        }
    }
    
    return count;
}
