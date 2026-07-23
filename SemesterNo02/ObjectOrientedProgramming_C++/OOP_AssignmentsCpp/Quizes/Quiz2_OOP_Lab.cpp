#include <iostream>
using namespace std;

int custom_strlen(const char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

void custom_strcpy(char *dest, const char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

bool contains_word(const char *text, const char *word)
{
    int textLen = custom_strlen(text);
    int wordLen = custom_strlen(word);

    for (int i = 0; i <= textLen - wordLen; i++)
    {
        int j;
        for (j = 0; j < wordLen; j++)
        {
            if (text[i + j] != word[j])
            {
                break;
            }
        }
        if (j == wordLen)
        {
            return true;
        }
    }
    return false;
}

class TeamMember
{
private:
    char *memberName;
    char *role;
    bool reciter;

public:
    static int totalMembers;
    static bool paraCompleted[30];

    TeamMember()
    {
        memberName = nullptr;
        role = nullptr;
        reciter = false;
        totalMembers++;
    }

    TeamMember(const char *name, const char *r)
    {
        memberName = new char[custom_strlen(name) + 1];
        custom_strcpy(memberName, name);

        role = new char[custom_strlen(r) + 1];
        custom_strcpy(role, r);

        if (contains_word(role, "reciter"))
        {
            reciter = true;
        }
        else
        {
            reciter = false;
        }
        totalMembers++;
    }

    TeamMember(const TeamMember &obj)
    {
        if (obj.memberName != nullptr)
        {
            memberName = new char[custom_strlen(obj.memberName) + 1];
            custom_strcpy(memberName, obj.memberName);
        }
        else
        {
            memberName = nullptr;
        }

        if (obj.role != nullptr)
        {
            role = new char[custom_strlen(obj.role) + 1];
            custom_strcpy(role, obj.role);
        }
        else
        {
            role = nullptr;
        }

        reciter = obj.reciter;
        totalMembers++;
    }

    ~TeamMember()
    {
        if (memberName != nullptr)
            delete[] memberName;
        if (role != nullptr)
            delete[] role;
    }

    TeamMember &setMemberName(const char *name)
    {
        if (memberName != nullptr)
            delete[] memberName;
        memberName = new char[custom_strlen(name) + 1];
        custom_strcpy(memberName, name);
        return *this;
    }

    TeamMember &setRole(const char *r)
    {
        if (role != nullptr)
            delete[] role;
        role = new char[custom_strlen(r) + 1];
        custom_strcpy(role, r);

        if (contains_word(role, "reciter"))
        {
            reciter = true;
        }
        else
        {
            reciter = false;
        }
        return *this;
    }

    static void markParaCompleted(int paraNumber)
    {
        if (paraNumber >= 1 && paraNumber <= 30)
        {
            paraCompleted[paraNumber - 1] = true;
        }
    }

    static void displayProgress()
    {
        int completedCount = 0;
        cout << "Paras Completed: ";
        for (int i = 0; i < 30; i++)
        {
            if (paraCompleted[i])
            {
                cout << (i + 1) << " ";
                completedCount++;
            }
        }
        cout << "\nParas In Progress: " << (30 - completedCount) << endl;
    }

    void display() const
    {
        cout << "Member Name: " << (memberName ? memberName : "None") << endl;
        cout << "Role: " << (role ? role : "None") << endl;
        cout << "Reciter: " << (reciter ? "Yes" : "No") << endl;
        cout << "Total Members in AJ Islamic Team: " << totalMembers << endl;
        cout << "-----------------------------------" << endl;
    }
};

int TeamMember::totalMembers = 0;
bool TeamMember::paraCompleted[30] = {false};

int main()
{
    TeamMember m1;
    m1.setMemberName("Ahmad Jawad").setRole("founder");

    TeamMember m2("hafiz arham", "co founder and reciter");

    TeamMember m3;
    m3.setMemberName("tahir").setRole("content writer");

    TeamMember m4 = m3;
    m4.setMemberName("waleed");

    TeamMember m5("HM Aly Khan", "reciter");

    cout << "\n--- AJ Islamic Library Team ---" << endl;
    m1.display();
    m2.display();
    m3.display();
    m4.display();
    m5.display();

    TeamMember::markParaCompleted(9);
    TeamMember::markParaCompleted(28);
    TeamMember::markParaCompleted(29);
    TeamMember::markParaCompleted(30);

    cout << "\n--- Quran Recitation Progress ---" << endl;
    TeamMember::displayProgress();
    cout << endl;

    return 0;
}