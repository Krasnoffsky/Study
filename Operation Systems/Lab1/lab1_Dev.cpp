#include <iostream>
#include <fstream>

using namespace std;

struct Info
{
    char name[30];
    int age;
};

struct Data
{
    Data *Next;
    Info simple_info;
};

void menu_input(int &input, int &counter, int &all_item, bool &exit, Data *&Head, Data *&Start)
{
    int wait;

    if(input == 1)
    {
        if(counter >= all_item)
        {
            cout << endl << "----------------------------------------------" << endl << "Last item, input '0' to continue" << endl << "Input: ";
            cin >> wait;
        }

        else
        {
            Head = Head->Next;
            counter++;
        }
    }

    else if(input == 2)
    {
        if (!Head)
        {
            Head = new Data;
            cout << endl << "Input name: ";
            cin >> Head->simple_info.name;
            cout << endl << "Input age: ";
            cin >> Head->simple_info.age;
            Start = Head;
            Head->Next = NULL;
            all_item++;
        }

        else
        {
            int pos_in_list;
            struct Data *New_element;

            cout << endl << "Enter the position of the new item: ";
            cin >> pos_in_list;

            if(pos_in_list > 0)
            {
                if(pos_in_list == 1)
                {
                    New_element = new Data;
                    cout << endl << "Input name: ";
                    cin >> New_element->simple_info.name;
                    cout << endl << "Input age: ";
                    cin >> New_element->simple_info.age;
                    Head = Start;
                    New_element->Next = Head;
                    Start = New_element;
                    all_item++;
                    Head = Start;
                    counter = 1;
                }

                else if(pos_in_list < all_item)
                {
                    New_element = new Data;
                    cout << endl << "Input name: ";
                    cin >> New_element->simple_info.name;
                    cout << endl << "Input age: ";
                    cin >> New_element->simple_info.age;
                    Head = Start;
                    for(int i = 1; i < pos_in_list - 1; i++) Head = Head->Next;
                    New_element->Next = Head->Next;
                    Head->Next = New_element;
                    all_item++;
                    Head = Start;
                    counter = 1;
                }

                else
                {
                    if(pos_in_list < all_item + 2)
                    {
                        while(Head->Next != NULL) Head = Head->Next;
                        Head->Next = new Data;
                        cout << endl << "Input name: ";
                        cin >> Head->Next->simple_info.name;
                        cout << endl << "Input age: ";
                        cin >> Head->Next->simple_info.age;
                        Head->Next->Next = NULL;
                        all_item++;
                        Head = Start;
                        counter = 1;
                    }
                }
            }
        }
    }

    else if(input == 3)
    {
        struct Data *Swap;
        Head = Start;
        cout << endl << "Enter the number of the item to remove: ";
        cin >> wait;

        if(wait > 0 and wait <= all_item)
        {
            for(int i = 1; i < wait - 1; i++) Head = Head->Next; 

            if(wait == 1)
            {
                Start = Head->Next;
                delete Head;
            }

            else if(wait == all_item) delete Head->Next;

            else
            {
                Swap = Head->Next;
                Head->Next = Head->Next->Next;
                delete Swap;
            }

            Head = Start;
            counter = 1;
            all_item--;
        }
    }

    else if(input == 4)
    {
        ofstream out("struct.bin", ios::binary);
        Head = Start;

        out.write((char*)&all_item, sizeof(all_item));

        while(Head != NULL)
        {
            out.write((char*)Head, sizeof(Data));
            Head = Head->Next;
        }

        out.close();
        Head = Start;
        counter = 1;
    }

    else if(input == 5)
    {
        ifstream in("struct.bin", ios::binary);

        Data *new_Head = NULL, *new_Start = NULL;

        in.read((char*)&all_item, sizeof(all_item));
        for(int i = 0; i < all_item; i++)
        {
            if (!new_Head)
            {
                new_Head = new Data;

                in.read((char*)new_Head, sizeof(Data));

                new_Start = new_Head;
                new_Head->Next = NULL;
            }

            else
            {
                while(new_Head->Next != NULL) new_Head = new_Head->Next;
                new_Head->Next = new Data;

                in.read((char*)new_Head->Next, sizeof(Data));

                new_Head->Next->Next = NULL;
                new_Head = new_Start;
                counter = 1;
            }
        }

        in.close();
        Start = new_Start;
        Head = Start;
        counter = 1;
    }

    else if(input == 6)
    {
        Head = Start;
        for(counter = 1; counter < all_item + 1; counter++)
        {
            cout << endl << "Counter: " << counter << "/" << all_item << endl << "Name: " << Head->simple_info.name << endl << "Age: " << Head->simple_info.age << endl;
            Head = Head->Next;
        }
        cout << endl << "----------------------------------------------" << endl << "Input '0' to continue" << endl << "Input: ";
        cin >> wait;
        Head = Start;
        counter = 1;
    }

    else if(input == 7)
    {
        Head = Start;
        counter = 1;
    }
    else if(input == 8) exit = true;
}

int main(int argc, char *argv[])
{
    Data *Head = NULL, *Start = NULL; 
    bool exit = false;

    for(int input, counter = 1, all_item = 0; exit == false;)
    {
        system("cls");
        cout << "Menu:" << endl << "1 - Next" << endl << "2 - Paste" << endl << "3 - Delete" << endl << "4 - Save" << endl << "5 - Load" << endl << "6 - Display the entire list" << endl << "7 - Go start" << endl << "8 - Exit";
        if(all_item > 0)
        {
            cout << endl << "----------------------------------------------" << endl << "Counter: " << counter << "/" << all_item; 
            cout << endl << "Name: " << Head->simple_info.name << endl << "Age: " << Head->simple_info.age;
        }
        cout << endl << "----------------------------------------------" << endl << "Input: ";
        cin >> input;
        if(input > 0 and input < 9) menu_input(input, counter, all_item, exit, Head, Start);
    }

    delete Head;
    delete Start;

    return 0;
}
