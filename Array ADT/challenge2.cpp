#include <iostream>
#include <map>
using namespace std;
map<string, string> tagValue;

void createData(int n, string previousTag)
{
    if (n == 0)
    {
        return;
    }
    string HRML;
    getline(cin, HRML);

    string tag, attr, value;
    int i = 1;
    int j = i;
    if (HRML[i] == '/')
    {
        tag = "";
    }
    else
    {
        while (HRML[i] != ' ')
            i++;
        if (previousTag == "")
        {
            tag = HRML.substr(j, i - j);
        }
        else
        {
            tag = previousTag + '.' + HRML.substr(j, i - j);
        }
        while (HRML[i] != '>')
        {
            while (HRML[i] == ' ' && HRML[i] != '>')
                i++;
            j = i;
            while (HRML[i] != '=' && HRML[i] != '>')
                i++;

            attr = HRML.substr(j, i - j);
            if (HRML[i] != '>')
            {
                i = i + 2;
                j = i;
                while (HRML[i] != '"' && HRML[i] != '>')
                    i++;
                value = HRML.substr(j, i - j);
                tagValue[tag + '~' + attr] = value;
            }
            else
            {
                break;
            }
        }
    }
    createData(--n, tag);
}
int main()
{
    // cout << "Enter number of lines and number of queries :";
    // int n, q;
    // cin >> n >> q;
    createData(2, "");
    cout << tagValue["tag1~attr"];
    return 0;
}
// <tag1 name = "Khan">
// <tag2 age = "24">
// </tag2>
// </tag1>
// tag1~name
// tag1.tag2~age