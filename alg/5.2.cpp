#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class stack
{
    size_t kol, index;
    char *array;
public:
    stack(size_t n)
    {
        kol = n;
        index = 0;
        array = new char[kol];
    }
    void push(char ch)
    {
        assert(index < kol);
        array[index] = ch;
        index++;
    }
    char pop()
    {
        assert(index > 0);
        index--;
        return array[index];
    }
    char top()
    {
        assert (index > 0);
        return array[index - 1];
    }
    bool is_empty()
    {
        return index == 0;
    }
    ~stack()
    {
        delete [] array;
    }
};
bool anagram( char *stroka1, const char *stroka2 )
{
    size_t len = strlen(stroka2);
    stack st(len);
    int i = 0, j = 0;
    
    for( ; i < len; i++)
    {
        while(j <= len)
        {
            if(stroka1[j] == stroka2[i])
            {
                stroka1[i] = stroka1[j];
                j++;
                break;
            }
            if(!st.is_empty() && st.top() == stroka2[i])
            {
                stroka1[i] = st.pop();
                break;
            }
            else
            {
                st.push(stroka1[j]);
                j++;
            }
        }
    }
    
    if (strcmp(stroka1,stroka2) == 0)
    {
        return true;
    }
    return false;
}

int main() {
    char *stroka1 = new char[1000];
    char *stroka2 = new char[1000];
    cin >> stroka1 >> stroka2;
    if (anagram(stroka1, stroka2) == true)
        cout << "YES";
    else cout << "NO";
    delete [] stroka1;
    delete [] stroka2;
    return 0;
}
