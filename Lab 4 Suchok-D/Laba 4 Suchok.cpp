
// SUCHOK DMITRIY 20-ITS 4-var
#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
    int n; unsigned char x;
    cin >> n;
    x = n;

    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1 ? 1 : 0);
    }

    int tmp = 0;
    string person = "";

    if ((x >> 7) & 1) person = "female";
    else person = "male";

    if ((x >> 5) & 1) tmp = 2;
    if ((x >> 5) & 1) tmp = tmp + 1;

    switch (tmp)
    {
    case 0:person = person + "/child"; break;
    case 1:person = person + "/teenager"; break;
    case 2:person = person + "/adult"; break;
    case 3: person = person + "/senior"; break;
    }

    int cs = 0;
    cs = ((x >> 5) & 1) ^ ((x >> 6) & 1) ^ ((x >> 7) & 1);

    tmp = 0;

    if (((x >> 7) & 1) == 0)
    {
        if ((x >> 4) & 1) tmp = 2;
        if ((x >> 3) & 1) tmp = tmp + 1;

        switch (tmp)
        {
        case 0:person = person + "/plumber"; break;
        case 1:person = person + "/president"; break;
        case 2:person = person + "/student"; break;
        case 3: person = person + "/tutor"; break;
        }

        tmp = 0;

        if ((x >> 2) & 1) tmp = 2;
        if ((x >> 1) & 1) tmp = tmp + 1;

        switch (tmp)
        {
        case 0:person = person + "/sport"; break;
        case 1:person = person + "/classic"; break;
        case 2:person = person + "/business"; break;
        case 3: person = person + "/hippie"; break;
        }

        tmp = 0;
    }
    else
    {
        if ((x >> 4) & 1) person = person + "/short"; else person = person + "/long";

        if ((x >> 3) & 1) tmp = 2;
        if ((x >> 2) & 1) tmp = tmp + 1;

        switch (tmp)
        {
        case 0:person = person + "/sport"; break;
        case 1:person = person + "/classic"; break;
        case 2:person = person + "/business"; break;
        case 3: person = person + "/hippie"; break;
        }

        tmp = 0;

        if ((x >> 1) & 1) person = person + "/married"; else person = person + "/not married";
    }

    cout << endl;
    cout << person << endl;

    if (((x >> 0) & 1) == cs) cout << "correct"; else cout << "incorrect";

    return 0;
}
