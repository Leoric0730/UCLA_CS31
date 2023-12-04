#include <iostream>
    #include <string>
    #include <cassert>
    using namespace std;

int enumerate (const string a[], int n, string target);
int findMatch(const string [], int n, string target);
bool findRun(const string a[], int n, string target, int& begin, int& end);
int findMin(const string a[], int n);
int moveToEnd(string a[], int n, int pos);
int moveToBeginning(string a[], int n, int pos);
int findDifference(const string a1[], int n1, const string a2[], int n2);
int removeDups(string a[], int n);
bool subsequence(const string a1[], int n1, const string a2[], int n2);
int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max);
int divide(string a[], int n, string divider);

int main() {
    string h[7] = { "neil", "sonia", "john", "amy", "", "elena", "john" };
            assert(enumerate(h, 7, "john") == 2);
            assert(findMatch(h, 7, "john") == 2);
            int bg;
            int en;
            assert(findRun(h, 7, "", bg, en) && bg == 4 && en == 4);
            assert(findRun(h, 7, "john", bg, en) && bg == 2 && en == 2);
    string g[4] = { "neil", "sonia", "amy", "elena" };
            assert(findMin(g, 4) == 2);
            assert(moveToEnd(g, 4, 1) == 1 && g[1] == "amy" && g[3] == "sonia");
            assert(findDifference(h, 7, g, 3) == 2);
            assert(findDifference(h, 4, g, 4) == 2);
            
    string people[5] = { "john", "sonia", "samuel", "elena", "neil" };
            assert(findMin(people, 5) == 3);
            assert(moveToBeginning(people, 5, 2) == 2 && people[0] == "samuel" && people[2] == "sonia");
    string f[4] = { "elena", "amy", "sonia", "john" };
            assert(moveToBeginning(f, 4, 2) == 2 && f[0] == "sonia" && f[2] == "amy");
    string e[5] = { "elena", "elena", "elena", "sonia", "sonia" };
            assert(removeDups(e, 5) == 2 && e[1] == "sonia");
    
    string x[4] = { "john", "john", "samuel", "sonia" };
            string y[4] = { "amy", "elena", "john", "ketanji" };
            string z[10];
            assert(makeMerger(x, 4, y, 4, z, 10) == 8 && z[5] == "ketanji");
    string sc[6] = { "john", "amy", "samuel", "elena", "sonia", "neil" };
    string sc2[4] = { "john", "sonia", "amy", "neil" };
    cout << "All tests succeeded" << endl;
    return 0;
}

int enumerate (const string a[], int n, string target)
{
    int num = 0;
    if (n<0) {return -1;}
    else
        for (int i=0; i < n; i++)
            if (a[i] == target){
                num = num +1;
                }
      
    return num;
}
    
int findMatch(const string a[], int n, string target)
{
    if (n<0) {return -1;}
    else
        for (int i=0; i<n; i++)
        {
            if (a[i] == target)
                return i;
            }
    return -1;
}


bool findRun(const string a[], int n, string target, int& begin, int& end)
{
    if (findMatch(a,n,target) == -1) {return false;}
    
    
    else
        for (int i = 0; i<n; i++)
        {
            if ( a[i] == target )
            {
                begin = i;
                end = i;
                i++;
                while (i<n)
                { if (a[i] == target)
                    end = i;
                    i++;
                  if (a[i] != target)
                      return true;
                }
                
            }
        }
    return true;
}

int findMin(const string a[], int n)
{
    if (n>0)
    {
        int min = 0;
        
        for (int i=0; i<n; i++)
        {
        if (a[i] < a[min])
            min = i;
          }
    return min;
    }
    else
        return -1;
}

int moveToEnd(string a[], int n, int pos)
{
    if (n <= 0) { return -1;}
    
     else
     {
         string intermediate = a[pos];
         for ( int i = pos; i < n-1; i ++)
         {
             a[i] = a[i+1];
         }
        a[n-1] = intermediate;
     }
    return pos;
}


int moveToBeginning(string a[], int n, int pos)
{
    if (n<=0) {return -1;}
    else
    {   string intermediate = a[pos];
        for (int i=1; i < pos; i++)
        {
            string unchange_1 = a[i];
            string unchange_2 = a[i-1];
            a[i] = unchange_2;
            a[i+1] = unchange_1;
            
            
        }
        a[0] = intermediate;
        return pos;
    }
}

int findDifference(const string a1[], int n1, const string a2[], int n2) // Still some problems existed
{
    if( n1 < 0 || n2 < 0) {return -1;}
    else if (n1 <= n2)
        {
            for (int i=0; i < n1 ; i++)
            {
                if(a1[i] != a2[i]) {return i+1;}
            }
            return n1;
        }
    else
    {
        for (int i=0; i < n2 ; i++)
        {
            if(a1[i] != a2[i]) {return i+1;}
        }
        return n2;
        }
}

int removeDups(string a[], int n)
{
    if (n <= 0) { return -1;}  // Function has no significance if n is negative or 0.
    else {
    int index = 0;
    for (int i = 0; i<n; i++)     // For every items in the array,
    {
        while(i<n-1 && a[i] == a[i+1]) {i++;}  //skip to the next item if consecutive items are the same.
    
        a[index] = a[i];    // The index th number of the new array.
        index ++;        // increment index by 1.
    }
    return index;
    }
    
}

bool subsequence(const string a1[], int n1, const string a2[], int n2)
{
    if( n1<0 || n2<0) {return false;}
    int i=0;
    int j=0;
    for (i=0; i<n1; i++){
        if (a1[i] == a2[j]) {j++;}  //Ensure that the order of a2 in a1 as specified.
    }
    if (j==n2){return true;}  // If all the elements have been found and thier order was secured, return true.
    else
        return false; // All cases beyond are false.
}

int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
       for(int i = 0; i < n1 - 1; ++i){
           if(a1[i] > a1[i + 1]){
            return false;
           }
       }
       for(int i = 0; i < n2 - 1; ++i){
           if(a2[i] > a2[i + 1]){
               return false;
           }
       }
       if( n1 + n2 <= max){
           int i1 = 0, i2 = 0, i3 = 0;
           while(i1 < n1 && i2 < n2){
               if(a1[i1] < a2[i2]){
                   result[i3++] = a1[i1++];
               }
               else{
                   result[i3++] = a2[i2++];
               }
           }
           for(int i = i1; i < n1; ++i){
               result[i3++] = a1[i];
           }
           for(int i = i2; i < n2; ++i){
               result[i3++] = a2[i];
           }
           return n1 + n2;
       }
       else{
           return -1;
       }
    }

int divide(string a[], int n, string divider)
{
    if (n<0) {return -1;}
    string result[1000000];
    int j=0;
    for (int i=0; i<n; i++)
    {
        if (a[i] < divider) {
            result[j] = a[i];
            j++;
        }
    }
        for (int k=0; k<n; k++){
            if (a[k] >= divider){
                result[j] = a[k];
                j++;
            }
        }
    int count=0;
    while(count<n && result[count] < divider)
    {count++;}
    return count;


}
